/*
    MY YOUTUBE VIDEO ON THIS Qn   : https://www.youtube.com/watch?v=S3ocpdBL-7Y
    Company Tags                  : GOOGLE
    Leetcode Link                 : https://leetcode.com/problems/longest-arithmetic-subsequence/
*/

//Approach-1 : Recursion + Memoization (TLE)
class Solution {
public:
    int n;
    int t[1001][1003];
    
    int solve(vector<int>& nums, int i, int diff) {
        
        if(i < 0)
            return 0;
        
        if(t[i][diff+501] != -1)
            return t[i][diff+501];
        
        int ans = 0;
        
        for(int k = i-1; k >= 0; k--) {
            
            if(nums[i] - nums[k] == diff)
                ans = max(ans, 1 + solve(nums, k, diff));
            
        }
        
        return t[i][diff+501] = ans;
    }
    
    int longestArithSeqLength(vector<int>& nums) {
        n = nums.size();
        if(n <= 2)
            return n;
        
        memset(t, -1, sizeof(t));
        
        
        int result = 0;
        
        for(int i = 0; i<n; i++) {
            for(int j = i+1; j < n; j++) {
                
                result = max(result, 2 + solve(nums, i, nums[j] - nums[i]));
                
            }
        }
        
        return result;
    }
};


//Approach-2 (Just solve it like Longest Increasing Subsequence)
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        
        if(n <= 2)
            return n;
        
        vector<vector<int>> t(n, vector<int>(1001,0));
        //t[i][j] = Max AP length till ith index (0 to i) having common difference j

        int result = 0;
        
        for (int i = 1; i<n; i++) {
            
            for (int j=0; j<i; j++) {
                
                int diff    = nums[i] - nums[j] + 500; //to avoid negative diff
                
                t[i][diff] = t[j][diff] > 0 ? t[j][diff] + 1 : 2;
                
                result      = max(result, t[i][diff]);
            }
        }

        return result;
    }
};
