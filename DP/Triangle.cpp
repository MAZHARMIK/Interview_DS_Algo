/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn   :
    Company Tags                  : Will updat elater
    Leetcode Link                 : https://leetcode.com/problems/triangle/  
    
    Solve "Minimum Falling Path Sum" (Leetcode-931) before this question - https://www.youtube.com/watch?v=rpW1qKAs4V4
*/


/**************************************************************** C++ ****************************************************************/
//Approach-1 Recursion with Memoization - TLE
//T.C : O(n^2) states in t[][]
//S.C : O(n^2)
class Solution {
public:
    int t[201][201];
    int n;
    int solve(vector<vector<int>>& triangle, int row, int col) {
        if (row == n-1)
            return triangle[row][col];

        if(t[row][col] != -1)
            return t[row][col];
        
        int minPath = triangle[row][col] + 
                      min(solve(triangle, row + 1, col),
                          solve(triangle, row + 1, col + 1));

        return t[row][col] = minPath;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        n = triangle.size();
        memset(t, -1, sizeof(t));
        return solve(triangle, 0, 0);
    }
};


//Approach-2 : Bottom Up - Just like "Minimum Falling Path Sum"
//T.C : O(n^2)
//S.C : O(n^2)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp = triangle;  // copy triangle for dp

        // Start from second last row and move upwards
        for (int row = n - 2; row >= 0; row--) {
            for (int col = 0; col <= row; col++) { //1st row me 1 column, 2nd Row me 2 Columns, and so on, that's why (col <= row)
                dp[row][col] += min(dp[row + 1][col], dp[row + 1][col + 1]);
            }
        }

        return dp[0][0];  // minimum path sum
    }
};


//Approach-3 : Bottom Up optimized - O(n) space
//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp = triangle.back();  // last row

        for (int row = n - 2; row >= 0; row--) {
            for (int col = 0; col <= row; col++) {
                dp[col] = triangle[row][col] + min(dp[col], dp[col + 1]);
            }
        }

        return dp[0];
    }
};


//Approach-4 : You can also solve it from top to bottom direction
//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n, 0);

        dp[0] = triangle[0][0];

        for (int row = 1; row < n; row++) {
            // go right → left to avoid overwriting
            for (int col = row; col >= 0; col--) {
                if (col == 0) {
                    dp[col] = dp[col] + triangle[row][col];  // only from above
                } else if (col == row) {
                    dp[col] = dp[col - 1] + triangle[row][col];  // only from above-left
                } else {
                    dp[col] = min(dp[col], dp[col - 1]) + triangle[row][col];
                }
            }
        }

        return *min_element(dp.begin(), dp.end());
    }
};


//Approach-5 : Bottom Up optimized - manipulating the input
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        
        for(int row = 1; row < rows; row++) {
            for(int col = 0; col<triangle[row].size(); col++) {
                int prev_up_val  = triangle[row-1][min(col, (int)triangle[row-1].size()-1)];
                int prev_up_left = triangle[row-1][max(col-1, 0)];
                
                triangle[row][col] += min(prev_up_val, prev_up_left);
            }
        }
        
        return *min_element(triangle[rows-1].begin(), triangle[rows-1].end());
        
    }
};




/**************************************************************** Java ****************************************************************/
//Approach-1 Recursion with Memoization - TLE
//T.C : O(n^2) states in t[][]
//S.C : O(n^2)
class Solution {
    int[][] t;
    int n;

    private int solve(List<List<Integer>> triangle, int row, int col) {
        if (row == n - 1) {
            return triangle.get(row).get(col);
        }

        if (t[row][col] != -1) {
            return t[row][col];
        }

        int minPath = triangle.get(row).get(col) +
                      Math.min(solve(triangle, row + 1, col),
                               solve(triangle, row + 1, col + 1));

        return t[row][col] = minPath;
    }

    public int minimumTotal(List<List<Integer>> triangle) {
        n = triangle.size();
        t = new int[n][n];

        for (int i = 0; i < n; i++) {
            Arrays.fill(t[i], -1);
        }

        return solve(triangle, 0, 0);
    }
}



//Approach-2 : Bottom Up - Just like "Minimum Falling Path Sum"
//T.C : O(n^2)
//S.C : O(n^2)
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int n = triangle.size();
        int[][] dp = new int[n][n];

        // Copy triangle into dp
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                dp[i][j] = triangle.get(i).get(j);
            }
        }

        // Bottom-up calculation
        for (int row = n - 2; row >= 0; row--) {
            for (int col = 0; col <= row; col++) {
                dp[row][col] += Math.min(dp[row + 1][col], dp[row + 1][col + 1]);
            }
        }

        return dp[0][0];
    }
}



//Approach-3 : Bottom Up optimized - O(n) space
//T.C : O(n^2)
//S.C : O(n)
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int n = triangle.size();
        int[] dp = new int[n];

        // Initialize with last row
        for (int i = 0; i < n; i++) {
            dp[i] = triangle.get(n - 1).get(i);
        }

        for (int row = n - 2; row >= 0; row--) {
            for (int col = 0; col <= row; col++) {
                dp[col] = triangle.get(row).get(col) + Math.min(dp[col], dp[col + 1]);
            }
        }

        return dp[0];
    }
}



//Approach-4 : You can also solve it from top to bottom direction
//T.C : O(n^2)
//S.C : O(n)
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int n = triangle.size();
        int[] dp = new int[n];

        dp[0] = triangle.get(0).get(0);

        for (int row = 1; row < n; row++) {
            // Go right → left to avoid overwriting previous values
            for (int col = row; col >= 0; col--) {
                if (col == 0) {
                    dp[col] = dp[col] + triangle.get(row).get(col);
                } else if (col == row) {
                    dp[col] = dp[col - 1] + triangle.get(row).get(col);
                } else {
                    dp[col] = Math.min(dp[col], dp[col - 1]) + triangle.get(row).get(col);
                }
            }
        }

        int minPath = dp[0];
        for (int val : dp) {
            minPath = Math.min(minPath, val);
        }

        return minPath;
    }
}



//Approach-5 : Bottom Up optimized - manipulating the input
//T.C : O(n^2)
//S.C : O(1)
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int rows = triangle.size();

        for (int row = 1; row < rows; row++) {
            for (int col = 0; col < triangle.get(row).size(); col++) {
                int prevUpVal = triangle.get(row - 1).get(Math.min(col, triangle.get(row - 1).size() - 1));
                int prevUpLeft = triangle.get(row - 1).get(Math.max(col - 1, 0));

                int updatedVal = triangle.get(row).get(col) + Math.min(prevUpVal, prevUpLeft);
                triangle.get(row).set(col, updatedVal);
            }
        }

        return Collections.min(triangle.get(rows - 1));
    }
}
