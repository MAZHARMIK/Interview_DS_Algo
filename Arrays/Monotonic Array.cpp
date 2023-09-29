/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=LfYSyPP6YOA
      Company Tags                : META (3 Times)
      Leetcode Link               : https://leetcode.com/problems/monotonic-array/
*/

/*************************** C++ ***************************/
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        
        bool increasing = false;
        bool decreasing = false;
        
        for(int i = 0; i < n-1; i++) {
            if(nums[i] < nums[i+1]) increasing = true;
            
            if(nums[i] > nums[i+1]) decreasing = true;

        }
        
        if(increasing == true && decreasing == true)
                return false;
        
        return true;
    }
};

/*************************** JAVA ***************************/
class Solution {
    public boolean isMonotonic(int[] nums) {
        int n = nums.length;
        
        boolean increasing = false;
        boolean decreasing = false;
        
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] < nums[i+1]) {
                increasing = true;
            }
            
            if(nums[i] > nums[i+1]) {
                decreasing = true;
            }
        }
        
        return !(increasing && decreasing);
    }
}
