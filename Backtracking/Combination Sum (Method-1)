/*
    Company Tags  : Adobe, Amazon, Microsoft
    Leetcode Link : https://leetcode.com/problems/combination-sum/
*/

class Solution {
public:
    int Sum(vector<int>& arr) {
        int sum = 0;
        for(int i = 0; i<arr.size(); i++)
            sum += arr[i];
        return sum;
    }
    void combination(vector<int>& candidates, int target, vector<int> curr, vector<vector<int>>& result, int idx) {
        if(Sum(curr) > target || idx >= candidates.size())
            return;
        if(Sum(curr) == target) {
            result.push_back(curr);
            return;
        }
        curr.push_back(candidates[idx]);
        combination(candidates, target, curr, result, idx);
        curr.pop_back();
        combination(candidates, target, curr, result, idx+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        
        combination(candidates, target, curr, result, 0);
        return result;
    }
};
