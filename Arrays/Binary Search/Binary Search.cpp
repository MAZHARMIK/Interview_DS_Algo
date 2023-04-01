/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Rxf93Ey1fpA
    Company Tags                : Everyone :-)
    Leetcode Link               : https://leetcode.com/problems/binary-search/
*/

//Iterative : O(log(n))
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        
        int l = 0, r = n-1;
        
        int mid = 0;
        
        while(l <= r) {
            
            mid = l + (r-l)/2;
            
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                l = mid+1;
            else
                r = mid-1;
        }
        
        return -1;
    }
};


//Recursive : O(log(n))
class Solution {
public:
    
    int solve(vector<int>& nums, int l, int r, int target) {
        if(l > r)
            return -1;
        
        int mid = l + (r-l)/2;
        
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] < target)
            return solve(nums, mid+1, r, target);
        else
            return solve(nums, l, mid-1, target);
    }
    
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        
        return solve(nums, 0, n-1, target);
    }
};
