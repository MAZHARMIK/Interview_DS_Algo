/*
    Company Tags  : Amazon
    Frequency     : 86%
    Leetcode Link : https://leetcode.com/problems/merge-two-binary-trees/
*/

//Approach-1 (Using DFS : Recursion) -> Recursion is the best way to solve Tree problems
class Solution {
public:    
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1)
            return root2;
        if(!root2)
            return root1;
        
        TreeNode* root = new TreeNode(root1->val + root2->val);
      
        root->left  = mergeTrees(root1->left, root2->left);
        root->right = mergeTrees(root1->right, root2->right);
      
        return root;
    }
};

//Approach-2 (Using BFS : Iterative) You can also use Stack to solve this problem
class Solution {
public:    
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1)
            return root2;
        if(!root2)
            return root1;
        
        queue<TreeNode*> que1;
        queue<TreeNode*> que2;
        
        que1.push(root1);
        que2.push(root2);
        TreeNode* root = root1;
        while(!que1.empty() || !que2.empty()) {
            TreeNode* r1 = que1.front(); que1.pop();
            TreeNode* r2 = que2.front(); que2.pop();
            
            r1->val += r2->val;
            
            if(!r1->left && r2->left)
                r1->left = r2->left;
            else if(r1->left && r2->left) {
                que1.push(r1->left);
                que2.push(r2->left);
            }
            
            if(!r1->right && r2->right)
                r1->right = r2->right;
            else if(r1->right && r2->right) {
                que1.push(r1->right);
                que2.push(r2->right);
            }
        }
        
        return root;
        
    }
};
