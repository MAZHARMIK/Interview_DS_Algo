/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Not sure if anyone will ask this :-)
    GfG Link                    : https://www.geeksforgeeks.org/problems/vertex-cover/1
*/

//Study about Gosper's Hack - http://programmingforinsomniacs.blogspot.com/2018/03/gospers-hack-explained.html

/************************************************************************** C++ **************************************************************************/
//T.C : O(log N * 2^N * N^2),
//S.C : O(N*N)
class Solution{
    public:
    
        int totalEdges = 0;
        bool isValidCover(int &k, int &n, vector<vector<int>> &adj) {
            
            
            int set = (1 << k) - 1;
            int limit = (1 << n);
            bool visited[n+1][n+1];
            
            while (set < limit) {
                
                memset(visited, 0, sizeof(visited));
                
                /************ Main Logic Starts************/
                int count = 0;
                for(int j = 1, u = 1; u < n+1; j = j << 1, u++) {
                    if(set & j) {
                        for(int v = 1; v < n+1; v++) {
                            
                            if(adj[u][v] == 1 && !visited[u][v]) {
                                visited[u][v] = true;
                                visited[v][u] = true;
                                count++;
                            }
                            
                        }
                    }
                }
                
                if(count == totalEdges) {
                    return true;
                }
                /************ Main Logic Ends************/
                
                
                int c = set & - set;
                int r = set + c;
                set = (((r ^ set) >> 2) / c) | r;
            }
            
            
            return false;
            
        }
    
        int vertexCover(int n, vector<pair<int, int>> &edges) {
            totalEdges = edges.size();
            
            vector<vector<int>> adj(n+1, vector<int>(n+1, 0));
            
            for(auto &it : edges) {
                int u = it.first;
                int v = it.second;
                
                adj[u][v] = 1;
                adj[v][u] = 1;
            }
            
            int low = 1, high = n; // binary search
            int result = n;
            while (low <= high) {
                int mid = (low + high) >> 1;
                if (isValidCover(mid, n, adj)) {
                    result = mid;
                    high = mid-1;
                } else {
                    low = mid + 1;
                }
            }
            return result;
        }
};


/************************************************************************** JAVA **************************************************************************/
//T.C : O(log N * 2^N * N^2),
//S.C : O(N*N)
class Solution {
    private static boolean isValidCover(int n, int k, int m, ArrayList<ArrayList<Integer>> adj) {
        int set = (1 << k) - 1;
        int limit = (1 << n);
        ArrayList<ArrayList<Boolean>> visited = new ArrayList<>(n + 1);

        for (int i = 0; i < n + 1; i++) {
            visited.add(new ArrayList<>(n + 1));
            for (int j = 0; j < n + 1; j++) {
                visited.get(i).add(false);
            }
        }

        while (set < limit) {
            for (int i = 0; i < n + 1; i++) {
                for (int j = 0; j < n + 1; j++) {
                    visited.get(i).set(j, false);
                }
            }

            int count = 0;
            for (int j = 1, v = 1; j < limit; j = j << 1, v++) {
                if ((set & j) != 0) {
                    for (int l = 1; l <= n; l++) {
                        if (adj.get(v).get(l) == 1 && !visited.get(v).get(l)) {
                            visited.get(v).set(l, true);
                            visited.get(l).set(v, true);
                            count++;
                        }
                    }
                }
            }

            if (count == m) {
                return true;
            }

            int c = set & -set;
            int r = set + c;
            set = (((r ^ set) >> 2) / c) | r;
        }

        return false;
    }

    public static int vertexCover(int n, int m, int[][] edges) {
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>(n + 1);

        for (int i = 0; i < n + 1; i++) {
            adj.add(new ArrayList<>(n + 1));
            for (int j = 0; j < n + 1; j++) {
                adj.get(i).add(0);
            }
        }

        for (int i = 0; i < m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj.get(u).set(v, 1);
            adj.get(v).set(u, 1);
        }

        int low = 1, high = n;
        int result = n;
        while (low <= high) {
            int mid = (low + high) >> 1;

            if (isValidCover(n, mid, m, adj)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid+1;
            }
        }

        return result;

    }
}
