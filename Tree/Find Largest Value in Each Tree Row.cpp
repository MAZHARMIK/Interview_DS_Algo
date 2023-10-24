/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=iBaccPOzD-w
    Company Tags                : META
    Leetcode Link               : https://leetcode.com/problems/find-largest-value-in-each-tree-row
*/

/********************************************* C++ *********************************************/
//Approach-1 (Using BFS)
//T.C : O(n) we visit each node once.
//S.C : O(n) taken by quque
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(!root)
            return {};
        
        queue<TreeNode*> que;
        que.push(root);
        
        vector<int> result;
        
        while(!que.empty()) {
            
            int n = que.size();
            int maxEl = INT_MIN;
            while(n--) {
                
                TreeNode* node = que.front();
                que.pop();
                
                maxEl = max(maxEl, node->val);
                
                if(node->left)
                    que.push(node->left);
                
                if(node->right)
                    que.push(node->right);
            }
            
            result.push_back(maxEl);
            
        }
        
        return result;
    }
};


//Approach-2 (Using DFS)
//T.C : O(n) We visit each node once
//S.C : O(n) Recursion stack space
class Solution {
public:
    vector<int> result;
    
    void DFS(TreeNode* root, int depth) {
        if(!root)
            return;
        
        if(depth == result.size()) {
            result.push_back(root->val);
        } else {
            result[depth] = max(result[depth], root->val);
        }
        
        DFS(root->left, depth+1);
        DFS(root->right, depth+1);
    }
    
    vector<int> largestValues(TreeNode* root) {
        DFS(root, 0);
        return result;
    }
};


/********************************************* JAVA *********************************************/
//Approach-1 (Using BFS)
//T.C : O(n) we visit each node once.
//S.C : O(n) taken by quque
public class Solution {
    public List<Integer> largestValues(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        if (root == null) {
            return result;
        }

        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);

        while (!queue.isEmpty()) {
            int size = queue.size();
            int maxEl = Integer.MIN_VALUE;

            for (int i = 0; i < size; i++) {
                TreeNode node = queue.poll();
                maxEl = Math.max(maxEl, node.val);

                if (node.left != null) {
                    queue.offer(node.left);
                }

                if (node.right != null) {
                    queue.offer(node.right);
                }
            }

            result.add(maxEl);
        }

        return result;
    }
}



//Approach-2 (Using DFS)
//T.C : O(n) We visit each node once
//S.C : O(n) Recursion stack space
public class Solution {
    private List<Integer> result = new ArrayList<>();

    public List<Integer> largestValues(TreeNode root) {
        dfs(root, 0);
        return result;
    }

    private void dfs(TreeNode root, int depth) {
        if (root == null) {
            return;
        }

        if (depth == result.size()) {
            result.add(root.val);
        } else {
            result.set(depth, Math.max(result.get(depth), root.val));
        }

        dfs(root.left, depth + 1);
        dfs(root.right, depth + 1);
    }
}
