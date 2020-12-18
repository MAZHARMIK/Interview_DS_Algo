/*
    Company Tags  : Amazon, Microsoft, Google
    Leetcode Link : https://leetcode.com/problems/4sum/
*/

class Solution {
public:
    void twoSum(vector<vector<int>>& result, vector<int>& nums, int i, int j, int n, int target) {
        int k = j+1, l = n-1;
        while(k<l) {
            if(nums[k] + nums[l] > target)
                l--;
            else if(nums[k] + nums[l] < target)
                k++;
            else {
                result.push_back({nums[i], nums[j], nums[k], nums[l]});
                while( k < n-1 && nums[k] == nums[k+1]) k++;
                while(l  > 0 && nums[l] == nums[l-1]) l--;
                k++;
                l--;
            }
        }
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> result;
        if(n < 4)
            return result;
        for(int i = 0; i<n-3; i++) {
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            for(int j = i+1; j<n-2; j++) {
                if(j > i+1 && nums[j] == nums[j-1])
                    continue;
                int subTarget = target-(nums[i]+nums[j]);
                twoSum(result, nums, i, j, n, subTarget);
            }
        }
        return result;
    }
};
