/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Amazon
    Leetcode Link               : https://leetcode.com/problems/course-schedule-iv/description/
*/


/************************************************************ C++ ************************************************************/
//Approach-1 (Using DFS) You can use BFS as well
//T.C : O(Q * (V+E))
//S.C : O(V+E)
class Solution {
public:

    bool dfs(unordered_map<int, vector<int>>& adj, int src, int dest, vector<bool>& visited) {
        visited[src] = true;

        if(src == dest) {
            return true;// yes we can reach to dest
        }

        bool isReacheable = false;
        for(auto &adjNode : adj[src]) {
            if(!visited[adjNode]) {
                isReacheable = isReacheable || dfs(adj, adjNode, dest, visited);
            }
        }

        return isReacheable;
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;

        for(auto &edge : prerequisites) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v); //u --> v
        }

        int Q = queries.size();
        vector<bool> result(Q);

        for(int i = 0; i < Q; i++) {
            int u = queries[i][0]; //source.
            int v = queries[i][1]; //Dest.

            vector<bool> visited(numCourses, false);
            result[i] = dfs(adj, u, v, visited); //You can use BFS as well
        }

        return result;
    }
};



//Approach-2 (Using preprocessing and DFS) - You can use BFS as well
//T.C : O(V^2 * (V+E))
//S.C : O(V+E)
class Solution {
public:
    // Perform DFS and mark prerequisites for each node
    bool dfs(unordered_map<int, vector<int>>& adj, vector<bool>& visited, int src, int target) {
        visited[src] = true;

        if (src == target) {
            return true;
        }

        bool isPrerequisite = false;
        for (auto adjNode : adj[src]) {
            if (!visited[adjNode]) {
                isPrerequisite = isPrerequisite || dfs(adj, visited, adjNode, target);
            }
        }
        return isPrerequisite;
    }

    void preprocess(int numCourses, unordered_map<int, vector<int>>& adjList, vector<vector<bool>>& isPrerequisite) {
        for (int u = 0; u < numCourses; u++) {
            for (int v = 0; v < numCourses; v++) {
                if (u != v) {
                    vector<bool> visited(numCourses, false);
                    if (dfs(adjList, visited, u, v)) {
                        isPrerequisite[u][v] = true;
                    }
                }
            }
        }
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adjList;
        for (auto edge : prerequisites) {
            adjList[edge[0]].push_back(edge[1]);
        }

        vector<vector<bool>> isPrerequisite(numCourses, vector<bool>(numCourses, false));
        preprocess(numCourses, adjList, isPrerequisite);

        int Q = queries.size();
        vector<bool> result(Q);

        for(int i = 0; i < Q; i++) {
            int u = queries[i][0]; //source.
            int v = queries[i][1]; //Dest.

            result[i] = isPrerequisite[u][v];
        }

        return result;
    }
};


//Approach-3 (Kahn's Algorithm)
//T.C : O(V^2 * (V+E))
//S.C : O(V+E)
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);
        for (auto &edge : prerequisites) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> que;
        for (int i = 0; i < numCourses; i++) {
            if (!indegree[i]) {
                que.push(i);
            }
        }

        // Map from the node as key to the set of prerequisite nodes.
        unordered_map<int, unordered_set<int>> mp;
        while (!que.empty()) {
            int node = que.front();
            que.pop();

            for (auto &ngbr : adj[node]) {
                // Add node and prerequisite of node to the prerequisites of adj
                mp[ngbr].insert(node);
                for (auto &prereq : mp[node]) {
                    mp[ngbr].insert(prereq);
                }

                indegree[ngbr]--;
                if (!indegree[ngbr]) {
                    que.push(ngbr);
                }
            }
        }

        int Q = queries.size();
        vector<bool> result(Q, false);
        for (int i = 0; i < Q; i++) {
            int src  = queries[i][0];
            int dest = queries[i][1];

            bool isReachable = mp[dest].contains(src);
            result[i] = isReachable;
        }

        return result;
    }
};



/************************************************************ JAVA ************************************************************/
// Approach-1 (Using DFS) - You can use BFS as well
// T.C : O(Q * (V+E))
// S.C : O(V+E)
class Solution {
    public List<Boolean> checkIfPrerequisite(int numCourses, int[][] prerequisites, int[][] queries) {
        // Create adjacency list representation of the graph
        Map<Integer, List<Integer>> adj = new HashMap<>();
        for (int[] edge : prerequisites) {
            int u = edge[0];
            int v = edge[1];
            adj.computeIfAbsent(u, k -> new ArrayList<>()).add(v); // u --> v
        }

        int Q = queries.length; // Number of queries
        List<Boolean> result = new ArrayList<>(Q);

        // Process each query
        for (int i = 0; i < Q; i++) {
            int u = queries[i][0]; // Source
            int v = queries[i][1]; // Destination

            // Initialize visited array for DFS
            boolean[] visited = new boolean[numCourses];
            result.add(dfs(adj, u, v, visited)); // You can use BFS as well
        }

        return result;
    }

    // Perform DFS to check if there is a path from src to dest
    private boolean dfs(Map<Integer, List<Integer>> adj, int src, int dest, boolean[] visited) {
        visited[src] = true;

        if (src == dest) {
            return true; // Yes, we can reach the destination
        }

        boolean isReachable = false;
        for (int adjNode : adj.getOrDefault(src, new ArrayList<>())) {
            if (!visited[adjNode]) {
                isReachable = isReachable || dfs(adj, adjNode, dest, visited);
            }
        }

        return isReachable;
    }
}


//Approach-2 (Using preprocessing and DFS) - You can use BFS as well
//T.C : O(V^2 * (V+E))
//S.C : O(V+E)
class Solution {
    public List<Boolean> checkIfPrerequisite(int numCourses, int[][] prerequisites, int[][] queries) {
        // Create adjacency list representation of the graph
        Map<Integer, List<Integer>> adjList = new HashMap<>();
        for (int[] edge : prerequisites) {
            adjList.computeIfAbsent(edge[0], k -> new ArrayList<>()).add(edge[1]);
        }

        // Preprocess to determine prerequisites
        boolean[][] isPrerequisite = new boolean[numCourses][numCourses];
        preprocess(numCourses, adjList, isPrerequisite);

        // Process each query
        List<Boolean> result = new ArrayList<>();
        for (int[] query : queries) {
            result.add(isPrerequisite[query[0]][query[1]]);
        }

        return result;
    }

    // Preprocess to mark prerequisites for each node
    private void preprocess(int numCourses, Map<Integer, List<Integer>> adjList, boolean[][] isPrerequisite) {
        for (int u = 0; u < numCourses; u++) {
            for (int v = 0; v < numCourses; v++) {
                if (u != v) {
                    boolean[] visited = new boolean[numCourses];
                    if (dfs(adjList, visited, u, v)) {
                        isPrerequisite[u][v] = true;
                    }
                }
            }
        }
    }

    // Perform DFS to check if src is a prerequisite of target
    private boolean dfs(Map<Integer, List<Integer>> adjList, boolean[] visited, int src, int target) {
        visited[src] = true;

        if (src == target) {
            return true;
        }

        for (int adjNode : adjList.getOrDefault(src, new ArrayList<>())) {
            if (!visited[adjNode] && dfs(adjList, visited, adjNode, target)) {
                return true;
            }
        }

        return false;
    }
}



//Approach-3 (Kahn's Algorithm)
//T.C : O(V^2 * (V+E))
//S.C : O(V+E)
class Solution {
    public List<Boolean> checkIfPrerequisite(int numCourses, int[][] prerequisites, int[][] queries) {
        // Create adjacency list and indegree array
        Map<Integer, List<Integer>> adj = new HashMap<>();
        int[] indegree = new int[numCourses];
        for (int[] edge : prerequisites) {
            int u = edge[0];
            int v = edge[1];
            adj.computeIfAbsent(u, k -> new ArrayList<>()).add(v);
            indegree[v]++;
        }

        // Initialize queue with nodes having indegree 0
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                queue.offer(i);
            }
        }

        // Map from node to set of prerequisite nodes
        Map<Integer, Set<Integer>> prereqMap = new HashMap<>();
        while (!queue.isEmpty()) {
            int node = queue.poll();

            for (int neighbor : adj.getOrDefault(node, new ArrayList<>())) {
                // Add current node and its prerequisites to the neighbor's prerequisites
                prereqMap.computeIfAbsent(neighbor, k -> new HashSet<>()).add(node);
                prereqMap.get(neighbor).addAll(prereqMap.getOrDefault(node, new HashSet<>()));

                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    queue.offer(neighbor);
                }
            }
        }

        // Process each query
        List<Boolean> result = new ArrayList<>();
        for (int[] query : queries) {
            int src = query[0];
            int dest = query[1];
            result.add(prereqMap.getOrDefault(dest, new HashSet<>()).contains(src));
        }

        return result;
    }
}
