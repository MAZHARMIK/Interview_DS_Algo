/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/find-subtree-sizes-after-changes
*/


/****************************************************** C++ ***************************************************/
//Approach (DFS)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    unordered_map<int, vector<int>> adj;
    vector<int> resultSize;
    vector<int> last;

    void dfs(int currNode, string& s, vector<int>& parent) {
        int c = s[currNode] - 'a';

        int above = last[c];

        last[c] = currNode;

        for (int child : adj[currNode])
            dfs(child, s, parent);

        last[c] = above;

        if (currNode != 0) {
            int newParent = parent[currNode];

            if (above != -1)
                newParent = above;

            resultSize[newParent] += resultSize[currNode];
        }
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        for (int i = 1; i < n; i++) {
            int u = parent[i];
            int v = i;
            adj[u].push_back(v);
        }

        resultSize.assign(n, 1);
        last.assign(26, -1);

        dfs(0, s, parent);
        
        return resultSize;
    }
};


/****************************************************** JAVA ***************************************************/
//Approach (DFS)
//T.C : O(n)
//S.C : O(n)
class Solution {
    private Map<Integer, List<Integer>> adj = new HashMap<>();
    private int[] resultSize;
    private int[] last;

    private void dfs(int currNode, String s, int[] parent) {
        int c = s.charAt(currNode) - 'a';

        int above = last[c];

        last[c] = currNode;

        for (int child : adj.getOrDefault(currNode, Collections.emptyList()))
            dfs(child, s, parent);

        last[c] = above;

        if (currNode != 0) {
            int newParent = parent[currNode];

            if (above != -1)
                newParent = above;

            resultSize[newParent] += resultSize[currNode];
        }
    }

    public int[] findSubtreeSizes(int[] parent, String s) {
        int n = parent.length;

        for (int i = 1; i < n; i++) {
            int u = parent[i];
            int v = i;
            adj.computeIfAbsent(u, k -> new ArrayList<>()).add(v);
        }

        resultSize = new int[n];
        Arrays.fill(resultSize, 1);

        last = new int[26];
        Arrays.fill(last, -1);

        dfs(0, s, parent);

        return resultSize;
    }
}
