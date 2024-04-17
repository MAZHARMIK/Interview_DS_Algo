/*     Scroll down to see JAVA code also  */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=SX7dC8htok0
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/smallest-string-starting-from-leaf/
    Similar Qn                  : https://leetcode.com/problems/sum-root-to-leaf-numbers/description/
*/



/***************************************************************** C++ *****************************************************/
//Approach-1 (Using DFS)
//T.C : O(n)
//S.C : O(n) space taken for resurion system stack
class Solution {
public:
    string result = "";
    
    
    void solve(TreeNode* root, string curr) {
        if(root == NULL) {
            return;
        }
        
        curr = char(root->val + 'a') + curr; //This will take O(length of curr) but I have ignored this. You can condiser this as well in calculating T.C
        
        if(root->left == NULL && root->right == NULL) {
            if(result == "" || result > curr) {
                result = curr;
            }
            return;
        }
        
        solve(root->left, curr);
        solve(root->right, curr);
        
        
    }
    
    string smallestFromLeaf(TreeNode* root) {
        solve(root, "");
        
        return result;
    }
};


//Approach-2 (Using BFS)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        queue<pair<TreeNode*, string>> que;
        
        string result = "";
        que.push({root, string(1, root->val + 'a')});
        
        while(!que.empty()) {
            
            auto[node, curr] = que.front();
            que.pop();
            
            if(node->left == NULL && node->right == NULL) {
                if(result == "" || result > curr) {
                    result = curr;
                }
            }
            
            if(node->left) {
                que.push({node->left, char(node->left->val + 'a') + curr});
            }
            
            if(node->right) {
                que.push({node->right, char(node->right->val + 'a') + curr});
            }
            
        }
        
        return result;
    }
};


/***************************************************************** JAVA *****************************************************/
//Approach-1 (Using DFS)
//T.C : O(n)
//S.C : O(n) space taken for resurion system stack
class Solution {
    String result = "";

    void solve(TreeNode root, String curr) {
        if (root == null) {
            return;
        }

        curr = (char) (root.val + 'a') + curr; // This will take O(length of curr) but I have ignored this. You can consider this as well in calculating T.C

        if (root.left == null && root.right == null) {
            if (result.equals("") || result.compareTo(curr) > 0) {
                result = curr;
            }
            return;
        }

        solve(root.left, curr);
        solve(root.right, curr);
    }

    public String smallestFromLeaf(TreeNode root) {
        solve(root, "");
        return result;
    }
}



//Approach-2 (Using BFS)
//T.C : O(n)
//S.C : O(n)
class Solution {
    public String smallestFromLeaf(TreeNode root) {
        Queue<Pair<TreeNode, String>> queue = new LinkedList<>();
        
        String result = "";
        queue.add(new Pair<>(root, String.valueOf((char)(root.val + 'a'))));
        
        while (!queue.isEmpty()) {
            Pair<TreeNode, String> pair = queue.poll();
            TreeNode node = pair.getKey();
            String curr = pair.getValue();
            
            if (node.left == null && node.right == null) {
                if (result.equals("") || result.compareTo(curr) > 0) {
                    result = curr;
                }
            }
            
            if (node.left != null) {
                queue.add(new Pair<>(node.left, (char)(node.left.val + 'a') + curr));
            }
            
            if (node.right != null) {
                queue.add(new Pair<>(node.right, (char)(node.right.val + 'a') + curr));
            }
        }
        
        return result;
    }
}
