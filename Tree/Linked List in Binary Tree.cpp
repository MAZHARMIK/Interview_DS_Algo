/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Ypzg7G3kg5A
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/linked-list-in-binary-tree/description/
*/


/****************************************************** C++ *********************************************/
//Approach-1 (Simple recursion)
//T.C : O(n*m) , n = number of nodes in trees, m = number of nodes in linkedlist. For every node in tree as starting node we will try matching with m nodes in list
//S.C : O(1) , but since we are running recursion we will take system resurcion stack = O(m+n)
class Solution {
public:

    bool check(ListNode* head, TreeNode* root) {
        if(!head) {
            return true;
        }

        if(!root || root->val != head->val) {
            return false;
        }

        return check(head->next, root->left) || check(head->next, root->right);
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!root) {
            return false;
        }
        return check(head, root)        || 
               isSubPath(head, root->left)  || 
               isSubPath(head, root->right);
    }
};


/****************************************************** JAVA *********************************************/
//Approach-1 (Simple recursion)
//T.C : O(n*m) , n = number of nodes in trees, m = number of nodes in linkedlist. For every node in tree as starting node we will try matching with m nodes in list
//S.C : O(1) , but since we are running recursion we will take system resurcion stack = O(m+n)
class Solution {

    // Helper function that checks if the linked list starting from 'head'
    // is a subpath of the binary tree starting from 'root'
    private boolean check(ListNode head, TreeNode root) {
        // If we've reached the end of the linked list, it means we've found a valid path
        if (head == null) {
            return true;
        }
        // If the tree node is null or the values don't match, the path is not valid
        if (root == null || root.val != head.val) {
            return false;
        }
        // Recursively check the left and right subtrees
        return check(head.next, root.left) || check(head.next, root.right);
    }

    // Main function to check if the linked list is a subpath of the binary tree
    public boolean isSubPath(ListNode head, TreeNode root) {
        // If the tree is empty, there's no path to check
        if (root == null) {
            return false;
        }
        // Check the current root and recursively check the left and right subtrees
        return check(head, root) || isSubPath(head, root.left) || isSubPath(head, root.right);
    }
}
