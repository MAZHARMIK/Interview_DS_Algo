/*
    MY YOUTUBE VIDE ON THIS Qn : https://www.youtube.com/watch?v=2XTXL7a6ItI
    Company Tags               : Amazon, Microsoft, Salesforce, Facebook
    Leetcode Link              : https://leetcode.com/problems/count-complete-tree-nodes/
*/

//Time Complexity : O(log(n) * log(n))
class Solution {
public:
    int leftHeight(TreeNode* root) {
        if(!root)
            return 0;
        
        int lh = 0;
        TreeNode* temp = root;
        while(temp) {
            temp = temp->left;
            lh++;
        }
        return lh;
    }
    int rightHeight(TreeNode* root) {
        if(!root)
            return 0;
        
        int rh = 0;
        TreeNode* temp = root;
        while(temp) {
            temp = temp->right;
            rh++;
        }
        return rh;
    }
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        
        int lh = leftHeight(root);
        int rh = rightHeight(root);
        if(lh == rh) {
            return pow(2, lh) - 1;
        }
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
