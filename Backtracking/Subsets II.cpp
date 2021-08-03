/*
    Company Tags  : Snapdeal
    Leetcode Link : https://leetcode.com/problems/subsets-ii/
*/

class Solution {
public:
    void generate(vector<int>& nums, vector<int> sub, vector<vector<int>>& result, int start) {
        result.push_back(sub);
        
        for(int i = start; i<nums.size(); i++) {
            if(i > start && nums[i] == nums[i-1])
                continue;
            sub.push_back(nums[i]);
            generate(nums, sub, result, i+1);
            sub.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> sub;
        sort(nums.begin(), nums.end());
        generate(nums, sub, result, 0);
        return result;
    }
};
