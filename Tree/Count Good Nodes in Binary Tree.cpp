/*
    Company Tags  : Not known yet
    Leetcode Link : https://leetcode.com/problems/count-good-nodes-in-binary-tree/
*/

class Solution {
public:
    int count = 0;
    void dfs(TreeNode* root, int val) {
        if(!root)
            return;
        
        if(root->val >= val)
            count++;
        
        dfs(root->left,  max(root->val, val));
        dfs(root->right, max(root->val, val));
    }
    
    int goodNodes(TreeNode* root) {
        if(!root)
            return 0;
        
        dfs(root, root->val);
        return count;
    }
};
