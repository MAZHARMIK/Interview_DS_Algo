/*         Scroll below to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=7b7GbuFMWRw
    Company Tags                : AMAZON
    Leetcode Link               : https://leetcode.com/problems/count-the-number-of-complete-components
*/


/********************************************************************** C++ **********************************************************************/
// Approach-1 (Using DFS)
// T.C : O(V+E)
// S.C : O(V+E)
class Solution {
public:
    void dfs(int i, unordered_map<int, vector<int>>& adj, vector<bool>& visited, int& v, int& e) {
        visited[i] = true;
        v++;
        e += adj[i].size();

        for(int &ngbr : adj[i]) {
            if(!visited[ngbr]) {
                dfs(ngbr, adj, visited, v, e);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;

        int result = 0;

        //Build the graph
        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++) {
            if(visited[i] == true) {
                continue;
            }
            int v = 0;
            int e = 0;
            dfs(i, adj, visited, v, e);

            if((v*(v-1)) == e) {
                result++;
            }
        }
        
        return result;
    }
};


// Approach-2 (Using BFS)
// T.C : O(V+E)
// S.C : O(V+E)
class Solution {
public:
    void bfs(int i, unordered_map<int, vector<int>>& adj, vector<bool>& visited, int& v, int &e) {
        queue<int> que;
        que.push(i);
        visited[i] = true;

        while(!que.empty()) {
            int curr = que.front();
            que.pop();
            v++;
            e += adj[curr].size();

            for(int &ngbr : adj[curr]) {
                if(!visited[ngbr]) {
                    visited[ngbr] = true;
                    que.push(ngbr);
                }
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;

        int result = 0;

        //Build the graph
        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++) {
            if(visited[i] == true) {
                continue;
            }
            int v = 0;
            int e = 0;
            bfs(i, adj, visited, v, e);

            if((v*(v-1)) == e) {
                result++;
            }
        }
        
        return result;
    }
};


// Approach-3 (Using DSU)
// T.C : O(E * alpha(V))
// S.C : O(V)
class Solution {
public:
    class DSU {
        public:
            vector<int> parent;
            vector<int> size;
            DSU(int n) {
                parent.resize(n);
                size.resize(n);
                for(int i = 0; i < n; i++) {
                    parent[i] = i;
                    size[i] = 1;
                }
            }

            int find(int x) {
                if(parent[x] == x) {
                    return x;
                }

                return parent[x] = find(parent[x]); //path compression
            }

            void Union(int x, int y) {
                int x_par = find(x);
                int y_par = find(y);

                if(x_par == y_par) {
                    return;
                }

                if(size[x_par] > size[y_par]) {
                    parent[y_par] = x_par;
                    size[x_par] += size[y_par];
                } else if(size[x_par] < size[y_par]) {
                    parent[x_par] = y_par;
                    size[y_par] += size[x_par];
                } else {
                    parent[x_par] = y_par;
                    size[y_par] += size[x_par];
                }
            }
    };
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        unordered_map<int, int> mp;// root -> edges

        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            dsu.Union(u, v);
        }

        //Count the edges for each root
        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int root = dsu.find(u);
            mp[root]++; //incrementing for edge count
        }

        int result = 0;
        for(int i = 0; i < n; i++) {
            if(dsu.find(i) == i) { //ye papa ji hain (root hai)
                int v = dsu.size[i];
                int e = mp[i];

                if((v*(v-1))/2 == e) {
                    result++;
                }
            }
        }

        return result;
    }
};


/********************************************************************** JAVA **********************************************************************/
// Approach-1 (Using DFS)
// T.C : O(V+E)
// S.C : O(V+E)
class Solution {
    private void dfs(int i, Map<Integer, List<Integer>> adj, boolean[] visited, int[] info) {
        visited[i] = true;
        info[0]++;
        info[1] += adj.getOrDefault(i, new ArrayList<>()).size();
        
        for (int ngbr : adj.getOrDefault(i, new ArrayList<>())) {
            if (!visited[ngbr]) {
                dfs(ngbr, adj, visited, info);
            }
        }
    }
    
    public int countCompleteComponents(int n, int[][] edges) {
        Map<Integer, List<Integer>> adj = new HashMap<>();
        int result = 0;
        
        for (int[] edge : edges) {
            adj.computeIfAbsent(edge[0], k -> new ArrayList<>()).add(edge[1]);
            adj.computeIfAbsent(edge[1], k -> new ArrayList<>()).add(edge[0]);
        }
        
        boolean[] visited = new boolean[n];
        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            
            int[] info = new int[2];
            dfs(i, adj, visited, info);
            
            if (info[0] * (info[0] - 1) == info[1]) {
                result++;
            }
        }
        
        return result;
    }
}

// Approach-2 (Using BFS)
// T.C : O(V+E)
// S.C : O(V+E)
class SolutionBFS {
    private void bfs(int i, Map<Integer, List<Integer>> adj, boolean[] visited, int[] info) {
        Queue<Integer> que = new LinkedList<>();
        que.add(i);
        visited[i] = true;
        
        while (!que.isEmpty()) {
            int curr = que.poll();
            info[0]++;
            info[1] += adj.getOrDefault(curr, new ArrayList<>()).size();
            
            for (int ngbr : adj.getOrDefault(curr, new ArrayList<>())) {
                if (!visited[ngbr]) {
                    visited[ngbr] = true;
                    que.add(ngbr);
                }
            }
        }
    }
    
    public int countCompleteComponents(int n, int[][] edges) {
        Map<Integer, List<Integer>> adj = new HashMap<>();
        int result = 0;
        
        for (int[] edge : edges) {
            adj.computeIfAbsent(edge[0], k -> new ArrayList<>()).add(edge[1]);
            adj.computeIfAbsent(edge[1], k -> new ArrayList<>()).add(edge[0]);
        }
        
        boolean[] visited = new boolean[n];
        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            
            int[] info = new int[2];
            bfs(i, adj, visited, info);
            
            if (info[0] * (info[0] - 1) == info[1]) {
                result++;
            }
        }
        
        return result;
    }
}

// Approach-3 (Using DSU)
// T.C : O(E * alpha(V))
// S.C : O(V)
class SolutionDSU {
    class DSU {
        int[] parent, size;
        
        DSU(int n) {
            parent = new int[n];
            size = new int[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }
        
        int find(int x) {
            if (parent[x] == x) return x;
            return parent[x] = find(parent[x]);
        }
        
        void union(int x, int y) {
            int xRoot = find(x), yRoot = find(y);
            if (xRoot == yRoot) return;
            
            if (size[xRoot] > size[yRoot]) {
                parent[yRoot] = xRoot;
                size[xRoot] += size[yRoot];
            } else {
                parent[xRoot] = yRoot;
                size[yRoot] += size[xRoot];
            }
        }
    }
    
    public int countCompleteComponents(int n, int[][] edges) {
        DSU dsu = new DSU(n);
        Map<Integer, Integer> edgeCount = new HashMap<>();
        
        for (int[] edge : edges) {
            dsu.union(edge[0], edge[1]);
        }
        
        for (int[] edge : edges) {
            int root = dsu.find(edge[0]);
            edgeCount.put(root, edgeCount.getOrDefault(root, 0) + 1);
        }
        
        int result = 0;
        for (int i = 0; i < n; i++) {
            if (dsu.find(i) == i) {
                int v = dsu.size[i];
                int e = edgeCount.getOrDefault(i, 0);
                
                if ((v * (v - 1)) / 2 == e) {
                    result++;
                }
            }
        }
        
        return result;
    }
}
