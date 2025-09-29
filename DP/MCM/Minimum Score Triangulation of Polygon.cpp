/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=2r2qr0-NZFc
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/minimum-score-triangulation-of-polygon
*/


/**************************************************************** C++ ****************************************************************/
//Approach (Recursion + Memoization)
//T.C : O(n*n*n)
//S.C : O(n*n)
class Solution {
public:
    int t[50][50];

    int solve(vector<int>& values, int i, int j) {
        if (j - i < 2) 
            return 0; // less than 3 vertices -> no triangle

        if (t[i][j] != -1)
            return t[i][j];

        int result = INT_MAX;
        for (int k = i + 1; k < j; ++k) {
            int weight = solve(values, i, k) +
                        values[i] * values[k] * values[j] +
                        solve(values, k, j);
            result = min(result, weight);
        }

        return t[i][j] = result;
    }

    int minScoreTriangulation(vector<int>& values) {
        memset(t, -1, sizeof(t));
        return solve(values, 0, values.size() - 1);
    }
};




/**************************************************************** JAVA ****************************************************************/
//Approach (Recursion + Memoization)
//T.C : O(n*n*n)
//S.C : O(n*n)
class Solution {
    private int[][] dp;

    private int solve(int[] values, int i, int j) {
        // Need at least 3 points to form a triangle
        if (j - i + 1 < 3) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int result = Integer.MAX_VALUE;

        for (int k = i + 1; k < j; k++) {
            int wt = values[i] * values[k] * values[j]
                     + solve(values, i, k)
                     + solve(values, k, j);

            result = Math.min(result, wt);
        }

        dp[i][j] = result;
        return result;
    }

    public int minScoreTriangulation(int[] values) {
        int n = values.length;
        dp = new int[n][n];

        // Initialize dp with -1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = -1;
            }
        }

        return solve(values, 0, n - 1);
    }
}
