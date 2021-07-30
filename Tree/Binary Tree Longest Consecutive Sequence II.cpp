/*
    Company Tags  : Google
    Leetcode Link : https://leetcode.com/problems/binary-tree-longest-consecutive-sequence-ii/
    
    Since this is a Premium Qn, I have added the Description as well as example below:
    Description
    Given a binary tree, find the length(number of nodes) of the longest consecutive sequence(Monotonic and adjacent node values differ by 1) path.
    The path could be start and end at any node in the tree.
    
    Example
    Example 1:
    Input:
    {1,2,0,3}
    Output:
    4
    Explanation:
        1
       / \
      2   0
     /
    3

    Path : 0-1-2-3

    Example 2:
    Input:
    {3,2,2}
    Output:
    2
    Explanation:
        3
       / \
      2   2
      
    Path : 2-3
*/

class Solution {
public:
    int maxL = 0;
    typedef pair<int, int> P;
    P find(TreeNode* root) {
        if(!root) return {0, 0};

        P p{1, 1}; //pair{dec_path, incr_path}

        P l = find(root->left);
        P r = find(root->right);

        if(root->left) {
            if(root->val-root->left->val == 1) { //dec from top
                p.first  = max(p.first, l.first+1);
            } else if(root->val-root->left->val == -1) { //incr from top
                p.second = max(p.second, l.second+1);
            }
        }

        if(root->right) {
            if(root->val-root->right->val == 1) { //dec from top
                p.first  = max(p.first, r.first+1);
            } else if(root->val-root->right->val == -1) { //incr from top
                p.second = max(p.second, r.second+1);
            }
        }

        maxL = max({maxL, p.first, p.second, p.first+p.second-1});
        return p;
    }

    int longestConsecutive2(TreeNode * root) {
        maxL = 0;
        find(root);
        return maxL;
    }
};
