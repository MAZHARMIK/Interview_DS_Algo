/*
      MY YOUTUBE VIDEO ON THIS Qn : 
      Company Tags                : 
      Leetcode Link               : 

      SIMILAR Qn : Leetcode Link -> https://leetcode.com/problems/all-possible-full-binary-trees/
                   YouTube Link  -> https://www.youtube.com/watch?v=lNEI25uT3WM
    
*/

//Approach-1 Recursion - ACCEPTED
class Solution {
public:

    vector<TreeNode*> solve(int start, int end) {
        
        if(start > end) {
            return {NULL};
        }
        
        if(start == end) {
            TreeNode* root = new TreeNode(start);
            return {root};
        }
        
        
        vector<TreeNode*> result;
        for(int i = start; i <= end; i++) {
            
            vector<TreeNode*> leftList  = solve(start, i-1);
            vector<TreeNode*> rightList = solve(i+1, end);
            
            for(TreeNode* leftRoot : leftList) {
                
                for(TreeNode* rightRoot : rightList) {
                    
                    TreeNode* root = new TreeNode(i);
                    root->left  = leftRoot;
                    root->right = rightRoot;
                    
                    result.push_back(root);
                    
                }
                
            }
            
        }
        
        return result;
        
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return solve(1, n);
    }
};


//Approach-2 Recursion + Memo - ACCEPTED
class Solution {
public:
    
    map<pair<int, int>, vector<TreeNode*>> mp;
    
    vector<TreeNode*> solve(int start, int end) {
        
        if(start > end) {
            return {NULL};
        }
        
        if(start == end) {
            TreeNode* root = new TreeNode(start);
            return {root};
        }
        
        if(mp.find({start, end}) != mp.end())
            return mp[{start, end}];
        
        vector<TreeNode*> result;
        for(int i = start; i <= end; i++) {
            
            vector<TreeNode*> leftList  = solve(start, i-1);
            vector<TreeNode*> rightList = solve(i+1, end);
            
            for(TreeNode* leftRoot : leftList) {
                
                for(TreeNode* rightRoot : rightList) {
                    
                    TreeNode* root = new TreeNode(i);
                    root->left  = leftRoot;
                    root->right = rightRoot;
                    
                    result.push_back(root);
                    
                }
                
            }
            
        }
        
        return mp[{start, end}] = result;
        
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return solve(1, n);
    }
};


//Approach-3 (Bottom Up) - sooon
