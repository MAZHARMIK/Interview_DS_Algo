/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=PeNJKq_8pEM
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/evaluate-boolean-binary-tree/description/
*/

/************************************************************ C++ ************************************************************/
//Using simple recursion
//T.C : O(n)
//S.C : O(depth of tree)
class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if(root->left == NULL && root->right == NULL) {
            return root->val;
        }
        
        if(root->val == 2) {
            return evaluateTree(root->left) | evaluateTree(root->right);
        }
        
        return evaluateTree(root->left) & evaluateTree(root->right);
    }
};



/************************************************************ JAVA ************************************************************/
//Using simple recursion
//T.C : O(n)
//S.C : O(depth of tree)
class Solution {
    public boolean evaluateTree(TreeNode root) {
        if (root.left == null && root.right == null) {
            return root.val != 0; // Convert int to boolean
        }
        
        if (root.val == 2) {
            return evaluateTree(root.left) | evaluateTree(root.right);
        }
        
        return evaluateTree(root.left) & evaluateTree(root.right);
    }
}
