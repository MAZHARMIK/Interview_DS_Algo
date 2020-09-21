/*
    Company Tags : Accolite, Amazon, American Express, Expedia, MakeMyTrip, Microsoft, Payu, Snapdeal, Times Internet, Twitter
    Link to Qn   : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return NULL;
        
        if(root->val == p->val || root->val == q->val)
            return root;
        
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        
        if(l && r)
            return root;
        
        return l?l:r;
    }
};
