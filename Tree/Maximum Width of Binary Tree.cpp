/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=hwjd0U36MUE
    Company Tags                : VMWare, Flipkart, Amazon
    Leetcode Link               : https://leetcode.com/problems/maximum-width-of-binary-tree/
*/

//Approach-1 (Using BFS)
class Solution {
public:
    typedef unsigned long long ll;
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)   
            return 0;
        queue<pair<TreeNode*, ll>> que;
        que.push({root, 0});
        ll maxWidth = 0;
        
        while(!que.empty()) {
            int n = que.size();
            ll f = que.front().second;
            ll l = que.back().second;
            maxWidth = max(maxWidth, l-f+1);
            
            while(n--) {
                TreeNode* curr = que.front().first;
                ll d          = que.front().second;
                que.pop();
                if(curr->left) {
                    que.push({curr->left, 2*d+1});
                }
                if(curr->right) {
                    que.push({curr->right, 2*d+2});
                }
            }
        }
        return maxWidth;
    }
};


//Approach-2 : Using DFS
class Solution {
public:
    typedef unsigned long long ll;
    
    void DFS(TreeNode* root, ll d, int level, vector<int>& arr, ll& maxWidth) {
        if(!root)
            return;
        
        if(level == arr.size()) {
            arr.push_back(d);
        } else {
            maxWidth = max(maxWidth, d-arr[level]+1);
        }
        
        DFS(root->left, 2*d+1, level+1, arr, maxWidth);
        DFS(root->right, 2*d+2, level+1, arr, maxWidth);
    }
    
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)   
            return 0;
        
        ll maxWidth = 1;
        vector<int> arr;
        DFS(root, 0, 0, arr, maxWidth);
        return maxWidth;
    }
};
