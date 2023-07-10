/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=uCvur520ejA
    Company Tags                : Amazon
    Leetcode Link               : https://leetcode.com/problems/minimum-depth-of-binary-tree/
*/

//Using Simple DFS - O(n)
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        
        if(root->left == NULL && root->right == NULL)
            return 1;
        
        int left  = root->left?minDepth(root->left):INT_MAX;
        int right = root->right?minDepth(root->right):INT_MAX;
        
        return 1 + min(left, right);
    }
};


//Using Simple BFS - O(n)
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        
        if(!root->left && !root->right)
            return 1;
        
        queue<TreeNode*> que;
        que.push(root);
        
        int depth = 1;
        
        while(!que.empty()) {
            
            int n = que.size();
            
            while(n--) {
                TreeNode* temp = que.front();
                que.pop();
                
                if(!temp->left && !temp->right)
                    return depth;
                
                if(temp->left)
                    que.push(temp->left);
                if(temp->right)
                    que.push(temp->right);
            }
            
            depth++;
            
        }
        
        return -1;
    }
};
