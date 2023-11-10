/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=aRsdEts7i0k
    Company Tags                : will soon update
    Leetcode Link               : https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/
*/

/**************************************************************** C++ ****************************************************************/
//Using simple DFS in map(adjaceny list)
//T.C : O(n) - Visiting all n nodes once.
//S.C : O(n) - stored in map
class Solution {
public:
    vector<int> result;
    
    void solve(int u, int prev, unordered_map<int, vector<int>> &adj) {
        
        result.push_back(u);
        
        for(int &v : adj[u]) {
            if(v != prev) {
                solve(v, u, adj);
            }
        }
        
    }
    
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> adj;
        
        for(vector<int> &vec : adjacentPairs) {
            
            int u = vec[0];
            int v = vec[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int startPoint = -1;
        
        for(auto &it : adj) {
            if(it.second.size() == 1) {
                startPoint = it.first;
                break;
            }
        }
        
        solve(startPoint, INT_MIN, adj);
        
        return result;
        
    }
};


/**************************************************************** JAVA ****************************************************************/
//Using simple DFS in map(adjaceny list)
//T.C : O(n) - Visiting all n nodes once.
//S.C : O(n) - stored in map
public class Solution {
    Map<Integer, List<Integer>> adj = new HashMap<>();

    public int[] restoreArray(int[][] adjacentPairs) {
        for (int[] edge : adjacentPairs) {
            int x = edge[0];
            int y = edge[1];

            adj.computeIfAbsent(x, k -> new ArrayList<>()).add(y);
            adj.computeIfAbsent(y, k -> new ArrayList<>()).add(x);
        }

        int root = 0;
        for (int num : adj.keySet()) {
            if (adj.get(num).size() == 1) {
                root = num;
                break;
            }
        }

        int[] result = new int[adj.size()];
        dfs(root, Integer.MAX_VALUE, result, 0);
        return result;
    }

    private void dfs(int node, int prev, int[] result, int i) {
        result[i] = node;
        for (int neighbor : adj.get(node)) {
            if (neighbor != prev) {
                dfs(neighbor, node, result, i + 1);
            }
        }
    }
}
