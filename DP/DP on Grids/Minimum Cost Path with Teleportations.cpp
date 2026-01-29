/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : coming soon
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/minimum-cost-path-with-teleportations
*/



/**************************************************************** C++ ****************************************************************/
//Approach-1 (Recursion + Memoization)
//T.C : O(m^2 * n^2 * k)
//S.C : O(m*n*k)
class Solution {
public:
    int m, n, K;

    // t[i][j][tPort] = min cost from (i,j) with tPort teleports already used
    vector<vector<vector<int>>> t;

    int solve(int i, int j, int tPort, vector<vector<int>>& grid) {
        // Reached destination
        if (i == m - 1 && j == n - 1)
            return 0;

        if (t[i][j][tPort] != -1) 
            return t[i][j][tPort];

        int result = 1e9; //Large value
        int curVal = grid[i][j];

        // Move Right
        if (j + 1 < n) {
            int next = solve(i, j + 1, tPort, grid);
            result = min(result, grid[i][j + 1] + next);
        }

        // Move Down
        if (i + 1 < m) {
            int next = solve(i + 1, j, tPort, grid);
            result = min(result, grid[i + 1][j] + next);
        }

        // Teleport
        if (tPort < K) {
            for (int x = 0; x < m; x++) {
                for (int y = 0; y < n; y++) {
                    if ((x != i || y != j) && grid[x][y] <= curVal) {
                        result = min(result, solve(x, y, tPort + 1, grid)); // cost = 0
                    }
                }
            }
        }

        return t[i][j][tPort] = result;
    }

    int minCost(vector<vector<int>>& grid, int k) {
        K = k;
        m = grid.size();
        n = grid[0].size();

        t.assign(m, vector<vector<int>>(n, vector<int>(K + 1, -1)));

        return solve(0, 0, 0, grid);
    }
};



//Approach-2 (Bottom Up)
//T.C : O(m^2 * n^2 * k)
//S.C : O(m*n*k)
class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        const int INF = 1e9;

        // t[i][j][tPort] = min cost from (i,j) with tPort teleports already used
        vector<vector<vector<int>>> t(
            m, vector<vector<int>>(n, vector<int>(k + 1, INF))
        );

        // Base case: destination
        for (int tPort = 0; tPort <= k; tPort++) {
            t[m - 1][n - 1][tPort] = 0;
        }

        // Fill teleport layers from back to front
        for (int tPort = k; tPort >= 0; tPort--) {
            for (int i = m - 1; i >= 0; i--) {
                for (int j = n - 1; j >= 0; j--) {

                    if (i == m - 1 && j == n - 1)
                        continue;

                    int result = 1e9;

                    // Right
                    if (j + 1 < n) {
                        result = min(result,
                                     grid[i][j + 1] + t[i][j + 1][tPort]);
                    }

                    // Down
                    if (i + 1 < m) {
                        result = min(result,
                                     grid[i + 1][j] + t[i + 1][j][tPort]);
                    }

                    // Teleport
                    if (tPort < k) {
                        for (int x = 0; x < m; x++) {
                            for (int y = 0; y < n; y++) {
                                if ((x != i || y != j) && grid[x][y] <= grid[i][j]) {
                                    result = min(result, t[x][y][tPort + 1]);
                                }
                            }
                        }
                    }

                    t[i][j][tPort] = result;
                }
            }
        }

        return t[0][0][0];
    }
};



//Approach-3 (Bottom Up with Layered DP for optimization)
//T.C : O(m*n*k)
//S.C : O(m*n*k)
class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        dp[m-1][n-1] = 0;

        int maxVal = 0;
        for(auto &row : grid) {
            for(int &val : row) {
                maxVal = max(maxVal, val);
            }
        }

        vector<int> teleportCost(maxVal+1, INT_MAX);

        for(int t = 0; t <= k; t++) {

            for(int i = m-1; i >= 0; i--) {
                for(int j = n-1; j >= 0; j--) {

                    if(i+1 < m)
                        dp[i][j] = min(dp[i][j], grid[i+1][j] + dp[i+1][j]);
                    
                    if(j+1 < n)
                        dp[i][j] = min(dp[i][j], grid[i][j+1] + dp[i][j+1]);

                    if(t > 0) {
                        dp[i][j] = min(dp[i][j], teleportCost[grid[i][j]]);
                    }
                }
            }

            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    teleportCost[grid[i][j]] = min(teleportCost[grid[i][j]], dp[i][j]);
                }
            }

            for(int i = 1; i < teleportCost.size(); i++) {
                teleportCost[i] = min(teleportCost[i], teleportCost[i-1]);
            }
        }

        return dp[0][0];
    }
};



/**************************************************************** JAVA ****************************************************************/
//Approach-1 (Recursion + Memoization)
//T.C : O(m^2 * n^2 * k)
//S.C : O(m*n*k)
class Solution {
    int m, n, K;
    int[][][] t;
    final int INF = (int)1e9;

    private int solve(int i, int j, int tPort, int[][] grid) {
        if (i == m - 1 && j == n - 1)
            return 0;

        if (t[i][j][tPort] != -1)
            return t[i][j][tPort];

        int result = INF;
        int curVal = grid[i][j];

        // Move Right
        if (j + 1 < n) {
            int next = solve(i, j + 1, tPort, grid);
            result = Math.min(result, grid[i][j + 1] + next);
        }

        // Move Down
        if (i + 1 < m) {
            int next = solve(i + 1, j, tPort, grid);
            result = Math.min(result, grid[i + 1][j] + next);
        }

        // Teleport
        if (tPort < K) {
            for (int x = 0; x < m; x++) {
                for (int y = 0; y < n; y++) {
                    if ((x != i || y != j) && grid[x][y] <= curVal) {
                        result = Math.min(result, solve(x, y, tPort + 1, grid));
                    }
                }
            }
        }

        return t[i][j][tPort] = result;
    }

    public int minCost(int[][] grid, int k) {
        m = grid.length;
        n = grid[0].length;
        K = k;

        t = new int[m][n][K + 1];
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                for (int tp = 0; tp <= K; tp++)
                    t[i][j][tp] = -1;

        return solve(0, 0, 0, grid);
    }
}


// T.C : O(m^2 * n^2 * k)
// S.C : O(m*n*k)
class Solution {
    public int minCost(int[][] grid, int k) {
        int m = grid.length;
        int n = grid[0].length;
        int INF = (int)1e9;

        int[][][] t = new int[m][n][k + 1];

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                for (int tp = 0; tp <= k; tp++)
                    t[i][j][tp] = INF;

        for (int tp = 0; tp <= k; tp++)
            t[m - 1][n - 1][tp] = 0;

        for (int tPort = k; tPort >= 0; tPort--) {
            for (int i = m - 1; i >= 0; i--) {
                for (int j = n - 1; j >= 0; j--) {

                    if (i == m - 1 && j == n - 1) continue;

                    int result = INF;

                    // Right
                    if (j + 1 < n)
                        result = Math.min(result,
                                grid[i][j + 1] + t[i][j + 1][tPort]);

                    // Down
                    if (i + 1 < m)
                        result = Math.min(result,
                                grid[i + 1][j] + t[i + 1][j][tPort]);

                    // Teleport
                    if (tPort < k) {
                        int curVal = grid[i][j];
                        for (int x = 0; x < m; x++) {
                            for (int y = 0; y < n; y++) {
                                if ((x != i || y != j) && grid[x][y] <= curVal) {
                                    result = Math.min(result, t[x][y][tPort + 1]);
                                }
                            }
                        }
                    }

                    t[i][j][tPort] = result;
                }
            }
        }

        return t[0][0][0];
    }
}


// T.C : O(m*n*k)
// S.C : O(m*n*k)
import java.util.*;

class Solution {
    public int minCost(int[][] grid, int k) {
        int m = grid.length;        // rows
        int n = grid[0].length;     // columns

        int[][] dp = new int[m][n];
        for (int[] row : dp) Arrays.fill(row, Integer.MAX_VALUE);
        dp[m - 1][n - 1] = 0;

        int maxVal = 0;
        for (int[] row : grid) {
            for (int val : row) {
                maxVal = Math.max(maxVal, val);
            }
        }

        int[] teleportCost = new int[maxVal + 1];
        Arrays.fill(teleportCost, Integer.MAX_VALUE);

        for (int t = 0; t <= k; t++) {

            // Bottom-right → top-left DP
            for (int i = m - 1; i >= 0; i--) {
                for (int j = n - 1; j >= 0; j--) {

                    if (i + 1 < m && dp[i + 1][j] != Integer.MAX_VALUE) {
                        dp[i][j] = Math.min(dp[i][j], grid[i + 1][j] + dp[i + 1][j]);
                    }

                    if (j + 1 < n && dp[i][j + 1] != Integer.MAX_VALUE) {
                        dp[i][j] = Math.min(dp[i][j], grid[i][j + 1] + dp[i][j + 1]);
                    }

                    if (t > 0) {
                        dp[i][j] = Math.min(dp[i][j], teleportCost[grid[i][j]]);
                    }
                }
            }

            // Update teleport cost using current dp
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    int val = grid[i][j];
                    teleportCost[val] = Math.min(teleportCost[val], dp[i][j]);
                }
            }

            // Prefix minimum
            for (int v = 1; v <= maxVal; v++) {
                teleportCost[v] = Math.min(teleportCost[v], teleportCost[v - 1]);
            }
        }

        return dp[0][0];
    }
}
