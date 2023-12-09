/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Wq3ibaP4dJY
    Company Tags                : A lot of companies have asked this.
    Leetcode Link               : https://leetcode.com/problems/binary-tree-inorder-traversal/
*/


/****************************************************** C++ ******************************************************/
//T.C : O(n)
//S.C : O(1) - Not including result array
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode* curr = root;
        TreeNode* pre;

        while (curr != nullptr) {
            if (curr->left == nullptr) {
                result.push_back(curr->val);
                curr = curr->right;
            } else {
                pre = curr->left;
                
                while (pre->right != nullptr) {
                    pre = pre->right;
                }
                
                pre->right = curr;
                TreeNode* temp = curr;
                curr = curr->left;
                temp->left = nullptr;
            }
        }

        return result;
    }
};


/****************************************************** C++ ******************************************************/
//T.C : O(n)
//S.C : O(1) - Not including result array
public class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        TreeNode curr = root;
        TreeNode pre;

        while (curr != null) {
            if (curr.left == null) {
                result.add(curr.val);
                curr = curr.right;
            } else {
                pre = curr.left;

                while (pre.right != null) {
                    pre = pre.right;
                }

                pre.right = curr;
                TreeNode temp = curr;
                curr = curr.left;
                temp.left = null;
            }
        }

        return result;
    }
}
