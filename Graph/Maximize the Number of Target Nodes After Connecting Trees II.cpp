/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-ii
*/



/****************************************************************** C++ ******************************************************************/
//Approach (Using DFS and Marking Nodes)
//T.C : O(V+E)
//S.C : O(V+E)
class Solution {
public:
    unordered_map<int, vector<int>> getAdj(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return adj;
    }

    //O(V+E)
    void dfs(int curr, unordered_map<int, vector<int>>& adj, int parent, vector<int>& mark, 
        int &zeroMarkedCount, int& oneMarkedCount) {

        if(mark[curr] == 0) {
            zeroMarkedCount++;
        } else {
            oneMarkedCount++;
        }

        for(auto &ngbr : adj[curr]) {
            if(ngbr != parent) {
                mark[ngbr] = (mark[curr] == 0) ? 1 : 0; //alternate marking
                dfs(ngbr, adj, curr, mark, zeroMarkedCount, oneMarkedCount);
            }
        }
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int N = edges1.size()+1; // Tree A
        int M = edges2.size()+1; // Tree B

        unordered_map<int, vector<int>> adjA = getAdj(edges1); //O(V1+E1)
        unordered_map<int, vector<int>> adjB = getAdj(edges2); //O(V2+E2)

        vector<int> markA(N, -1);
        markA[0] = 0; //mark 0th node as 0
        int zeroMarkedCountA = 0;
        int oneMarkedCountA  = 0;
        dfs(0, adjA, -1, markA, zeroMarkedCountA, oneMarkedCountA); //O(V+E)


        vector<int> markB(M, -1);
        markB[0] = 0; //mark 0th node as 0
        int zeroMarkedCountB = 0;
        int oneMarkedCountB  = 0;
        dfs(0, adjB, -1, markB, zeroMarkedCountB, oneMarkedCountB); //O(V+E)

        int maxFromTree2 = max(zeroMarkedCountB, oneMarkedCountB);

        vector<int> result(N);
        for(int i = 0; i < N; i++) { //O(V)
            result[i] = (markA[i] == 0 ? zeroMarkedCountA : oneMarkedCountA) + maxFromTree2;
        }

        return result;

        
    }
};



/****************************************************************** JAVA ******************************************************************/
//Approach (Using DFS and Marking Nodes)
//T.C : O(V+E)
//S.C : O(V+E)
class Solution {

    public Map<Integer, List<Integer>> getAdj(int[][] edges) {
        Map<Integer, List<Integer>> adj = new HashMap<>();
        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj.putIfAbsent(u, new ArrayList<>());
            adj.putIfAbsent(v, new ArrayList<>());

            adj.get(u).add(v);
            adj.get(v).add(u);
        }
        return adj;
    }

    // DFS to color/mark the graph in two groups: 0 and 1
    private void dfs(int curr, Map<Integer, List<Integer>> adj, int parent,
                     int[] mark, int[] count) {
        if (mark[curr] == 0) {
            count[0]++; // zeroMarkedCount
        } else {
            count[1]++; // oneMarkedCount
        }

        for (int neighbor : adj.getOrDefault(curr, new ArrayList<>())) {
            if (neighbor != parent) {
                mark[neighbor] = (mark[curr] == 0) ? 1 : 0;
                dfs(neighbor, adj, curr, mark, count);
            }
        }
    }

    public int[] maxTargetNodes(int[][] edges1, int[][] edges2) {
        int N = edges1.length + 1; // number of nodes in Tree 1
        int M = edges2.length + 1; // number of nodes in Tree 2

        Map<Integer, List<Integer>> adjA = getAdj(edges1);
        Map<Integer, List<Integer>> adjB = getAdj(edges2);

        int[] markA = new int[N];
        Arrays.fill(markA, -1);
        markA[0] = 0;
        int[] countA = new int[2]; // countA[0] = zeroMarkedCount, countA[1] = oneMarkedCount
        dfs(0, adjA, -1, markA, countA);

        int[] markB = new int[M];
        Arrays.fill(markB, -1);
        markB[0] = 0;
        int[] countB = new int[2];
        dfs(0, adjB, -1, markB, countB);

        int maxFromTree2 = Math.max(countB[0], countB[1]);

        int[] result = new int[N];
        for (int i = 0; i < N; i++) {
            result[i] = (markA[i] == 0 ? countA[0] : countA[1]) + maxFromTree2;
        }

        return result;
    }
}
