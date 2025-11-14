/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=GluIvp5NaGw
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/increment-submatrices-by-one
*/


/************************************************************ C++ ************************************************/
//Approach - Using Difference Array Technique similar to 1-D Array
//T.C : O(q*n + n*n)
//S.C : O(n*n) if we consider space of the result 2D Array , else O(1)
class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> diff(n, vector<int>(n, 0));

        //Same as Difference Array Technique in 1D Array

        //Step-1 Process query
        for(auto &query : queries) {
            int row1 = query[0];
            int col1 = query[1];

            int row2 = query[2];
            int col2 = query[3];

            for(int i = row1; i <= row2; i++) {
                diff[i][col1] += 1;

                if(col2 + 1 < n)
                    diff[i][col2+1] -= 1;
            }
        }

        ////Step-2 Now calculate prefix sum
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < n; j++) {
                diff[i][j] += diff[i][j-1];
            }
        }

        return diff;
    }
};



/************************************************************ JAVA ************************************************/
//Approach - Using Difference Array Technique similar to 1-D Array
//T.C : O(q*n + n*n)
//S.C : O(n*n) if we consider space of the result 2D Array , else O(1)
class Solution {
    public int[][] rangeAddQueries(int n, int[][] queries) {
        int[][] diff = new int[n][n];

        // Step 1: Process queries (Difference Array Technique)
        for (int[] q : queries) {
            int row1 = q[0];
            int col1 = q[1];
            int row2 = q[2];
            int col2 = q[3];

            for (int i = row1; i <= row2; i++) {
                diff[i][col1] += 1;
                if (col2 + 1 < n) {
                    diff[i][col2 + 1] -= 1;
                }
            }
        }

        // Step 2: Row-wise prefix sums
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n; j++) {
                diff[i][j] += diff[i][j - 1];
            }
        }

        return diff;
    }
}
