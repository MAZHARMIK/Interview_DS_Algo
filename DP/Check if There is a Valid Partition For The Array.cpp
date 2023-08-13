/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=tofpb5rIwRk
      Company Tags                : GOOGLE
      Leetcode Link               : https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/
*/

************************************************************ C++ ************************************************************
//Approach-1 (Using Recursion + Memoization)
//Recursion T.C : O(3^n) - Trying 3 different possibilities for every i
//Memoization T.C : O(n) - We will visit max n states
class Solution {
public:
    int n;
    int t[100001];
    bool solve(vector<int>& nums, int i) {
        
        if(i >= n)
            return true;
        
        if(t[i] != -1)
            return t[i];
        
        bool result = false;
        
        if(i+1 < n && nums[i] == nums[i+1])
            result |= solve(nums, i+2);
        
        if(i+2 < n && nums[i] == nums[i+1] && nums[i+1] == nums[i+2])
            result |= solve(nums, i+3);
        
        if(i+2 < n && nums[i+1] - nums[i] == 1 && nums[i+2] - nums[i+1] == 1)
            result |= solve(nums, i+3);
        
        return t[i] = result;
        
    }
    
    bool validPartition(vector<int>& nums) {
        n = nums.size();
        
        memset(t, -1, sizeof(t));
        
        return solve(nums, 0);
        
    }
};


//Approach-2 (Bottom Up)
//Soon - in my "DP Concepts & Qns" playlist







************************************************************ JAVA ************************************************************
//Approach-1 (Using Recursion + Memoization)
//Recursion T.C : O(3^n) - Trying 3 different possibilities for every i
//Memoization T.C : O(n) - We will visit max n states
class Solution {
    public boolean validPartition(int[] nums) {
        return solve(nums, 0, new Boolean[nums.length]);
    }
    
    public boolean solve(int[] nums, int i, Boolean[] dp){
        if(i == nums.length)
            return true;
        
        if(dp[i] != null)
            return dp[i];

        boolean result = false;
        
        if((i + 1) < nums.length && (nums[i] == nums[i+1]))
            result |= solve(nums, i+2, dp);
        
        if((i + 2) < nums.length && nums[i] == nums[i+1] && nums[i+1] == nums[i+2])
            result |= solve(nums, i+3, dp);
        
        if((i + 2) < nums.length && ((nums[i] + 1) == nums[i+1]) && ((nums[i] + 2) == nums[i+2]))
            result |= solve(nums, i+3, dp);

        return dp[i] = result;
    }
}
