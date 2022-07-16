/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=_cBWWebTVpI&list=PLpIkg8OmuX-K6A0sEPFxOSJh4_AjCGAFf&index=4
    Company Tags                : Amazon, Facebook, Google
    Question on GfG             : Find triplets with zero sum (https://practice.geeksforgeeks.org/problems/find-triplets-with-zero-sum/1)
    Leetcode Qn Link            : https://leetcode.com/problems/3sum/
*/

class Solution {
public:
    void twoSum(vector<int>& nums, int k, vector<vector<int>>& result, int target) {
        //Two pointer technique (Sorted array) Things you must not forget in interviews
        
        int i = k, j = nums.size()-1;
        while(i < j) {
            if(nums[i]+nums[j] > target)
                j--;
            else if(nums[i] + nums[j] < target)
                i++;
            else {
                result.push_back({-target, nums[i], nums[j]});
                while(i < j && nums[i] == nums[i+1]) i++;
                while(i < j && nums[j] == nums[j-1]) j--;
                i++; //Things you must not forget in interviews
                j--; //Things you must not forget in interviews
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3) //Things you must not forget in interviews
            return {};
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for(int i = 0; i<nums.size()-2; i++) {  //(i<nums.size()-2)Things you must not forget in interviews
            if(i!= 0 && nums[i] == nums[i-1]) { //Things you must not forget in interviews
                continue;
            }
            twoSum(nums, i+1, result, -nums[i]);
        }
        return result;
    }
};
