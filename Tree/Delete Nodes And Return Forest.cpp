/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=z-pX53sYwWI&list=PLpIkg8OmuX-K23LhcamOcDlTBisiNJy5E&index=7
    Company Tags                : Google, Amazon
    Leetcode Qn Link            : https://leetcode.com/problems/delete-nodes-and-return-forest/
*/


class Solution {
public:
    TreeNode* deleteNodes(TreeNode* root, set<int> st, vector<TreeNode*>& result) {
        if(!root)
            return NULL;
        root->left  = deleteNodes(root->left , st, result); //left  se deleted nodes
        root->right = deleteNodes(root->right, st, result); //right se deleted nodes
        
        if(st.count(root->val)) { //if I have to delete this root, then put root->left and root->right in result
            if(root->left  != NULL)
                result.push_back(root->left);
            if(root->right != NULL)
                result.push_back(root->right);
            return NULL;
        }
        else
            return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int> st;
        for(int i:to_delete)
            st.insert(i);
        
        vector<TreeNode*> result;
        deleteNodes(root, st, result); // <-- it will not consider root
        
        //So, check here if root is to be deleted or not
        if(!st.count(root->val)) {
            result.push_back(root);
        }
        return result;
    }
};
