/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=icVJUN45f1E
    Company Tags                : Nil
    GfG Link                    : https://practice.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1
*/

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        unordered_map<int, vector<pair<int, int>>> adj;
        
        for(auto &vec : edges) {
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> result(n+1, INT_MAX);
        vector<int> parent(n+1);
        
        for(int i = 1; i<=n; i++) {
            parent[i] = i;
        }
        
        result[1] = 0;
		pq.push({0, 1});

		while(!pq.empty()) {

		    int d  = pq.top().first;
		    int node = pq.top().second;
		    pq.pop();

		    for(auto &it : adj[node]) {

    			int adjNode = it.first;
    			int dist    = it.second;
    
    			if(d + dist < result[adjNode]) {
    
    			    result[adjNode] = d + dist;
    			    pq.push({d+dist, adjNode});
    			    parent[adjNode] = node;
    
    			}

		    }

		}

        vector<int> path;
        int node = n;
        
        if(result[node] == INT_MAX)
            return {-1};
        
        while(parent[node] != node) {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        reverse(begin(path), end(path));
		return path;
    }
};
