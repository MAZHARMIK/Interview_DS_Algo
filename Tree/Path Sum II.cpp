/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=eoyO8hOkPNs&t=3s
    Company Tags                : Bloomberg, LinkedIn, Amazon, Bloomberg, Quora
    Leetcode Link               : https://leetcode.com/problems/path-sum-ii/
*/

class Solution {
public:
    void collectPaths(TreeNode* root, int curr, vector<int>& temp, vector<vector<int>>& result) {
        if(!root)
            return;
        temp.push_back(root->val);
        if(root->left == NULL && root->right == NULL && root->val == curr) {
            result.push_back(temp);
        }
        
        collectPaths(root->left, curr-root->val, temp, result);
        collectPaths(root->right, curr-root->val, temp, result);
        temp.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        
        vector<int> temp;
        collectPaths(root, sum, temp, result);
        return result;
    }
};
