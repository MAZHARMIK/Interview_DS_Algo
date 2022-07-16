/*
    MY YOUTUBE VIDEO LINK : https://www.youtube.com/watch?v=-Qs1T_xfzLo&list=PLpIkg8OmuX-K23LhcamOcDlTBisiNJy5E&index=1
    Company Tags          : Accolite, Amazon, Flipkart, Knowlarity, MakeMyTrip, Ola Cabs, Open Solutions, OYO ROoms, Paytm, Qualcomm, Samsung,
                            Snapdeal, Twitter
    Leetcode Qn Link      : https://leetcode.com/problems/binary-tree-right-side-view/
    Approach              : Use DFS or Level Order Traversal
    Time Complexity       : O(n)
*/

//Approach - 1 (DFS)
class Solution {
public:
    //modifed pre order traversal
    void preOrder(TreeNode* root, int level, vector<int>& result) {
        if(!root)
            return;
        
        if(result.size() < level)
            result.push_back(root->val);
        
        preOrder(root->right, level+1, result);
        preOrder(root->left, level+1, result);
    }
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return {};
        
        vector<int> result;
        
        preOrder(root, 1, result);
        
        return result;
    }
};


//Approach-2 (Level Order Traversal)
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return {};
        
        queue<TreeNode*> que;
        vector<int> result;
        
        que.push(root);
        
        while(!que.empty()) {
            int n = que.size();
            TreeNode* rightNode = NULL;
            while(n--) {
                rightNode = que.front();
                que.pop();
                
                if(rightNode->left)
                    que.push(rightNode->left);
                if(rightNode->right)
                    que.push(rightNode->right);
            }
            result.push_back(rightNode->val);
        }
        return result;
    }
};
