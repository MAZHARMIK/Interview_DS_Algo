/*
    Company Tags  : Airbnb, Microsoft
    Leetcode Link : https://leetcode.com/problems/house-robber-ii/
*/


//Approach-1 (Recur + Memo)
class Solution {
public:
    int t[101];
    int solve(vector<int>& nums, int idx, int n) {
        if(idx > n)
            return 0;
        
        if(t[idx] != -1)
            return t[idx];
        
        int take  = nums[idx] + solve(nums, idx+2, n);
        int skip  = solve(nums, idx+1, n);
        
        return t[idx] = max(take, skip);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        
        if(n == 2)
            return max(nums[0], nums[1]);
        
        memset(t, -1, sizeof(t));
        
        int take_first_house = solve(nums, 0, n-2);
        memset(t, -1, sizeof(t));
        int skip_first_house = solve(nums, 1, n-1);
        
        
        return max(take_first_house, skip_first_house);
    }
};

//Approach-2 (Bottom UP)
class Solution {
public:
    
    //this function is solution of House robber I. We just use it to solve House Robber II
    int solve(vector<int>& nums, int l, int r) {
        int prev = 0, curr = 0;
        
        for(int i = l; i<=r; i++) {
            int temp = max(nums[i] + prev, curr);
            
            prev = curr;
            curr = temp;
        }
        
        return curr;
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        
        if(n == 2)
            return max(nums[0], nums[1]);
        
        int take_first_house = solve(nums, 0, n-2);
        
        int skip_first_house = solve(nums, 1, n-1);
        
        
        return max(take_first_house, skip_first_house);
    }
};
