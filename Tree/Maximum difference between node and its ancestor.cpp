/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=cvekQzmBdcs
    Company Tags                : Google, Amazon, Microsoft
    Leetcode Link               : https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/
    GfG Link                    : https://practice.geeksforgeeks.org/problems/maximum-difference-between-node-and-its-ancestor/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
*/

/************************************************************ C++ ***************************************************************************/
//Approach-1 (Brute Force) - O(n^2) - n = number of nodes in the Tree
/*
  Just simply take a root, find all the differences of it from its childres and find max one
  Again go to root->left and do the same as above
  Again go to root->right and do the same as above
*/
class Solution {
public:
    int maxDiff;

    void findMaxUtil(TreeNode* root, TreeNode* child) {
        if(!root || !child)
            return;
        
        maxDiff = max(maxDiff, abs(root->val - child->val));

        findMaxUtil(root, child->left);
        findMaxUtil(root, child->right);
    }

    void findMaxDiff(TreeNode* root) {
        if(!root || !root->left && !root->right)
         return;
         
         //Find max differences of this root with all its children
         findMaxUtil(root, root->left);
         findMaxUtil(root, root->right);

         //firther move left and right
         findMaxDiff(root->left);
         findMaxDiff(root->right);
    }

    int maxAncestorDiff(TreeNode* root) {
        maxDiff = INT_MIN;

        findMaxDiff(root);   

        return maxDiff;     
    }
};


//Approach-2
//Optimal (O(n)) using min and max value for |min-max|
class Solution {
public:
    
    int findMaxDiff(TreeNode* root, int minV, int maxV) {
        if(!root)
            return abs(minV-maxV);
        
        minV = min(root->val, minV);
        maxV = max(root->val, maxV);

        int l = findMaxDiff(root->left,  minV, maxV);
        int r = findMaxDiff(root->right, minV, maxV);


        return max(l, r);

    }

    int maxAncestorDiff(TreeNode* root) {
        int minV = root->val;
        int maxV = root->val;

        return findMaxDiff(root, minV, maxV);
   
    }
};


/************************************************************ JAVA ***************************************************************************/
/************************************************************ C++ ***************************************************************************/
//Approach-1 (Brute Force) - O(n^2) - n = number of nodes in the Tree
/*
  Just simply take a root, find all the differences of it from its childres and find max one
  Again go to root->left and do the same as above
  Again go to root->right and do the same as above
*/
class Solution {
    int maxDiff;

    void findMaxUtil(TreeNode root, TreeNode child) {
        if (root == null || child == null) {
            return;
        }

        maxDiff = Math.max(maxDiff, Math.abs(root.val - child.val));

        findMaxUtil(root, child.left);
        findMaxUtil(root, child.right);
    }

    void findMaxDiff(TreeNode root) {
        if (root == null || (root.left == null && root.right == null)) {
            return;
        }

        // Find max differences of this root with all its children
        findMaxUtil(root, root.left);
        findMaxUtil(root, root.right);

        // Further move left and right
        findMaxDiff(root.left);
        findMaxDiff(root.right);
    }

    public int maxAncestorDiff(TreeNode root) {
        maxDiff = Integer.MIN_VALUE;

        findMaxDiff(root);

        return maxDiff;
    }
}


//Approach-2
//Optimal (O(n)) using min and max value for |min-max|
class Solution {
    public int findMaxDiff(TreeNode root, int minV, int maxV) {
        if (root == null) {
            return Math.abs(minV - maxV);
        }

        minV = Math.min(root.val, minV);
        maxV = Math.max(root.val, maxV);

        int l = findMaxDiff(root.left, minV, maxV);
        int r = findMaxDiff(root.right, minV, maxV);

        return Math.max(l, r);
    }

    public int maxAncestorDiff(TreeNode root) {
        int minV = root.val;
        int maxV = root.val;

        return findMaxDiff(root, minV, maxV);
    }
}
