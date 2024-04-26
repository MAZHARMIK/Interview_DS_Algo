/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=rpW1qKAs4V4
    Company Tags                : Google, Microsoft, Amazon, Samsung
    Leetcode Link               : https://leetcode.com/problems/minimum-falling-path-sum-ii/
    
    Similar tough problem : Leetcode - 1937 : Maximum Number of Points with Cost  (Must Try !!!!)
*/

/*************************************************************** C++ ***************************************************************/
//Approach-1 (Recur + Memoization)
//T.C : O(N^3)
//S.C : O(N^2)
class Solution {
public:
    int n;
    int t[201][201];
    int solve(int row, int col, vector<vector<int>>& grid) {
        if (row == n - 1) {
            return grid[row][col];
        }

        if(t[row][col] != -1) {
            return t[row][col];
        }
        
        int ans = INT_MAX;
        for (int nextCol = 0; nextCol < n; nextCol++) {
            if (nextCol != col) {
                ans = min(ans, solve(row + 1, nextCol, grid));
            }
        }

        return t[row][col] = grid[row][col] + ans;
    }
    
    int minFallingPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        memset(t, -1, sizeof(t));

        int result = INT_MAX;
        for (int col = 0; col < n; col++) {
            result = min(result, solve(0, col, grid));
        }

        return result;
    }
};



//Approach-2 (Bottom Up)
//T.C : O(N^3)
//S.C : O(N^2)
class Solution {
public:
    int n;
    
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        
        vector<vector<int>> t(n, vector<int>(n, INT_MAX));

        for (int col = 0; col < n; col++) {
            t[n - 1][col] = grid[n - 1][col];
        }

        for (int row = n - 2; row >= 0; row--) {
            for (int col = 0; col < n; col++) {
                int ans = INT_MAX;
                for (int nextCol = 0; nextCol < n; nextCol++) {
                    if (nextCol != col) {
                        ans = min(ans, t[row + 1][nextCol]);
                    }
                }
                t[row][col] = grid[row][col] + ans;
            }
        }

        int result = INT_MAX;
        for (int col = 0; col < n; col++) {
            result = min(result, t[0][col]);
        }

        return result;
    }
};


//Approach-3 (Getting rid of extra for loop)
//T.C : O(N^2)
//S.C : O(N^2)
class Solution {
public:
    int n;
    
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        
        vector<vector<int>> t(n, vector<int>(n, INT_MAX));

        int nextMin1Col = -1;
        int nextMin2Col = -1;
        
        for (int col = 0; col < n; col++) {
            t[n - 1][col] = grid[n - 1][col];
            
            if(nextMin1Col == -1 || t[n - 1][col] <= t[n-1][nextMin1Col]) {
                nextMin2Col = nextMin1Col;
                nextMin1Col = col;
            } else if(nextMin2Col == -1 || t[n - 1][col] <= t[n-1][nextMin2Col]) {
                nextMin2Col = col;
            }
        }

        for (int row = n - 2; row >= 0; row--) {
            
            int min1Col = -1;
            int min2Col = -1;
            
            for (int col = 0; col < n; col++) {
                
                if(col != nextMin1Col) {
                    t[row][col] = grid[row][col] + t[row+1][nextMin1Col];
                } else {
                    t[row][col] = grid[row][col] + t[row+1][nextMin2Col];
                }
                
                if(min1Col == -1 || t[row][col] <= t[row][min1Col]) {
                    min2Col = min1Col;
                    min1Col = col;
                } else if(min2Col == -1 || t[row][col] <= t[row][min2Col]) {
                    min2Col = col;
                }
            }
                            
            nextMin1Col = min1Col;
            nextMin2Col = min2Col;
                
        }

        int result = INT_MAX;
        for (int col = 0; col < n; col++) {
            result = min(result, t[0][col]);
        }

        return result;
        //Or you can directly return the minimum from the first row
        //return t[0][nextMin1Col];
    }
};


//Approach-4 
//T.C : O(N^2)
//S.C : O(1)
class Solution {
public:
    int n;
    
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();

        int nextMin1Col = -1;
        int nextMin2Col = -1;
        
        int nextMin1Val = -1;
        int nextMin2Val = -1;
        
        for (int col = 0; col < n; col++) {

            if(nextMin1Col == -1 || grid[n - 1][col] <= nextMin1Val) {
                nextMin2Col = nextMin1Col;
                nextMin2Val = nextMin1Val;
                
                nextMin1Col = col;
                nextMin1Val = grid[n-1][col];
                
            } else if(nextMin2Col == -1 || grid[n - 1][col] <= nextMin2Val) {
                nextMin2Col = col;
                nextMin2Val = grid[n-1][col];
            }
        }

        for (int row = n - 2; row >= 0; row--) {
            
            int min1Col = -1;
            int min2Col = -1;
            
            int min1Val = -1;
            int min2Val = -1;
            
            for (int col = 0; col < n; col++) {
                
                int ans;
                if(col != nextMin1Col) {
                    ans = grid[row][col] + nextMin1Val;
                } else {
                    ans = grid[row][col] + nextMin2Val;
                }
                
                if(min1Col == -1 || ans <= min1Val) {
                    min2Col = min1Col;
                    min2Val = min1Val;
                    
                    min1Col = col;
                    min1Val = ans;
                } else if(min2Col == -1 || ans <= min2Val) {
                    min2Col = col;
                    min2Val = ans;
                }
            }
                            
            nextMin1Col = min1Col;
            nextMin1Val = min1Val;
            
            nextMin2Col = min2Col;
            nextMin2Val = min2Val;
                
        }

        // Return the minimum from the first row
        return nextMin1Val;
    }
};


/*************************************************************** JAVA ***************************************************************/
//Approach-1 (Recur + Memoization)
//T.C : O(N^3)
//S.C : O(N^2)
class Solution {
    int n;
    int[][] t = new int[201][201]; // Using 2D array for memoization

    public int solve(int row, int col, int[][] grid) {
        if (row == n - 1) {
            return grid[row][col];
        }

        if (t[row][col] != -1) {
            return t[row][col];
        }

        int ans = Integer.MAX_VALUE;
        for (int nextCol = 0; nextCol < n; nextCol++) {
            if (nextCol != col) {
                ans = Math.min(ans, solve(row + 1, nextCol, grid));
            }
        }

        return t[row][col] = grid[row][col] + ans;
    }

    public int minFallingPathSum(int[][] grid) {
        n = grid.length;
        for (int i = 0; i < t.length; i++) {
            Arrays.fill(t[i], -1); // Initialize memoization table
        }

        int result = Integer.MAX_VALUE;
        for (int col = 0; col < n; col++) {
            result = Math.min(result, solve(0, col, grid));
        }

        return result;
    }
}


//Approach-2 (Bottom Up)
//T.C : O(N^3)
//S.C : O(N^2)
class Solution {
    public int minFallingPathSum(int[][] grid) {
        int n = grid.length;

        int[][] t = new int[n][n];
        for (int[] row : t) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }

        for (int col = 0; col < n; col++) {
            t[n - 1][col] = grid[n - 1][col];
        }

        for (int row = n - 2; row >= 0; row--) {
            for (int col = 0; col < n; col++) {
                int ans = Integer.MAX_VALUE;
                for (int nextCol = 0; nextCol < n; nextCol++) {
                    if (nextCol != col) {
                        ans = Math.min(ans, t[row + 1][nextCol]);
                    }
                }
                t[row][col] = grid[row][col] + ans;
            }
        }

        int result = Integer.MAX_VALUE;
        for (int col = 0; col < n; col++) {
            result = Math.min(result, t[0][col]);
        }

        return result;
    }
}


//Approach-3 (Getting rid of extra for loop)
//T.C : O(N^2)
//S.C : O(N^2)
class Solution {
    public int minFallingPathSum(int[][] grid) {
        int n = grid.length;

        int[][] t = new int[n][n];
        for (int[] row : t) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }

        int nextMin1Col = -1;
        int nextMin2Col = -1;
        
        for (int col = 0; col < n; col++) {
            t[n - 1][col] = grid[n - 1][col];
            
            if(nextMin1Col == -1 || t[n - 1][col] <= t[n-1][nextMin1Col]) {
                nextMin2Col = nextMin1Col;
                nextMin1Col = col;
            } else if(nextMin2Col == -1 || t[n - 1][col] <= t[n-1][nextMin2Col]) {
                nextMin2Col = col;
            }
        }

        for (int row = n - 2; row >= 0; row--) {
            
            int min1Col = -1;
            int min2Col = -1;
            
            for (int col = 0; col < n; col++) {
                
                if(col != nextMin1Col) {
                    t[row][col] = grid[row][col] + t[row+1][nextMin1Col];
                } else {
                    t[row][col] = grid[row][col] + t[row+1][nextMin2Col];
                }
                
                if(min1Col == -1 || t[row][col] <= t[row][min1Col]) {
                    min2Col = min1Col;
                    min1Col = col;
                } else if(min2Col == -1 || t[row][col] <= t[row][min2Col]) {
                    min2Col = col;
                }
            }
                            
            nextMin1Col = min1Col;
            nextMin2Col = min2Col;
                
        }

        int result = Integer.MAX_VALUE;
        for (int col = 0; col < n; col++) {
            result = Math.min(result, t[0][col]);
        }

        return result;
        // Or you can directly return the minimum from the first row
        // return t[0][nextMin1Col];
    }
}


//Approach-4 
//T.C : O(N^2)
//S.C : O(1)
class Solution {
    public int minFallingPathSum(int[][] grid) {
        int n = grid.length;

        int nextMin1Col = -1;
        int nextMin2Col = -1;
        
        int nextMin1Val = -1;
        int nextMin2Val = -1;
        
        for (int col = 0; col < n; col++) {

            if(nextMin1Col == -1 || grid[n - 1][col] <= nextMin1Val) {
                nextMin2Col = nextMin1Col;
                nextMin2Val = nextMin1Val;
                
                nextMin1Col = col;
                nextMin1Val = grid[n-1][col];
                
            } else if(nextMin2Col == -1 || grid[n - 1][col] <= nextMin2Val) {
                nextMin2Col = col;
                nextMin2Val = grid[n-1][col];
            }
        }

        for (int row = n - 2; row >= 0; row--) {
            
            int min1Col = -1;
            int min2Col = -1;
            
            int min1Val = -1;
            int min2Val = -1;
            
            for (int col = 0; col < n; col++) {
                
                int ans;
                if(col != nextMin1Col) {
                    ans = grid[row][col] + nextMin1Val;
                } else {
                    ans = grid[row][col] + nextMin2Val;
                }
                
                if(min1Col == -1 || ans <= min1Val) {
                    min2Col = min1Col;
                    min2Val = min1Val;
                    
                    min1Col = col;
                    min1Val = ans;
                } else if(min2Col == -1 || ans <= min2Val) {
                    min2Col = col;
                    min2Val = ans;
                }
            }
                            
            nextMin1Col = min1Col;
            nextMin1Val = min1Val;
            
            nextMin2Col = min2Col;
            nextMin2Val = min2Val;
                
        }

        // Return the minimum from the first row
        return nextMin1Val;
    }
}
