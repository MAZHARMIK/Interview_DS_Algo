/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=fGSPLQ1la90
    Company Tags                : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/detonate-the-maximum-bombs/
*/

//Approach-1 (Using DFS)
class Solution {
public:
    typedef long long LL;
    void DFS(int u, unordered_set<int> & visited, unordered_map<int, vector<int>> &adj) {
        
        visited.insert(u);
        
        for(int &v : adj[u]) {
            if(visited.find(v) == visited.end()) { //Not visited
                DFS(v, visited, adj);
            }
        }

    }
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        
        unordered_map<int, vector<int>> adj;
        
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                
                if(i == j) //same bomb
                    continue;
                
                LL x1 = bombs[i][0];
                LL y1 = bombs[i][1];
                LL r1 = bombs[i][2];
                
                LL x2 = bombs[j][0];
                LL y2 = bombs[j][1];
                LL r2 = bombs[j][2];
                
                //Make a directed edge from i to j if i can detonate j as well
                
                LL distance = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
                
                if(LL(r1*r1) >= distance) {
                    adj[i].push_back(j);
                }
                
            }
        }
        
        
        int result = 0;
        unordered_set<int> visited;
        
        for(int i = 0; i<n; i++) {
            DFS(i, visited, adj);
            int count = visited.size();
            result = max(result, count);
            visited.clear();
        }
        
        return result;
        
    }
};


//Approach-2 (Using BFS)
class Solution {
public:
    typedef long long LL;
    int BFS(int u, unordered_map<int, vector<int>> &adj) {
        unordered_set<int> visited;
        queue<int> que;
        que.push(u);
        visited.insert(u);

        while(!que.empty()) {
            
            int temp = que.front();
            que.pop();
            
            for(int &v : adj[temp]) {
                
                if(visited.find(v) == visited.end()) {
                    que.push(v);
                    visited.insert(v);
                }
                
            }
            
            
        }
        
        return visited.size();
    }
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        
        unordered_map<int, vector<int>> adj;
        
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                
                if(i == j) //same bomb
                    continue;
                
                LL x1 = bombs[i][0];
                LL y1 = bombs[i][1];
                LL r1 = bombs[i][2];
                
                LL x2 = bombs[j][0];
                LL y2 = bombs[j][1];
                LL r2 = bombs[j][2];
                
                //Make a directed edge from i to j if i can detonate j as well
                
                LL distance = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
                
                if(LL(r1*r1) >= distance) {
                    adj[i].push_back(j);
                }
                
            }
        }
        
        
        int result = 0;
        
        for(int i = 0; i<n; i++) {
            int count = BFS(i, adj);
            result = max(result, count);
        }
        
        return result;
        
    }
};
