/*
    Company Tags              : NIL (Leetcode Weekly Contest)
    Leetcode Link             : https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/
    Same Question on Leetcode : https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/
*/

class Solution {
public:
    map<TreeNode*, int> heightNode;
    int max_h = 0;
    TreeNode* lowestCommonAncestor(TreeNode* root) {
        if(!root || heightNode[root] == max_h)
            return root;
        TreeNode* l = lowestCommonAncestor(root->left);
        TreeNode* r = lowestCommonAncestor(root->right);
        if(l && r)
            return root;
        return l?l:r;
    }
    
    void collectLeaves(TreeNode* root, int h) {
        if(!root)
            return;
        max_h = max(max_h, h);
        heightNode[root] = h;
        
        collectLeaves(root->left, h+1);
        collectLeaves(root->right, h+1);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int h = 0;
        collectLeaves(root, h);        
        return lowestCommonAncestor(root);
    }
};
