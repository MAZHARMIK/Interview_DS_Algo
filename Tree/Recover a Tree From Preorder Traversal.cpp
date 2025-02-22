/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/recover-a-tree-from-preorder-traversal
*/


/****************************************************** C++ ***************************************************/
//Approach - Using Recursion (Simulation of DFS in Tree)
//T.C : O(n)
//S.C : O(n) for System Stack used for Recursion
class Solution {
public:
    int n;

    TreeNode* solve(const string& traversal, int& i, int depth) {
        if (i >= n)
            return NULL;

        int j = i;
        while (j < n && traversal[j] == '-') {
            j++;
        }
        
        int dash = j-i;

        if(depth != dash) {
            return NULL;
        }

        i += dash;

        int value = 0;
        while (i < n && isdigit(traversal[i])) {
            value = value * 10 + (traversal[i] - '0');
            i++;
        }

        TreeNode* root = new TreeNode(value);

        root->left  = solve(traversal, i, depth + 1);
        root->right = solve(traversal, i, depth + 1);

        return root;
    }

    TreeNode* recoverFromPreorder(string traversal) {
        n = traversal.length();
        int i = 0;
        return solve(traversal, i, 0);
    }

};



/****************************************************** JAVA ***************************************************/
//Approach - Using Recursion (Simulation of DFS in Tree)
//T.C : O(n)
//S.C : O(n) for System Stack used for Recursion
class Solution {
    private int n;
    
    private TreeNode solve(String traversal, int[] index, int depth) {
        if (index[0] >= n) {
            return null;
        }
        
        int j = index[0];
        while (j < n && traversal.charAt(j) == '-') {
            j++;
        }
        
        int dash = j - index[0];
        
        if (depth != dash) {
            return null;
        }
        
        index[0] += dash;
        
        int value = 0;
        while (index[0] < n && Character.isDigit(traversal.charAt(index[0]))) {
            value = value * 10 + (traversal.charAt(index[0]) - '0');
            index[0]++;
        }
        
        TreeNode root = new TreeNode(value);
        root.left = solve(traversal, index, depth + 1);
        root.right = solve(traversal, index, depth + 1);
        
        return root;
    }
    
    public TreeNode recoverFromPreorder(String traversal) {
        n = traversal.length();
        int[] index = {0}; // Using an array to pass by reference
        return solve(traversal, index, 0);
    }
}
