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

    public Map<Integer, List<Integer>> buildAdj(List<List<Integer>> edges) {
        Map<Integer, List<Integer>> adj = new HashMap<>();
        for (List<Integer> edge : edges) {
            int u = edge.get(0);
            int v = edge.get(1);
            adj.computeIfAbsent(u, k -> new ArrayList<>()).add(v);
            adj.computeIfAbsent(v, k -> new ArrayList<>()).add(u);
        }
        return adj;
    }

    public List<Integer> BFS(Map<Integer, List<Integer>> adj, int source) {
        Queue<Integer> que = new LinkedList<>();
        que.add(source);

        Map<Integer, Boolean> visited = new HashMap<>();
        visited.put(source, true);

        int distance = 0;
        int farthestNode = source;

        while (!que.isEmpty()) {
            int size = que.size();

            while (size-- > 0) {
                int curr = que.poll();
                farthestNode = curr;

                for (int nbr : adj.getOrDefault(curr, new ArrayList<>())) {
                    if (!visited.getOrDefault(nbr, false)) {
                        visited.put(nbr, true);
                        que.add(nbr);
                    }
                }
            }
            if (!que.isEmpty()) {
                distance++;
            }
        }

        return Arrays.asList(farthestNode, distance);
    }

    public int findDiameter(Map<Integer, List<Integer>> adj) {
        // Step 1: Find the farthest node from a random node (0)
        List<Integer> result1 = BFS(adj, 0);
        int farthestNode = result1.get(0);

        // Step 2: Find the farthest node from the node obtained above
        List<Integer> result2 = BFS(adj, farthestNode);
        return result2.get(1);
    }

    public int minimumDiameterAfterMerge(List<List<Integer>> edges1, List<List<Integer>> edges2) {
        Map<Integer, List<Integer>> adj1 = buildAdj(edges1);
        Map<Integer, List<Integer>> adj2 = buildAdj(edges2);

        int d1 = findDiameter(adj1);
        int d2 = findDiameter(adj2);

        int combined = (d1 + 1) / 2 + (d2 + 1) / 2 + 1;

        return Math.max(Math.max(d1, d2), combined);
    }
}
