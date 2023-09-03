/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=DaakAKiCkyc
    Company Tags                : Amazon, Cisco, Paytm, OLA Cabs, Walmart, LinkedIn
    Leetcode Link               : https://leetcode.com/problems/unique-paths/
*/

************************************************************ C++ ************************************************************
//Approach-1 - Recursion + Memoization - T.C : O(m*n)
class Solution {
public:
    int t[101][101];
        
    int solve(int m, int n, int i, int j) {
        if(i >= m || j >= n || i < 0 || j < 0)
            return 0;
        
        if(i == m-1 && j == n-1)
            return 1;
        
        if(t[i][j] != -1)
            return t[i][j];
        
        return t[i][j] = solve(m, n, i+1, j) + solve(m, n, i, j+1);
        
    }
    
    int uniquePaths(int m, int n) {
        memset(t, -1, sizeof(t));
        
        return solve(m, n, 0, 0);
    }
};

//Approach-2 (using Bottom Up) - T.C : O(m*n)
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> t(m, vector<int>(n, 0));
        //t[i][j] = total ways to reach at [i][j]
        
        //Since we start from[0][0], we move right and right
        //so, there is only one way to reach each cell in the first row
        for(int col = 0; col<n; col++) {
            t[0][col] = 1;
        }
        
        //Since we start from[0][0], we move down and down
        //so, there is only one way to reach each cell in the first column
        for(int row = 0; row<m; row++) {
            t[row][0] = 1;
        }
        
        for(int i = 1; i<m; i++) {
            for(int j = 1; j<n; j++) {
                //ways to reach [i][j] will be from up [i-1][j] or from left [i][j-1]
                t[i][j] = t[i-1][j] + t[i][j-1];
            }
        }
        
        return t[m-1][n-1];//return total ways to reach [m-1][n-1] which is our Finish
    }
};



************************************************************ JAVA ************************************************************
//Approach-1 - Recursion + Memoization - T.C : O(m*n)
class Solution {
    int[][] t;

    public int solve(int m, int n, int i, int j) {
        if(i >= m || i < 0 || j >= n || j < 0)
            return 0;
           
        if(i == m-1 && j == n-1)
            return 1;
        
        if(t[i][j] != -1) 
            return t[i][j];
        
        return t[i][j] = solve(m, n, i+1, j) + solve(m, n, i, j+1);
    }

    public int uniquePaths(int m, int n) {
        t = new int[m][n];
        for (int[] row: t)
            Arrays.fill(row, -1);
        
        return solve(m, n, 0, 0);
    }

}
    
//Approach-2 (using Bottom Up) - T.C : O(m*n)
//Note : You can write C++ code above as simple as this one but I commented the code above for clarity and added some extra line of code for clarity
public class Solution {
    public int uniquePaths(int m, int n) {
        int[][] grid = new int[m][n];
        
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(i==0 || j==0)
                    grid[i][j] = 1;
                else
                    grid[i][j] = grid[i][j-1] + grid[i-1][j];
            }
        }
        
        return grid[m-1][n-1];
    }
}
