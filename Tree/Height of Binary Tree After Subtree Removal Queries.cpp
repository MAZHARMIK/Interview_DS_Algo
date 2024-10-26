/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/height-of-binary-tree-after-subtree-removal-queries
*/


/****************************************************** C++ *********************************************/
//Approach - Simple Recursion and preprocessing
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int level[1000001]; //level of each node
    int height[100001]; //height of each node
    int levelMaxHt[100001];
    int levelSecondMaxHt[100001];

    int findHeight(TreeNode* root, int l) {
        if(!root) {
            return 0;
        }

        level[root->val] = l;
        height[root->val] = max(findHeight(root->left, l+1), findHeight(root->right, l+1)) + 1;

        if(levelMaxHt[l] < height[root->val]) {
            levelSecondMaxHt[l] = levelMaxHt[l];
            levelMaxHt[l] = height[root->val];
        } else if(levelSecondMaxHt[l] < height[root->val]) {
            levelSecondMaxHt[l] = height[root->val];
        }

        return height[root->val];
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        findHeight(root, 0);

        vector<int> result;

        for(int &node : queries) {
            //node = that we have to delete
            int L = level[node]; //O(1) //node ka level hai ye

            //L + H - 1

            int tempResult = L + (levelMaxHt[L] == height[node] ? levelSecondMaxHt[L] : levelMaxHt[L]) - 1;

            result.push_back(tempResult);
        } 

        return result;
    }
};


/****************************************************** JAVA *********************************************/
//Approach - Simple Recursion and preprocessing
//T.C : O(n)
//S.C : O(n)
class Solution {
    private int[] level = new int[1000001]; // Level of each node
    private int[] height = new int[100001]; // Height of each node
    private int[] levelMaxHt = new int[100001];
    private int[] levelSecondMaxHt = new int[100001];

    // Method to find the height of each node and populate the max heights at each level
    private int findHeight(TreeNode root, int l) {
        if (root == null) {
            return 0;
        }

        level[root.val] = l;
        height[root.val] = Math.max(findHeight(root.left, l + 1), findHeight(root.right, l + 1)) + 1;

        if (levelMaxHt[l] < height[root.val]) {
            levelSecondMaxHt[l] = levelMaxHt[l];
            levelMaxHt[l] = height[root.val];
        } else if (levelSecondMaxHt[l] < height[root.val]) {
            levelSecondMaxHt[l] = height[root.val];
        }

        return height[root.val];
    }

    // Main method to process queries
    public int[] treeQueries(TreeNode root, int[] queries) {
        findHeight(root, 0);

        int[] result = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            int node = queries[i];
            int L = level[node]; // Node's level

            // Calculate result for this node
            int tempResult = L + (levelMaxHt[L] == height[node] ? levelSecondMaxHt[L] : levelMaxHt[L]) - 1;
            result[i] = tempResult;
        }

        return result;
    }
}
