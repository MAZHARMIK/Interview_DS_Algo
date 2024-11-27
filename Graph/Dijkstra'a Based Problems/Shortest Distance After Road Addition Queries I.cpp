/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/shortest-distance-after-road-addition-queries-i
*/


/************************************************************ C++ ************************************************/
//Approach - Using Dijkstra's Algorothm - Assuming each edge weight is 1
//T.C : 
//S.C : 
class Solution {
public:
    #define P pair<int, int>
    unordered_map<int, vector<P>> adj;

    int dijkstra(int n) {
        vector<int> result(n, INT_MAX);
        result[0] = 0;
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            int d    = pq.top().first;    // Distance of current node
            int node = pq.top().second; // Current node
            pq.pop();
            
            if (node == n - 1)
                return result[n - 1];
            
            if (d > result[node])
                continue;

            for (P &p : adj[node]) {
                int adjNode = p.first;
                int dist    = p.second;
                if (d + dist < result[adjNode]) {
                    result[adjNode] = d + dist;
                    pq.push({d + dist, adjNode});
                }
            }
        }
        return result[n - 1];
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        adj.clear();
        vector<int> result;

        for (int i = 0; i < n - 1; ++i) {
            adj[i].push_back({i + 1, 1});
        }

        for (auto query : queries) {
            int u = query[0];
            int v = query[1];
            adj[u].push_back({v, 1});
            int d = dijkstra(n);
            result.push_back(d);
        }

        return result;
    }
};


//Approach - Using BFS (edges are unweighted)
//T.C : 
//S.C : 
class Solution {
public:
    unordered_map<int, vector<int>> adj;

    int bfs(int n) {
        queue<int> que;
        que.push(0);
        vector<bool> visited(n, false);
        visited[0] = true;

        int level = 0;
        while (!que.empty()) {
            int size = que.size();
            while (size--) {
                int node = que.front();
                que.pop();

                if (node == n - 1) {
                    return level; // Found the destination node
                }

                for (int neighbor : adj[node]) {
                    if (!visited[neighbor]) {
                        que.push(neighbor);
                        visited[neighbor] = true;
                    }
                }
            }
            level++;
        }
        return -1; // If destination node is unreachable
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        adj.clear();

        for (int i = 0; i < n - 1; i++) {
            adj[i].push_back(i + 1);
        }

        int k = queries.size();
        vector<int> res(k);
        for (int i = 0; i < k; i++) {
            adj[queries[i][0]].push_back(queries[i][1]);
            res[i] = bfs(n);
        }
        return res;
    }
};
