/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k
*/


/**************************************************************** C++ ****************************************************************/
//Approach-1 (Recursion + Memoization : DP On Grids)
//T.C : O(m*n*k)
//S.C : O(m*n*k)
class Solution {
public:
    int M = 1e9 + 7;
    vector<vector<vector<int>>> t;

    int solve(int row, int col, int remain, vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        if(row >= m || col >= n)
            return 0;

        if(row == m - 1 && col == n - 1)
            return ((remain + grid[row][col]) % k == 0);

        if(t[row][col][remain] != -1)
            return t[row][col][remain];

        int newRemain = (remain + grid[row][col]) % k;

        int down  = solve(row + 1, col, newRemain, grid, k);
        int right = solve(row, col + 1, newRemain, grid, k);

        return t[row][col][remain] = (down + right) % M;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        t.assign(m, vector<vector<int>>(n, vector<int>(k, -1)));

        return solve(0, 0, 0, grid, k);
    }
};


//Approach-2 (Bottom Up  : DP On Grids)
//T.C : O(m*n*k)
//S.C : O(m*n*k)
class Solution {
public:
    int M = 1e9 + 7;

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int t[m+1][n+1][k+1];
        memset(t, 0, sizeof(t));
        // t[i][j][remain] = number of paths from [i][j] to [m-1][n-1] with current remainder = remain

        // Base case same as recursion
        for(int remain = 0; remain < k; remain++) {
            t[m-1][n-1][remain] = ((remain + grid[m-1][n-1]) % k == 0 ? 1 : 0);
        }

        for(int row = m - 1; row >= 0; row--) {
            for(int col = n - 1; col >= 0; col--) {

                for(int remain = 0; remain < k; remain++) {

                    if(row == m - 1 && col == n - 1)
                        continue;

                    int newRemain = (remain + grid[row][col]) % k;

                    long long down  = t[row + 1][col][newRemain];
                    long long right = t[row][col + 1][newRemain];

                    t[row][col][remain] = (down + right) % M;
                }
            }
        }

        return t[0][0][0];
    }
};




/**************************************************************** JAVA ****************************************************************/
//Approach-1 (Recursion + Memoization : DP On Grids)
//T.C : O(m*n*k)
//S.C : O(m*n*k)
class Solution {
    int M = 1_000_000_007;
    Integer[][][] t;  // memo table

    int solve(int row, int col, int remain, int[][] grid, int k) {
        int m = grid.length;
        int n = grid[0].length;

        if (row >= m || col >= n)
            return 0;

        // Base Case (same as C++)
        if (row == m - 1 && col == n - 1) {
            return ((remain + grid[row][col]) % k == 0) ? 1 : 0;
        }

        if (t[row][col][remain] != null)
            return t[row][col][remain];

        int newRemain = (remain + grid[row][col]) % k;

        int down  = solve(row + 1, col, newRemain, grid, k);
        int right = solve(row, col + 1, newRemain, grid, k);

        return t[row][col][remain] = (int)(((long)down + right) % M);
    }

    public int numberOfPaths(int[][] grid, int k) {
        int m = grid.length;
        int n = grid[0].length;

        t = new Integer[m][n][k];

        return solve(0, 0, 0, grid, k);
    }
}





//Approach-2 (Bottom Up  : DP On Grids)
//T.C : O(m*n*k)
//S.C : O(m*n*k)
class Solution {
    int M = 1_000_000_007;

    public int numberOfPaths(int[][] grid, int k) {
        int m = grid.length;
        int n = grid[0].length;

        int[][][] t = new int[m+1][n+1][k+1];

        // Base case same as recursion
        for (int remain = 0; remain < k; remain++) {
            t[m-1][n-1][remain] = 
                ((remain + grid[m-1][n-1]) % k == 0) ? 1 : 0;
        }

        // Fill bottom-up
        for (int row = m - 1; row >= 0; row--) {
            for (int col = n - 1; col >= 0; col--) {

                for (int remain = 0; remain < k; remain++) {

                    if (row == m - 1 && col == n - 1)
                        continue;

                    int newRemain = (remain + grid[row][col]) % k;

                    long down  = t[row + 1][col][newRemain];
                    long right = t[row][col + 1][newRemain];

                    t[row][col][remain] = (int)((down + right) % M);
                }
            }
        }

        return t[0][0][0];
    }
}
