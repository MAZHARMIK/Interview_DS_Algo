/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=lWU1wI7koGk
    Company Tags                : Meta
    Leetcode Link               : https://leetcode.com/problems/minimize-maximum-of-array/
    Similar Leetcode Qn         : https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/
*/

class Solution {
public:
    
    bool isValid(vector<int> &nums, int mid_max, int n) {
        
        vector<long long> arr(begin(nums), end(nums));
        
        for(int i = 0; i<n-1; i++) {
            
            if(arr[i] > mid_max)
                return false;
            
            long long buffer = mid_max - arr[i];
            
            arr[i+1] = arr[i+1] - buffer;   
            
        }
        
        return arr[n-1] <= mid_max;
        
    }
    
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        
        int maxL = 0;
        int maxR = *max_element(begin(nums), end(nums));
        
        int result;
        
        while(maxL <= maxR) {
            
            int mid_max = maxL + (maxR-maxL)/2;
            
            if(isValid(nums, mid_max, n)) {
                result = mid_max;
                maxR   = mid_max-1;
            } else {
                maxL = mid_max+1;
            }
            
        }
        
        return result;
    }
};
