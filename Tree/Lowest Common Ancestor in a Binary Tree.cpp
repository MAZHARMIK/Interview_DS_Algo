/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Oi3_06ultic
    Company Tags                : Accolite, Amazon, American Express, Expedia, MakeMyTrip, Microsoft, Payu, Snapdeal, Times Internet, Twitter
    Link to Qn                  : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
*/


/****************************************************** C++ ***************************************************/
//Approach - Use DFS and find
//T.C : O(n)
//S.C : O(n) for System Stack used for Recursion
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return NULL;
        
        if(root->val == p->val || root->val == q->val)
            return root;
        
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        
        if(l && r)
            return root;
        
        return l?l:r;
    }
};



/****************************************************** JAVA ***************************************************/
//Approach - Use DFS and find
//T.C : O(n)
//S.C : O(n) for System Stack used for Recursion
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null)
            return null;

        if (root.val == p.val || root.val == q.val)
            return root;

        TreeNode left = lowestCommonAncestor(root.left, p, q);
        TreeNode right = lowestCommonAncestor(root.right, p, q);

        if (left != null && right != null)
            return root;

        return left != null ? left : right;
    }
}
