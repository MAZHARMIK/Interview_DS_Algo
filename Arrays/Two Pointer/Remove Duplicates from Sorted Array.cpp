/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Facebook, Google, Amazon, Microsoft, Expedia, LinkedIn
    Leetcode Link               : https://leetcode.com/problems/remove-duplicates-from-sorted-array/
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int i = 0, j = 1;
        
        while(j < n) {
            if(nums[i] != nums[j]) nums[++i] = nums[j];
            j++;
        }
        
        return i+1;
    }
};
