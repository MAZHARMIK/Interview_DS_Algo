/*
    Company Tags  : Google, Facebook, Amazon, NetEase
    Leetcode Link : https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/
*/

class Solution {
public:
    int maxL = 0;
    void find(TreeNode* prev, TreeNode* curr, int l) {
        if(!curr)
            return;
        
        if(prev && (curr->val)-(prev->val) == 1)
            l += 1;
        else
            l = 1;
        
        find(curr, curr->left, l);
        find(curr, curr->right, l);
      
        maxL = max(maxL, l);
    }

    int longestConsecutive(TreeNode * root) {
        find(NULL, root, 0);

        return maxL;
    }
};
