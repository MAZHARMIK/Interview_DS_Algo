/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=ylJ2lDHUBZA
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/power-grid-maintenance
*/



/****************************************************************** C++ ******************************************************************/
//Approach-1 (Using DFS)
//T.C : O((c + n) + q log c)
//S.C : O(c + n)
class Solution {
public:
    //O(c + n)
    void dfs(int node, unordered_map<int, vector<int>> &adj, int id, vector<int>& nodeId, 
            unordered_map<int, set<int>>& mp, vector<bool>& visited) {
        visited[node] = true;
        mp[id].insert(node);
        nodeId[node] = id;

        for(int &ngbr : adj[node]) {
            if(!visited[ngbr]) {
                dfs(ngbr, adj, id, nodeId, mp, visited);
            }
        }
    }

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;

        for(auto &edge :  connections) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(c+1, false);
        vector<int> nodeId(c+1);
        //id -> {}
        unordered_map<int, set<int>> mp;

        //O(c+n)
        for(int node = 1; node <= c; node++) {
            if(!visited[node]) {
                int id = node;
                dfs(node, adj, id, nodeId, mp, visited);
            }
        }

        vector<int> result;
        //O(q * log(c))
        for(auto &query : queries) {
            int type = query[0]; //1, 2
            int node = query[1]; //station/node

            if(type == 1) {
                int id = nodeId[node];
                if(mp[id].count(node)) {
                    result.push_back(node);
                } else if(!mp[id].empty()) {
                    result.push_back(*mp[id].begin());
                } else {
                    result.push_back(-1);
                }
            } else {
                int id = nodeId[node];
                mp[id].erase(node); //log(c)
            }

        }
        return result;
    }
};


//Approach-2 (Using BFS)
//T.C : O((c + n) + q log c)
//S.C : O(c + n)
class Solution {
public:
    // O(c + n)
    void bfs(int start, unordered_map<int, vector<int>> &adj, int id,
             vector<int>& nodeId, unordered_map<int, set<int>>& mp,
             vector<bool>& visited) {

        queue<int> q;
        q.push(start);
        visited[start] = true;
        nodeId[start] = id;
        mp[id].insert(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int &ngbr : adj[node]) {
                if (!visited[ngbr]) {
                    visited[ngbr] = true;
                    nodeId[ngbr] = id;
                    mp[id].insert(ngbr);
                    q.push(ngbr);
                }
            }
        }
    }

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;

        for (auto &edge : connections) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(c + 1, false);
        vector<int> nodeId(c + 1);
        unordered_map<int, set<int>> mp;

        // O(c + n)
        for (int node = 1; node <= c; node++) {
            if (!visited[node]) {
                int id = node;
                bfs(node, adj, id, nodeId, mp, visited);
            }
        }

        vector<int> result;
        // O(q * log(c))
        for (auto &query : queries) {
            int type = query[0]; // 1 or 2
            int node = query[1]; // station/node

            if (type == 1) {
                int id = nodeId[node];
                if (mp[id].count(node)) {
                    result.push_back(node);
                } else if (!mp[id].empty()) {
                    result.push_back(*mp[id].begin());
                } else {
                    result.push_back(-1);
                }
            } else {
                int id = nodeId[node];
                mp[id].erase(node); // O(log c)
            }
        }

        return result;
    }
};



//Approach-3 (Using DSU)
//Coming soon




/****************************************************************** JAVA ******************************************************************/
//Approach-1 (Using DFS)
//T.C : O((c + n) + q log c)
//S.C : O(c + n)
class Solution {
    // O(c + n)
    private void dfs(int node, Map<Integer, List<Integer>> adj, int id,
                     int[] nodeId, Map<Integer, TreeSet<Integer>> mp,
                     boolean[] visited) {
        visited[node] = true;
        mp.computeIfAbsent(id, k -> new TreeSet<>()).add(node);
        nodeId[node] = id;

        for (int ngbr : adj.getOrDefault(node, new ArrayList<>())) {
            if (!visited[ngbr]) {
                dfs(ngbr, adj, id, nodeId, mp, visited);
            }
        }
    }

    public int[] processQueries(int c, int[][] connections, int[][] queries) {
        Map<Integer, List<Integer>> adj = new HashMap<>();

        for (int[] edge : connections) {
            int u = edge[0];
            int v = edge[1];
            adj.computeIfAbsent(u, k -> new ArrayList<>()).add(v);
            adj.computeIfAbsent(v, k -> new ArrayList<>()).add(u);
        }

        boolean[] visited = new boolean[c + 1];
        int[] nodeId = new int[c + 1];
        Map<Integer, TreeSet<Integer>> mp = new HashMap<>();

        // O(c + n)
        for (int node = 1; node <= c; node++) {
            if (!visited[node]) {
                int id = node;
                dfs(node, adj, id, nodeId, mp, visited);
            }
        }

        List<Integer> result = new ArrayList<>();
        // O(q * log(c))
        for (int[] query : queries) {
            int type = query[0];
            int node = query[1];
            int id = nodeId[node];

            if (type == 1) {
                TreeSet<Integer> set = mp.get(id);
                if (set != null && set.contains(node)) {
                    result.add(node);
                } else if (set != null && !set.isEmpty()) {
                    result.add(set.first());
                } else {
                    result.add(-1);
                }
            } else {
                TreeSet<Integer> set = mp.get(id);
                if (set != null) {
                    set.remove(node); // O(log c)
                }
            }
        }

        // convert List<Integer> to int[]
        return result.stream().mapToInt(i -> i).toArray();
    }
}



//Approach-2 (Using BFS)
//T.C : O((c + n) + q log c)
//S.C : O(c + n)
class Solution {
    // O(c + n)
    private void bfs(int start, Map<Integer, List<Integer>> adj, int id,
                     int[] nodeId, Map<Integer, TreeSet<Integer>> mp,
                     boolean[] visited) {
        Queue<Integer> q = new LinkedList<>();
        q.offer(start);
        visited[start] = true;
        nodeId[start] = id;

        mp.computeIfAbsent(id, k -> new TreeSet<>()).add(start);

        while (!q.isEmpty()) {
            int node = q.poll();
            for (int ngbr : adj.getOrDefault(node, new ArrayList<>())) {
                if (!visited[ngbr]) {
                    visited[ngbr] = true;
                    nodeId[ngbr] = id;
                    mp.get(id).add(ngbr);
                    q.offer(ngbr);
                }
            }
        }
    }

    public int[] processQueries(int c, int[][] connections, int[][] queries) {
        Map<Integer, List<Integer>> adj = new HashMap<>();

        for (int[] edge : connections) {
            int u = edge[0];
            int v = edge[1];
            adj.computeIfAbsent(u, k -> new ArrayList<>()).add(v);
            adj.computeIfAbsent(v, k -> new ArrayList<>()).add(u);
        }

        boolean[] visited = new boolean[c + 1];
        int[] nodeId = new int[c + 1];
        Map<Integer, TreeSet<Integer>> mp = new HashMap<>();

        // O(c + n)
        for (int node = 1; node <= c; node++) {
            if (!visited[node]) {
                int id = node;
                bfs(node, adj, id, nodeId, mp, visited);
            }
        }

        List<Integer> result = new ArrayList<>();
        // O(q * log(c))
        for (int[] query : queries) {
            int type = query[0];
            int node = query[1];
            int id = nodeId[node];

            if (type == 1) {
                TreeSet<Integer> set = mp.get(id);
                if (set != null && set.contains(node)) {
                    result.add(node);
                } else if (set != null && !set.isEmpty()) {
                    result.add(set.first());
                } else {
                    result.add(-1);
                }
            } else {
                TreeSet<Integer> set = mp.get(id);
                if (set != null) {
                    set.remove(node); // O(log c)
                }
            }
        }

        return result.stream().mapToInt(i -> i).toArray();
    }
}


//Approach-3 (Using DSU)
//Coming soon
