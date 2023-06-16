/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=GWCVpTCSIFY
    Company Tags                : AMAZON, SAMSUNG(June, 2023, Online Assessment)
    Leetcode Link               : https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/
*/

//Approach-1 (Using BFS - T.C : O(n))
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int maxSum = INT_MIN;
        int resultLevel = 0;
        int currLevel = 1;
        
        queue<TreeNode*> que;
        que.push(root);
        
        
        while(!que.empty()) {

            int n = que.size();
            
            int sum = 0;
            
            while(n--) {
                
                TreeNode* node = que.front();
                que.pop();
                
                sum += node->val;
                
                if(node->left)
                    que.push(node->left);
                
                if(node->right)
                    que.push(node->right);
            }
            
            if(sum > maxSum) {
                maxSum = sum;
                resultLevel = currLevel;
            }
            currLevel++;
        }
        
        return resultLevel;
        
    }
};


//Approach-2 (Using DFS - T.C : O(n))
class Solution {
public:
    
    map<int, int> mp;
    
    void DFS(TreeNode* root, int currLevel) {
        
        if(!root)
            return;
        
        mp[currLevel] += root->val;
        
        DFS(root->left, currLevel+1);
        DFS(root->right, currLevel+1);
        
    }
    
    int maxLevelSum(TreeNode* root) {
        mp.clear();
        
        DFS(root, 1);
        
        int maxSum = INT_MIN;
        int result = 0;
        
        for(auto &it : mp) {
            
            int level = it.first;
            int sum   = it.second;
            
            if(sum > maxSum) {
                maxSum = sum;
                result = level;
            }
            
        }
        
        return result;
    }
};
