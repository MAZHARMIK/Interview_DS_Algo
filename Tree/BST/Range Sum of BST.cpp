/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=qIFhQ2m6i64
    Company Tags                : Google, Amazon, D.E. Shaw 
    Leetcode Link               : https://leetcode.com/problems/range-sum-of-bst/
    GfG Link                    : https://practice.geeksforgeeks.org/problems/count-bst-nodes-that-lie-in-a-given-range/1
*/

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root)
            return 0;
        
        //Within Range
        if(root->val >= low && root->val <= high) {
            return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
        }
        
        //When outside the range (Less than low) - Go right
        if(root->val < low)
            return rangeSumBST(root->right, low, high);

        //When outside the range (Greater than high) - Go left
        return rangeSumBST(root->left, low, high);
    }
};
