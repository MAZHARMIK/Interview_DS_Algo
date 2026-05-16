/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Google
    Leetcode Link               : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
*/

/*********************************************************** C++ **************************************************/
//Approach (Binary Search with Duplicate Elimination)
//T.C : O(log n) on average, O(n) in worst case due to duplicate skipping
//S.C : O(1)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;

        int resultIdx = 0;

        while(l <= r) {

            // remove duplicates from left
            while(l < r && nums[l] == nums[l + 1])
                l++;

            // remove duplicates from right
            while(l < r && nums[r] == nums[r - 1])
                r--;

            int mid = l + (r - l) / 2;

            // update answer
            if(nums[mid] < nums[resultIdx])
                resultIdx = mid;

            // minimum lies on right side
            if(nums[mid] > nums[r]) {
                l = mid + 1;
            }
            // minimum can be mid or on left side
            else {
                r = mid - 1;
            }
        }

        return nums[resultIdx];
    }
};

/*********************************************************** JAVA **************************************************/
//Approach (Binary Search with Duplicate Elimination)
//T.C : O(log n) on average, O(n) in worst case due to duplicate skipping
//S.C : O(1)
class Solution {
    public int findMin(int[] nums) {
        int l = 0;
        int r = nums.length - 1;

        int resultIdx = 0;

        while (l <= r) {

            // remove duplicates from left
            while (l < r && nums[l] == nums[l + 1])
                l++;

            // remove duplicates from right
            while (l < r && nums[r] == nums[r - 1])
                r--;

            int mid = l + (r - l) / 2;

            // update answer
            if (nums[mid] < nums[resultIdx])
                resultIdx = mid;

            // minimum lies on right side
            if (nums[mid] > nums[r]) {
                l = mid + 1;
            }
            // minimum can be mid or on left side
            else {
                r = mid - 1;
            }
        }

        return nums[resultIdx];
    }
}
