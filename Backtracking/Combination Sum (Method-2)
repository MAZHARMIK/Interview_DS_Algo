/*
    Company Tags  : Adobe, Amazon, Microsoft
    Leetcode Link : https://leetcode.com/problems/combination-sum/
*/

class Solution {
public:
    void combination(vector<int>& candidates, int target, vector<int> curr, vector<vector<int>>& result, int idx) {
        if(target < 0)
            return;
        if(target == 0) {
            result.push_back(curr);
            return;
        }
        
        for(int i = idx; i < candidates.size(); i++) {
            curr.push_back(candidates[i]);
            combination(candidates, target-candidates[i], curr, result, i);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        
        combination(candidates, target, curr, result, 0);
        return result;
    }
};
