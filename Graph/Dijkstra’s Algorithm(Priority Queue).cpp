/*     Scroll below to see JAVA code also    */
/*
	MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=xQ3vjWwFRuI
	Company Tags		    	: Flipkart, Microsoft
	GfG Link		    		: https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
*/


/************************************************************ C++ ************************************************/
//Time : O(E * log(V))
//E = number of edges
//V = number of vertices
class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> result(V, INT_MAX);

        result[S] = 0;
        pq.push({0, S});
        // NOTE - You can add a visited vector to avoid revisiting a node again and again.
        // It will reduce the time complexity.

        while (!pq.empty())
        {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto &vec : adj[node])
            {
                int adjNode = vec[0];
                int dist = vec[1];

                if (d + dist < result[adjNode])
                {
                    result[adjNode] = d + dist;
                    pq.push({d + dist, adjNode});
                }
            }
        }

        return result;
    }
};



/************************************************************ JAVA ************************************************/
//Time : O(E * log(V))
//E = number of edges
//V = number of vertices
class Solution {
    public ArrayList<Integer> dijkstra(ArrayList<ArrayList<ArrayList<Integer>>> adj,
                                       int src) {
        int V = adj.size();

        int[] dist = new int[V];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[src] = 0;

        // Min-heap ordered by distance: {distance, node}
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        pq.add(new int[]{0, src});

        while (!pq.isEmpty()) {
            int[] curr = pq.poll();
            int d = curr[0];
            int node = curr[1];

            // Skip stale entries
            if (d > dist[node]) {
                continue;
            }

            for (ArrayList<Integer> edge : adj.get(node)) {
                int adjNode = edge.get(0);
                int weight = edge.get(1);

                if (d + weight < dist[adjNode]) {
                    dist[adjNode] = d + weight;
                    pq.add(new int[]{dist[adjNode], adjNode});
                }
            }
        }

        ArrayList<Integer> result = new ArrayList<>();
        for (int x : dist) {
            result.add(x);
        }
        return result;
    }
}
