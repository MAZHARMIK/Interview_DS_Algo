/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=7jIWcMDxT28&list=PLpIkg8OmuX-K23LhcamOcDlTBisiNJy5E&index=12
    Company Tags                : Amazon, Microsoft, Accolite, Adobe, CouponDunia, FactSet, Goldman Sachs, Housing.com, Oracle, Samsung, Atlassian
    Leetcode Qn Link            : https://leetcode.com/problems/path-sum/
*/
class Solution {
public:
    bool pathSum(TreeNode* root, int sum, int curr) {
        if(!root)
            return false;
        
        if(!root->left && !root->right)
            return ((curr+root->val) == sum);
        
        bool l = pathSum(root->left,  sum, curr+root->val);
        bool r = pathSum(root->right, sum, curr+root->val);
        return l||r;
    }
    bool hasPathSum(TreeNode* root, int sum) {
        return pathSum(root, sum, 0);
    }
};
