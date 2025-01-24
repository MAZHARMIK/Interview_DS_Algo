/*						SCROLL BELOW TO SEE JAVA CODE AS WELL					*/
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=k8LBJqGLLQE
    Company Tags                : MICROSOFT
    Leetcode Link               : https://leetcode.com/problems/find-eventual-safe-states/
*/


/****************************************************************  C++  *****************************************************************/
//Approach-1 (Using Same code of DFS Cycle Check in directed Graph)
//T.C : O(V+E)
//S.C : O(V+E)
class Solution {
public:
    bool isCycleDFS(vector<vector<int>>& adj, int u, vector<bool>& visited, vector<bool>& inRecursion) {
        visited[u] = true;
        inRecursion[u] = true;
        
        
        for(int &v : adj[u]) {
            //if not visited, then we check for cycle in DFS
            if(visited[v] == false && isCycleDFS(adj, v, visited, inRecursion))
                return true;
            else if(inRecursion[v] == true)
                return true;
        }
        
        inRecursion[u] = false;
        return false;
        
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<bool> visited(V, false);
        vector<bool> inRecursion(V, false);
        
        for(int i = 0; i<V; i++) {
            if(!visited[i])
                isCycleDFS(graph, i, visited, inRecursion);
        }
        
        vector<int> safeNodes;
        for(int i = 0; i<V; i++) {
            if(!inRecursion[i])
                safeNodes.push_back(i);
        }
        
        return safeNodes;
    }
};


//Approach-2 (Using BFS) (Toplogical Sort)
//T.C : O(V+E)
//S.C : O(V+E)
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();

        vector<vector<int>> adj(V);
        
        
        queue<int> que;
	    vector<int> indegree(V, 0);
	    int count = 0;
	    //1
	    for(int u = 0; u < V; u++) {
	        for(int &v : graph[u]) {
                adj[v].push_back(u);
	            indegree[u]++;
	        }
	    }
	    
	    //2. Fill que, indegree with 0
	    for(int i = 0; i < V; i++) {
	        if(indegree[i] == 0) {
	            que.push(i);
	            count++;
	        }
	    }
	    
	    //3. Simple BFS
        vector<bool> safe(V, false);
	    while(!que.empty()) {
	        int u = que.front();
	        que.pop();
            safe[u] = true;
	        
	        for(int &v : adj[u]) {
	            indegree[v]--;
	            
	            if(indegree[v] == 0) {
	                que.push(v);
	                count++;
	            }
	            
	        }
	    }
	    
	    vector<int> safeNodes;
        for(int i = 0; i < V; i++) {
            if(safe[i]) {
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};



/****************************************************************  Java  *****************************************************************/
// Approach-1 (Using Same code of DFS Cycle Check in directed Graph)
// T.C : O(V+E)
// S.C : O(V+E)
class Solution {
    private boolean isCycleDFS(List<List<Integer>> adj, int u, boolean[] visited, boolean[] inRecursion) {
        visited[u] = true;
        inRecursion[u] = true;

        for (int v : adj.get(u)) {
            // if not visited, then we check for cycle in DFS
            if (!visited[v] && isCycleDFS(adj, v, visited, inRecursion)) {
                return true;
            } else if (inRecursion[v]) {
                return true;
            }
        }

        inRecursion[u] = false;
        return false;
    }

    public List<Integer> eventualSafeNodes(int[][] graph) {
        int V = graph.length;
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
            for (int v : graph[i]) {
                adj.get(i).add(v);
            }
        }

        boolean[] visited = new boolean[V];
        boolean[] inRecursion = new boolean[V];

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                isCycleDFS(adj, i, visited, inRecursion);
            }
        }

        List<Integer> safeNodes = new ArrayList<>();
        for (int i = 0; i < V; i++) {
            if (!inRecursion[i]) {
                safeNodes.add(i);
            }
        }

        return safeNodes;
    }
}

// Approach-2 (Using BFS) (Topological Sort)
// T.C : O(V+E)
// S.C : O(V+E)
class Solution {
    public List<Integer> eventualSafeNodes(int[][] graph) {
        int V = graph.length;

        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
        }

        Queue<Integer> queue = new LinkedList<>();
        int[] indegree = new int[V];
        int count = 0;

        // 1. Create reverse graph and calculate indegree
        for (int u = 0; u < V; u++) {
            for (int v : graph[u]) {
                adj.get(v).add(u);
                indegree[u]++;
            }
        }

        // 2. Fill queue with nodes having indegree 0
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                queue.add(i);
                count++;
            }
        }

        // 3. Simple BFS
        boolean[] safe = new boolean[V];
        while (!queue.isEmpty()) {
            int u = queue.poll();
            safe[u] = true;

            for (int v : adj.get(u)) {
                indegree[v]--;

                if (indegree[v] == 0) {
                    queue.add(v);
                    count++;
                }
            }
        }

        List<Integer> safeNodes = new ArrayList<>();
        for (int i = 0; i < V; i++) {
            if (safe[i]) {
                safeNodes.add(i);
            }
        }

        return safeNodes;
    }
}
