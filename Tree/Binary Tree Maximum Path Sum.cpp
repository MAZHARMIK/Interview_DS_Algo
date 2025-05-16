/*        Scroll below to see JAVA code as well        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Op6YFcs8R9M
    Company Tags                : Google, Amazon, Meta, Flipkart
    Leetcode Link               : https://leetcode.com/problems/binary-tree-maximum-path-sum/
    GfG Link                    : https://practice.geeksforgeeks.org/problems/maximum-path-sum-from-any-node/1
*/

/****************************************************** C++ ******************************************/
//Approach - Recursively finding the best path
//T.C : O(n)
//S.C : O(n)
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


/****************************************************** JAVA ******************************************/
//Approach - Recursively finding the best path
//T.C : O(n)
//S.C : O(n)
class Solution {
    
    private int maxSum;
    
    private int solve(TreeNode root) {
        if (root == null) {
            return 0;
        }
        
        int left = solve(root.left);
        int right = solve(root.right);
        
        int neecheHiMilgayaAnswer = left + right + root.val; // (1)
        int koiEkAcha = Math.max(left, right) + root.val; // (2)
        int onlyRootAcha = root.val; // (3)

        maxSum = Math.max(maxSum, Math.max(neecheHiMilgayaAnswer, Math.max(koiEkAcha, onlyRootAcha)));
        
        // Most important part
        return Math.max(koiEkAcha, onlyRootAcha);
    }
    
    public int maxPathSum(TreeNode root) {
        maxSum = Integer.MIN_VALUE;
        solve(root);
        return maxSum;
    }
}
