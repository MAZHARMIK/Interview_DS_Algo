/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=UIrargaZ61M
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/cousins-in-binary-tree-ii
*/


/****************************************************** C++ *********************************************/
//Approach-1 (2 Pass)
//T.C : O(2*n)
//S.C : O(n)
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(root == NULL)
            return root;

        queue<TreeNode*> que;
        que.push(root);
        vector<int> levelSum;

        //Step-1 (find sum of each level and store in levelSum array)
        while(!que.empty()) {
            int currLevelSum = 0;
            int n = que.size();
            while(n--) {
                TreeNode* curr = que.front();
                que.pop();
                currLevelSum += curr->val;
                if(curr->left) {
                    que.push(curr->left);
                }
                if(curr->right) {
                    que.push(curr->right);
                }
            }

            levelSum.push_back(currLevelSum);
        }
        cout << levelSum.size() << endl;

        //Step-2 (update each node value with cousin sum)
        que.push(root);
        root->val = 0; //root has not cousins
        int i = 1;
        while(!que.empty()) {
            int n = que.size(); //current level me kitne nodes hain

            while(n--) {
                TreeNode* curr = que.front();
                que.pop();

                //levelSum of currentLevel - sibilnigSum
                int siblingSum = curr->left != NULL ? curr->left->val : 0;
                siblingSum += curr->right != NULL ? curr->right->val : 0;

                if(curr->left) {
                    curr->left->val = levelSum[i] - siblingSum;
                    que.push(curr->left);
                }
                if(curr->right) {
                    curr->right->val = levelSum[i] - siblingSum;
                    que.push(curr->right);
                }
            }
            i++;
        }

        return root;

    }
};


//Approach-2 (1 Pass)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(root == NULL) {
            return root;
        }        

        queue<TreeNode*> que;
        que.push(root);
        int levelSum = root->val;

        while(!que.empty()) {
            int n = que.size();
            int nextLevelSum = 0;

            while(n--) {
                TreeNode* curr = que.front();
                que.pop();

                curr->val = levelSum - curr->val;

                int siblingSum = (curr->left != NULL ? curr->left->val : 0);
                siblingSum += (curr->right != NULL ? curr->right->val : 0);

                if(curr->left) {
                    nextLevelSum += curr->left->val;
                    curr->left->val = siblingSum;
                    que.push(curr->left);
                }


                if(curr->right) {
                    nextLevelSum += curr->right->val;
                    curr->right->val = siblingSum;
                    que.push(curr->right);
                }
            }

            levelSum = nextLevelSum;
        }

        return root;
    }
};


/****************************************************** JAVA *********************************************/
//Approach-1 (2 Pass)
//T.C : O(2*n)
//S.C : O(n)
class Solution {
    public TreeNode replaceValueInTree(TreeNode root) {
        if (root == null) {
            return root;
        }

        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        List<Integer> levelSum = new ArrayList<>();

        // Step-1: Find the sum of each level and store it in the levelSum list
        while (!queue.isEmpty()) {
            int currLevelSum = 0;
            int n = queue.size();
            for (int i = 0; i < n; i++) {
                TreeNode curr = queue.poll();
                currLevelSum += curr.val;
                if (curr.left != null) {
                    queue.add(curr.left);
                }
                if (curr.right != null) {
                    queue.add(curr.right);
                }
            }
            levelSum.add(currLevelSum);
        }

        // Step-2: Update each node value with the cousin sum
        queue.add(root);
        root.val = 0;  // root has no cousins
        int level = 1;
        while (!queue.isEmpty()) {
            int n = queue.size();

            for (int i = 0; i < n; i++) {
                TreeNode curr = queue.poll();

                // levelSum of currentLevel - siblingSum
                int siblingSum = (curr.left != null ? curr.left.val : 0) + (curr.right != null ? curr.right.val : 0);

                if (curr.left != null) {
                    curr.left.val = levelSum.get(level) - siblingSum;
                    queue.add(curr.left);
                }
                if (curr.right != null) {
                    curr.right.val = levelSum.get(level) - siblingSum;
                    queue.add(curr.right);
                }
            }
            level++;
        }

        return root;
    }
}


//Approach-2 (1 Pass)
//T.C : O(n)
//S.C : O(n)
class Solution {
    public TreeNode replaceValueInTree(TreeNode root) {
        if (root == null) {
            return root;
        }

        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        int levelSum = root.val;

        while (!queue.isEmpty()) {
            int n = queue.size();
            int nextLevelSum = 0;

            for (int i = 0; i < n; i++) {
                TreeNode curr = queue.poll();

                // Update current node value
                curr.val = levelSum - curr.val;

                int siblingSum = (curr.left != null ? curr.left.val : 0) +
                                 (curr.right != null ? curr.right.val : 0);

                // Process left child
                if (curr.left != null) {
                    nextLevelSum += curr.left.val;
                    curr.left.val = siblingSum;
                    queue.add(curr.left);
                }

                // Process right child
                if (curr.right != null) {
                    nextLevelSum += curr.right.val;
                    curr.right.val = siblingSum;
                    queue.add(curr.right);
                }
            }

            // Move to the next level
            levelSum = nextLevelSum;
        }

        return root;
    }
}
