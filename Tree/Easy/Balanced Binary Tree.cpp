/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=w8qXEQkCQO0
    Company Tags                : Adobe, Apple, Capgemini, Meta, CBSL Group (India)
    Leetcode Link               : https://leetcode.com/problems/balanced-binary-tree
*/

/************************************************************ C++ ************************************************************/
//Approach : Using simple recursion
//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:
    int height(TreeNode* root) {

        if(!root)
            return 0;

        int leftH  = height(root->left);
        int rightH = height(root->right);

        return max(leftH, rightH) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if(!root) {
            return true;
        }
        
        int leftH  = height(root->left);
        int rightH = height(root->right);

        if(abs(leftH - rightH) > 1)
            return false;
        
        return isBalanced(root->left) && isBalanced(root->right);
    }
};



/************************************************************ JAVA ************************************************************/
//Approach : Using simple recursion
//T.C : O(n^2)
//S.C : O(n)
class Solution {

    public boolean isBalanced(TreeNode root) {
        return height(root) != -1;
    }

    private int height(TreeNode node) {
        if (node == null) return 0;

        int leftHeight = height(node.left);
        if (leftHeight == -1) return -1;

        int rightHeight = height(node.right);
        if (rightHeight == -1) return -1;

        if (Math.abs(leftHeight - rightHeight) > 1)
            return -1;

        return Math.max(leftHeight, rightHeight) + 1;
    }
}
