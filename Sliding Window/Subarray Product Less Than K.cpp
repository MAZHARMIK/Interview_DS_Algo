/*
    Company Tags  : Yatra
    Leetcode Link : https://leetcode.com/problems/subarray-product-less-than-k/
*/


//Approach-1  : Sliding window , Time : O(N)
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1)
            return 0;
        int n = nums.size();
        int count = 0;
        
        int left = 0;
        int right = 0;
        int prod = 1;
        
        while(right < n){
            prod *= nums[right];
            
            while(prod >= k) {
                prod /= nums[left];
                left++;
            }
            
            count += (right-left)+1;
            right++;
        }
        return count;
    }
};
