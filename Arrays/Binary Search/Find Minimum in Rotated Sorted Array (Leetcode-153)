/*
  Company Tags     : Amazon
  Leetcode Qn Link : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
*/

class Solution {
public:
    int findPivot(vector<int>& nums) {
        int mid;
        int l = 0, r = nums.size()-1;
        while(l < r) {
            mid = l + (r-l)/2;
            if(nums[mid] < nums[r])
                r  = mid;
            else
                l = mid+1;
        }
        return nums[l];
    }
    
    int findMin(vector<int>& nums) {
        return findPivot(nums);
    }
};

/*
NOTE : 
What's wring with below logic : 
if(nums[mid] > nums[l])
  l = mid+1;
else
  r = mid;
 
Because, you are moving away from minimum element here.
We should converge towards the side of array where the minimum element resides.
*/
