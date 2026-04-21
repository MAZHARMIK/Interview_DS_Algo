/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=4X3B07RFNW8
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/maximum-amount-of-money-robot-can-earn
*/



/**************************************************************** C++ ****************************************************************/
//Approach (Recursion + Memoization)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    int m;
    int n;
    int t[501][501][3];

    int solve(vector<vector<int>>& coins, int i, int j, int neu) {
        if(i == m-1 && j == n-1) {
            if(coins[i][j] < 0 && neu > 0) {
                return 0; //neutralize kardiya robber ko
            }

            return coins[i][j];
        }

        if(i >= m || j >= n) {
            return INT_MIN;
        }

        if(t[i][j][neu] != INT_MIN) {
            return t[i][j][neu];
        }

        //Take the current cell value
        int take = coins[i][j] + max(solve(coins, i+1, j, neu), solve(coins, i, j+1, neu));

        //Skip current value if you can
        int skip = INT_MIN;
        if(coins[i][j] < 0 && neu > 0) {
            int skipDown = solve(coins, i+1, j, neu-1);
            int skipRight = solve(coins, i, j+1, neu-1);

            skip = max(skipDown, skipRight);
        }

        return t[i][j][neu] = max(take, skip);
    }

    int maximumAmount(vector<vector<int>>& coins) {

        m = coins.size();
        n = coins[0].size();

        for(int i = 0; i < 501; i++) {
            for(int j = 0; j < 501; j++) {
                for(int k = 0; k < 3; k++) {
                    t[i][j][k] = INT_MIN;
                }
            }
        }

        return solve(coins, 0, 0, 2);
    }
};




/**************************************************************** JAVA ****************************************************************/
//Approach (Recursion + Memoization)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
    int m, n;
    int[][][] dp;

    int solve(int[][] coins, int i, int j, int neu) {

        // Out of bounds
        if (i >= m || j >= n) return Integer.MIN_VALUE;

        // Base case
        if (i == m - 1 && j == n - 1) {
            if (coins[i][j] < 0 && neu > 0) return 0;
            return coins[i][j];
        }

        // Memo
        if (dp[i][j][neu] != Integer.MIN_VALUE) {
            return dp[i][j][neu];
        }

        int best = Integer.MIN_VALUE;

        // Move Down
        int down = solve(coins, i + 1, j, neu);
        if (down != Integer.MIN_VALUE) {
            best = Math.max(best, coins[i][j] + down);
        }

        // Move Right
        int right = solve(coins, i, j + 1, neu);
        if (right != Integer.MIN_VALUE) {
            best = Math.max(best, coins[i][j] + right);
        }

        // Neutralize (skip negative)
        if (coins[i][j] < 0 && neu > 0) {
            int downSkip = solve(coins, i + 1, j, neu - 1);
            int rightSkip = solve(coins, i, j + 1, neu - 1);

            int skipBest = Math.max(downSkip, rightSkip);
            if (skipBest != Integer.MIN_VALUE) {
                best = Math.max(best, skipBest);
            }
        }

        return dp[i][j][neu] = best;
    }

    public int maximumAmount(int[][] coins) {
        m = coins.length;
        n = coins[0].length;

        dp = new int[m][n][3];

        // Initialize with MIN_VALUE
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < 3; k++) {
                    dp[i][j][k] = Integer.MIN_VALUE;
                }
            }
        }

        return solve(coins, 0, 0, 2);
    }
}
