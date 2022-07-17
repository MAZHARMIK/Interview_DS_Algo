/*
  MY YOUTUBE VIDEO FOR THIS Qn : https://www.youtube.com/watch?v=Jin6vO0MdzY&list=PLpIkg8OmuX-LkgtrEF7eyyYWJM3m5tVQY&index=2
  Company Tags                 : Amazon, Adobe, Microsoft, Morgan Stanley, Samsung, Snapdeal, Times Internet
  Leetcode Qn Link             : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
*/

class Solution {
public:
    int findPivot(vector<int>& nums) {
        int mid;
        int l = 0, r = nums.size()-1;
        while(l < r) {
            mid = l + (r-l)/2;
          
            if(nums[mid] > nums[r]) { //something wrong on right side. Possibly my answer lies in right side.
                l = mid+1;            //move right (Discarding mid, because it's greater than nums[r], so it can't be the minimum element)
            } else {
                r = mid;
            }
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
