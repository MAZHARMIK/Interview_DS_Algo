/*     Scroll below to see JAVA code also   */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=dYsJpsgCPzw
    Company Tags                : Google
    Leetcode Link               : https://leetcode.com/problems/count-submatrices-with-all-ones
*/


/************************************************** C++ **************************************************/
//Approach (Using same concept as finding subarrays having all 1s in a 1D Array)
//T.C : O(m * m * n)
//S.C : O(n)
class Solution {
public:

    int OnedArrayCount(vector<int>& vec) {
        int cons = 0;
        int subCount = 0;

        for(int &val : vec) {
            if(val == 0) {
                cons = 0;
            } else {
                cons++;
            }

            subCount += cons;
        }

        return subCount;
    }

    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int result = 0;
        //O(m*m*n)
        for(int startRow = 0; startRow < m; startRow++) {

            vector<int> vec(n, 1);
            for(int endRow = startRow; endRow < m; endRow++) {
                
                for(int col = 0; col < n; col++) {
                    vec[col] = vec[col] & mat[endRow][col];
                }

                result += OnedArrayCount(vec);
            }
        }

        return result;
    }
};



/************************************************** JAVA **************************************************/
//Approach (Using same concept as finding subarrays having all 1s in a 1D Array)
//T.C : O(m * m * n)
//S.C : O(n)
class Solution {

    // Helper function: counts subarrays of consecutive 1s in a row
    private int countSubarraysOfOnes(int[] rowMask) {
        int consecutiveOnes = 0;
        int subarrayCount = 0;

        for (int val : rowMask) {
            if (val == 0) {
                consecutiveOnes = 0;
            } else {
                consecutiveOnes++;
            }
            subarrayCount += consecutiveOnes;
        }

        return subarrayCount;
    }

    public int numSubmat(int[][] mat) {
        int rows = mat.length;
        int cols = mat[0].length;

        int totalCount = 0;

        // Fix the starting row
        for (int topRow = 0; topRow < rows; topRow++) {
            // rowMask[col] = 1 if column col has all 1s between topRow..bottomRow
            int[] rowMask = new int[cols];
            for (int i = 0; i < cols; i++) rowMask[i] = 1;

            // Expand bottom row
            for (int bottomRow = topRow; bottomRow < rows; bottomRow++) {
                // Update rowMask using AND
                for (int col = 0; col < cols; col++) {
                    rowMask[col] = rowMask[col] & mat[bottomRow][col];
                }

                // Count submatrices from this row span
                totalCount += countSubarraysOfOnes(rowMask);
            }
        }

        return totalCount;
    }
}
