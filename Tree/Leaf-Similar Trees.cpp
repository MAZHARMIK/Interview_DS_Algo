/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=rlWJlXQNt0Q
    Company Tags                : Meta, Microsoft, Twitter, Amazon, Goldman Sachs
    Leetcode Link               : https://leetcode.com/problems/leaf-similar-trees/
*/


class Solution {
public:
    
    void inOrder(TreeNode* root, string& s) {
        if(root == NULL) return;
        
        //leaf node
        if(root->left == NULL && root->right == NULL) {
            s += to_string(root->val) + "_";
            return;
        }
        
        inOrder(root->left, s);
        inOrder(root->right, s);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string s1 = "";
        string s2 = "";
        
        inOrder(root1, s1);
        inOrder(root2, s2);
        
        return s1==s2;
    }
};
