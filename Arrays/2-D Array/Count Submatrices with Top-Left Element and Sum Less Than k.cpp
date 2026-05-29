/*     Scroll below to see JAVA code also   */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=sWNfDG1kyrA
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/count-submatrices-with-top-left-element-and-sum-less-than-k
*/


/************************************************** C++ **************************************************/
//Approach-1 (Brute Force)
//T.C : O(m^2 * n^2)
//S.C : O(1)
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        // Fix the bottom-right corner at (i, j)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // Sum from (0,0) to (i,j)
                int sum = 0;
                for (int m1 = 0; m1 <= i; m1++) {
                    for (int n1 = 0; n1 <= j; n1++) {
                        sum += grid[m1][n1];
                    }
                }

                if (sum <= k) count++;
            }
        }

        return count;
    }
};



//Approach-2 (Using precomputed results)
//T.C : O(m*n)
//S.C : O(1)
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int count = 0;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                
                if (i > 0) 
                  grid[i][j] += grid[i - 1][j];
                if (j > 0) 
                  grid[i][j] += grid[i][j - 1];
                if (i > 0 && j > 0) 
                  grid[i][j] -= grid[i - 1][j - 1];
                
                if(grid[i][j] <= k)
                    count++;
                else 
                    break;
            }
        }

        return count;
    }
};




/************************************************** JAVA **************************************************/
//Approach-1 (Brute Force)
//T.C : O(m^2 * n^2)
//S.C : O(1)
class Solution {
    public int countSubmatrices(int[][] grid, int k) {
        int m = grid.length;
        int n = grid[0].length;
        int count = 0;

        // Fix the bottom-right corner at (i, j)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // Sum from (0,0) to (i,j)
                int sum = 0;
                for (int m1 = 0; m1 <= i; m1++) {
                    for (int n1 = 0; n1 <= j; n1++) {
                        sum += grid[m1][n1];
                    }
                }

                if (sum <= k) count++;
            }
        }

        return count;
    }
}


//Approach-2 (Using precomputed results)
//T.C : O(m*n)
//S.C : O(1)
class Solution {
    public int countSubmatrices(int[][] grid, int k) {
        int m = grid.length;
        int n = grid[0].length;
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                if (i > 0) 
                  grid[i][j] += grid[i - 1][j];
                if (j > 0) 
                  grid[i][j] += grid[i][j - 1];
                if (i > 0 && j > 0) 
                  grid[i][j] -= grid[i - 1][j - 1];

                if (grid[i][j] <= k) {
                    count++;
                } else {
                    break;
                }
            }
        }

        return count;
    }
}
