/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/minimum-score-after-removals-on-a-tree
*/


/************************************************************ C++ ************************************************/
//Approach - Using DFS
//T.C : O(n^2)
//S.C : O(V+E), V = number of vertices and E = number of edges
class Solution {
public:
    void dfs(int node, int par, vector<int>& xorFromRoot,
            vector<int>& parent, vector<int>& inTime, vector<int>& outTime,
            int& timer, vector<int>& nums, unordered_map<int, vector<int>>& adj) {

        xorFromRoot[node] = nums[node];
        parent[node] = par;
        inTime[node] = timer++;
        for (int ngbr : adj[node]) {
            if (ngbr != par) {
                dfs(ngbr, node, xorFromRoot, parent, inTime, outTime, timer, nums, adj);
                xorFromRoot[node] ^= xorFromRoot[ngbr];
            }
        }
        outTime[node] = timer++;
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        unordered_map<int, vector<int>> adj;
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> xorFromRoot(n, 0);
        vector<int> parent(n, -1);

        //Using time, to find ancestor
        vector<int> inTime(n, 0);
        vector<int> outTime(n, 0);
        int timer = 0;

        dfs(0, -1, xorFromRoot, parent, inTime, outTime, timer, nums, adj);

        //To check if v is descendant of u or not (i.e. if u is an ancestor of v)
        auto isDescendant = [&](int u, int v) {
            return inTime[v] >= inTime[u] && outTime[v] <= outTime[u];
        };

        auto getScore = [](int a, int b, int c) {
            int maxXor = max({a, b, c});
            int minXor = min({a, b, c});
            return maxXor - minXor;
        };

        int result = INT_MAX;
        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int x, y, z;
                if (isDescendant(i, j)) {
                    x = xorFromRoot[j];
                    y = xorFromRoot[i] ^ xorFromRoot[j];
                    z = xorFromRoot[0] ^ xorFromRoot[i];
                } else if (isDescendant(j, i)) {
                    x = xorFromRoot[i];
                    y = xorFromRoot[j] ^ xorFromRoot[i];
                    z = xorFromRoot[0] ^ xorFromRoot[j];
                } else {
                    x = xorFromRoot[i];
                    y = xorFromRoot[j];
                    z = xorFromRoot[0] ^ x ^ y;
                }

                result = min(result, getScore(x, y, z));
            }
        }
        return result;
    }
};


/************************************************************ JAVA ******************************************************/
//Approach - Using DFS
//T.C : O(n^2)
//S.C : O(V+E), V = number of vertices and E = number of edges
class Solution {
    public int minimumScore(int[] nums, int[][] edges) {
        int n = nums.length;
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }
        for (int[] edge : edges) {
            adj.get(edge[0]).add(edge[1]);
            adj.get(edge[1]).add(edge[0]);
        }

        int[] xorFromRoot = new int[n];
        int[] parent = new int[n];
        int[] inTime = new int[n];
        int[] outTime = new int[n];
        int[] timer = new int[1]; // Using array to mimic pass-by-reference

        dfs(0, -1, xorFromRoot, parent, inTime, outTime, timer, nums, adj);

        int result = Integer.MAX_VALUE;

        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int x, y, z;
                if (isDescendant(i, j, inTime, outTime)) {
                    x = xorFromRoot[j];
                    y = xorFromRoot[i] ^ xorFromRoot[j];
                    z = xorFromRoot[0] ^ xorFromRoot[i];
                } else if (isDescendant(j, i, inTime, outTime)) {
                    x = xorFromRoot[i];
                    y = xorFromRoot[j] ^ xorFromRoot[i];
                    z = xorFromRoot[0] ^ xorFromRoot[j];
                } else {
                    x = xorFromRoot[i];
                    y = xorFromRoot[j];
                    z = xorFromRoot[0] ^ x ^ y;
                }

                int maxXor = Math.max(x, Math.max(y, z));
                int minXor = Math.min(x, Math.min(y, z));
                result = Math.min(result, maxXor - minXor);
            }
        }

        return result;
    }

    private void dfs(int node, int par, int[] xorFromRoot, int[] parent,
                     int[] inTime, int[] outTime, int[] timer, int[] nums, List<List<Integer>> adj) {
        xorFromRoot[node] = nums[node];
        parent[node] = par;
        inTime[node] = timer[0]++;
        for (int ngbr : adj.get(node)) {
            if (ngbr != par) {
                dfs(ngbr, node, xorFromRoot, parent, inTime, outTime, timer, nums, adj);
                xorFromRoot[node] ^= xorFromRoot[ngbr];
            }
        }
        outTime[node] = timer[0]++;
    }

    private boolean isDescendant(int u, int v, int[] inTime, int[] outTime) {
        return inTime[v] >= inTime[u] && outTime[v] <= outTime[u];
    }
}
