/*     MY YOUTUBE VIDEO ON THIS Qn    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=OzueBIOLJ44
    Company Tags                : Dunzo, Sprinkler
    Leetcode Link               : https://leetcode.com/problems/delete-leaves-with-a-given-value
*/


/************************************************************ C++ ************************************************************/
//Simple Recursion story to code
//T.C : O(n)
//S.C : O(height)
class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(!root) {
            return NULL;
        }

        root->left  = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);

        if(root->left == NULL && root->right == NULL && root->val == target)
            return NULL;

        return root;
        
    }
};



/************************************************************ JAVA ************************************************************/
//Simple Recursion story to code
//T.C : O(n)
//S.C : O(height)
class Solution {
    public TreeNode removeLeafNodes(TreeNode root, int target) {
        if(root == null) {
            return null;
        }

        root.left  = removeLeafNodes(root.left, target);
        root.right = removeLeafNodes(root.right, target);

        if(root.left == null && root.right == null && root.val == target)
            return null;

        return root;
    }
}
