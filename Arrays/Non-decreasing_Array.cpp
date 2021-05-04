/*
    Company Tags  : Google
    Leetcode Link : https://leetcode.com/problems/non-decreasing-array/
*/

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        bool modify = false;
        int min = INT_MIN;
        for(int i = 0; i<n-1; i++) {
            if(nums[i] <= nums[i+1])
                min = nums[i];
            else {
                if(nums[i+1] < min) {
                    //For example : 3, 4, 1  (I would want to make 1 -> 4) i.e. (3, 4, 4)
                    //nums[i+1] = 1
                    //nums[i]   = 4
                    //min       = 3
                    nums[i+1] = nums[i];
                }
                if(modify)
                    return false;
                modify = true;
            }
        }
        
        return true;
    }
};
