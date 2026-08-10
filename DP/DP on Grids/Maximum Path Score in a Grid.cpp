/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=S8ETOX9njRQ
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/maximum-path-score-in-a-grid
*/



/**************************************************************** C++ ****************************************************************/
//Approach-1 (Recursion + Memoization)
//T.C : O(m*n*k)
//S.C : O(m*n*k)
class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> t(
            m+1, vector<vector<int>>(n+1, vector<int>(k + 1, -1))
        );

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                for (int cost = k; cost >= 0; cost--) {

                    int newCost = cost + (grid[i][j] > 0); // Please change in c++ also

                    if (newCost > k) continue;

                    // Base case: destination
                    if (i == m - 1 && j == n - 1) {
                        t[i][j][cost] = grid[i][j];
                        continue;
                    }

                    int down  = -1;
                    int right = -1;

                    if (i + 1 < m)
                        down = t[i + 1][j][newCost];

                    if (j + 1 < n)
                        right = t[i][j + 1][newCost];

                    int bestNext = max(down, right);

                    if (bestNext != -1) {
                        t[i][j][cost] = grid[i][j] + bestNext;
                    }
                }
            }
        }

        return t[0][0][0];
    }
};


//Approach-2 (Bottom Up)
//T.C : O(m*n*k)
//S.C : O(m*n*k)
class Solution {
public:
    int m, n;

    int solve(vector<vector<int>>& grid, int k, int i, int j, int cost, vector<vector<vector<int>>>& t) {
        if(i >= m || j >= n)
            return INT_MIN;
        
        int newCost = cost + (grid[i][j] > 0); // Please change in c++ also

        if(newCost > k)
            return INT_MIN;
        
        if(i == m-1 && j == n-1)
            return grid[i][j]; //score
        
        if(t[i][j][cost] != -1) {
            return t[i][j][cost];
        }
        
        //down
        //right
        int down  = solve(grid, k, i+1, j, newCost, t);
        int right = solve(grid, k, i, j+1, newCost, t);

        int bestNext = max(down, right);

        if(bestNext == INT_MIN) {
            return t[i][j][cost] = INT_MIN;
        }

        return t[i][j][cost] = grid[i][j] + bestNext;
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<vector<int>>> t(m+1, vector<vector<int>>(n+1, vector<int>(k + 1, -1)));

        int result = solve(grid, k, 0, 0, 0, t);

        return result == INT_MIN ? -1 : result;
    }
};



/**************************************************************** JAVA ****************************************************************/
//Approach-1 (Recursion + Memoization)
//T.C : O(m*n*k)
//S.C : O(m*n*k)
class Solution {
    public int maxPathScore(int[][] grid, int k) {
        int m = grid.length;
        int n = grid[0].length;

        int[][][] dp = new int[m + 1][n + 1][k + 1];

        // initialize with -1 (invalid state)
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                for (int c = 0; c <= k; c++) {
                    dp[i][j][c] = -1;
                }
            }
        }

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                for (int cost = k; cost >= 0; cost--) {

                    int newCost = cost + (grid[i][j] > 0);  // Not like this - Missing conditional operator sysntax
        int newCost = cost + (grid[i][j] > 0 ? 1 : 0);  // It should be like this 

                    if (newCost > k) continue;

                    // base case
                    if (i == m - 1 && j == n - 1) {
                        dp[i][j][cost] = grid[i][j];
                        continue;
                    }

                    int down = -1, right = -1;

                    if (i + 1 < m)
                        down = dp[i + 1][j][newCost];

                    if (j + 1 < n)
                        right = dp[i][j + 1][newCost];

                    int bestNext = Math.max(down, right);

                    if (bestNext != -1) {
                        dp[i][j][cost] = grid[i][j] + bestNext;
                    }
                }
            }
        }

        return dp[0][0][0];
    }
}


//Approach-2 (Bottom Up)
//T.C : O(m*n*k)
//S.C : O(m*n*k)
class Solution {

    int m, n;
    int[][][] dp;

    public int solve(int[][] grid, int k, int i, int j, int cost) {

        if (i >= m || j >= n) return Integer.MIN_VALUE;

        int newCost = cost + (grid[i][j] > 0);  // Not like this - Missing conditional operator sysntax
        int newCost = cost + (grid[i][j] > 0 ? 1 : 0);  // It should be like this 

        if (newCost > k) return Integer.MIN_VALUE;

        if (i == m - 1 && j == n - 1) {
            return grid[i][j];
        }

        if (dp[i][j][cost] != Integer.MIN_VALUE) {
            return dp[i][j][cost];
        }

        int down = solve(grid, k, i + 1, j, newCost);
        int right = solve(grid, k, i, j + 1, newCost);

        int bestNext = Math.max(down, right);

        if (bestNext == Integer.MIN_VALUE) {
            return dp[i][j][cost] = Integer.MIN_VALUE;
        }

        return dp[i][j][cost] = grid[i][j] + bestNext;
    }

    public int maxPathScore(int[][] grid, int k) {
        m = grid.length;
        n = grid[0].length;

        dp = new int[m][n][k + 1];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int c = 0; c <= k; c++) {
                    dp[i][j][c] = Integer.MIN_VALUE;
                }
            }
        }

        int res = solve(grid, k, 0, 0, 0);

        return res == Integer.MIN_VALUE ? -1 : res;
    }
}
