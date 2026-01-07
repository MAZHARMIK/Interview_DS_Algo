/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=ITySQXe9Ybg
    Company Tags                : Google, Facebok, Amazon(Phone Interview)
    Leetcode Link               : https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/
*/


/****************************************************** C++ ***************************************************/
//T.C : O(n)
//S.C : O(n) if we consider recursion stack space, else O(1)
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



/****************************************************** JAVA ***************************************************/
//T.C : O(n)
//S.C : O(n) if we consider recursion stack space, else O(1)
class Solution {

    private long totalSum = 0;
    private long maxProduct = 0;
    private static final int MOD = 1_000_000_007;

    // First DFS: calculate total sum of the tree
    private long getTotalSum(TreeNode root) {
        if (root == null) return 0;
        return root.val + getTotalSum(root.left) + getTotalSum(root.right);
    }

    // Second DFS: compute subtree sums and maximize product
    private long dfs(TreeNode root) {
        if (root == null) return 0;

        long leftSum  = dfs(root.left);
        long rightSum = dfs(root.right);
        long subTreeSum = root.val + leftSum + rightSum;

        // Try cutting above this subtree
        long product = subTreeSum * (totalSum - subTreeSum);
        maxProduct = Math.max(maxProduct, product);

        return subTreeSum;
    }

    public int maxProduct(TreeNode root) {
        totalSum = getTotalSum(root); // First pass
        dfs(root);                    // Second pass
        return (int)(maxProduct % MOD);
    }
}
