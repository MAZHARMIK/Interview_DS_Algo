/*                   Scroll below to see JAVA code as well                */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=K9-ZV-_UJ0Q
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/find-the-maximum-number-of-fruits-collected
*/

/************************************************************ C++ ************************************************************/
//Approach-1 - (Recursion + Memoization)
//T.C : O(n^2)
//S.C : O(n^2)
class Solution {
    int n;
    vector<vector<int>> t;

public:

    //Can only move diagonally
    int child1Collect(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += grid[i][i];
            grid[i][i] = 0;
            t[i][i] = 0;
        }
        return ans;
    }

    int child2Collect(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || i >= n || j < 0 || j >= n) {
            return 0;
        }
        if (i == n - 1 && j == n - 1) {
            return 0;
        }
        
        //can't go beyond diagonal or left to diagonal (only have n-1 moves)
        if (i == j || i > j) {
            return 0;
        }

        if (t[i][j] != -1)
            return t[i][j];

        int leftcorner = grid[i][j] + child2Collect(i + 1, j - 1, grid);
        int middle = grid[i][j] + child2Collect(i + 1, j, grid);
        int rightcorner = grid[i][j] + child2Collect(i + 1, j + 1, grid);

        return t[i][j] = max({middle, rightcorner, leftcorner});
    }

    int child3Collect(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || i >= n || j < 0 || j >= n) {
            return 0;
        }
        if (i == n - 1 && j == n - 1) {
            return 0;
        }

        //can't go beyond diagonal or right to diagonal (only have n-1 moves)
        if (i == j || j > i) {
            return 0;
        }
        if (t[i][j] != -1)
            return t[i][j];

        int topcorner   = grid[i][j] + child3Collect(i - 1, j + 1, grid);
        int right       = grid[i][j] + child3Collect(i, j + 1, grid);
        int rightcorner = grid[i][j] + child3Collect(i + 1, j + 1, grid);

        return t[i][j] = max({right, rightcorner, topcorner});
    }

    int maxCollectedFruits(vector<vector<int>>& grid) {
        n = grid.size();
        t.resize(n, vector<int>(n, -1));

        // First child
        int firstChildScore = child1Collect(grid);

        // Second child
        int secondChildScore = child2Collect(0, n - 1, grid);

        // Third child
        int thirdChildScore  = child3Collect(n - 1, 0, grid);

        return (firstChildScore + secondChildScore + thirdChildScore);
    }    
};


//Approach-2 - (Bottom Up)
//T.C : O(n^2)
//S.C : O(n^2)
class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        vector<vector<int>> t(n, vector<int>(n, 0));
        //t[i][j] = max fruits collected till [i][j]

        //child1Collect - Diagonal elements
        int result = 0;
        for(int i = 0; i < n; i++) {
            result += fruits[i][i];
        }


        //Before child2 and child3, nullify the cells which can't be visited by child2 and child3
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i < j && i+j < n-1) {
                    t[i][j] = 0;
                } else if(i > j && i+j < n-1) {
                    t[i][j] = 0;
                } else {
                    t[i][j] = fruits[i][j];
                }
            }
        }


        //child2 collect fruits
        //cells upper to diagonal : i < j
        for(int i = 1; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                t[i][j] += max({t[i-1][j-1], t[i-1][j], (j+1 < n) ? t[i-1][j+1] : 0});
            }
        }

        //child3 collect fruits
        //cells upper to diagonal : i > j
        for(int j = 1; j < n; j++) {
            for(int i = j+1; i < n; i++) {
                t[i][j] += max({t[i-1][j-1], t[i][j-1], (i+1 < n) ? t[i+1][j-1] : 0});
            }
        }

        return result + t[n-2][n-1] + t[n-1][n-2];

    }
};




/************************************************************ JAVA ************************************************************/
//Approach-1 - (Recursion + Memoization)
//T.C : O(n^2)
//S.C : O(n^2)
class Solution {
    int n;
    int[][] t;

    // Can only move diagonally
    private int child1Collect(int[][] grid) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += grid[i][i];
            grid[i][i] = 0;
            t[i][i] = 0;
        }
        return ans;
    }

    private int child2Collect(int i, int j, int[][] grid) {
        if (i < 0 || i >= n || j < 0 || j >= n) {
            return 0;
        }
        if (i == n - 1 && j == n - 1) {
            return 0;
        }

        // can't go beyond diagonal or left to diagonal (only have n-1 moves)
        if (i == j || i > j) {
            return 0;
        }

        if (t[i][j] != -1)
            return t[i][j];

        int leftcorner = grid[i][j] + child2Collect(i + 1, j - 1, grid);
        int middle = grid[i][j] + child2Collect(i + 1, j, grid);
        int rightcorner = grid[i][j] + child2Collect(i + 1, j + 1, grid);

        return t[i][j] = Math.max(middle, Math.max(rightcorner, leftcorner));
    }

    private int child3Collect(int i, int j, int[][] grid) {
        if (i < 0 || i >= n || j < 0 || j >= n) {
            return 0;
        }
        if (i == n - 1 && j == n - 1) {
            return 0;
        }

        // can't go beyond diagonal or right to diagonal (only have n-1 moves)
        if (i == j || j > i) {
            return 0;
        }
        if (t[i][j] != -1)
            return t[i][j];

        int topcorner = grid[i][j] + child3Collect(i - 1, j + 1, grid);
        int right = grid[i][j] + child3Collect(i, j + 1, grid);
        int rightcorner = grid[i][j] + child3Collect(i + 1, j + 1, grid);

        return t[i][j] = Math.max(right, Math.max(rightcorner, topcorner));
    }

    public int maxCollectedFruits(int[][] grid) {
        n = grid.length;
        t = new int[n][n];
        for (int[] row : t) {
            Arrays.fill(row, -1);
        }

        // First child
        int firstChildScore = child1Collect(grid);

        // Second child
        int secondChildScore = child2Collect(0, n - 1, grid);

        // Third child
        int thirdChildScore = child3Collect(n - 1, 0, grid);

        return (firstChildScore + secondChildScore + thirdChildScore);
    }
}


//Approach-2 - (Bottom Up)
//T.C : O(n^2)
//S.C : O(n^2)
class Solution {
    public int maxCollectedFruits(int[][] fruits) {
        int n = fruits.length;
        int[][] t = new int[n][n];
        // t[i][j] = max fruits collected till [i][j]

        // child1Collect - Diagonal elements
        int result = 0;
        for (int i = 0; i < n; i++) {
            result += fruits[i][i];
        }

        // Before child2 and child3, nullify the cells which can't be visited by child2 and child3
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i < j && i + j < n - 1) {
                    t[i][j] = 0;
                } else if (i > j && i + j < n - 1) {
                    t[i][j] = 0;
                } else {
                    t[i][j] = fruits[i][j];
                }
            }
        }

        // child2 collect fruits
        // cells upper to diagonal : i < j
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                t[i][j] += Math.max(t[i - 1][j - 1], Math.max(t[i - 1][j], (j + 1 < n) ? t[i - 1][j + 1] : 0));
            }
        }

        // child3 collect fruits
        // cells below diagonal : i > j
        for (int j = 1; j < n; j++) {
            for (int i = j + 1; i < n; i++) {
                t[i][j] += Math.max(t[i - 1][j - 1], Math.max(t[i][j - 1], (i + 1 < n) ? t[i + 1][j - 1] : 0));
            }
        }

        return result + t[n - 2][n - 1] + t[n - 1][n - 2];
    }
}
