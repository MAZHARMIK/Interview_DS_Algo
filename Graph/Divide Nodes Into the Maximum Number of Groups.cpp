/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Iku-NBN2jRE
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/divide-nodes-into-the-maximum-number-of-groups
*/


/************************************************************ C++ ************************************************/
//Approach - Using Bipartite, DFS and BFS
//T.C : O(V * (V+E))
//S.C : O(V+E)
class Solution {
public:
    //1 : Red
    //0 : Green
    bool isBipartite(unordered_map<int, vector<int>> &adj, int curr, vector<int>& colors, int currColor) {
        colors[curr] = currColor;

        for(int &ngbr : adj[curr]) {
            if(colors[ngbr] == colors[curr]) {
                return false;
            }

            if(colors[ngbr] == -1) {
                if(isBipartite(adj, ngbr, colors, 1 - currColor) == false) {
                    return false;
                }
            }
        }

        return true;
    }

    int bfs(unordered_map<int, vector<int>> &adj, int currNode, int n) {
        queue<int> que;
        vector<bool> visited(n, false);
        que.push(currNode);
        visited[currNode] = true;

        int level = 1; //max groups in that components
        while(!que.empty()) {

            int size = que.size();
            while(size--) {
                int curr = que.front();
                que.pop();

                for(int &ngbr : adj[curr]) {
                    if(visited[ngbr])
                        continue;
                    
                    que.push(ngbr);
                    visited[ngbr] = true;
                }
            }
            level++; //1 extra will be incremeented in the last loop
        }

        return level-1;
    }

    int getMaxFromEachComp(unordered_map<int, vector<int>> &adj, int curr, vector<bool>& visited, vector<int>& levels) {
        int maxGrp = levels[curr];
        visited[curr] = true;

        for(int &ngbr : adj[curr]) {
            if(!visited[ngbr]) {
                maxGrp = max(maxGrp, getMaxFromEachComp(adj, ngbr, visited, levels));
            }
        }

        return maxGrp;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj; //O(V+E) space

        for(auto& edge : edges) {
            int u = edge[0] - 1; //converting to 0-based idnex
            int v = edge[1] - 1;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        //Bipartite check
        vector<int> colors(n, -1); //O(V)
        //O(V*(V+E))
        for(int node = 0; node < n; node++) { //O(n)
            if(colors[node] == -1) {
                if(isBipartite(adj, node, colors, 1) == false) { //O(V+E)
                    return -1;
                }
            }
        }

        //BFS karke max levels nikalo for each node
        vector<int> levels(n, 0);
        //T.C :O(V * (V+E))
        for(int node = 0; node < n; node++) { //O(V)
            levels[node] = bfs(adj, node, n); //O(V+E)
        }


        int maxGroupEachComp = 0;
        vector<bool> visited(n, false);
        for(int node = 0; node < n; node++) { //O(V * (V+E))
            if(!visited[node]) {
                maxGroupEachComp += getMaxFromEachComp(adj, node, visited, levels);
            }
        }

        return maxGroupEachComp;
    }
};



/************************************************************ JAVA ************************************************/
//Approach - Using Bipartite, DFS and BFS
//T.C : O(V * (V+E))
//S.C : O(V+E)
class Solution {
    // Helper function to check if the graph is bipartite
    public boolean isBipartite(Map<Integer, List<Integer>> adj, int curr, int[] colors, int currColor) {
        colors[curr] = currColor;
        
        for (int ngbr : adj.get(curr)) {
            if (colors[ngbr] == colors[curr]) {
                return false;
            }
            
            if (colors[ngbr] == -1) {
                if (!isBipartite(adj, ngbr, colors, 1 - currColor)) {
                    return false;
                }
            }
        }
        
        return true;
    }

    // BFS function to get the maximum level
    public int bfs(Map<Integer, List<Integer>> adj, int currNode, int n) {
        Queue<Integer> que = new LinkedList<>();
        boolean[] visited = new boolean[n];
        que.add(currNode);
        visited[currNode] = true;

        int level = 1;
        while (!que.isEmpty()) {
            int size = que.size();
            while (size-- > 0) {
                int curr = que.poll();
                
                for (int ngbr : adj.get(curr)) {
                    if (visited[ngbr]) continue;
                    
                    que.add(ngbr);
                    visited[ngbr] = true;
                }
            }
            level++;
        }

        return level - 1;
    }

    // Helper function to get the maximum group size from each connected component
    public int getMaxFromEachComp(Map<Integer, List<Integer>> adj, int curr, boolean[] visited, int[] levels) {
        int maxGrp = levels[curr];
        visited[curr] = true;

        for (int ngbr : adj.get(curr)) {
            if (!visited[ngbr]) {
                maxGrp = Math.max(maxGrp, getMaxFromEachComp(adj, ngbr, visited, levels));
            }
        }

        return maxGrp;
    }

    // Main function to calculate the result
    public int magnificentSets(int n, int[][] edges) {
        Map<Integer, List<Integer>> adj = new HashMap<>();
        
        for (int[] edge : edges) {
            int u = edge[0] - 1;
            int v = edge[1] - 1;
            
            adj.computeIfAbsent(u, k -> new ArrayList<>()).add(v);
            adj.computeIfAbsent(v, k -> new ArrayList<>()).add(u);
        }

        // Bipartite check
        int[] colors = new int[n];
        Arrays.fill(colors, -1);

        for (int node = 0; node < n; node++) {
            if (colors[node] == -1) {
                if (!isBipartite(adj, node, colors, 1)) {
                    return -1;
                }
            }
        }

        // BFS to find max levels for each node
        int[] levels = new int[n];
        for (int node = 0; node < n; node++) {
            levels[node] = bfs(adj, node, n);
        }

        // Sum the max group sizes for each component
        int maxGroupEachComp = 0;
        boolean[] visited = new boolean[n];
        for (int node = 0; node < n; node++) {
            if (!visited[node]) {
                maxGroupEachComp += getMaxFromEachComp(adj, node, visited, levels);
            }
        }

        return maxGroupEachComp;
    }
}
