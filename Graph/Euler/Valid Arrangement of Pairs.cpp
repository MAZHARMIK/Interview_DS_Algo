/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=ElXqjhZoUC0
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/valid-arrangement-of-pairs
*/


/************************************************************ C++ ************************************************/
//Approach - Hierholzer's Algorithm to find Euler Path
//T.C : O(V+E) for normal DFS
//S.C : O(V+E)
class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        //Step-1 Build adjacency list - Graph
        unordered_map<int, vector<int>> adj;
        
        //build  indegree and outdegree
        unordered_map<int, int> indegree, outdegree;
        //key - node
        //value - indegree/outdegree

        for(auto& edge : pairs) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v); //u --> v
            outdegree[u]++;
            indegree[v]++;
        }

        //Find the startNode of the Euler Path
        int startNode = pairs[0][0];
        for(auto &it :  adj) {
            int node = it.first;
            if(outdegree[node] - indegree[node] == 1) {
                startNode = node;
                break;
            }
        }

        //Simply do the Khandani DFS
        vector<int> EulerPath; //to store my eulerpath
        stack<int> st; //to perform dfs
        st.push(startNode);

        while(!st.empty()) {
            int curr = st.top();
            if(!adj[curr].empty()) {
                int ngbr = adj[curr].back();
                adj[curr].pop_back();
                st.push(ngbr);
            } else {
                EulerPath.push_back(curr);
                st.pop();
            }
        }


        //Build your result
        reverse(begin(EulerPath), end(EulerPath));
        vector<vector<int>> result;
        for(int i = 0; i < EulerPath.size()-1; i++) {
            result.push_back({EulerPath[i], EulerPath[i+1]});
        }

        return result;
    }
};



/************************************************************ JAVA ************************************************/
//Approach - Hierholzer's Algorithm to find Euler Path
//T.C : O(V+E) for normal DFS
//S.C : O(V+E)
class Solution {
    public int[][] validArrangement(int[][] pairs) {
        // Step-1: Build adjacency list - Graph
        Map<Integer, List<Integer>> adj = new HashMap<>();
        
        // Build indegree and outdegree
        Map<Integer, Integer> indegree = new HashMap<>();
        Map<Integer, Integer> outdegree = new HashMap<>();

        // Build the graph and calculate indegree/outdegree
        for (int[] edge : pairs) {
            int u = edge[0];
            int v = edge[1];
            
            adj.computeIfAbsent(u, k -> new ArrayList<>()).add(v);
            outdegree.put(u, outdegree.getOrDefault(u, 0) + 1);
            indegree.put(v, indegree.getOrDefault(v, 0) + 1);
        }

        // Step-2: Find the start node of the Euler Path
        int startNode = pairs[0][0];
        for (int node : adj.keySet()) {
            if (outdegree.getOrDefault(node, 0) - indegree.getOrDefault(node, 0) == 1) {
                startNode = node;
                break;
            }
        }

        // Step-3: Perform DFS to find the Euler Path
        List<Integer> eulerPath = new ArrayList<>();
        Stack<Integer> stack = new Stack<>();
        stack.push(startNode);

        while (!stack.isEmpty()) {
            int curr = stack.peek();
            if (adj.containsKey(curr) && !adj.get(curr).isEmpty()) {
                int neighbor = adj.get(curr).remove(adj.get(curr).size() - 1);
                stack.push(neighbor);
            } else {
                eulerPath.add(curr);
                stack.pop();
            }
        }

        // Step-4: Build the result from the Euler path
        Collections.reverse(eulerPath);
        int[][] result = new int[eulerPath.size() - 1][2];
        for (int i = 0; i < eulerPath.size() - 1; i++) {
            result[i][0] = eulerPath.get(i);
            result[i][1] = eulerPath.get(i + 1);
        }

        return result;
    }
}
