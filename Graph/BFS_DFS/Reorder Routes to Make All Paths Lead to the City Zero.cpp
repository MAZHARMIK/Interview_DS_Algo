/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=42Z0eaopoZ8
      Company Tags                : META
      Leetcode Link               : https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/
*/

//DFS - Using Visited Array
class Solution {
public:
    int count = 0;
    void dfs(int node, int parent, vector<vector<pair<int, int>>>& adj, vector<bool>& visited) {
        visited[node] = true;
        
        for (auto& [child, sign] : adj[node]) {
            if (!visited[child]) {
                count += sign;
                dfs(child, node, adj, visited);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& connection : connections) {
            adj[connection[0]].push_back({connection[1], 1});
            adj[connection[1]].push_back({connection[0], 0});
        }
        vector<bool> visited(n, false);
        dfs(0, -1, adj, visited);
        return count;
    }
};

//DFS - Without using Visited Array because there will be no cycle and hence this is undirected graph
class Solution {
public:
    int count = 0;
    void dfs(int node, int parent, vector<vector<pair<int, int>>>& adj) {

        for (auto& [child, sign] : adj[node]) {
            if (child != parent) {
                count += sign;
                dfs(child, node, adj);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& connection : connections) {
            adj[connection[0]].push_back({connection[1], 1});
            adj[connection[1]].push_back({connection[0], 0});
        }
 
        dfs(0, -1, adj);
        return count;
    }
};



//BFS - Soon
