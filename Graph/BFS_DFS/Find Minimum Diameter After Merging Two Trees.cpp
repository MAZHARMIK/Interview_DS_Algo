/*                       Scroll down to see JAVA code also             */
/*
    MY YOUTUBE VIDEO ON THIS Qn  : 
    Company Tags                 : will update
    Leetcode Link                : https://leetcode.com/problems/find-minimum-diameter-after-merging-two-trees
*/

/*
    Similar Medium Problem : Leetcode-1245 : Tree Diameter
    Video Link - https://www.youtube.com/watch?v=na3LE8CBYLo
*/

/********************************************************************** C++ **********************************************************************/
//Approach (Using BFS)
//T.C : O(V+E)
//S.C : O(V+E)
class Solution {
public:
    unordered_map<int, vector<int>> buildAdjList(int size, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adjList;
        for (auto edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        return adjList;
    }
    
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1,
                                  vector<vector<int>>& edges2) {
        // Calculate the number of nodes for each tree
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        // Build adjacency lists for both trees
        unordered_map<int, vector<int>> adj1 = buildAdjList(n, edges1);
        unordered_map<int, vector<int>> adj2 = buildAdjList(m, edges2);

        // Calculate the diameters of both trees
        int d1 = findDiameter(n, adj1);
        int d2 = findDiameter(m, adj2);

        // Calculate the longest path that spans across both trees
        int combined = (d1+1)/2 + (d2+1)/2 + 1;

        // Return the maximum of the three possibilities
        return max({d1, d2, combined});
    }

private:

    // Function to find the diameter of a tree using two BFS calls
    int findDiameter(int n, unordered_map<int, vector<int>>& adjList) {
        // First BFS to find the farthest node from any arbitrary node (e.g., 0)
        auto [farthestNode, _] = findFarthestNode(n, adjList, 0);

        // Second BFS from the farthest node to determine the diameter
        auto [_, diameter] = findFarthestNode(n, adjList, farthestNode);
        return diameter;
    }

    // BFS helper function to find the farthest node and its distance from the
    // source
    pair<int, int> findFarthestNode(int n, unordered_map<int, vector<int>>& adjList,
                                    int sourceNode) {
        queue<int> nodesQueue;
        unordered_map<int, bool> visited;
        // Push source node into the queue
        nodesQueue.push(sourceNode);
        visited[sourceNode] = true;

        int maxDistance = 0, farthestNode = sourceNode;

        // Explore neighbors
        while (!nodesQueue.empty()) {
            int size = nodesQueue.size();
            for (int i = 0; i < size; ++i) {
                int currentNode = nodesQueue.front();
                nodesQueue.pop();
                // Update farthest node
                // The farthest node is the last one that was popped out of the
                // queue.
                farthestNode = currentNode;

                for (int neighbor : adjList[currentNode]) {
                    // Explore neighbors
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        nodesQueue.push(neighbor);
                    }
                }
            }
            if (!nodesQueue.empty()) {
                maxDistance++;
            }
        }
        return {farthestNode, maxDistance};
    }
};



/********************************************************************** JAVA **********************************************************************/
//Approach (Using BFS)
//T.C : O(V+E)
//S.C : O(V+E)
class Solution {

    // Function to build the adjacency list for a tree
    public Map<Integer, List<Integer>> buildAdjList(int size, int[][] edges) {
        Map<Integer, List<Integer>> adjList = new HashMap<>();
        for (int[] edge : edges) {
            adjList.computeIfAbsent(edge[0], k -> new ArrayList<>()).add(edge[1]);
            adjList.computeIfAbsent(edge[1], k -> new ArrayList<>()).add(edge[0]);
        }
        return adjList;
    }

    public int minimumDiameterAfterMerge(int[][] edges1, int[][] edges2) {
        // Calculate the number of nodes for each tree
        int n = edges1.length + 1;
        int m = edges2.length + 1;

        // Build adjacency lists for both trees
        Map<Integer, List<Integer>> adj1 = buildAdjList(n, edges1);
        Map<Integer, List<Integer>> adj2 = buildAdjList(m, edges2);

        // Calculate the diameters of both trees
        int d1 = findDiameter(n, adj1);
        int d2 = findDiameter(m, adj2);

        // Calculate the longest path that spans across both trees
        int combined = (d1 + 1) / 2 + (d2 + 1) / 2 + 1;

        // Return the maximum of the three possibilities
        return Math.max(Math.max(d1, d2), combined);
    }

    // Function to find the diameter of a tree using two BFS calls
    public int findDiameter(int n, Map<Integer, List<Integer>> adjList) {
        // First BFS to find the farthest node from any arbitrary node (e.g., 0)
        List<Integer> farthestNode = findFarthestNode(n, adjList, 0);

        // Second BFS from the farthest node to determine the diameter
        farthestNode = findFarthestNode(n, adjList, farthestNode.get(0));
        return farthestNode.get(1);
    }

    // BFS helper function to find the farthest node and its distance from the source
    public List<Integer> findFarthestNode(int n, Map<Integer, List<Integer>> adjList, int sourceNode) {
        Queue<Integer> nodesQueue = new LinkedList<>();
        Map<Integer, Boolean> visited = new HashMap<>();
        
        // Push source node into the queue
        nodesQueue.add(sourceNode);
        visited.put(sourceNode, true);

        int maxDistance = 0, farthestNode = sourceNode;

        // Explore neighbors
        while (!nodesQueue.isEmpty()) {
            int size = nodesQueue.size();
            for (int i = 0; i < size; i++) {
                int currentNode = nodesQueue.poll();
                // Update farthest node
                farthestNode = currentNode;

                for (int neighbor : adjList.getOrDefault(currentNode, new ArrayList<>())) {
                    // Explore neighbors
                    if (!visited.getOrDefault(neighbor, false)) {
                        visited.put(neighbor, true);
                        nodesQueue.add(neighbor);
                    }
                }
            }
            if (!nodesQueue.isEmpty()) {
                maxDistance++;
            }
        }
        return Arrays.asList(farthestNode, maxDistance);
    }
}
