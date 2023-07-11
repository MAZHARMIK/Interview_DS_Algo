/*
    MY YOUTUBE VIDEO ON THIS Qn : (Approach-1) - https://www.youtube.com/watch?v=1PMjfQl_UVQ 
    Company Tags                : Amazon, Citicorp, Flipkart, Goldman Sachs, Hike, Ola Cabs, Samsung, Walmart
    Leetcode Link               : https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
*/

//Approach-1  (Using Parent Pointers)
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;
    void addParent(TreeNode* root) {
        if(!root)
            return;
        
        if(root->left)
            parent[root->left] = root;
        
        addParent(root->left);
        
        if(root->right)
            parent[root->right] = root;
        
        addParent(root->right);
    }
    
    void collectKDistanceNodes(TreeNode* target, int k, vector<int>& result) {
        
        queue<TreeNode*> que;
        que.push(target);
        unordered_set<int> visited;
        visited.insert(target->val);
        
        while(!que.empty()) {
            
            int n = que.size();
            if(k == 0)
                break;
            
            while(n--) {
                TreeNode* curr = que.front();
                que.pop();
                
                if(curr->left && !visited.count(curr->left->val)) {
                    que.push(curr->left);
                    visited.insert(curr->left->val);
                }
                if(curr->right && !visited.count(curr->right->val)) {
                    que.push(curr->right);
                    visited.insert(curr->right->val);
                }
                
                if(parent.count(curr) && !visited.count(parent[curr]->val)) {
                    que.push(parent[curr]);
                    visited.insert(parent[curr]->val);
                }
            }
            k--;
        }
        
        while(!que.empty()) {
            TreeNode* temp = que.front();
            que.pop();
            result.push_back(temp->val);
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;
        
        addParent(root);
        
        collectKDistanceNodes(target, k, result);
        return result;
    }
};


//Approach-2 (Without Using Parent Pointers)
