/*         Scroll down to see JAVA code also            */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=eoyO8hOkPNs&t=3s
    Company Tags                : Bloomberg, LinkedIn, Amazon, Bloomberg, Quora
    Leetcode Link               : https://leetcode.com/problems/path-sum-ii/
*/


/************************************************************ C++ ************************************************************/
//T.C : The time complexity of the code is O(N), where N is the number of nodes in the binary tree. 
//This is because each node is visited exactly once during the recursive traversal.
//Note that I am ignoring the time taken to move the temp values to result - result.push_back(temp);
//S.C :  The space complexity is O(H) in the worst case, where H is the height of the binary tree. 
//This is due to the recursion stack during the depth-first search. In the worst case, 
//the recursion stack will have H function calls, where H is the height of the tree.
class Solution {
public:
    void collectPaths(TreeNode* root, int curr, vector<int>& temp, vector<vector<int>>& result) {
        if(!root)
            return;
        temp.push_back(root->val);
        if(root->left == NULL && root->right == NULL && root->val == curr) {
            result.push_back(temp);
        }
        
        collectPaths(root->left, curr-root->val, temp, result);
        collectPaths(root->right, curr-root->val, temp, result);
        temp.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        
        vector<int> temp;
        collectPaths(root, sum, temp, result);
        return result;
    }
};


/************************************************************ JAVA ************************************************************/
//T.C : The time complexity of the code is O(N), where N is the number of nodes in the binary tree. 
//This is because each node is visited exactly once during the recursive traversal.
//Note that I am ignoring the time taken to move the temp values to result - result.push_back(temp);
//S.C :  The space complexity is O(H) in the worst case, where H is the height of the binary tree. 
//This is due to the recursion stack during the depth-first search. In the worst case, 
//the recursion stack will have H function calls, where H is the height of the tree.
public class Solution {
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        collectPaths(root, sum, temp, result);
        return result;
    }

    private void collectPaths(TreeNode root, int curr, List<Integer> temp, List<List<Integer>> result) {
        if (root == null)
            return;
        
        temp.add(root.val);

        if (root.left == null && root.right == null && root.val == curr) {
            result.add(new ArrayList<>(temp));
        }

        collectPaths(root.left, curr - root.val, temp, result);
        collectPaths(root.right, curr - root.val, temp, result);

        temp.remove(temp.size() - 1);
    }
}
