/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/twisted-mirror-path-count/
*/


/**************************************************************** C++ ****************************************************************/
//Approach-1 (Recursion Memo)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    int LEFT = 0; //Arrived at current cell from left cell (it means it was moving right)
    int UP = 1; //Arrived at current cell from up cell (it means it was moving down)
    int MOD = 1e9+7;
    int m; //rows
    int n; //cols

    //T.C : O(m*n)
    //S.C : O(m*n)
    //memoization = [i][j] = {-1, -1}
    int solve(vector<vector<int>>& grid, int i, int j, int cameFrom, vector<vector<array<int, 2>>>& t) {
        if(i >= m || j >= n) {
            return 0;
        }

        if(i == m-1 && j == n-1)
            return 1;
        

        if(t[i][j][cameFrom] != -1) {
            return t[i][j][cameFrom];
        }
        
        if(grid[i][j] == 1) { //mirror
            if(cameFrom == LEFT) {
                return t[i][j][cameFrom] = solve(grid, i+1, j, UP, t);
            } else {
                return t[i][j][cameFrom] = solve(grid, i, j+1, LEFT, t);
            }
        }

        //grid[i][j] == 0
        int totalPathsCount = 0;
        totalPathsCount = (totalPathsCount + solve(grid, i, j+1, LEFT, t)) % MOD;
        totalPathsCount = (totalPathsCount + solve(grid, i+1, j, UP, t)) % MOD;

        return t[i][j][cameFrom] = totalPathsCount;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<array<int, 2>>> t(m+1, vector<array<int, 2>>(n, {-1, -1}));

        return solve(grid, 0, 0, LEFT, t);
    }
};



//Approach-2 (Bottom Up)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    int LEFT = 0;
    int UP   = 1;
    int MOD = 1e9 + 7;
    int m, n;

    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // t[row][col][LEFT] = ways to reach this cell by entering from the left
        // t[row][col][UP]   = ways to reach this cell by entering from above
        vector<vector<array<int, 2>>> t(m, vector<array<int, 2>>(n, {0, 0}));

        // Start cell: one way to be here (start is never a mirror, slot is arbitrary)
        t[0][0][LEFT] = 1;

        // Prefill 0th row: one way to reach each cell, until the first mirror
        for (int col = 1; col < n; col++) {
            t[0][col][LEFT] = 1;
            if (grid[0][col] == 1)
                break;          // deflected down, cells beyond stay 0
        }

        // Prefill 0th column: one way to reach each cell, until the first mirror
        for (int row = 1; row < m; row++) {
            t[row][0][UP] = 1;
            if (grid[row][0] == 1)
                break;          // deflected right, cells below stay 0
        }

        // Fill the rest
        for (int row = 1; row < m; row++) {
            for (int col = 1; col < n; col++) {

                // Entering from the left neighbour (row, col-1)
                if (grid[row][col - 1] == 1)
                    t[row][col][LEFT] = t[row][col - 1][UP];       // mirror: only UP-entrants turn right
                else
                    t[row][col][LEFT] = (t[row][col - 1][LEFT] + t[row][col - 1][UP]) % MOD;

                // Entering from the top neighbour (row-1, col)
                if (grid[row - 1][col] == 1)
                    t[row][col][UP] = t[row - 1][col][LEFT];       // mirror: only LEFT-entrants turn down
                else
                    t[row][col][UP] = (t[row - 1][col][LEFT] + t[row - 1][col][UP]) % MOD;
            }
        }

        // Destination is always empty: every arrival counts, from either side
        return (t[m - 1][n - 1][LEFT] + t[m - 1][n - 1][UP]) % MOD;
    }
};


//Approach-3 (Bottom Up - Line By Line Mapped from Recursion Memoization)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    int LEFT = 0;   // arrived from the left cell (was moving right)
    int UP   = 1;   // arrived from the cell above (was moving down)
    int MOD = 1e9 + 7;
    int m, n;

    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();


        vector<vector<array<int, 2>>> t(m + 1, vector<array<int, 2>>(n + 1, {0, 0}));

        for (int row = m - 1; row >= 0; row--) {
            for (int col = n - 1; col >= 0; col--) {
                for (int cameFrom = 0; cameFrom < 2; cameFrom++) {

                    // Destination reached
                    if (row == m - 1 && col == n - 1) {
                        t[row][col][cameFrom] = 1;
                        continue;
                    }

                    // Mirror: reflect based on where we came from
                    if (grid[row][col] == 1) {
                        if (cameFrom == LEFT)
                            t[row][col][cameFrom] = t[row + 1][col][UP];     // came from left -> turn down
                        else
                            t[row][col][cameFrom] = t[row][col + 1][LEFT];   // came from up -> turn right
                        continue;
                    }

                    // Empty cell: branch into both moves
                    long long total = 0;
                    total += t[row][col + 1][LEFT];  // move right, next cell is entered from its LEFT
                    total += t[row + 1][col][UP];    // move down, next cell is entered from its UP

                    t[row][col][cameFrom] = total % MOD;
                }
            }
        }

        return t[0][0][LEFT]; // starting cell is always 0 (use either UP or LEFT)
    }
};

/**************************************************************** JAVA ****************************************************************/
//Approach-1 (Recursion Memo)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
    int LEFT = 0; // Arrived at current cell from left cell (it means it was moving right)
    int UP = 1;   // Arrived at current cell from up cell (it means it was moving down)
    int MOD = 1_000_000_007;
    int m; // rows
    int n; // cols

    int solve(int[][] grid, int i, int j, int cameFrom, int[][][] t) {
        // Out of bounds: invalid path
        if (i >= m || j >= n) {
            return 0;
        }

        // Destination reached
        if (i == m - 1 && j == n - 1)
            return 1;

        if (t[i][j][cameFrom] != -1) {
            return t[i][j][cameFrom];
        }

        if (grid[i][j] == 1) { // mirror
            if (cameFrom == LEFT) {
                return t[i][j][cameFrom] = solve(grid, i + 1, j, UP, t);
            } else {
                return t[i][j][cameFrom] = solve(grid, i, j + 1, LEFT, t);
            }
        }

        // grid[i][j] == 0
        int totalPathsCount = 0;
        totalPathsCount = (totalPathsCount + solve(grid, i, j + 1, LEFT, t)) % MOD;
        totalPathsCount = (totalPathsCount + solve(grid, i + 1, j, UP, t)) % MOD;

        return t[i][j][cameFrom] = totalPathsCount;
    }

    public int uniquePaths(int[][] grid) {
        m = grid.length;
        n = grid[0].length;

        // t[i][j][LEFT / UP] = -1 initially
        int[][][] t = new int[m][n][2];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                t[i][j][0] = -1;
                t[i][j][1] = -1;
            }
        }

        return solve(grid, 0, 0, LEFT, t);
    }
}


//Approach-2 (Bottom Up)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
    int LEFT = 0;
    int UP = 1;
    int MOD = 1_000_000_007;
    int m, n;

    public int uniquePaths(int[][] grid) {
        m = grid.length;
        n = grid[0].length;

        // t[row][col][LEFT] = ways to reach this cell by entering from the left
        // t[row][col][UP]   = ways to reach this cell by entering from above
        int[][][] t = new int[m][n][2]; // Java initializes to 0

        // Start cell: one way to be here (start is never a mirror, slot is arbitrary)
        t[0][0][LEFT] = 1;

        // Prefill 0th row: one way to reach each cell, until the first mirror
        for (int col = 1; col < n; col++) {
            t[0][col][LEFT] = 1;
            if (grid[0][col] == 1)
                break; // deflected down, cells beyond stay 0
        }

        // Prefill 0th column: one way to reach each cell, until the first mirror
        for (int row = 1; row < m; row++) {
            t[row][0][UP] = 1;
            if (grid[row][0] == 1)
                break; // deflected right, cells below stay 0
        }

        // Fill the rest
        for (int row = 1; row < m; row++) {
            for (int col = 1; col < n; col++) {

                // Entering from the left neighbour (row, col-1)
                if (grid[row][col - 1] == 1)
                    t[row][col][LEFT] = t[row][col - 1][UP]; // mirror: only UP-entrants turn right
                else
                    t[row][col][LEFT] = (t[row][col - 1][LEFT] + t[row][col - 1][UP]) % MOD;

                // Entering from the top neighbour (row-1, col)
                if (grid[row - 1][col] == 1)
                    t[row][col][UP] = t[row - 1][col][LEFT]; // mirror: only LEFT-entrants turn down
                else
                    t[row][col][UP] = (t[row - 1][col][LEFT] + t[row - 1][col][UP]) % MOD;
            }
        }

        // Destination is always empty: every arrival counts, from either side
        return (t[m - 1][n - 1][LEFT] + t[m - 1][n - 1][UP]) % MOD;
    }
}


//Approach-3 (Bottom Up - Line By Line Mapped from Recursion Memoization)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
    int LEFT = 0; // arrived from the left cell (was moving right)
    int UP = 1;   // arrived from the cell above (was moving down)
    int MOD = 1_000_000_007;
    int m, n;

    public int uniquePaths(int[][] grid) {
        m = grid.length;
        n = grid[0].length;

        // (m+1) x (n+1), zero-filled: row == m or col == n is "out of bounds" and reads as 0
        int[][][] t = new int[m + 1][n + 1][2];

        for (int row = m - 1; row >= 0; row--) {
            for (int col = n - 1; col >= 0; col--) {
                for (int cameFrom = 0; cameFrom < 2; cameFrom++) {

                    // Destination reached
                    if (row == m - 1 && col == n - 1) {
                        t[row][col][cameFrom] = 1;
                        continue;
                    }

                    // Mirror: reflect based on where we came from
                    if (grid[row][col] == 1) {
                        if (cameFrom == LEFT)
                            t[row][col][cameFrom] = t[row + 1][col][UP];   // came from left -> turn down
                        else
                            t[row][col][cameFrom] = t[row][col + 1][LEFT]; // came from up -> turn right
                        continue;
                    }

                    // Empty cell: branch into both moves
                    long total = 0;
                    total += t[row][col + 1][LEFT]; // move right, next cell is entered from its LEFT
                    total += t[row + 1][col][UP];   // move down, next cell is entered from its UP

                    t[row][col][cameFrom] = (int) (total % MOD);
                }
            }
        }

        return t[0][0][LEFT]; // starting cell is always 0 (use either UP or LEFT)
    }
}
