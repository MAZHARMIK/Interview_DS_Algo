/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/reverse-odd-levels-of-binary-tree
*/


/****************************************************** C++ *********************************************/
//Approach-1 - Simple BFS
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> que;

        que.push(root);
        int level = 0;

        while(!que.empty()) {
            int n = que.size();

            vector<TreeNode*> levelNodes;
            while(n--) {
                TreeNode* temp = que.front();
                que.pop();
                levelNodes.push_back(temp);

                if(temp->left) {
                    que.push(temp->left);
                }
                if(temp->right) {
                    que.push(temp->right);
                }
            }
            if(level%2 == 1) {
                int l = 0, r = levelNodes.size()-1;
                while(l < r) {
                    int tempVal = levelNodes[l]->val;
                    levelNodes[l]->val = levelNodes[r]->val;
                    levelNodes[r]->val = tempVal;
                    l++;
                    r--;
                }
            }
            level++;
        }

        return root;
    }
};


//Approach-2 - Tricky DFS (explained the trick on how to write such DFS)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    void solve(TreeNode* l, TreeNode* r, int level) {
        if(l == NULL || r == NULL) { //Not leaf
            return;
        }

        if(level%2 == 1) {
            int temp = l->val;
            l->val = r->val;
            r->val = temp;
        }

        solve(l->left, r->right, level+1);
        solve(l->right, r->left, level+1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        solve(root->left, root->right, 1); //root at 0 and left and right child at level = 1
        return root;
    }
};



/****************************************************** JAVA *********************************************/
//Approach-1 - Simple BFS
//T.C : O(n)
//S.C : O(n)
class Solution {
    public TreeNode reverseOddLevels(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        int level = 0;

        while (!queue.isEmpty()) {
            int size = queue.size();
            List<TreeNode> levelNodes = new ArrayList<>();

            for (int i = 0; i < size; i++) {
                TreeNode node = queue.poll();
                levelNodes.add(node);

                if (node.left != null) {
                    queue.add(node.left);
                }
                if (node.right != null) {
                    queue.add(node.right);
                }
            }

            if (level % 2 == 1) {
                int left = 0, right = levelNodes.size() - 1;
                while (left < right) {
                    int temp = levelNodes.get(left).val;
                    levelNodes.get(left).val = levelNodes.get(right).val;
                    levelNodes.get(right).val = temp;
                    left++;
                    right--;
                }
            }

            level++;
        }

        return root;
    }
}


//Approach-2 - Tricky DFS (explained the trick on how to write such DFS)
//T.C : O(n)
//S.C : O(n)
class Solution {
    private void solve(TreeNode left, TreeNode right, int level) {
        if (left == null || right == null) {
            return;
        }

        if (level % 2 == 1) {
            int temp = left.val;
            left.val = right.val;
            right.val = temp;
        }

        solve(left.left, right.right, level + 1);
        solve(left.right, right.left, level + 1);
    }

    public TreeNode reverseOddLevels(TreeNode root) {
        solve(root.left, root.right, 1); // root is at level 0, left and right children at level 1
        return root;
    }
}
