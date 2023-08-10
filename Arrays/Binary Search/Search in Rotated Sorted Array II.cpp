/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=eneo_XPUEj0
    Company Tags                : Adobe, Amazon, Microsoft, Morgan Stanley, Samsung, Snapdeal, Times Internet
    Leetcode Link               : https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
*/

class Solution {
public:
    int pivot(vector<int>& nums, int l, int r) {
        while(l < r) {
            
            while(l < r && nums[l] == nums[l+1])
                l++;
            
            while(r < l && nums[r] == nums[r-1])
                r--;
            
            /*
                You need to do what I did above because you'll fail in case like
                [1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1]
                2
                Here, the nums[mid] <= nums[r] and
                and we will cut down the right half but our pivot lies there
                So, make it a RULE, whenever there are duplicate elements and you need to to something
                like Binary Search, you need to ignore duplicates like done above
                Similar Qn : "Smallest element in a rotated sorted array with duplicates"
            */
            int mid = l + (r-l)/2;
            
            if(nums[mid] <= nums[r]) { //sorted part
                r = mid; //possibly my pivot
            } else {
                l = mid+1;
            }
        }
        
        return r;
    }
    
    bool binarySearch(vector<int>& nums, int l, int r, int& target) {
        while(l <= r) {
            int mid = l + (r-l)/2;
            
            if(nums[mid] == target)
                return true;
            
            if(nums[mid] < target)
                l = mid+1;
            else
                r = mid-1;
        }
        
        return false;
    }
    
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        
        
        int p = pivot(nums, 0 , n-1);
        cout <<"p = " << p << endl;
        if(binarySearch(nums, 0, p-1, target)) {
            return true;
        }
        
        return binarySearch(nums, p, n-1, target);
            
    }
};
