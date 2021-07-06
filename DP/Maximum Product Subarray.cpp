/*
    Company Tags  : Amazon, Microsoft, Morgan Stanley, Myntra, Myntra-Question
    Leetcode Link : https://leetcode.com/problems/maximum-product-subarray/
*/

//Smart variation of Kadane's Algorithm
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        
        int prev_max   = nums[0];
        int prev_min   = nums[0];
        int global_max = nums[0];
        
        int curr_max   = nums[0];
        int curr_min   = nums[0];
        
        for(int i = 1; i<n; i++) {
            curr_max   = max({nums[i], prev_max*nums[i], prev_min*nums[i]});
            
            curr_min   = min({nums[i], prev_max*nums[i], prev_min*nums[i]});
            
            global_max = max(global_max, curr_max);
            
            prev_max = curr_max;
            prev_min = curr_min;
        }
        
        return global_max;
    }
};
