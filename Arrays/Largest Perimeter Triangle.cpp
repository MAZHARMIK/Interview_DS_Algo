/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=wukuOrHM3eg
    Company Tags                : C3.ai
    Leetcode Link               : https://leetcode.com/problems/largest-perimeter-triangle/
    
*/

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        
        sort(begin(nums), end(nums));
        
        for(int i = n-3; i>=0; i--) {
            //nums[i] < nums[i+1] < nums[i+2]
            
            if(nums[i] + nums[i+1] > nums[i+2]) //a + b > c
                return nums[i] + nums[i+1] + nums[i+2];
        }
        
        return 0;
        
    }
};
