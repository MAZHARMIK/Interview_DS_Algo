/*        Scroll below to see JAVA code as well        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Vn-voe1XNtQ
    Company Tags                : <soon>
    Leetcode Link               : https://leetcode.com/problems/find-closest-node-to-given-two-nodes/
*/


/****************************************************************** C++ ******************************************************************/
//Approach-1 (BFS)
//T.C : O(V+E), V = number of vertices and E = number of edges
//S.C : O(n)
class Solution {
public:
    int n;
    
    void bfs(vector<int>& edges, int startNode, vector<int>& dist_node) {
        queue<int> que;
        que.push(startNode);
        dist_node[startNode] = 0;
        vector<bool> visited(n, false);
        visited[startNode] = true;
        
        while(!que.empty()) {
            int u = que.front();
            que.pop();
            
            int v = edges[u];
            
            if(v != -1 && !visited[v]) {
                visited[v] = true;
                dist_node[v] = 1 + dist_node[u];
                que.push(v);
            }
        }
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        n = edges.size();
        
        vector<int> dist1(n, INT_MAX);
        vector<int> dist2(n, INT_MAX);
        
        bfs(edges, node1, dist1);
        bfs(edges, node2, dist2);
        
        
        int minDistNode    = -1;
        int minDistTillNow = INT_MAX;
        for (int i = 0; i < n; i++) {
            
            int maxD = max(dist1[i], dist2[i]);
            
            if (minDistTillNow > maxD) {
                minDistNode = i;
                minDistTillNow = maxD;
            }
        }

        return minDistNode;
        
    }
};


//Approach-2 (DFS)
//T.C : O(V+E), V = number of vertices and E = number of edges
//S.C : O(n)
class Solution {
public:
    int n;
    
    void dfs(vector<int>& edges, int startNode, vector<int>& dist_node, vector<bool>& visited) {
        visited[startNode] = true;
        
        int v = edges[startNode];
        
        if(v != -1 && !visited[v]) {
            visited[v] = true;
            dist_node[v] = 1 + dist_node[startNode];
            dfs(edges, v, dist_node, visited);
        }
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        n = edges.size();
        
        vector<int> dist1(n, INT_MAX);
        vector<int> dist2(n, INT_MAX);
        vector<bool> visited1(n, false);
        vector<bool> visited2(n, false);
        dist1[node1] = 0;
        dist2[node2] = 0;
        
        dfs(edges, node1, dist1, visited1);
        dfs(edges, node2, dist2, visited2);
        
        
        int minDistNode    = -1;
        int minDistTillNow = INT_MAX;
        for (int i = 0; i < n; i++) {
            
            int maxD = max(dist1[i], dist2[i]);
            
            if (minDistTillNow > maxD) {
                minDistNode = i;
                minDistTillNow = maxD;
            }
        }

        return minDistNode;
        
    }
};


/****************************************************************** JAVA ******************************************************************/
//Approach-1 (BFS)
//T.C : O(V+E), V = number of vertices and E = number of edges
//S.C : O(n)
class Solution {
    private int n;

    private void bfs(int[] edges, int startNode, int[] dist_node) {
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(startNode);
        dist_node[startNode] = 0;
        boolean[] visited = new boolean[n];
        visited[startNode] = true;

        while (!queue.isEmpty()) {
            int u = queue.poll();
            int v = edges[u];

            if (v != -1 && !visited[v]) {
                visited[v] = true;
                dist_node[v] = 1 + dist_node[u];
                queue.offer(v);
            }
        }
    }

    public int closestMeetingNode(int[] edges, int node1, int node2) {
        n = edges.length;

        int[] dist1 = new int[n];
        int[] dist2 = new int[n];
        Arrays.fill(dist1, Integer.MAX_VALUE);
        Arrays.fill(dist2, Integer.MAX_VALUE);

        bfs(edges, node1, dist1);
        bfs(edges, node2, dist2);

        int minDistNode = -1;
        int minDistTillNow = Integer.MAX_VALUE;

        for (int i = 0; i < n; i++) {
            int maxDist = Math.max(dist1[i], dist2[i]);
            if (dist1[i] != Integer.MAX_VALUE && dist2[i] != Integer.MAX_VALUE) {
                if (maxDist < minDistTillNow) {
                    minDistTillNow = maxDist;
                    minDistNode = i;
                }
            }
        }

        return minDistNode;
    }
}


//Approach-2 (DFS)
//T.C : O(V+E), V = number of vertices and E = number of edges
//S.C : O(n)
class Solution {
    private int n;

    private void dfs(int[] edges, int startNode, int[] dist_node, boolean[] visited) {
        visited[startNode] = true;
        int v = edges[startNode];

        if (v != -1 && !visited[v]) {
            dist_node[v] = 1 + dist_node[startNode];
            dfs(edges, v, dist_node, visited);
        }
    }

    public int closestMeetingNode(int[] edges, int node1, int node2) {
        n = edges.length;

        int[] dist1 = new int[n];
        int[] dist2 = new int[n];
        boolean[] visited1 = new boolean[n];
        boolean[] visited2 = new boolean[n];

        Arrays.fill(dist1, Integer.MAX_VALUE);
        Arrays.fill(dist2, Integer.MAX_VALUE);

        dist1[node1] = 0;
        dist2[node2] = 0;

        dfs(edges, node1, dist1, visited1);
        dfs(edges, node2, dist2, visited2);

        int minDistNode = -1;
        int minDistTillNow = Integer.MAX_VALUE;

        for (int i = 0; i < n; i++) {
            if (dist1[i] != Integer.MAX_VALUE && dist2[i] != Integer.MAX_VALUE) {
                int maxDist = Math.max(dist1[i], dist2[i]);

                if (maxDist < minDistTillNow) {
                    minDistTillNow = maxDist;
                    minDistNode = i;
                }
            }
        }

        return minDistNode;
    }
}
