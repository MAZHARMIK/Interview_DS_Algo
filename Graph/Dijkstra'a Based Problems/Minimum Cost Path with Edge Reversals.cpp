/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/minimum-cost-path-with-edge-reversals/
*/


/************************************************************ C++ ************************************************/
//Approach (Using Dijkstra's Algorithm)
//T.C : O(E * log(V)), E = number of edges, V = number of vertices
//S.C : O(V+E) for adjacency list
class Solution {
public:
    typedef pair<int, int> P;

    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<P>> adj;

        for(auto &edge : edges) {
            int u  = edge[0];
            int v  = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, 2*wt}); //reversed edge
        }

        vector<int> result(n, INT_MAX);
        result[0] = 0;
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, 0}); //distance = 0, sourceNode = 0

        while(!pq.empty()) {
            int d    = pq.top().first;
		    int node = pq.top().second;
		    pq.pop();
            if(node == n-1)
                return result[node];

		    for(auto &p : adj[node]) {

                int adjNode = p.first;
                int dist    = p.second;

                if(d + dist < result[adjNode]) {
                    result[adjNode] = d + dist;
                    pq.push({d+dist, adjNode});
                }
		    }
        }

        return -1;
    }
};




/************************************************************ JAVA ************************************************/
//Approach (Using Dijkstra's Algorithm)
//T.C : O(E * log(V)), E = number of edges, V = number of vertices
//S.C : O(V+E) for adjacency list
import java.util.*;

class Solution {

    static class Pair {
        int node;
        int dist;

        Pair(int node, int dist) {
            this.node = node;
            this.dist = dist;
        }
    }

    public int minCost(int n, int[][] edges) {

        // Adjacency list: node -> {neighbor, weight}
        Map<Integer, List<Pair>> adj = new HashMap<>();

        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj.computeIfAbsent(u, k -> new ArrayList<>()).add(new Pair(v, wt));
            adj.computeIfAbsent(v, k -> new ArrayList<>()).add(new Pair(u, 2 * wt)); // reversed edge
        }

        int[] dist = new int[n];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[0] = 0;

        // Min-heap based on distance
        PriorityQueue<Pair> pq = new PriorityQueue<>((a, b) -> a.dist - b.dist);
        pq.offer(new Pair(0, 0)); // node, distance

        while (!pq.isEmpty()) {
            Pair cur = pq.poll();
            int node = cur.node;
            int d = cur.dist;

            // Skip stale entries
            if (d > dist[node]) continue;

            if (node == n - 1) return d;

            if (!adj.containsKey(node)) continue;

            for (Pair nei : adj.get(node)) {
                int nextNode = nei.node;
                int weight = nei.dist;

                if (d + weight < dist[nextNode]) {
                    dist[nextNode] = d + weight;
                    pq.offer(new Pair(nextNode, dist[nextNode]));
                }
            }
        }

        return -1;
    }
}
