/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=mKFqKaD7g34
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/delete-columns-to-make-sorted-iii
    LIS Printing Pattern Video  : https://youtu.be/rYuLUjRSTeo?si=Dm--R2jBXZmM8WtZ
*/


/**************************************************************** C++ ****************************************************************/
//Approach - Using LIS Khandani Template
//T.C : O(cols*cols*rows)
//S.C : O(cols)
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int rows = strs.size();
        int cols = strs[0].length();

        vector<int> dp(cols, 1);
        //dp[i] = LIS ending at index i

        int LIS = 1;

        //Khandani LIS Pattern
        for(int i = 0; i < cols; i++) {
            for(int j = 0; j < i; j++) {

                bool valid = true;
                for(int k = 0; k < rows; k++) {
                    if(strs[k][j] > strs[k][i]) {
                        valid = false;
                        break;
                    }
                }

                if(valid) {
                    dp[i] = max(dp[i], dp[j]+1);
                }

            }

            LIS = max(LIS, dp[i]);
        }

        return cols - LIS;

    }
};



/**************************************************************** JAVA ****************************************************************/
//Approach - Using LIS Khandani Template
//T.C : O(cols*cols*rows)
//S.C : O(cols)
class Solution {
    public int minDeletionSize(String[] strs) {
        int rows = strs.length;
        int cols = strs[0].length();

        int[] dp = new int[cols];
        // dp[i] = LIS ending at column i

        int LIS = 1;

        for (int i = 0; i < cols; i++) {
            dp[i] = 1;

            for (int j = 0; j < i; j++) {

                boolean valid = true;
                for (int k = 0; k < rows; k++) {
                    if (strs[k].charAt(j) > strs[k].charAt(i)) {
                        valid = false;
                        break;
                    }
                }

                if (valid) {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
            }

            LIS = Math.max(LIS, dp[i]);
        }

        return cols - LIS;
    }
}
