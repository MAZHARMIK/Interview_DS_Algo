/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Op6YFcs8R9M
    Company Tags                : Google, Amazon, Meta, Flipkart
    Leetcode Link               : https://leetcode.com/problems/binary-tree-maximum-path-sum/
    GfG Link                    : https://practice.geeksforgeeks.org/problems/maximum-path-sum-from-any-node/1
*/

class Solution {
public:
    
    int maxSum;
    
    int solve(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int l = solve(root->left);
        int r = solve(root->right);
        
        int neeche_hi_milgaya_answer = l + r + root->val; //(1)
        
        int koi_ek_acha = max(l, r) + root->val; //(2)
        
        int only_root_acha = root->val; //(3)
        
        maxSum = max({maxSum, neeche_hi_milgaya_answer, koi_ek_acha, only_root_acha});
        
        
        //most important part
        return max(koi_ek_acha, only_root_acha);
        
    }
    
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        
        solve(root);
        
        return maxSum;
        
    }
};
