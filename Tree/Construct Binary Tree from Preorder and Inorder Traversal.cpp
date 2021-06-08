/*
    Company Tags  :  Accolite, Amazon, Microsoft
    Leetcode Link : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
*/

class Solution {
public:
    int index;
    unordered_map<int, int> mp;
    TreeNode* construct(vector<int>& preorder, vector<int>& inorder, int l, int r, int& n) {
        if(l > r)
            return NULL;
        
        int rootVal = preorder[index];
        index++;
        int i = mp[rootVal];
        
        TreeNode* root = new TreeNode(rootVal);
        root->left     = construct(preorder, inorder, l, i-1, n);
        root->right    = construct(preorder, inorder, i+1, r, n);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        index = 0;
        mp.clear();
        int n = preorder.size();
        for(int i = 0; i<n; i++) {
            mp[inorder[i]] = i;
        }
        return construct(preorder, inorder, 0, n-1, n);
    }
};
