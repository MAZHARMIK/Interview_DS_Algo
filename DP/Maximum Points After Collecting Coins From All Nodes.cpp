/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=kJUhjb0K4_M
    Company Tags                : Soon I will update
    Leetcode Link               : https://leetcode.com/problems/maximum-points-after-collecting-coins-from-all-nodes/
*/

/**************************************************************** C++ ****************************************************************/
//Approach-1 (Using Recursion + Memoization of 3 parameters - 3D Memoization)
//T.C : O(V+E) - Just traversing the Graph using DFS
//S.C : O(V + E + V^2) -> V^2 comes from size of 't' - O(V * V * 14) = O(V^2)
class Solution {
private:
    unordered_map<int, unordered_map<int, unordered_map<int, int>>> t;

    int dfs(int i, int parent, int k, int power, const vector<int> &coins, unordered_map<int, vector<int>>& adj) {
        if (power >= 14) 
          return 0;

        //cout << "State = " << i << ",  " << parent << ", " << power << endl;
      
        if (t.count(i) && t[i].count(parent) && t[i][parent].count(power)) {
            return t[i][parent][power];
        }

        int case1 = (coins[i] >> power) - k;
        int case2 = coins[i] >> (power + 1);

        for (int j : adj[i]) {
            if (j != parent) {
                case1 += dfs(j, i, k, power, coins, adj);
                case2 += dfs(j, i, k, power + 1, coins, adj);
            }
        }

        int result = max(case1, case2);
        t[i][parent][power] = result;
        return result;
    }

public:
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        int n = coins.size();
        unordered_map<int, vector<int>> adj(n);
        for (vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return dfs(0, -1, k, 0, coins, adj);
    }
};

/*
  I have printed all the states (i, parent, power) of every recursive call for a test case
  edges = [[0,1],[1,2],[2,3]], coins = [10,10,3,3], k = 5
  
  State = 0,  -1, 0
  State = 1,  0, 0
  State = 2,  1, 0
  State = 3,  2, 0
  State = 3,  2, 1 <-------
  State = 2,  1, 1
  State = 3,  2, 1 <-------
  State = 3,  2, 2 <-------
  State = 1,  0, 1
  State = 2,  1, 1
  State = 2,  1, 2
  State = 3,  2, 2 <-------
  State = 3,  2, 3

  If you notice, i and power itself can uniquely identify the state of a recursive call.
  Noteice whenever i and power are same for any ther recursive call, then parent is always same (which is obvious - Parent for a node will never change)
  Example : 
  State = 3,  2, 1
  State = 3,  2, 1
  Or, 
  State = 3,  2, 2
  State = 3,  2, 2

  So, you can skip parent in memoization map. You can simply use 2-d array to memoize.
*/

//Approach-2 (Using Recursion + Memoization of 2 parameters - 2D Memoization)
//T.C : O(V+E) - Just traversing the Graph using DFS
//S.C : O(V + E) - adj
class Solution {
private:
    int t[100001][14];

    int dfs(int i, int parent, int k, int power, const vector<int> &coins, unordered_map<int, vector<int>>& adj) {
        if (power >= 14) 
            return 0;

        if(t[i][power] != -1) {
            return t[i][power];
        }

        int case1 = (coins[i] >> power) - k;
        int case2 = coins[i] >> (power + 1);

        for (int j : adj[i]) {
            if (j != parent) {
                case1 += dfs(j, i, k, power, coins, adj);
                case2 += dfs(j, i, k, power + 1, coins, adj);
            }
        }

        int result = max(case1, case2);
        return t[i][power] = result;
    }

public:
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        int n = coins.size();
        memset(t, -1, sizeof(t));
        unordered_map<int, vector<int>> adj(n);
        for (vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return dfs(0, -1, k, 0, coins, adj);
    }
};


/**************************************************************** JAVA ****************************************************************/
//Approach-2 (Using Recursion + Memoization of 2 parameters - 2D Memoization)
//T.C : O(V+E) - Just traversing the Graph using DFS
//S.C : O(V + E) - adj
class Solution {
    int N;
    List<Integer>[] G;
    Integer dp[][];
    public int maximumPoints(int[][] edges, int[] coins, int k) {
        N = coins.length; 
        G = new ArrayList[N];
        dp = new Integer[N+1][14];
        for (int i = 0; i < N; i++) {
            G[i] = new ArrayList<>();
        }
        for (int[] e : edges) {
            G[e[0]].add(e[1]);
            G[e[1]].add(e[0]);
        }
        
        return getMax(0, -1, 0, coins, k);
    }
    
    public int getMax(int i, int parent, int pow, int[] coins, int k) {
        if (pow >= 14) {
            return 0;
        }
        if  (dp[i][pow] != null) {
            return dp[i][pow];
        }
        
        int res1 = (coins[i] >> pow) - k;
        int res2 = (int)Math.floor((coins[i] >> (pow+1)));
        for (int u : G[i]) {
            if (u == parent) {
                continue;
            }
            res1 += getMax(u, i, pow, coins, k);
            res2 += getMax(u, i, pow+1, coins, k);
        }

        return dp[i][pow] = Math.max(res1, res2);
    }
}
