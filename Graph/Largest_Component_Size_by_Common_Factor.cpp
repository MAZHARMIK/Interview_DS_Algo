/*
    Company Tags  : Google
    Leetcode Link : https://leetcode.com/problems/largest-component-size-by-common-factor/
*/

//Approach-1 (Union Find - TLE)
class Solution {
public:
    bool commonFactor(int &a, int &b) {
        int factor = 2;
        
        while(factor <= a && factor <= b) {
            if(a%factor == 0 && b%factor == 0)
                return true;
            factor++;
        }
        return false;
    }
    
    int find(vector<int>& parent, int i) {
        if(parent[i] == -1)
            return i;
        
        return parent[i] = find(parent, parent[i]);
    }
    
    void Union(vector<int>& parent, int x, int y) {
        parent[x] = y;
    }
    
    int largestComponentSize(vector<int>& nums) {
        vector<pair<int, int>> edges;
        int n = nums.size();
        
        //This part is costly resulting in TLE (Building the graph)
        for(int i = 0; i<n-1; i++) {
            for(int j = i+1; j<n; j++) {
                if(commonFactor(nums[i], nums[j])) {
                    edges.push_back({i, j});
                }
            }
        }
        
        vector<int> parent(n, -1);
        int result = 0;
        
        for(pair<int, int>& edge : edges) {
            int u = edge.first;
            int v = edge.second;
            
            int x = find(parent, u);
            int y = find(parent, v);
            
            if(x != y)
                Union(parent, x, y);
            
        }
        
        unordered_map<int, int> mp;
        for(int i = 0; i<n; i++) {
            int set = find(parent, i);
            mp[set]++;
            result = max(result, mp[set]);
        }
        return result;
    }
};

//Approach-2 (Union Find By Rank and Compression) (TLE)
class Solution {
public:
    bool commonFactor(int &a, int &b) {
        int factor = 2;
        
        while(factor <= a && factor <= b) {
            if(a%factor == 0 && b%factor == 0)
                return true;
            factor++;
        }
        return false;
    }
    
    int find(vector<vector<int>>& sub, int i) {
        if(sub[i][0] == i)
            return i;
        
        return sub[i][0] = find(sub, sub[i][0]);
    }
    
    void Union(vector<vector<int>>& sub, int x, int y) {
        int x_s = find(sub, x);
        int y_s = find(sub, y);
        
        if(sub[x_s][1] > sub[y_s][1]) {
            sub[y_s][0] = x_s;
        } else if (sub[x_s][1] > sub[y_s][1]) {
            sub[x_s][0] = y_s;
        } else {
            sub[y_s][0] = x_s;
            sub[x_s][1]++;
        }
    }
    
    int largestComponentSize(vector<int>& nums) {
        vector<pair<int, int>> edges;
        int n = nums.size();
        
        //This part is costly resulting in TLE (Building the graph)
        for(int i = 0; i<n-1; i++) {
            for(int j = i+1; j<n; j++) {
                if(commonFactor(nums[i], nums[j])) {
                    edges.push_back({i, j});
                    
                }
            }
        }
        vector<vector<int>> sub(n, vector<int>(2));
        for(int i = 0; i<n; i++)
            sub[i][0] = i;
        
        int result = 0;
        
        for(pair<int, int>& edge : edges) {
            int u = edge.first;
            int v = edge.second;
            
            int x = find(sub, u);
            int y = find(sub, v);
            
            if(x != y)
                Union(sub, x, y);
            
        }
        
        unordered_map<int, int> mp;
        for(int i = 0; i<n; i++) {
            int set = find(sub, i);
            mp[set]++;
            result = max(result, mp[set]);
        }
        return result;
    }
};

//Approach-3 (Union Find With Precalculated Parent vector) ACCEPTED
//You can further optimise it using Union Find with Rank and Path Compresion
class Solution {
public:
    
    int find(vector<int>& parent, int i) {
        if(parent[i] == -1)
            return i;
        
        return parent[i] = find(parent, parent[i]);
    }
    
    void Union(vector<int>& parent, int x, int y) {
        int x_s = find(parent, x);
        int y_s = find(parent, y);
        
        if(x_s != y_s)
            parent[x_s] = y_s;
    }
    
    int largestComponentSize(vector<int>& nums) {
        int n = nums.size();
        vector<int> parent(100001, -1);
        
        for(int &x : nums) {
            for(int factor = 2; factor<=sqrt(x); factor++) {
                if(x%factor == 0) {
                    Union(parent, factor, x); //setting parent
                    Union(parent, x, x/factor); //setting parent
                }
            }
        }
        
        unordered_map<int, int> mp;
        int result = 0;
        for(int &x : nums) {
            int root = find(parent, x);
            mp[root]++;
            result = max(result, mp[root]);
        }
        return result;
    }
};
