/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=U1VsdRgVevY
    Company Tags                : Google, Adobe, Amazon, Microsoft, Morgan Stanley, Samsung, Snapdeal, Times Internet
    Leetcode Link               : https://leetcode.com/problems/search-in-rotated-sorted-array/
    Similar GfG Link            : https://practice.geeksforgeeks.org/problems/search-in-a-rotated-array4618/1
*/


class Solution {
public:
    int find_pivot(vector<int>& nums, int l, int r) {
        while(l < r) {
            int mid = l + (r-l)/2;
            
            if(nums[mid] > nums[r]) {
                l = mid+1;
            } else {
                r = mid;
            }
        }
        return r;
    }
    
    int binary_search(vector<int>& nums, int l, int r, int target) {
        while(l<=r) {
            int mid = l + (r-l)/2;
            if(nums[mid] == target)
                return mid;
            if(nums[mid] < target)
                l = mid+1;
            else
                r = mid-1;
        }
        
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = find_pivot(nums, 0, n-1);

        if(nums[pivot] == target)
            return pivot;
        
        int idx = -1;
        idx = binary_search(nums, pivot+1, n-1, target);
        if(idx != -1)
            return idx;
        idx = binary_search(nums, 0, pivot-1, target);
        return idx;
    }
};
