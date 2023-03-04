/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=z6LwIkEn9qc
    Company Tags                : Microsoft
    Leetcode Link               : https://leetcode.com/problems/count-subarrays-with-fixed-bounds/
*/

//Approach-1 (Brute Force)
//Find all subarrays and check if min is minK and max is maxK
//Code will be provided soon for brute force

//Approach-2 (Optimal O(n)) - Sliding Window
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        
        int minPosition = -1;
        int maxPosition = -1;
        int leftBound   = -1;
        
        for(int i = 0; i < nums.size(); i++) {
            
            if(nums[i] < minK || nums[i] > maxK)
                leftBound = i;
            
            if(nums[i] == minK)
                minPosition = i;
            if(nums[i] == maxK)
                maxPosition = i;
            
            int count = min(maxPosition, minPosition) - leftBound;
            
            ans += (count <= 0) ? 0 : count;
            
        }
        
        return ans;
    }
};
