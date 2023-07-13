/*
    My YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : META, GOOGLE, AMAZON
    Leetcode Link               : https://leetcode.com/problems/maximum-alternating-subsequence-sum/

*/

//Approach-1 (Recursion + Memo)
class Solution {
public:
    int n;
    long long t[1000001][2];
    long long solve(int idx, vector<int>& nums, bool iseven) {
        
        if(idx >= n) {
            return 0;
        }
        
        if(t[idx][iseven] != -1)
            return t[idx][iseven];
        
        long long skip = solve(idx+1, nums, iseven);
        
        long long take = 0;
        if(iseven == true) {
            take = solve(idx+1, nums, !iseven) + nums[idx];
        } else {
            take = solve(idx+1, nums, !iseven) - nums[idx];
        }
        
        return t[idx][iseven] = max(skip, take);
        
    }
    
    long long maxAlternatingSum(vector<int>& nums) {
        n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(0, nums, true);
    }
};


//Approach-2 (Bottom Up)
