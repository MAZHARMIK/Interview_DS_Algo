/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=tGtXUkUbYfo
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-i
*/



/****************************************************************** C++ ******************************************************************/
//Approach-1 (Using BFS)
//T.C : O(V*(V+E))
//S.C : O(V+E)
class Solution {
public:

    int bfs(int curr, unordered_map<int, vector<int>>& adj, int d, int N) {

        queue<pair<int, int>> que;
        que.push({curr, 0});
        vector<bool> visited(N, false);
        visited[curr] = true;

        int count = 0; //count the target nodes
        while(!que.empty()) {
            int currNode = que.front().first;
            int dist = que.front().second;
            que.pop();

            if(dist > d) {
                continue;
            }

            count++; //include current node in targetNodes count
            //visit neighbors of currNode
            for(auto &ngbr : adj[currNode]) {
                if(!visited[ngbr]) {
                    visited[ngbr] = true;
                    que.push({ngbr, dist+1});
                }
            }

        }

        return count;
    }

    vector<int> findCount(vector<vector<int>>& edges, int d) {
        int N = edges.size()+1;

        //adjacency list
        unordered_map<int, vector<int>> adj;
        for(auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> result(N);
        for(int i = 0; i < N; i++) {
            result[i] = bfs(i, adj, d, N);
        }

        return result;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        //Tree 1 me kitne nodes hain
        int N = edges1.size() + 1;

        vector<int> result1 = findCount(edges1, k); //stores targetnodes count from each node within tree1 within k distance
        vector<int> result2 = findCount(edges2, k-1); //stores targetnodes count from each node within tree2 within k-1 distance

        int maxTargetNodesCount = *max_element(begin(result2), end(result2));
        
        for(int i = 0; i < result1.size(); i++) {
            result1[i] += maxTargetNodesCount;
        }

        return result1;
    }
};



//Approach-2 (Using DFS)
//T.C : O(V*(V+E))
//S.C : O(V+E)
class Solution {
public:

    int dfs(int curr, unordered_map<int, vector<int>>& adj, int d, int currNodeKaParent) {
        if(d < 0)
            return 0;
        
        int count = 1; //counting current node as 1

        for(int &ngbr : adj[curr]) {
            if(ngbr != currNodeKaParent) {
                count += dfs(ngbr, adj, d-1, curr);
            }
        }

        return count;
    }

    vector<int> findCount(vector<vector<int>>& edges, int d) {
        int N = edges.size()+1;

        //adjacency list
        unordered_map<int, vector<int>> adj;
        for(auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> result(N);
        for(int i = 0; i < N; i++) {
            result[i] = dfs(i, adj, d, -1);
        }

        return result;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        //Tree 1 me kitne nodes hain
        int N = edges1.size() + 1;

        vector<int> result1 = findCount(edges1, k); //stores targetnodes count from each node within tree1 within k distance
        vector<int> result2 = findCount(edges2, k-1); //stores targetnodes count from each node within tree2 within k-1 distance

        int maxTargetNodesCount = *max_element(begin(result2), end(result2));
        
        for(int i = 0; i < result1.size(); i++) {
            result1[i] += maxTargetNodesCount;
        }

        return result1;
    }
};


/****************************************************************** JAVA ******************************************************************/
//Approach-1 (Using BFS)
//T.C : O(V*(V+E))
//S.C : O(V+E)
class Solution {

    private int bfs(int curr, Map<Integer, List<Integer>> adj, int d, int N) {
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{curr, 0});
        boolean[] visited = new boolean[N];
        visited[curr] = true;

        int count = 0; // count the target nodes
        while (!queue.isEmpty()) {
            int[] pair = queue.poll();
            int currNode = pair[0];
            int dist = pair[1];

            if (dist > d) {
                continue;
            }

            count++; // include current node in targetNodes count

            for (int neighbor : adj.getOrDefault(currNode, new ArrayList<>())) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    queue.offer(new int[]{neighbor, dist + 1});
                }
            }
        }

        return count;
    }

    private int[] findCount(int[][] edges, int d) {
        int N = edges.length + 1;
        Map<Integer, List<Integer>> adj = new HashMap<>();

        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj.computeIfAbsent(u, k -> new ArrayList<>()).add(v);
            adj.computeIfAbsent(v, k -> new ArrayList<>()).add(u);
        }

        int[] result = new int[N];
        for (int i = 0; i < N; i++) {
            result[i] = bfs(i, adj, d, N);
        }

        return result;
    }

    public int[] maxTargetNodes(int[][] edges1, int[][] edges2, int k) {
        int N = edges1.length + 1;

        int[] result1 = findCount(edges1, k);     // From tree1 within distance k
        int[] result2 = findCount(edges2, k - 1); // From tree2 within distance k-1

        int maxTargetNodesCount = Arrays.stream(result2).max().getAsInt();

        for (int i = 0; i < N; i++) {
            result1[i] += maxTargetNodesCount;
        }

        return result1;
    }
}


//Approach-2 (Using DFS)
//T.C : O(V*(V+E))
//S.C : O(V+E)
class Solution {

    private int dfs(int curr, Map<Integer, List<Integer>> adj, int d, int parent) {
        if (d < 0) return 0;

        int count = 1; // count current node

        for (int neighbor : adj.getOrDefault(curr, new ArrayList<>())) {
            if (neighbor != parent) {
                count += dfs(neighbor, adj, d - 1, curr);
            }
        }

        return count;
    }

    private int[] findCount(int[][] edges, int d) {
        int N = edges.length + 1;
        Map<Integer, List<Integer>> adj = new HashMap<>();

        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj.computeIfAbsent(u, k -> new ArrayList<>()).add(v);
            adj.computeIfAbsent(v, k -> new ArrayList<>()).add(u);
        }

        int[] result = new int[N];
        for (int i = 0; i < N; i++) {
            result[i] = dfs(i, adj, d, -1);
        }

        return result;
    }

    public int[] maxTargetNodes(int[][] edges1, int[][] edges2, int k) {
        int N = edges1.length + 1;

        int[] result1 = findCount(edges1, k);
        int[] result2 = findCount(edges2, k - 1);

        int maxTargetNodesCount = Arrays.stream(result2).max().getAsInt();

        for (int i = 0; i < N; i++) {
            result1[i] += maxTargetNodesCount;
        }

        return result1;
    }
}
