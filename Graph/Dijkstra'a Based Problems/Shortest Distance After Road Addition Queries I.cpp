/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=INUZt6li__c
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/shortest-distance-after-road-addition-queries-i
*/


/************************************************************ C++ ************************************************/
//Approach-1 (Using Dijkstra's Algorothm - Assuming each edge weight is 1)
//T.C : O(q * (V+E)) , V = number of vertices and E = number of edges
//S.C : O(V+E)
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


//Approach-2 (Using BFS (edges are unweighted)
//T.C : O(q * (E log(V)) , V = number of vertices and E = number of edges
//S.C : O(V+E)
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



/************************************************************ JAVA ************************************************/
//Approach-1 - Using Dijkstra's Algorothm - Assuming each edge weight is 1
//T.C : O(q * (V+E)) , V = number of vertices and E = number of edges
//S.C : O(V+E)
class Solution {
    private Map<Integer, List<int[]>> adj = new HashMap<>();

    private int dijkstra(int n) {
        int[] result = new int[n];
        Arrays.fill(result, Integer.MAX_VALUE);
        result[0] = 0;

        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        pq.offer(new int[]{0, 0}); // {distance, node}

        while (!pq.isEmpty()) {
            int[] top = pq.poll();
            int d = top[0];
            int node = top[1];

            if (node == n - 1) {
                return result[n - 1];
            }

            if (d > result[node]) {
                continue;
            }

            if (!adj.containsKey(node)) {
                continue;
            }

            for (int[] edge : adj.get(node)) {
                int adjNode = edge[0];
                int dist = edge[1];
                if (d + dist < result[adjNode]) {
                    result[adjNode] = d + dist;
                    pq.offer(new int[]{d + dist, adjNode});
                }
            }
        }

        return result[n - 1];
    }

    public int[] shortestDistanceAfterQueries(int n, int[][] queries) {
        // Initialize the adjacency list with the default edges
        for (int i = 0; i < n - 1; ++i) {
            adj.computeIfAbsent(i, k -> new ArrayList<>()).add(new int[]{i + 1, 1});
        }

        int[] result = new int[queries.length];

        // Process each query
        for (int i = 0; i < queries.length; i++) {
            int u = queries[i][0];
            int v = queries[i][1];

            adj.computeIfAbsent(u, k -> new ArrayList<>()).add(new int[]{v, 1});
            result[i] = dijkstra(n);
        }

        return result;
    }
}


//Approach-2 (Using BFS (edges are unweighted)
//T.C : O(q * (E log(V)) , V = number of vertices and E = number of edges
//S.C : O(V+E)
class Solution {
    private Map<Integer, List<Integer>> adj = new HashMap<>();

    private int bfs(int n) {
        Queue<Integer> queue = new LinkedList<>();
        boolean[] visited = new boolean[n];
        queue.offer(0);
        visited[0] = true;

        int level = 0;
        while (!queue.isEmpty()) {
            int size = queue.size();
            while (size-- > 0) {
                int node = queue.poll();

                if (node == n - 1) {
                    return level; // Found the destination node
                }

                for (int neighbor : adj.getOrDefault(node, new ArrayList<>())) {
                    if (!visited[neighbor]) {
                        queue.offer(neighbor);
                        visited[neighbor] = true;
                    }
                }
            }
            level++;
        }
        return -1; // If destination node is unreachable
    }

    public int[] shortestDistanceAfterQueries(int n, int[][] queries) {
        adj.clear();

        // Initialize adjacency list with direct edges (i -> i + 1)
        for (int i = 0; i < n - 1; i++) {
            adj.computeIfAbsent(i, k -> new ArrayList<>()).add(i + 1);
        }

        int k = queries.length;
        int[] res = new int[k];
        for (int i = 0; i < k; i++) {
            int u = queries[i][0];
            int v = queries[i][1];
            adj.computeIfAbsent(u, k1 -> new ArrayList<>()).add(v);
            res[i] = bfs(n);
        }

        return res;
    }
}
