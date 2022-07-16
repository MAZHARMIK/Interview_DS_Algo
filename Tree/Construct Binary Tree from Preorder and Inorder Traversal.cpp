/*
    MY YOUTUBE LINK :  https://www.youtube.com/watch?v=G5c1wM3Kpuw&list=PLpIkg8OmuX-K23LhcamOcDlTBisiNJy5E&index=4
    Company Tags    :  Accolite, Amazon, Microsoft
    Leetcode Link   :  https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
*/


//Basic Approach
class Solution {
public:
    
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int start, int end, int& idx) {
        if(start > end)
            return NULL;
        
        int rootVal = preorder[idx];
        int i = start;
        
        for(; i <= end; i++) {
            if(inorder[i] == rootVal)
                break;
        }
        
        idx++;
        TreeNode* root = new TreeNode(rootVal);
        root->left  = solve(preorder, inorder, start, i-1, idx);
        root->right = solve(preorder, inorder, i+1, end, idx);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        
        int idx = 0;
        
        return solve(preorder, inorder, 0, n-1, idx);
    }
};


//Optimized approach by using map to find index of root in inorder array
class Solution {
public:
    unordered_map<int, int> mp;
    TreeNode* construct(vector<int>& preorder, vector<int>& inorder, int l, int r, int& idx) {
        if(l > r)
            return NULL;
        
        int rootVal = preorder[idx];
        idx++;
        int i = mp[rootVal];
        
        TreeNode* root = new TreeNode(rootVal);
        root->left     = construct(preorder, inorder, l, i-1, idx);
        root->right    = construct(preorder, inorder, i+1, r, idx);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        mp.clear();
        int n = preorder.size();
        for(int i = 0; i<n; i++) {
            mp[inorder[i]] = i;
        }
        
        int idx = 0;
        return construct(preorder, inorder, 0, n-1, idx);
    }
};
