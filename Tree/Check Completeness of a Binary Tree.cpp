/*
    MY YOUTUBE VIDEO FOR THIS Qn : https://www.youtube.com/watch?v=08e5EBHoXxE&t=101s
    Company Tags                 : Amazon
    Leetcode Link                : https://leetcode.com/problems/check-completeness-of-a-binary-tree/
*/

//Approach-1 : BFS

//Asked in Amazon

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        //Using BFS
        
        queue<TreeNode*> que;
        
        que.push(root);
        
        bool past = false; //kya aapne past me NULL node dekha hai ?
        
        while(!que.empty()) {
            TreeNode* node = que.front();
            que.pop();
            
            if(node == NULL) {
                past = true;
            } else {
                if(past == true) {
                    return false;
                }
                
                que.push(node->left);
                que.push(node->right);
            }
        }
        
        return true;
    }
};
