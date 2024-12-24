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
    int n;
    pair<int, int> BFS(unordered_map<int, vector<int>>& adj, int source) {
        queue<int> que;
        que.push(source);

        unordered_map<int, bool> visited;
        visited[source] = true;

        int distance = 0;
        int farthestNode = source;

        while(!que.empty()) {
            int size = que.size(); //current level me itne nodes hain

            while(size--) {
                int curr = que.front();
                que.pop();

                farthestNode = curr;

                for(auto &nbr : adj[curr]) {
                    if(visited[nbr] == false) {
                        visited[nbr] = true;
                        que.push(nbr);
                    }
                }
            }
            if(!que.empty()) {
                distance++;
            }
        }

        return {farthestNode, distance};

    }

    int findDiameter(unordered_map<int, vector<int>> adj) {
        //step-1 find the farthest node from a random node - 0
        auto [farthestNode, dist] = BFS(adj, 0);

        //step-2 : the farthestNode we got above is nothing but one end of the diameter of adj

        //step-3 : Find the farthestnode from the node we got above , that will be the other end of diameter - diameter
        auto [otherEndNode, diameter] = BFS(adj, farthestNode);

        return diameter;
    }

    unordered_map<int, vector<int>> buildAdj(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;

        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        unordered_map<int, vector<int>> adj1 = buildAdj(edges1);
        unordered_map<int, vector<int>> adj2 = buildAdj(edges2);

        int d1 = findDiameter(adj1);
        int d2 = findDiameter(adj2);

        int combined = (d1+1)/2 + (d2+1)/2 + 1;

        return max({d1, d2, combined});
        
    }
};


/********************************************************************** JAVA **********************************************************************/
//Approach (Using BFS)
//T.C : O(V+E)
//S.C : O(V+E)
public class Solution {

    // Function to build the adjacency list for a tree
    public Map<Integer, List<Integer>> buildAdjList(int[][] edges) {
        Map<Integer, List<Integer>> adjList = new HashMap<>();
        for (int[] edge : edges) {
            adjList.computeIfAbsent(edge[0], k -> new ArrayList<>()).add(edge[1]);
            adjList.computeIfAbsent(edge[1], k -> new ArrayList<>()).add(edge[0]);
        }
        return adjList;
    }

    public int minimumDiameterAfterMerge(int[][] edges1, int[][] edges2) {
        // Build adjacency lists for both trees
        Map<Integer, List<Integer>> adj1 = buildAdjList(edges1);
        Map<Integer, List<Integer>> adj2 = buildAdjList(edges2);

        // Calculate the diameters of both trees
        int d1 = findDiameter(adj1);
        int d2 = findDiameter(adj2);

        // Calculate the longest path that spans across both trees
        int combined = (d1 + 1) / 2 + (d2 + 1) / 2 + 1;

        // Return the maximum of the three possibilities
        return Math.max(Math.max(d1, d2), combined);
    }

    // Function to find the diameter of a tree using two BFS calls
    public int findDiameter(Map<Integer, List<Integer>> adjList) {
        // First BFS to find the farthest node from any arbitrary node (e.g., 0)
        List<Integer> farthestNode = BFS(adjList, 0);

        // Second BFS from the farthest node to determine the diameter
        farthestNode = BFS(adjList, farthestNode.get(0));
        return farthestNode.get(1);
    }

    // BFS helper function to find the farthest node and its distance from the source
    public List<Integer> BFS(Map<Integer, List<Integer>> adjList, int sourceNode) {
        Queue<Integer> que = new LinkedList<>();
        Map<Integer, Boolean> visited = new HashMap<>();
        
        // Push source node into the queue
        que.add(sourceNode);
        visited.put(sourceNode, true);

        int maxDistance = 0, farthestNode = sourceNode;

        // Explore neighbors
        while (!que.isEmpty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                int currentNode = que.poll();
                // Update farthest node
                farthestNode = currentNode;

                for (int neighbor : adjList.getOrDefault(currentNode, new ArrayList<>())) {
                    // Explore neighbors
                    if (!visited.getOrDefault(neighbor, false)) {
                        visited.put(neighbor, true);
                        que.add(neighbor);
                    }
                }
            }
            if (!que.isEmpty()) {
                maxDistance++;
            }
        }
        return Arrays.asList(farthestNode, maxDistance);
    }
}
