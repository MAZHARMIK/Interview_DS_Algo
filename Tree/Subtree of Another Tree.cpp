/*
    Company Tags  : Facebook, eBay
    Frequency     : 28%
    Leetcode Link : https://leetcode.com/problems/subtree-of-another-tree/
*/

class Solution {
public:
    bool check(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot)
            return true;
        if(!root || !subRoot) return false;
        
        if(root->val == subRoot->val && check(root->left, subRoot->left)
          && check(root->right, subRoot->right))
            return true;
        
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root)
            return false;
        
        if(check(root, subRoot))
            return true;
        
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
