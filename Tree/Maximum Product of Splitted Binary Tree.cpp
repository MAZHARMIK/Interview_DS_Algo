/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=ITySQXe9Ybg
    Company Tags                : Google, Facebok, Amazon(Phone Interview)
    Leetcode Link               : https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/
*/


class Solution {
public:
    
    long M = 1e9+7;
    long totalSum = 0, maxP = 0;
    
    int findTotalSum(TreeNode* root) {
        if(!root)
            return 0;
        
        int leftSubtreeSum  = findTotalSum(root->left);
        int rightSubtreeSum = findTotalSum(root->right);
        int sum             = root->val + leftSubtreeSum + rightSubtreeSum;
        
        maxP = max(maxP, (totalSum - sum) * sum);
        
        return sum;
    }
    
    int maxProduct(TreeNode* root) {
        if(!root)
            return 0;
        
        maxP = 0;
        
        totalSum = findTotalSum(root);
        
        
        findTotalSum(root);
        
        return maxP%M;
    }
};
