/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=EPvZsimuqwM
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/design-graph-with-shortest-path-calculator
*/

/******************************************************** C++ ********************************************************/
//Approach-1 (Using Floyd Warshal Algorithm)
//T.C : O(N^3) - Making adj Matrix
class Graph {
public:
    vector<vector<int>> adj;
    int N;
    Graph(int n, vector<vector<int>>& edges) {
        N = n;
        adj = vector<vector<int>>(n, vector<int>(n, 1e9));
        
        for(auto &vec : edges) {
            int u    = vec[0];
            int v    = vec[1];
            int cost = vec[2];
            
            adj[u][v] = cost;
        }
        
        for(int i = 0; i<n; i++) {
            adj[i][i] = 0;
        }
        
        //Floyd Warshal
        for(int k = 0; k<n; k++) {
            
            for(int i = 0; i<N; i++) {
                for(int j = 0; j<N; j++) {
                    
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                        
                }
            }
            
        }
    }
    
    void addEdge(vector<int> edge) {
        int u    = edge[0];
        int v    = edge[1];
        int cost = edge[2];
        //check with 2 new vertices - u and v
        
        for(int i = 0; i<N; i++) {
            for(int j = 0; j<N; j++) {

                adj[i][j] = min(adj[i][j], adj[i][u] + cost + adj[v][j]);

            }
        }
    }
    
    int shortestPath(int node1, int node2) {
        return adj[node1][node2] == 1e9 ? -1 : adj[node1][node2];
    }
};


//Approach-2 (Using Dijkstra's Algorithm)
//Code - https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Dijkstra'a%20Based%20Problems/Design%20Graph%20With%20Shortest%20Path%20Calculator.cpp


/******************************************************** JAVA ********************************************************/
//Approach-1 (Using Floyd Warshal Algorithm)
//T.C : O(N^3) - Making adj Matrix
class Graph {
    int[][] adj;
    int N;

    public Graph(int n, int[][] edges) {
        N = n;
        adj = new int[n][n];
        
        for (int i = 0; i < n; i++) {
            Arrays.fill(adj[i], (int)1e9);
            adj[i][i] = 0;
        }

        for (int[] vec : edges) {
            int u = vec[0];
            int v = vec[1];
            int cost = vec[2];

            adj[u][v] = cost;
        }

        // Floyd Warshall
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    adj[i][j] = Math.min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
    }

    public void addEdge(int[] edge) {
        int u = edge[0];
        int v = edge[1];
        int cost = edge[2];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                adj[i][j] = Math.min(adj[i][j], adj[i][u] + cost + adj[v][j]);
            }
        }
    }

    public int shortestPath(int node1, int node2) {
        return adj[node1][node2] == (int)1e9 ? -1 : adj[node1][node2];
    }
}



//Approach-2 (Using Dijkstra's Algorithm)
//Code - https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Dijkstra'a%20Based%20Problems/Design%20Graph%20With%20Shortest%20Path%20Calculator.cpp
