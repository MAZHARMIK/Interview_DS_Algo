/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=8YdqvOKViWA
    Company Tags                : Amazon, Microsoft
    Leetcode Link               : https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance
*/

//Using Dijkstra's - https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Dijkstra'a%20Based%20Problems/Find%20the%20City%20With%20the%20Smallest%20Number%20of%20Neighbors%20at%20a%20Threshold%20Distance.cpp
//Using Floyd Warshall - https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Floyd%20Warshall/Find%20the%20City%20With%20the%20Smallest%20Number%20of%20Neighbors%20at%20a%20Threshold%20Distance.cpp

/************************************************************ C++ ************************************************************/
//Approach (Using Bellman-Ford)
//T.C : O(V * (V * E)) where E is the number of edges and V = number of vertices. We call Bellman(V*E) for each vertex.
        //In worst case , max edges = V*(V-1)/2
        //O(V * V*(V-1)/2 * log V)
        //Which is approximately equal to O(V^4)
//S.C : O(V^2)
class Solution {
public:
    #define P pair<int, int>

    void bellmanFord(int n, vector<vector<int>>& edges, vector<int>& shortestPathDistances, int source) {
        fill(shortestPathDistances.begin(), shortestPathDistances.end(), INT_MAX);
        shortestPathDistances[source] = 0;

        for (int i = 1; i < n; i++) {
            for (const auto& edge : edges) {
                int u  = edge[0];
                int v  = edge[1];
                int wt = edge[2];
                if (shortestPathDistances[u] != INT_MAX &&
                    shortestPathDistances[u] + wt < shortestPathDistances[v]) {
                    shortestPathDistances[v] = shortestPathDistances[u] + wt;
                }
                //bi-directional edge
                if (shortestPathDistances[v] != INT_MAX &&
                    shortestPathDistances[v] + wt < shortestPathDistances[u]) {
                    shortestPathDistances[u] = shortestPathDistances[v] + wt;
                }
            }
        }
    }

    int getCityWithFewestReachable(int n, const vector<vector<int>>& shortestPathMatrix, int distanceThreshold) {
        int cityWithFewestReachable = -1;
        int fewestReachableCount = INT_MAX;

        for (int i = 0; i < n; i++) {
            int reachableCount = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && shortestPathMatrix[i][j] <= distanceThreshold) {
                    reachableCount++;
                }
            }

            if (reachableCount <= fewestReachableCount) {
                fewestReachableCount = reachableCount;
                cityWithFewestReachable = i;
            }
        }
        return cityWithFewestReachable;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> shortestPathMatrix(n, vector<int>(n, INT_MAX));

        for (int i = 0; i < n; i++) {
            shortestPathMatrix[i][i] = 0;  // Distance to itself is zero
        }

        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            shortestPathMatrix[u][v] = wt;
            shortestPathMatrix[v][u] = wt;
        }

        // Compute shortest paths from each city using Dijkstra's algorithm
        for (int i = 0; i < n; i++) {
            bellmanFord(n, edges, shortestPathMatrix[i], i);
        }

        return getCityWithFewestReachable(n, shortestPathMatrix, distanceThreshold);
    }
};


/************************************************************ JAVA ************************************************************/
//Approach (Using Bellman-Ford)
//T.C : O(V * (V * E)) where E is the number of edges and V = number of vertices. We call Bellman(V*E) for each vertex.
        //In worst case , max edges = V*(V-1)/2
        //O(V * V*(V-1)/2 * log V)
        //Which is approximately equal to O(V^4)
//S.C : O(V^2)
import java.util.*;

class Solution {

    // Bellman-Ford algorithm to find shortest paths from a source city
    void bellmanFord(int n, int[][] edges, int[] shortestPathDistances, int source) {
        Arrays.fill(shortestPathDistances, Integer.MAX_VALUE);
        shortestPathDistances[source] = 0;

        for (int i = 1; i < n; i++) {
            for (int[] edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];
                if (shortestPathDistances[u] != Integer.MAX_VALUE && 
                    shortestPathDistances[u] + wt < shortestPathDistances[v]) {
                    shortestPathDistances[v] = shortestPathDistances[u] + wt;
                }
                // Bi-directional edge
                if (shortestPathDistances[v] != Integer.MAX_VALUE && 
                    shortestPathDistances[v] + wt < shortestPathDistances[u]) {
                    shortestPathDistances[u] = shortestPathDistances[v] + wt;
                }
            }
        }
    }

    int getCityWithFewestReachable(int n, int[][] shortestPathMatrix, int distanceThreshold) {
        int cityWithFewestReachable = -1;
        int fewestReachableCount = Integer.MAX_VALUE;

        for (int i = 0; i < n; i++) {
            int reachableCount = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && shortestPathMatrix[i][j] <= distanceThreshold) {
                    reachableCount++;
                }
            }

            if (reachableCount <= fewestReachableCount) {
                fewestReachableCount = reachableCount;
                cityWithFewestReachable = i;
            }
        }
        return cityWithFewestReachable;
    }

    public int findTheCity(int n, int[][] edges, int distanceThreshold) {
        int[][] shortestPathMatrix = new int[n][n];

        for (int i = 0; i < n; i++) {
            Arrays.fill(shortestPathMatrix[i], Integer.MAX_VALUE);
            shortestPathMatrix[i][i] = 0;  // Distance to itself is zero
        }

        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            shortestPathMatrix[u][v] = wt;
            shortestPathMatrix[v][u] = wt;
        }

        // Compute shortest paths from each city using Bellman-Ford algorithm
        for (int i = 0; i < n; i++) {
            bellmanFord(n, edges, shortestPathMatrix[i], i);
        }

        return getCityWithFewestReachable(n, shortestPathMatrix, distanceThreshold);
    }
}
