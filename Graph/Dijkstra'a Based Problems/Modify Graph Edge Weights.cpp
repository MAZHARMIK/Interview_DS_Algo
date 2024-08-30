/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/modify-graph-edge-weights
*/



/************************************************************ C++ ************************************************************/
//Using Dijkstra for Shortest Path
//T.C : O(E * E * Log(V)) //E = number of edges, V = number of vertices/nodes
//S.C : O(V+E)
class Solution {
public:
    typedef long long ll;
    const int LARGE_VALUE = 2e9;
    typedef pair<long, long> P;

    ll DijkstraAlgo(vector<vector<int>>& edges, int n, int src, int dest) {
        //make the graph excluing -1 et edges
        unordered_map<ll, vector<pair<ll, ll>>> adj; //u -> (v, wt)

        for(vector<int>& edge : edges) {
            if(edge[2] != -1) {
                int u  = edge[0];
                int v  = edge[1];
                int wt = edge[2];

                adj[u].push_back({v, wt});
                adj[v].push_back({u, wt});
            }
        }

        priority_queue<P, vector<P>, greater<P>> pq;
        vector<ll> result(n, INT_MAX); //result[i] = shortest path distance of src to ith node
        vector<bool> visited(n, false);

        result[src] = 0; //src to src distance is 0
        pq.push({0, src});

        while(!pq.empty()) {
            ll currDist = pq.top().first;
            ll currNode = pq.top().second;
            pq.pop();

            if(visited[currNode] == true) {
                continue;
            }
            visited[currNode] = true;

            for(auto&[nbr, wt] : adj[currNode]) {
                if(result[nbr] > currDist + wt) {
                    result[nbr] = currDist + wt;
                    pq.push({result[nbr], nbr});
                }
            }
        }

        return result[dest];
    }

    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        ll currShortestDist = DijkstraAlgo(edges, n, source, destination);

        if(currShortestDist < target) {
            return {};
        }

        bool matchedTarget = (currShortestDist == target);

        for(vector<int>& edge : edges) {
            if(edge[2] == -1) {

                edge[2] = (matchedTarget == true) ? LARGE_VALUE : 1; //assign lowest number i.e. 1

                if(matchedTarget != true) {
                    ll newShortestDist = DijkstraAlgo(edges, n, source, destination);

                    if(newShortestDist <= target) {
                        matchedTarget = true;
                        edge[2] += (target - newShortestDist);
                    }
                }
            }
        }

        if(matchedTarget == false) {
            return {};
        }
        return edges;
    }
};




/************************************************************ JAVA ************************************************************/
//Using Dijkstra for Shortest Path
//T.C : O(E * E * Log(V)) //E = number of edges, V = number of vertices/nodes
//S.C : O(V+E)
class Solution {
    private static final int LARGE_VALUE = (int) 2e9;

    // Dijkstra's algorithm to find the shortest path
    private long dijkstraAlgo(int[][] edges, int n, int src, int dest) {
        // Create adjacency list excluding edges with -1 weight
        Map<Long, List<long[]>> adj = new HashMap<>();
        for (int[] edge : edges) {
            if (edge[2] != -1) {
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];

                adj.computeIfAbsent((long) u, k -> new ArrayList<>()).add(new long[]{v, wt});
                adj.computeIfAbsent((long) v, k -> new ArrayList<>()).add(new long[]{u, wt});
            }
        }

        // Priority queue for Dijkstra's algorithm
        PriorityQueue<long[]> pq = new PriorityQueue<>(Comparator.comparingLong(a -> a[0]));
        long[] result = new long[n];  // shortest path distance from src to each node
        boolean[] visited = new boolean[n];
        Arrays.fill(result, Long.MAX_VALUE); // Initialize distances as infinity
        result[src] = 0;  // Distance from src to src is 0
        pq.offer(new long[]{0, src}); // (distance, node)

        while (!pq.isEmpty()) {
            long[] curr = pq.poll();
            long currDist = curr[0];
            int currNode = (int) curr[1];

            if (visited[currNode]) continue;
            visited[currNode] = true;

            if (!adj.containsKey((long) currNode)) continue;

            for (long[] neighbor : adj.get((long) currNode)) {
                int nbr = (int) neighbor[0];
                long weight = neighbor[1];

                if (result[nbr] > currDist + weight) {
                    result[nbr] = currDist + weight;
                    pq.offer(new long[]{result[nbr], nbr});
                }
            }
        }

        return result[dest];
    }

    public int[][] modifiedGraphEdges(int n, int[][] edges, int source, int destination, int target) {
        long currShortestDist = dijkstraAlgo(edges, n, source, destination);

        if (currShortestDist < target) {
            return new int[0][];
        }

        boolean matchedTarget = (currShortestDist == target);

        // Iterate through each edge with -1 weight
        for (int[] edge : edges) {
            if (edge[2] == -1) {
                edge[2] = matchedTarget ? LARGE_VALUE : 1; // Assign the smallest possible value if no match

                if (!matchedTarget) {
                    long newShortestDist = dijkstraAlgo(edges, n, source, destination);

                    if (newShortestDist <= target) {
                        matchedTarget = true;
                        edge[2] += (target - newShortestDist);  // Adjust weight to match target distance
                    }
                }
            }
        }

        if (!matchedTarget) {
            return new int[0][];
        }
        return edges;
    }
}
