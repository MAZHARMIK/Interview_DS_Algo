/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/number-of-ways-to-assign-edge-weights-i
*/

/*********************************************************** C++ **************************************************/
//Approach (DFS to find max depth + Fast Exponentiation)
//T.C : O(n) for DFS + O(log n) for power
//S.C : O(n) for adjacency list + O(n) recursion stack
class Solution {
public:
    static constexpr long long MOD = 1e9 + 7;

    long long power(long long base, long long exponent) {
        if (exponent == 0)
            return 1;

        long long half = power(base, exponent / 2);

        long long result = (half * half) % MOD;

        if (exponent % 2 == 1) {
            result = (result * base) % MOD;
        }

        return result;
    }

    int getMaxDepth(unordered_map<int, vector<int>>& adj, int node, int parent) {

        int depth = 0;

        for (int neighbor : adj[node]) {
            if (neighbor == parent)
                continue;

            depth = max(depth, getMaxDepth(adj, neighbor, node) + 1);
        }

        return depth;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {

        unordered_map<int, vector<int>> adj;

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int maxDepth = getMaxDepth(adj, 1, 0);

        return power(2, maxDepth - 1);
    }
};


/*********************************************************** JAVA **************************************************/
//Approach (DFS to find max depth + Fast Exponentiation)
//T.C : O(n) for DFS + O(log n) for power
//S.C : O(n) for adjacency list + O(n) recursion stack
class Solution {
    static final long MOD = 1_000_000_007L;

    private long power(long base, long exponent) {
        if (exponent == 0)
            return 1;

        long half = power(base, exponent / 2);

        long result = (half * half) % MOD;

        if (exponent % 2 == 1) {
            result = (result * base) % MOD;
        }

        return result;
    }

    private int getMaxDepth(Map<Integer, List<Integer>> adj, int node, int parent) {

        int depth = 0;

        for (int neighbor : adj.getOrDefault(node, new ArrayList<>())) {
            if (neighbor == parent)
                continue;

            depth = Math.max(depth, getMaxDepth(adj, neighbor, node) + 1);
        }

        return depth;
    }

    public int assignEdgeWeights(int[][] edges) {

        Map<Integer, List<Integer>> adj = new HashMap<>();

        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj.computeIfAbsent(u, k -> new ArrayList<>()).add(v);
            adj.computeIfAbsent(v, k -> new ArrayList<>()).add(u);
        }

        int maxDepth = getMaxDepth(adj, 1, 0);

        return (int) power(2, maxDepth - 1);
    }
}
