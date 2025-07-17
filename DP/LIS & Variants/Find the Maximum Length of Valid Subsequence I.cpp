/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=g38YHwee1Yo
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-i
    LIS Printing Pattern Video  : https://youtu.be/rYuLUjRSTeo?si=Dm--R2jBXZmM8WtZ
*/


/**************************************************************** C++ ****************************************************************/
//Approach - 1 - Using LIS Pattern (Recursion) - Memoization will give MLE due to high constraints
//T.C : Without Memoization O(2^n), With memoization - O(n^2) but MLE
//S.C : O(n^2)
class Solution {
public:

    int LIS(vector<int>& nums, int i, int prev, int mod) {
        if(i >= nums.size()) {
            return 0;
        }

        int take = 0;
        int skip = 0;
        
        //take
        if(prev == -1 || (nums[prev] + nums[i])%2 == mod) {
            take = 1 + LIS(nums, i+1, i, mod);
        }

        //skip
        skip = LIS(nums, i+1, prev, mod);

        return max(take, skip);
    }

    int maximumLength(vector<int>& nums) {
        int maxSubLength = 0;

        maxSubLength = max(maxSubLength, LIS(nums, 0, -1, 0)); //%2 == 0 k lie
        maxSubLength = max(maxSubLength, LIS(nums, 0, -1, 1)); //%2 == 1 k lie

        return maxSubLength;

    }
};



//Approach - 2 - Using LIS Pattern (Bottom Up) - TLE
//T.C : O(n^2) but TLE
//S.C : O(n)
class Solution {
public:
    int maximumLength(vector<int>& nums) {
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
        vector<vector<int>> dp(2, vector<int>(n, 1));
        int maxSub = 1;

        //mod = 1
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                int mod = (nums[j] + nums[i])%2;
                //mod = 0 = 0th row , %2 = 0 waale case ka result
                //mod = 1 = 1st row, %2 = 1 waale case ka result
                dp[mod][i] = max(dp[mod][i], 1 + dp[mod][j]);
                maxSub = max(maxSub, dp[mod][i]);
            }
        }


        return maxSub;
    }
};
