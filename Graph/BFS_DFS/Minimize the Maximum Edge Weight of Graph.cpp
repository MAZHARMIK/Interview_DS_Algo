/*                       Scroll down to see JAVA code also             */
/*
    MY YOUTUBE VIDEO ON THIS Qn  : 
    Company Tags                 : will update
    Leetcode Link                : https://leetcode.com/problems/minimize-the-maximum-edge-weight-of-graph/
*/



/********************************************************************** C++ **********************************************************************/
//Approach-1 (Using BFS)
//T.C : O(log(maxWt) * (V+E))
//S.C : O(V+E)
class Solution {
public:
    typedef pair<int, int> P;

    bool canAllReachZero(int n, unordered_map<int, vector<P>>& adj, int mid) {
        //BFS
        queue<int> que;
        vector<bool> visited(n, false);

        que.push(0);
        visited[0] = true;

        while(!que.empty()) {
            int u = que.front();
            que.pop();

            for(P &p : adj[u]) {
                int v = p.first; //ngbr node
                int w = p.second;  //edge weight

                if(w <= mid && !visited[v]) {
                    visited[v] = true;
                    que.push(v);
                }
            }
        }

        for(int i = 0; i < n; i++) {
            if(visited[i] == false) { //this ith node was not visited
                return false; //we could not visit all the nodes
            }
        }

        return true;
    }

    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        unordered_map<int, vector<P>> adj;
        // u -> {(v1, w1), (v2,w2),... }

        int maxWt = 0;
        //Form the adj with reversed edge
        for(vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[v].push_back({u, w}); //with reversed edge
            maxWt = max(maxWt, w);
        }

        //apply binary search on answer (weight)
        int result = INT_MAX; //invalid answer

        int l = 0;
        int r = maxWt;

        while(l <= r) {
            int mid = l + (r-l)/2;

            if(canAllReachZero(n, adj, mid) == true) {
                result = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }

        return result == INT_MAX ? -1 : result;

    }
};


//Approach-2 (Using DFS)
//T.C : O(log(maxWt) * (V+E))
//S.C : O(V+E)
class Solution {
public:
    
    typedef pair<int, int> P;

    void dfs(int u, unordered_map<int, vector<P>>& adj, int mid, vector<bool>& visited) {
        visited[u] = true;

        //visit all ngbrs of u if possible
        for(auto &p : adj[u]) {
            int v = p.first;
            int w = p.second;

            if(w <= mid && !visited[v]) {
                visited[v] = true;
                dfs(v, adj, mid, visited);
            }
        }
    }

    bool canAllReachZero(int n, unordered_map<int, vector<P>>& adj, int mid) {
        //DFS
        vector<bool> visited(n, false);
        dfs(0, adj, mid, visited);

        for(int i = 0; i < n; i++) {
            if(visited[i] == false) {
                return false;
            }
        }

        return true;
    }

    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        unordered_map<int, vector<P>> adj;
        // u -> {(v1, w1), (v2,w2),... }

        int maxWt = 0;
        //Form the adj with reversed edge
        for(vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[v].push_back({u, w}); //with reversed edge
            maxWt = max(maxWt, w);
        }

        //apply binary search on answer (weight)
        int result = INT_MAX; //invalid answer

        int l = 0;
        int r = maxWt;
        
        //T.C : O(log(maxWt) * (V+E))
        //S.C : O(V+E)
        while(l <= r) {
            int mid = l + (r-l)/2;

            if(canAllReachZero(n, adj, mid) == true) { //O(V+E) due to BFS or DFS
                result = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }

        return result == INT_MAX ? -1 : result;

    }
};



/********************************************************************** JAVA **********************************************************************/
// Approach-1 (Using BFS)
// T.C : O(log(maxWt) * (V+E))
// S.C : O(V+E)
class Solution {
    private static class Pair {
        int node, weight;

        Pair(int node, int weight) {
            this.node = node;
            this.weight = weight;
        }
    }

    private boolean canAllReachZero(int n, Map<Integer, List<Pair>> adj, int mid) {
        // BFS
        Queue<Integer> queue = new LinkedList<>();
        boolean[] visited = new boolean[n];

        queue.add(0);
        visited[0] = true;

        while (!queue.isEmpty()) {
            int u = queue.poll();

            for (Pair p : adj.getOrDefault(u, new ArrayList<>())) {
                int v = p.node; // neighbor node
                int w = p.weight; // edge weight

                if (w <= mid && !visited[v]) {
                    visited[v] = true;
                    queue.add(v);
                }
            }
        }

        for (boolean isVisited : visited) {
            if (!isVisited) { // this node was not visited
                return false; // we could not visit all the nodes
            }
        }

        return true;
    }

    public int minMaxWeight(int n, int[][] edges, int threshold) {
        Map<Integer, List<Pair>> adj = new HashMap<>();
        int maxWt = 0;

        // Form the adjacency list with reversed edges
        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj.computeIfAbsent(v, k -> new ArrayList<>()).add(new Pair(u, w)); // reversed edge
            maxWt = Math.max(maxWt, w);
        }

        // Apply binary search on the answer (weight)
        int result = Integer.MAX_VALUE; // invalid answer
        int l = 0, r = maxWt;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (canAllReachZero(n, adj, mid)) {
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return result == Integer.MAX_VALUE ? -1 : result;
    }
}

// Approach-2 (Using DFS)
// T.C : O(log(maxWt) * (V+E))
// S.C : O(V+E)
class SolutionDFS {
    private static class Pair {
        int node, weight;

        Pair(int node, int weight) {
            this.node = node;
            this.weight = weight;
        }
    }

    private void dfs(int u, Map<Integer, List<Pair>> adj, int mid, boolean[] visited) {
        visited[u] = true;

        // Visit all neighbors of u if possible
        for (Pair p : adj.getOrDefault(u, new ArrayList<>())) {
            int v = p.node;
            int w = p.weight;

            if (w <= mid && !visited[v]) {
                visited[v] = true;
                dfs(v, adj, mid, visited);
            }
        }
    }

    private boolean canAllReachZero(int n, Map<Integer, List<Pair>> adj, int mid) {
        // DFS
        boolean[] visited = new boolean[n];
        dfs(0, adj, mid, visited);

        for (boolean isVisited : visited) {
            if (!isVisited) {
                return false;
            }
        }

        return true;
    }

    public int minMaxWeight(int n, int[][] edges, int threshold) {
        Map<Integer, List<Pair>> adj = new HashMap<>();
        int maxWt = 0;

        // Form the adjacency list with reversed edges
        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj.computeIfAbsent(v, k -> new ArrayList<>()).add(new Pair(u, w)); // reversed edge
            maxWt = Math.max(maxWt, w);
        }

        // Apply binary search on the answer (weight)
        int result = Integer.MAX_VALUE; // invalid answer
        int l = 0, r = maxWt;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (canAllReachZero(n, adj, mid)) { // O(V+E) due to BFS or DFS
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return result == Integer.MAX_VALUE ? -1 : result;
    }
}
