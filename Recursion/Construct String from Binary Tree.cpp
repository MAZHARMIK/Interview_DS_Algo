/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=KZLMac8vUVw
    Company Tags                : AMAZON
    Leetcode Link               : https://leetcode.com/problems/construct-string-from-binary-tree/
*/

/******************************************************** C++ **********************************************************************/
//Approach - Simple Recursion Story
//T.C : O(n)
class Solution {
public:
    string tree2str(TreeNode* root) {
        if(!root) {
            return "";
        }
        
        string result = to_string(root->val);
        string l = tree2str(root->left);
        string r = tree2str(root->right);
       
        if(!root->left && !root->right) {
            return result;
        }
        
        if(!root->right)
            return result + "(" + l + ")";
        
        if(!root->left)
            return result + "()" + "(" + r + ")";
        
        return result + "(" + l + ")" + "(" + r + ")";
    }
};


/******************************************************** JAVA **********************************************************************/
//Approach - Simple Recursion Story
//T.C : O(n)
public class Solution {
    public String tree2str(TreeNode root) {
        if (root == null) {
            return "";
        }

        String result = Integer.toString(root.val);
        String l = tree2str(root.left);
        String r = tree2str(root.right);

        if (root.left == null && root.right == null) {
            return result;
        }

        if (root.right == null) {
            return result + "(" + l + ")";
        }

        if (root.left == null) {
            return result + "()" + "(" + r + ")";
        }

        return result + "(" + l + ")" + "(" + r + ")";
    }
}
