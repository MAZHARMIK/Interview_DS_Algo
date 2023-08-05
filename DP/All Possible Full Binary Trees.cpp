/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=lNEI25uT3WM
      Company Tags                : GOOGLE, AMAZON
      Leetcode Link               : https://leetcode.com/problems/all-possible-full-binary-trees/

      SIMILAR Qn : Leetcode Link -> https://leetcode.com/problems/unique-binary-search-trees-ii/
      
*/

//Approach-1 (Recursion + Memo)
class Solution {
public:
    
    unordered_map<int, vector<TreeNode*>> mp;
    vector<TreeNode*> solve(int n) {

        if(n%2 == 0) //Even nodes can't make Full Binary Tree
            return {};
        
        if(n == 1) {
            TreeNode* node = new TreeNode(0);
            return {node};
        }
        
                
        if(mp.find(n) != mp.end())
            return mp[n];
        
        
        vector<TreeNode*> result;
        
        for(int i = 1; i<n; i += 2) {
            
            vector<TreeNode*> leftAllFBT  = allPossibleFBT(i);
            vector<TreeNode*> rightAllFBT = allPossibleFBT(n-i-1);
            
            for(auto &l : leftAllFBT) {
                
                for(auto &r : rightAllFBT) {
                    
                    TreeNode* root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    result.push_back(root);
                }
                
            }
            
        }
        
        return mp[n] = result;
    }
    
    vector<TreeNode*> allPossibleFBT(int n) {
        return solve(n);
    }
};



//Approach-2 (Bottom Up)
//soon
