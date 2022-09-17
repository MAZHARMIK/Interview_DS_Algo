/*
	MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=bzQIbtlnBW0&t=3s
    	Company Tags  		    : Amazon, Microsoft, Google
    	Leetcode Link 		    : https://leetcode.com/problems/binary-tree-pruning/
*/

//Approach-1 (Naive and the first approach that comes to mind) Time: O(n^2)
/*
	 I am at node X, 
		 if my left doesn't contain '1', X->left = NULL
		  if my right doesn't contain '1', X->left = NULL
	 Do this for every node while DFS
*/
class Solution {
public:
	//This is called for all node and hence Time : O(n^2)
    bool checkOne(TreeNode* root) {
        if(!root)
            return false;
        
        if(root->val == 1)
            return true;
        
        return checkOne(root->left) || checkOne(root->right);
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        if(!root)
            return NULL;
        
        pruneTree(root->left);
        pruneTree(root->right);
        
        if(!checkOne(root->left))  root->left = NULL;
        if(!checkOne(root->right)) root->right = NULL;
        
        
        if(!root->left && !root->right && root->val == 0)
            return NULL;
        return root;
    }
};

//Approach-2 (We check from bottom to up and at the same time remove subtree) 
//Time (O(n))
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(!root)
            return NULL;
        
        root->left  = pruneTree(root->left);
        root->right = pruneTree(root->right);
        
        if(!root->left && !root->right && root->val == 0)
            return NULL;
        
        return root;
    }
};
