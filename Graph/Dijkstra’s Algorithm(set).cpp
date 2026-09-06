/*			SCROLL BELOW TO SEE THE JAVA CODE AS WELL			*/
/*
	MY YOUTUBE VIDEO ON THIS Qn   : https://www.youtube.com/watch?v=3qIoYIMidpc
	Company Tags		      	  : Flipkart, Microsoft
	GfG Link		      		  : https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
*/


/************************************************** C++ ********************************************************/
//Time : O(E * log(V))
//E = number of edges
//V = number of vertices
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
	//from the source vertex S.
	vector <int> dijkstra(int V, vector<vector<int>> adj[], int S) {
	    set<pair<int, int>> pq;

            vector<int> result(V, INT_MAX);

            result[S] = 0;
            pq.insert({0, S});

            while(!pq.empty()) {

                auto &it = *pq.begin();
                int d  = it.first;
                int node = it.second;
                pq.erase(it);

                for(auto &vec : adj[node]) {

                    int adjNode = vec[0];
                    int dist    = vec[1];

                    if(d + dist < result[adjNode]) {
                        
                        if(result[adjNode] != INT_MAX) {
                            auto iter = pq.find({result[adjNode], adjNode});
                            pq.erase(iter);
			    //OR, pq.erase({result[adjNode], adjNode});
                        }
                        
                        result[adjNode] = d + dist;
                        pq.insert({d+dist, adjNode});

                    }

                }

            }

            return result;
	}
};




/************************************************** JAVA ********************************************************/
//Time : O(E * log(V))
//E = number of edges
//V = number of vertices
import java.util.*;

class Solution {
    public ArrayList<Integer> dijkstra(int V, int[][] edges, int src) {
        // Build adjacency list from the edge list.
        // Each edge is [u, v, w]; graph is treated as undirected.
        List<int[]>[] adj = new ArrayList[V];
        for (int i = 0; i < V; i++) adj[i] = new ArrayList<>();
        for (int[] e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].add(new int[]{v, w});
            adj[v].add(new int[]{u, w});
        }

        int[] result = new int[V];
        Arrays.fill(result, Integer.MAX_VALUE);
        result[src] = 0;

        // TreeSet used as an indexed priority queue: {distance, node}.
        // Ordered by distance, then node to keep entries unique.
        TreeSet<int[]> pq = new TreeSet<>((a, b) ->
            a[0] != b[0] ? Integer.compare(a[0], b[0])
                         : Integer.compare(a[1], b[1]));
        pq.add(new int[]{0, src});

        while (!pq.isEmpty()) {
            int[] it = pq.pollFirst();   // remove smallest, like *pq.begin() + erase
            int d = it[0];
            int node = it[1];

            for (int[] vec : adj[node]) {
                int adjNode = vec[0];
                int dist = vec[1];
                if (d + dist < result[adjNode]) {
                    // Remove the stale entry if one exists (mirrors the C++ erase).
                    if (result[adjNode] != Integer.MAX_VALUE) {
                        pq.remove(new int[]{result[adjNode], adjNode});
                    }
                    result[adjNode] = d + dist;
                    pq.add(new int[]{d + dist, adjNode});
                }
            }
        }

        ArrayList<Integer> ans = new ArrayList<>(V);
        for (int r : result) ans.add(r);
        return ans;
    }
}
