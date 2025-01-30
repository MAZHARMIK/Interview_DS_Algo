/*     Scroll below to see JAVA code also   */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=ca9ND5_EQxk
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/maximum-matrix-sum
*/


/******************************************** C++ ********************************************/
//Approach - Check Odd or Even count of -ves
//T.C : O(row*col)
//S.C : O(1)
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        long long sum = 0;
        int countNegatives = 0; 
        int smallestAbsoluteValue = INT_MAX;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                sum += abs(matrix[i][j]);

                countNegatives += matrix[i][j] < 0 ? 1 : 0;

                smallestAbsoluteValue = min(smallestAbsoluteValue, abs(matrix[i][j]));

            }
        }

        if(countNegatives%2 == 0) {
            return sum;
        }

        return sum - 2*smallestAbsoluteValue;
    }
};



/******************************************** JAVA ********************************************/
//Approach - Check Odd or Even count of -ves
//T.C : O(row*col)
//S.C : O(1)
class Solution {
    public long maxMatrixSum(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;

        long sum = 0;
        int countNegatives = 0;
        int smallestAbsoluteValue = Integer.MAX_VALUE;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sum += Math.abs(matrix[i][j]);

                if (matrix[i][j] < 0) {
                    countNegatives++;
                }

                smallestAbsoluteValue = Math.min(smallestAbsoluteValue, Math.abs(matrix[i][j]));
            }
        }

        if (countNegatives % 2 == 0) {
            return sum;
        }

        return sum - 2L * smallestAbsoluteValue;
    }
}
