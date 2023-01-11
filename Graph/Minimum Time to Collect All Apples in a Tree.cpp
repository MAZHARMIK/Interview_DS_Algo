/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=qSBvKlUq0xo
      Company Tags                : Microsoft
      Leetcode Link               : https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/
*/

//DFS - O(V+E) - We visit all nodes and edges in the graph
class Solution {
public:
    
    int DFS(unordered_map<int, vector<int>> &adj, int curr, int parent, vector<bool>& hasApple) {
        int time = 0;
        
        for(int &child : adj[curr]) {
            if(child == parent)
                continue;
            
            int time_from_bachha_log = DFS(adj, child, curr, hasApple);
            
            if(time_from_bachha_log || hasApple[child])
                time += 2 + time_from_bachha_log;
            
        }
        
        
        return time;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int, vector<int>> adj;
        
        for(auto &vec : edges) {
            int u = vec[0];
            int v = vec[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        return DFS(adj, 0, -1, hasApple);
    }
};
