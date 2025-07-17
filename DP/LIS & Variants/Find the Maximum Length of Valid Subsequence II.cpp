/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=g38YHwee1Yo
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-ii
    LIS Printing Pattern Video  : https://youtu.be/rYuLUjRSTeo?si=Dm--R2jBXZmM8WtZ
*/


/**************************************************************** C++ ****************************************************************/
//Approach - Using LIS Pattern (Bottom Up)
//T.C : O(n^2)
//S.C : O(n*k)
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        //Using same LIS bottom up code

        int n = nums.size();
        
        //vector<int> dp1(n, 1); //mod1
        //vector<int> dp0(n, 1); //mod0
        // dp0 {} //mod0
        // dp1 {} //mod1
        //{
          //  {}, 0th row for mod0
           // {}  1st row for mod1         
        //}

        //row = 0 is for mod0
        //row = 1 is for mod1
        //row = 2 is for mod2
        //....
        //row = k-1 is for mod k-1
        vector<vector<int>> dp(k, vector<int>(n, 1));
        int maxSub = 1;

        //mod = 1
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                int mod = (nums[j] + nums[i]) % k;
                //mod = 0 = 0th row , %2 = 0 waale case ka result
                //mod = 1 = 1st row, %2 = 1 waale case ka result
                dp[mod][i] = max(dp[mod][i], 1 + dp[mod][j]);
                maxSub = max(maxSub, dp[mod][i]);
            }
        }


        return maxSub;
    }
};



/**************************************************************** JAVA ****************************************************************/
//Approach - Using LIS Pattern (Bottom Up)
//T.C : O(n^2)
//S.C : O(n*k)
class Solution {
    public int maximumLength(int[] nums, int k) {
        //Using same LIS bottom up code

        int n = nums.length;
        
        int[][] dp = new int[k][n];
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = 1;
            }
        }

        int maxSub = 1;

        //mod = 1
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                int mod = (nums[j] + nums[i]) % k;
                //mod = 0 = 0th row , %2 = 0 waale case ka result
                //mod = 1 = 1st row, %2 = 1 waale case ka result
                dp[mod][i] = Math.max(dp[mod][i], 1 + dp[mod][j]);
                maxSub = Math.max(maxSub, dp[mod][i]);
            }
        }

        return maxSub;
    }
}
