/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=8YdqvOKViWA
    Company Tags                : Amazon, Microsoft
    Leetcode Link               : https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance
*/

//Using Dijkstra's - https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Dijkstra'a%20Based%20Problems/Find%20the%20City%20With%20the%20Smallest%20Number%20of%20Neighbors%20at%20a%20Threshold%20Distance.cpp
//Using Bellman Ford - https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Bellman-Ford%20Based%20Problems/Find%20the%20City%20With%20the%20Smallest%20Number%20of%20Neighbors%20at%20a%20Threshold%20Distance.cpp


/************************************************************ C++ ************************************************************/
//Approach (Using Dijkstra's)
//T.C : O(V^3)
//S.C : O(V^2)
class Solution {
public:
    #define P pair<int, int>
    void floydWarshall(int n, vector<vector<int>>& shortestPathMatrix) {
        
        for(int via = 0; via < n; via++) {
            
            for(int i = 0; i<n; i++) {
                for(int j = 0; j<n; j++) {
                    
                   shortestPathMatrix[i][j] = min(shortestPathMatrix[i][j],
                                                  shortestPathMatrix[i][via] + shortestPathMatrix[via][j]);
                    
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
        vector<vector<int>> shortestPathMatrix(n, vector<int>(n, 1e9+7));

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

        floydWarshall(n, shortestPathMatrix);

        return getCityWithFewestReachable(n, shortestPathMatrix, distanceThreshold);
    }
};



/************************************************************ JAVA ************************************************************/
//Approach (Using Dijkstra's)
//T.C : O(V^3)
//S.C : O(V^2)
class Solution {

    // Floyd-Warshall algorithm to find shortest paths between all pairs of cities
    void floydWarshall(int n, int[][] shortestPathMatrix) {
        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    shortestPathMatrix[i][j] = Math.min(shortestPathMatrix[i][j],
                                                        shortestPathMatrix[i][via] + shortestPathMatrix[via][j]);
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

        // Initialize the shortest path matrix with large values
        for (int i = 0; i < n; i++) {
            Arrays.fill(shortestPathMatrix[i], (int) 1e9 + 7);
            shortestPathMatrix[i][i] = 0;  // Distance to itself is zero
        }

        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            shortestPathMatrix[u][v] = wt;
            shortestPathMatrix[v][u] = wt;
        }

        // Compute shortest paths using Floyd-Warshall algorithm
        floydWarshall(n, shortestPathMatrix);

        return getCityWithFewestReachable(n, shortestPathMatrix, distanceThreshold);
    }
}
