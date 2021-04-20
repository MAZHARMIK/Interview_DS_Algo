/*
    Company Tags  : Let me know when you get it :-)
    Leetcode Link : https://leetcode.com/problems/n-ary-tree-preorder-traversal/
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void traverseNaryTree(Node* root, vector<int>& result) {
        if(!root)
            return;
        
        result.push_back(root->val);
        
        for(int i = 0; i<root->children.size(); i++) {
            traverseNaryTree(root->children[i], result);
        }
    }
    vector<int> preorder(Node* root) {
        vector<int> result;
        traverseNaryTree(root, result);
        return result;
    }
};
