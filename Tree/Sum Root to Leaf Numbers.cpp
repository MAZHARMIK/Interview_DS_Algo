/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=KTwkq-MsJDw
    Company Tags                : Google, Meta, Accolite, Amazon, Microsoft, Samsung, FactSet, 
                                  Housing.com, Oracle, Goldman Sachs, Adobe, Coupon Dunia, Atlassian
    Leetcode Link               : https://leetcode.com/problems/sum-root-to-leaf-numbers/
*/

//Recursion
class Solution {
public:
    
    int find(TreeNode* root, int curr) {
        
        if(!root)
            return 0;
        
        curr = curr*10 + root->val;
        
        if(root->left == NULL && root->right == NULL) {
            return curr;
        }
        
        int left_num  = find(root->left, curr);
        int right_num = find(root->right, curr);
        
        return left_num + right_num;
    }
    
    int sumNumbers(TreeNode* root) {
        return find(root, 0);
    }
};


//Simple Recursion
class Solution {
public:
    int sumNumbers(TreeNode* root, int sum = 0) {
        if(!root)
            return 0;
        
        if(!root->left && !root->right)
            return sum*10+root->val;
        
        int ls = sumNumbers(root->left, sum*10+root->val);
        int rs = sumNumbers(root->right, sum*10+root->val);
        
        return ls + rs;
    }
};
