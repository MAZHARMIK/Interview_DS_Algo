/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=RnFCrjkkIUE
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/maximum-number-of-k-divisible-components
*/



/****************************************************************** C++ ******************************************************************/
//Approach (Using DFS) - You can easily replace DFS with BFS as well
//T.C : O(n) - We visit all nodes once
//S.C : O(n-1) ~ O(n) - We store edges in the adjacency list
class Solution {
public:
    int count = 0;
    int dfs(int curr, int parent,
            unordered_map<int, vector<int>> &adj,
            vector<int> &values, int k) {
        

        int sum = 0;

        for (int &ngbr : adj[curr]) {
            if (ngbr != parent) {
                sum += dfs(ngbr, curr, adj, values, k);
                sum %= k;
            }
        }

        sum += values[curr];
        sum %= k;

        if (sum == 0) 
            count++;

        return sum;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>> &edges,
                                vector<int> &values, int k) {

        unordered_map<int, vector<int>> adj;
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        count = 0;

        dfs(0, -1, adj, values, k);

        return count;
    }
};



/****************************************************************** JAVA ******************************************************************/
//Approach (Using DFS) - You can easily replace DFS with BFS as well
//T.C : O(n) - We visit all nodes once
//S.C : O(n-1) ~ O(n) - We store edges in the adjacency list
import java.util.*;

class Solution {
    int count = 0;

    private int dfs(int curr, int parent,
                    Map<Integer, List<Integer>> adj,
                    int[] values, int k) {

        int sum = 0;

        for (int ngbr : adj.get(curr)) {
            if (ngbr != parent) {
                sum += dfs(ngbr, curr, adj, values, k);
                sum %= k;
            }
        }

        sum += values[curr];
        sum %= k;

        if (sum == 0)
            count++;

        return sum;
    }

    public int maxKDivisibleComponents(int n, int[][] edges, int[] values, int k) {

        Map<Integer, List<Integer>> adj = new HashMap<>();

        // initialize adjacency lists
        for (int i = 0; i < n; i++) {
            adj.put(i, new ArrayList<>());
        }

        // build graph
        for (int[] e : edges) {
            int u = e[0];
            int v = e[1];
            adj.get(u).add(v);
            adj.get(v).add(u);
        }

        count = 0;

        dfs(0, -1, adj, values, k);

        return count;
    }
}
