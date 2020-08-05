/*
  Company Tags     : Amazon
  Leetcode Qn Link : https://leetcode.com/problems/subarray-sum-equals-k/
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int result = 0;
        int sum = 0;
        map<int, int> mp;
        mp.insert({0,1});
        int n = nums.size();
        for(int i = 0; i<n; i++) {
            sum += nums[i];
            
            if(mp.count(sum-k))
                result += mp[sum-k];
            
            mp[sum]++;
        }
        return result;
    }
};
