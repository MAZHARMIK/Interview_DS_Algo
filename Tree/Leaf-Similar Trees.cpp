/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=rlWJlXQNt0Q
    Company Tags                : Meta, Microsoft, Twitter, Amazon, Goldman Sachs
    Leetcode Link               : https://leetcode.com/problems/leaf-similar-trees/
*/

/******************************************************** C++ ********************************************************/
//T.C : O(n)
//S.C : O(n) (string s) - I am ignoring the recursion stack space here
class Solution {
public:
    
    void inOrder(TreeNode* root, string& s) {
        if(root == NULL) return;
        
        //leaf node
        if(root->left == NULL && root->right == NULL) {
            s += to_string(root->val) + "_";
            return;
        }
        
        inOrder(root->left, s);
        inOrder(root->right, s);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string s1 = "";
        string s2 = "";
        
        inOrder(root1, s1);
        inOrder(root2, s2);
        
        return s1==s2;
    }
};


/******************************************************** JAVA ********************************************************/
//T.C : O(n)
//S.C : O(n) (string s) - I am ignoring the recursion stack space here
public class Solution {
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        StringBuilder s1 = new StringBuilder();
        StringBuilder s2 = new StringBuilder();

        inOrder(root1, s1);
        inOrder(root2, s2);

        return s1.toString().equals(s2.toString());
    }

    private void inOrder(TreeNode root, StringBuilder s) {
        if (root == null) return;

        // Leaf node
        if (root.left == null && root.right == null) {
            s.append(root.val).append("_");
            return;
        }

        inOrder(root.left, s);
        inOrder(root.right, s);
    }
}
