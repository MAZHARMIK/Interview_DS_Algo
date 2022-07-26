/*
    Leetcode Link  : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
    GfG Link       : https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1
    Company Tags   : Twitter, Google, Accolite, Amazon, American Express, Cisco, Expedia, Flipkart, MakeMyTrip, Microsoft, OYO Rooms, PayPal, Payu, Snapdeal, 
                    Times Internet
*/


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return NULL;
        
        if(root == p || root == q)
            return root;
        
        TreeNode* leftN  = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightN = lowestCommonAncestor(root->right, p, q);
        
        if(leftN && rightN)
            return root;
        
        return leftN ? leftN : rightN;
    }
};

