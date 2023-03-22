/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=blUPwDof-r4
    Company Tags                : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/
*/

                                    /*LEETCODE WEEKLY CONTEST - 322*/

//DFS
class Solution {
public:

    void dfs(unordered_map<int, vector<pair<int, int>>> &adj, int u, vector<bool>& visited, int &result) {
        
        visited[u] = true;
        
        for(auto &vec : adj[u]) {
            int v = vec.first;
            int c = vec.second;
            
            result = min(result, c);
            
            if(!visited[v]) {
                dfs(adj, v, visited, result);
            }
        }
    }
    
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int, int>>> adj;
        
        for(auto &vec : roads) {
            
            int u = vec[0];
            int v = vec[1];
            int c = vec[2];
            
            adj[u].push_back({v, c});
            adj[v].push_back({u, c});
        }
        
        vector<bool> visited(n, false);
        int result = INT_MAX;
        dfs(adj, 1, visited, result);
        
        return result;
    }
};

//BFS soon
//Also, Union Find approach will be provided soon in Union Find sub-repo
