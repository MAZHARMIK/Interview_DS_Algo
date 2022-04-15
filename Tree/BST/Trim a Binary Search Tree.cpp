/*
    Company Tags  : Google
    Leetcode Link : https://leetcode.com/problems/trim-a-binary-search-tree/
*/

//Approach - 1 : The most common way to solve Tree problems : Write a story and trust the resursive call
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root)
            return root;
        
        root->left  = trimBST(root->left, low, high);  //trust it that it will solve left subtree
        root->right = trimBST(root->right, low, high); //trust it that it will solve right subtree
        
        //Handle the case
        if(root->val < low) {
            return root->right;
        } else if(root->val > high) {
            return root->left;
        }
        
        //return your result
        return root;
    }
};

//Approach - 2 : Using simple DFS (Similar to Approach-1)
class Solution {
public:
    
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root)
            return root;
        
        if(root->val < low) //because we need to look for higher values
            return trimBST(root->right, low, high);
            
        else if(root->val > high) //because we need to look for lower values
            return trimBST(root->left, low, high);
        
        //call inorder (DFS)
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        
        return root;
    }
};
