/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Y4UGaLpSqCg
    Company Tags                : Similar Qn Asked by Google for N-ary tree(SWE Intern Position, 2nd Technical Interview) , Year = 2023, September, META
    Leetcode Link               : https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree
*/

/************************************************ C++ ************************************************/
//Approach-1 (Brute Force)
//T.C : O(n^2) For every root, you visit it's subtree to find average
//S.C : O(1) (excluding recursion stack space)
class Solution {
public:
    int result;
    
    int sum(TreeNode* root, int &count) {
        if(!root)
            return 0;
        
        count++;
        
        int l = sum(root->left, count);
        int r = sum(root->right, count);
        
        return l + r + root->val;
    }
    
    void solve(TreeNode* root) {
        if(!root)
            return;
        
        int count = 0;
        int totalSum = sum(root, count);
        
        if((totalSum)/count == root->val) {
            result++;
        }
        
        solve(root->left);
        solve(root->right);
        
    }
    
    int averageOfSubtree(TreeNode* root) {
        result = 0;
        
        solve(root);
        
        return result;
    }
};

//Approach-2 (Doing postorder traversal)
//T.C : O(n)
//S.C : O(1) (excluding recursion stack space)
class Solution {
public:
    int result;
    
    pair<int, int> solve(TreeNode* root) {
        if(!root)
            return {0, 0};
        
        pair<int, int> l = solve(root->left);
        pair<int, int> r = solve(root->right);
        
        int leftSum   = l.first;
        int leftCount = l.second;
        
        int rightSum   = r.first;
        int rightCount = r.second;
        
        int SUM   = leftSum + rightSum + root->val;
        int COUNT = leftCount + rightCount + 1;
        
        int avg = SUM/COUNT;
        
        if(avg == root->val) {
            result++;
        }
        
        return {SUM, COUNT};
    }
    
    int averageOfSubtree(TreeNode* root) {
        result = 0;
        
        solve(root);
        
        return result;
    }
};

/************************************************ JAVA ************************************************/
//Approach-1 (Brute Force)
//T.C : O(n^2) For every root, you visit it's subtree to find average
//S.C : O(1) (excluding recursion stack space)
public class Solution {
    private int result;
    
    private int sum(TreeNode root, int[] count) {
        if (root == null) {
            return 0;
        }
        
        count[0]++;
        
        int leftSum = sum(root.left, count);
        int rightSum = sum(root.right, count);
        
        return leftSum + rightSum + root.val;
    }
    
    private void solve(TreeNode root) {
        if (root == null) {
            return;
        }
        
        int[] count = {0};
        int totalSum = sum(root, count);
        
        if (totalSum / count[0] == root.val) {
            result++;
        }
        
        solve(root.left);
        solve(root.right);
    }
    
    public int averageOfSubtree(TreeNode root) {
        result = 0;
        
        solve(root);
        
        return result;
    }
}

//Approach-2 (Doing postorder traversal)
//T.C : O(n)
//S.C : O(1) (excluding recursion stack space)
public class Solution {
    private int result;
    
    private Pair<Integer, Integer> solve(TreeNode root) {
        if (root == null) {
            return new Pair<>(0, 0);
        }
        
        Pair<Integer, Integer> left = solve(root.left);
        Pair<Integer, Integer> right = solve(root.right);
        
        int leftSum = left.getKey();
        int leftCount = left.getValue();
        
        int rightSum = right.getKey();
        int rightCount = right.getValue();
        
        int SUM = leftSum + rightSum + root.val;
        int COUNT = leftCount + rightCount + 1;
        
        int avg = SUM / COUNT;
        
        if (avg == root.val) {
            result++;
        }
        
        return new Pair<>(SUM, COUNT);
    }
    
    public int averageOfSubtree(TreeNode root) {
        result = 0;
        
        solve(root);
        
        return result;
    }
}
