/*
    Company Tags  : Google
    Leetcode Link : https://leetcode.com/problems/wiggle-sort/
    
    Since it's a premium Qn, I have provided the Description and examples below:
    
    Description:
    Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....

    For example, given nums = [3, 5, 2, 1, 6, 4], one possible answer is [1, 6, 2, 5, 3, 4]. 
    
    Note : Please sort the array in place and do not define additional arrays.
*/

/*
    Approach : You just need to take care of next index for even and odd indices
               Wiggle sort will be done automatically
*/

class Solution {
public:
    void wiggleSort(vector<int> &nums) {
        int n = nums.size();

        for(int i = 0; i<n-1; i++) {
            if(i%2 == 0) {
                if(nums[i] > nums[i+1])
                    swap(nums[i], nums[i+1]);
            } else {
                if(nums[i] < nums[i+1])
                    swap(nums[i], nums[i+1]);
            }
        }
    }
};
