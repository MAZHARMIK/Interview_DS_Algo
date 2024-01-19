/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=EQC0ckOyEGs
    Company Tags                : Google, Microsoft, Amazon, Flipkart, OLA, Goldman Sachs, MakeMyTrip, OYO Rooms, Samsung
    Leetcode Link               : https://leetcode.com/problems/minimum-falling-path-sum/
    
    Similar tough problem : Leetcode - 1937 : Maximum Number of Points with Cost  (Must Try !!!!)
*/

/*************************************************************** C++ ***************************************************************/
//Approach-1 (Recur + Memoization) : O(m*n) (New test Case has been added, this will give TLE in last Test Case) (49 / 50 testcases passed)
//T.C : O(m*n)
//S.C : O(101) ~ O(1) (Excluding stack recursion space)
class Solution {
public:
    int MFS(vector<vector<int>>& A, int row, int col, vector<vector<int>>& t) {
        if(row == A.size()-1)
            return A[row][col];
        if(t[row][col] != -1)
            return t[row][col];
        
        int minSum = INT_MAX;
        
        for(int shift = -1; shift<=1; shift++) {
            if(col + shift >=0 && col+shift < A[row].size()) {
                minSum = min(minSum, A[row][col] + MFS(A, row+1, col+shift, t));
            }
        }
        
        return t[row][col] = minSum;
    }
    int minFallingPathSum(vector<vector<int>>& A) {
        int m = A.size(); //row
        int n = m; //column
        vector<vector<int>> t(101, vector<int>(101));
        for(int i = 0; i<101; i++) {
            for(int j = 0; j<101; j++) {
                t[i][j] = -1;
            }
        }
        int result = INT_MAX;
        for(int col = 0; col<n; col++) {
            result = min(result, MFS(A, 0, col, t));
        }
        return result;
    }
};

//Approach-2 (Bottom UP DP) : O(m*n)
//T.C : O(m*n)
//S.C :  O(m*n)
class Solution {
public:
    int MFS(vector<vector<int>>& A) {
        int m = A.size();
        vector<vector<int>> t(m, vector<int>(m));
        
        //initialization
        for(int col = 0; col<m; col++) {
            t[0][col] = A[0][col];
        }
        
        for(int row = 1; row < m; row++) {
            for(int col = 0; col < m; col++) {
                t[row][col] = A[row][col] + min({t[row-1][col], 
                                                 t[row-1][max(0, col-1)], 
                                                 t[row-1][min(m-1, col+1)]});
            }
        }

        return *min_element(t[m-1].begin(), t[m-1].end());
        
    }
    int minFallingPathSum(vector<vector<int>>& A) { 
        return MFS(A);
    }
};


//Approach-3 (Bottom Up Space Optimized)
//T.C : O(m*n)
//S.C :  O(m*n)
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n = A.size();
        vector<int> prev(n);
        for(int col = 0; col<n; col++)
            prev[col] = A[0][col];
        
        for(int row = 1; row<n; row++) {
            vector<int> curr(n);
            for(int col = 0; col<n; col++) {
                curr[col] = A[row][col] + min({prev[max(0, col-1)],  prev[col],  prev[min(n-1, col+1)]});
            }
            prev = curr;
        }
        return *min_element(prev.begin(), prev.end());
    }
};



/*************************************************************** JAVA ***************************************************************/
//Approach-1 (Recur + Memoization) : O(m*n) (New test Case has been added, this will give TLE in last Test Case) (49 / 50 testcases passed)
//T.C : O(m*n)
//S.C : O(101) ~ O(1) (Excluding stack recursion space)
public class Solution {
    public int minFallingPathSum(int[][] A) {
        int m = A.length; // row
        int n = m; // column
        int[][] t = new int[101][101];
        for (int[] row : t) {
            Arrays.fill(row, -1);
        }
        int result = Integer.MAX_VALUE;
        for (int col = 0; col < n; col++) {
            result = Math.min(result, MFS(A, 0, col, t));
        }
        return result;
    }

    private int MFS(int[][] A, int row, int col, int[][] t) {
        if (row == A.length - 1)
            return A[row][col];
        if (t[row][col] != -1)
            return t[row][col];

        int minSum = Integer.MAX_VALUE;

        for (int shift = -1; shift <= 1; shift++) {
            if (col + shift >= 0 && col + shift < A[row].length) {
                minSum = Math.min(minSum, A[row][col] + MFS(A, row + 1, col + shift, t));
            }
        }

        return t[row][col] = minSum;
    }
}


//Approach-2 (Bottom UP DP) : O(m*n)
//T.C : O(m*n)
//S.C :  O(m*n) space
class Solution {
    public int minFallingPathSum(int[][] matrix) {
        int m = matrix.length;
        int[][] t = new int[m][m];

        // initialization
        for (int col = 0; col < m; col++) {
            t[0][col] = matrix[0][col];
        }

        for (int row = 1; row < m; row++) {
            for (int col = 0; col < m; col++) {
                t[row][col] = matrix[row][col] + Math.min(
                        t[row - 1][col],
                        Math.min(t[row - 1][Math.max(0, col - 1)], t[row - 1][Math.min(m - 1, col + 1)])
                );
            }
        }

        return Arrays.stream(t[m - 1]).min().orElse(0);
    }
}


//Approach-3 (Bottom Up Space Optimized)
//T.C : O(m*n)
//S.C :  O(m*n) space
class Solution {
    public int minFallingPathSum(int[][] A) {
        int n = A.length;
        int[] prev = new int[n];
        
        // Initialize the first row of prev array
        for (int col = 0; col < n; col++) {
            prev[col] = A[0][col];
        }
        
        // Iterate over the remaining rows
        for (int row = 1; row < n; row++) {
            int[] curr = new int[n];
            for (int col = 0; col < n; col++) {
                curr[col] = A[row][col] + Math.min(Math.min(prev[Math.max(0, col - 1)], prev[col]), prev[Math.min(n - 1, col + 1)]);
            }
            prev = curr;
        }
        
        // Return the minimum element in the last row of the dp array
        int minPathSum = Integer.MAX_VALUE;
        for (int value : prev) {
            minPathSum = Math.min(minPathSum, value);
        }
        
        return minPathSum;
    }
}
