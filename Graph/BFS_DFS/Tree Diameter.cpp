/*                       Scroll down to see JAVA code also             */
/*
    MY YOUTUBE VIDEO ON THIS Qn  : 
    Company Tags                 : GOOGLE, META
    Leetcode Link                : https://leetcode.com/problems/tree-diameter/description/
    Hard Version of This Problem : https://leetcode.com/problems/find-minimum-diameter-after-merging-two-trees
*/

/*
    Leetcode-1245 : Tree Diameter
    Given an undirected tree, return its diameter: the number of edges in a longest path in that tree.
    The tree is given as an array of edges where edges[i] = [u, v] is a bidirectional edge between nodes u and v.
    Each node has labels in the set {0, 1, ..., edges.length}.
*/

/********************************************************************** C++ **********************************************************************/
//Approach (Using BFS)
//T.C : O(V+E)
//S.C : O(V+E)
class Solution {
public:
    int treeDiameter(vector<vector<int>>& edges) {
        // Number of nodes in the tree
        int n = edges.size() + 1;

        // Build adjacency list
        unordered_map<int, vector<int>> adj;
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // Find the diameter of the tree
        return findDiameter(n, adj);
    }

private:
    // Function to find the diameter of a tree using two BFS calls
    int findDiameter(int n, unordered_map<int, vector<int>>& adj) {
        // First BFS to find the farthest node from any arbitrary node (e.g., 0)
        auto [farthestNode, _] = findFarthestNode(n, adj, 0);

        // Second BFS from the farthest node to determine the diameter
        auto [_, diameter] = findFarthestNode(n, adj, farthestNode);
        return diameter;
    }

    // BFS helper function to find the farthest node and its distance from the source
    pair<int, int> findFarthestNode(int n, unordered_map<int, vector<int>>& adj, int sourceNode) {
        queue<int> que;
        vector<bool> visited(n, false);

        // Push source node into the queue
        que.push(sourceNode);
        visited[sourceNode] = true;

        int maximumDistance = 0;
        int farthestNode = sourceNode;

        // Explore neighbors
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                int currentNode = que.front();
                que.pop();
                // Update farthest node
                farthestNode = currentNode;

                for (int neighbor : adj[currentNode]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        que.push(neighbor);
                    }
                }
            }
            if (!que.empty()) maximumDistance++;
        }
        return {farthestNode, maximumDistance};
    }
};



/********************************************************************** JAVA **********************************************************************/
//Approach (Using BFS)
//T.C : O(V+E)
//S.C : O(V+E)
class Solution {
    public int treeDiameter(int[][] edges) {
        // Number of nodes in the tree
        int n = edges.length + 1;

        // Build adjacency list
        Map<Integer, List<Integer>> adj = new HashMap<>();
        for (int[] edge : edges) {
            adj.computeIfAbsent(edge[0], k -> new ArrayList<>()).add(edge[1]);
            adj.computeIfAbsent(edge[1], k -> new ArrayList<>()).add(edge[0]);
        }

        // Find the diameter of the tree
        return findDiameter(n, adj);
    }

    // Function to find the diameter of a tree using two BFS calls
    private int findDiameter(int n, Map<Integer, List<Integer>> adj) {
        // First BFS to find the farthest node from any arbitrary node (e.g., 0)
        int[] farthestNodeResult = findFarthestNode(n, adj, 0);

        // Second BFS from the farthest node to determine the diameter
        int[] diameterResult = findFarthestNode(n, adj, farthestNodeResult[0]);
        return diameterResult[1];
    }

    // BFS helper function to find the farthest node and its distance from the source
    private int[] findFarthestNode(int n, Map<Integer, List<Integer>> adj, int sourceNode) {
        Queue<Integer> que = new LinkedList<>();
        boolean[] visited = new boolean[n];

        // Push source node into the queue
        que.add(sourceNode);
        visited[sourceNode] = true;

        int maximumDistance = 0;
        int farthestNode = sourceNode;

        // Explore neighbors
        while (!que.isEmpty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                int currentNode = que.poll();
                // Update farthest node
                farthestNode = currentNode;

                for (int neighbor : adj.getOrDefault(currentNode, new ArrayList<>())) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        que.add(neighbor);
                    }
                }
            }
            if (!que.isEmpty()) maximumDistance++;
        }

        // Return an array with farthest node and its distance
        return new int[]{farthestNode, maximumDistance};
    }
}
