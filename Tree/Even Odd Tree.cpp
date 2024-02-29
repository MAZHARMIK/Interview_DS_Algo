/*         Scroll down to see JAVA code also       */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=ai7zemxYjz4
    Company Tags                : Amazon
    Leetcode Link               : https://leetcode.com/problems/even-odd-tree/
*/

/*************************************************************** C++ *****************************************************************/
//Approach-1 (When we deal with level, always first think of BFS)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> que;
        
        que.push(root);
        bool even_level = true;
        
        while(!que.empty()) {
            
            int n = que.size();
            int prev;
            if(even_level)
                prev = INT_MIN;
            else
                prev = INT_MAX;
            
            while(n--) {
                
                TreeNode* node = que.front();
                que.pop();
                
                if (even_level && (node->val % 2 == 0 || node->val <= prev)) {
                    return false;
                }
                if (!even_level && (node->val % 2 == 1 || node->val >= prev)) {
                    return false;
                }
                
 
                
                prev = node->val;
                if(node->left) {
                    que.push(node->left);
                }
                if(node->right) {
                    que.push(node->right);
                }
                
            }
            
            even_level = !even_level;
            
        }
        
        return true;
    }
};



//Approach-2 (DFS)
//T.C : O(n)
//S.C : Auxiliary Space O(n) + Recursion Space O(depth)
class Solution {
public:
    
    vector<int> levelPrev;
    
    bool solve(TreeNode* root, int level) {
        if(!root) {
            return true;
        }
        
        if((level%2 == 0 && root->val%2 == 0) || (level%2 != 0 && root->val%2 != 0)) {
            return false;
        }
        
        if(level >= levelPrev.size()) {
            levelPrev.resize(level+1);
        }

        if(levelPrev[level] != 0) { //already there is a value at this level
            if((level%2 == 0 && root->val <= levelPrev[level]) ||
               (level%2 != 0 && root->val >= levelPrev[level]))
                return false;
        }
        
        levelPrev[level] = root->val;
        
        return solve(root->left, level+1) && solve(root->right, level+1);
    }
    
    bool isEvenOddTree(TreeNode* root) {
        return solve(root, 0);
    }
};



/*************************************************************** JAVA *****************************************************************/
//Approach-1 (When we deal with level, always first think of BFS)
//T.C : O(n)
//S.C : O(n)
class Solution {
    public boolean isEvenOddTree(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        boolean evenLevel = true;

        while (!queue.isEmpty()) {
            int size = queue.size();
            int prev = evenLevel ? Integer.MIN_VALUE : Integer.MAX_VALUE;

            while (size-- > 0) {
                TreeNode node = queue.poll();

                if ((evenLevel && (node.val % 2 == 0 || node.val <= prev)) ||
                    (!evenLevel && (node.val % 2 == 1 || node.val >= prev))) {
                    return false;
                }

                prev = node.val;

                if (node.left != null) {
                    queue.offer(node.left);
                }
                if (node.right != null) {
                    queue.offer(node.right);
                }
            }

            evenLevel = !evenLevel;
        }

        return true;
    }
}


//Approach-2 (DFS)
//T.C : O(n)
//S.C : Auxiliary Space O(n) + Recursion Space O(depth)
class Solution {
    private List<Integer> levelPrev = new ArrayList<>();

    public boolean isEvenOddTree(TreeNode root) {
        return solve(root, 0);
    }

    private boolean solve(TreeNode root, int level) {
        if (root == null) {
            return true;
        }

        if ((level % 2 == 0 && root.val % 2 == 0) || (level % 2 != 0 && root.val % 2 != 0)) {
            return false;
        }

        if (level >= levelPrev.size()) {
            levelPrev.add(root.val);
        } else {
            if ((level % 2 == 0 && root.val <= levelPrev.get(level)) ||
                (level % 2 != 0 && root.val >= levelPrev.get(level))) {
                return false;
            }
            levelPrev.set(level, root.val);
        }

        return solve(root.left, level + 1) && solve(root.right, level + 1);
    }
}
