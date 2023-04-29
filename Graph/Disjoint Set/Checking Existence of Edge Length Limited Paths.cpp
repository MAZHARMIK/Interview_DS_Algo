/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=WYBpATWlXWA
    Company Tags                : GOOGLE (onsite 2nd Round)
    Leetcode Link               : https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths/
*/

//Using DSU
class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find (int x) {
        if (x == parent[x]) 
            return x;

        return parent[x] = find(parent[x]);
    }

    void Union (int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent) 
            return;

        if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if(rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }

    
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        
        rank.resize(n, 0);
        parent.resize(n);
        for(int i = 0; i<n; i++)
            parent[i] = i;
        
        
        for(int i = 0; i<queries.size(); i++) {
            queries[i].push_back(i);
        }
        
        
        auto lambda = [&](vector<int>& v1, vector<int>& v2) {
            return v1[2] < v2[2];
        };

        sort(begin(edgeList), end(edgeList), lambda);
        sort(begin(queries),  end(queries),  lambda);
        
        vector<bool> result(queries.size());
        
        int j = 0;
        for(vector<int>& query : queries) {
            
            int u   = query[0];
            int v   = query[1];
            int w   = query[2];
            int idx = query[3];
            
            while(j < edgeList.size() && edgeList[j][2] < w) {
                Union(edgeList[j][0], edgeList[j][1]);
                j++;
            }
            
            result[idx] = find(u) == find(v);
            
        }
        
        return result;
        
    }
};
