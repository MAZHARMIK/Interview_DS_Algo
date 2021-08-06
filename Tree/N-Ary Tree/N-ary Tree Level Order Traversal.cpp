/*
    Company Tags  : Amazon
    Leetcode Link : https://leetcode.com/problems/n-ary-tree-level-order-traversal/
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        vector<vector<int>> result;
        queue<Node*> que;
        que.push(root);
        
        while(!que.empty()) {
            int n = que.size();
            vector<int> levelNodes;
            while(n--) {
                Node* curr = que.front();
                que.pop();
              
                levelNodes.push_back(curr->val);
                for(Node* node : curr->children) {
                    que.push(node);
                }
            }
            result.push_back(std::move(levelNodes));
        }
        
        return result;
    }
};
