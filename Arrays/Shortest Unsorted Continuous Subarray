/*
    Company Tags  : Google, Facebook, Amazon, LinkedIn, Microsoft, Uber, Apple, Adobe  (Very Popular and quite frequently asked :-) )
    Leetcode Link : https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
*/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        
        int Min = INT_MAX;
        int Max = INT_MIN;
        
        for(int i = 1; i<n; i++) {
            if(nums[i] < nums[i-1]) {
                Min = min(Min, nums[i]);
            }
        }
        
        for(int i = n-2; i>=0; i--) {
            if(nums[i] > nums[i+1]) {
                Max = max(Max, nums[i]);
            }
        }
        
        int start = 0;
        for(int i = 0; i<n; i++) {
            if(nums[i] > Min) {
                start = i;
                break;
            }
        }
        
        int end = 0;
        for(int i = n-1; i>=0; i--) {
            if(nums[i] < Max) {
                end = i;
                break;
            }
        }
        
        return end-start<=0?0:end-start+1;
    }
};
