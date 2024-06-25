/*    scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=8YuKhynQaqA
    Company Tags                : AMAZON
    Leetcode Link               : https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree
*/

//NOTE - You can do it in many ways, Brute Force , Better Brute Force, Iterative Inorder, Morris Traversal etc - You can give them a try for your practice.

/****************************************************************** JAVA ******************************************************************/
//Simple recursive approach
//T.C : O(n)
//S.C : O(1)
class Solution {
public:

    void solve(TreeNode* root, int &sum) {
        if(!root) { //root == NULL
            return;
        }

        
        solve(root->right, sum); //RIGHT is covered
        
        sum += root->val;

        root->val = sum;

        solve(root->left, sum); //Covergin the left
    }

    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;

        solve(root, sum);

        return root;
    }
};


/****************************************************************** JAVA ******************************************************************/
//Simple recursive approach
//T.C : O(n)
//S.C : O(1)
class Solution {
    public void solve(TreeNode root, int[] sum) {
        if (root == null) {
            return;
        }

        solve(root.right, sum); // Process right subtree

        sum[0] += root.val; // Update the sum with the value of the current node
        root.val = sum[0]; // Update the current node value with the sum

        solve(root.left, sum); // Process left subtree
    }

    public TreeNode bstToGst(TreeNode root) {
        int[] sum = new int[1]; // Use an array to hold the sum because Java passes by value
        solve(root, sum); // Start the conversion
        return root; // Return the modified tree
    }
}
