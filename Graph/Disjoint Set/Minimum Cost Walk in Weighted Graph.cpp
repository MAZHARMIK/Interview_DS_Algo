/*       Scroll below to see JAVA code also     */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=B3Wgf-g6i-k
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/minimum-cost-walk-in-weighted-graph/
*/

/******************************************************************* C++ ****************************************************/
//T.C : 
/*
    The time complexity of the union-find operations (with path compression) is approximately O(α(n)), 
    where α is the inverse Ackermann function, which is practically constant for all reasonable values of n.
    The time complexity of processing each edge and each query is O(1).
    Therefore, the overall time complexity of the algorithm is O(E + Qα(n)), where E is the number of edges, 
    Q is the number of queries, and α(n) is the inverse Ackermann function.
*/
//S.C : O(n)
class Solution {
public:

    vector<int> parent;
    int find(int x) {
        if(parent[x] == x)
            return x;
        
        return parent[x] = find(parent[x]);
    }
    void Union(int x, int y) {
        parent[y] = x;
    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        
        parent.resize(n);
        vector<int> cost(n);  //Store "And operation" cost of each component
	    
	    for(int i = 0; i<n; i++) {
	        parent[i] = i;
            cost[i]   = -1;
        }
        
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            int parent_u = find(u);
            int parent_v = find(v);
            

            if (parent_u != parent_v) {
                cost[parent_u] &= cost[parent_v];
                Union(parent_u, parent_v);
            }

            cost[parent_u] &= w;
        }
        
        vector<int> res;
        for (auto &q : query) {
            int s = q[0];
            int t = q[1];
            
            int p1 = find(s);
            int p2 = find(t);
            
            if (s == t)
                res.push_back(0);
            else if (p1 != p2)
                res.push_back(-1);
            else
                res.push_back(cost[p1]);
        }
        return res;
    }
};



/******************************************************************* JAVA ****************************************************/
class Solution {
    public int[] minimumCost(int n, int[][] edges, int[][] query) {
        int[] parent = new int[n];
        int[] cost = new int[n];
        Arrays.fill(cost, -1);
        int[] result = new int[query.length];
        
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        
        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            int parent_u = find(u, parent);
            int parent_v = find(v, parent);
            
            if (parent_u != parent_v) {
                cost[parent_u] &= cost[parent_v];
                union(parent_u, parent_v, parent);
            }
            
            cost[parent_u] &= w;
        }
        
        for (int i = 0; i < query.length; i++) {
            int s = query[i][0];
            int t = query[i][1];
            
            int p1 = find(s, parent);
            int p2 = find(t, parent);
            
            if (s == t)
                result[i] = 0;
            else if (p1 != p2)
                result[i] = -1;
            else
                result[i] = cost[p1];
        }
        
        return result;
    }
    
    private int find(int x, int[] parent) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x], parent);
    }
    
    private void union(int x, int y, int[] parent) {
        parent[y] = x;
    }
}
