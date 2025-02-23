/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal
*/


/****************************************************** C++ ***************************************************/
//Approach-1 (brute force)
//T.C : O(n^2)
//S.C : O(n) for System Stack used for Recursion
class Solution {
public:
    TreeNode* solve(int prestart, int poststart, int preend, vector<int>& preorder, vector<int>& postorder) {
        if(prestart > preend) {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[prestart]);
        if(prestart == preend) {
            return root;
        }
        int nextNode = preorder[prestart+1]; //root of left subtree

        int j = poststart;
        while(postorder[j] != nextNode) {
            j++;
        }

        int num = j - poststart + 1;

        root->left = solve(prestart+1, poststart, prestart+num, preorder, postorder);
        root->right = solve(prestart+num+1, j+1, preend, preorder, postorder);

        return root;
    }


    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        return solve(0, 0, n-1, preorder, postorder);
    }
};



//Approach-2 (using map to optimise)
//T.C : O(n)
//S.C : O(n) using map of size n (you can also include n for System Stack used for Recursion)
class Solution {
public:
    TreeNode* solve(int prestart, int poststart, int preend, vector<int>& preorder, vector<int>& postorder,
                    unordered_map<int, int>& mp) {
        if(prestart > preend) {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[prestart]);
        if(prestart == preend) {
            return root;
        }
        int nextNode = preorder[prestart+1]; //root of left subtree

        int j = mp[nextNode];

        int num = j - poststart + 1;

        root->left = solve(prestart+1, poststart, prestart+num, preorder, postorder, mp);
        root->right = solve(prestart+num+1, j+1, preend, preorder, postorder, mp);

        return root;
    }


    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) {
            mp[postorder[i]] = i;
        }
        return solve(0, 0, n-1, preorder, postorder, mp);
    }
};



/****************************************************** Java ***************************************************/
// Approach-1 (brute force)
// T.C : O(n^2)
// S.C : O(n) for System Stack used for Recursion
class Solution {
    public TreeNode solve(int prestart, int poststart, int preend, int[] preorder, int[] postorder) {
        if (prestart > preend) {
            return null;
        }

        TreeNode root = new TreeNode(preorder[prestart]);
        if (prestart == preend) {
            return root;
        }
        int nextNode = preorder[prestart + 1]; // root of left subtree

        int j = poststart;
        while (postorder[j] != nextNode) {
            j++;
        }

        int num = j - poststart + 1;

        root.left = solve(prestart + 1, poststart, prestart + num, preorder, postorder);
        root.right = solve(prestart + num + 1, j + 1, preend, preorder, postorder);

        return root;
    }

    public TreeNode constructFromPrePost(int[] preorder, int[] postorder) {
        int n = preorder.length;
        return solve(0, 0, n - 1, preorder, postorder);
    }
}


// Approach-2 (using map to optimize)
// T.C : O(n)
// S.C : O(n) using map of size n (you can also include n for System Stack used for Recursion)
import java.util.HashMap;
import java.util.Map;

class Solution {
    public TreeNode solve(int prestart, int poststart, int preend, int[] preorder, int[] postorder,
                          Map<Integer, Integer> mp) {
        if (prestart > preend) {
            return null;
        }

        TreeNode root = new TreeNode(preorder[prestart]);
        if (prestart == preend) {
            return root;
        }
        int nextNode = preorder[prestart + 1]; // root of left subtree

        int j = mp.get(nextNode);

        int num = j - poststart + 1;

        root.left = solve(prestart + 1, poststart, prestart + num, preorder, postorder, mp);
        root.right = solve(prestart + num + 1, j + 1, preend, preorder, postorder, mp);

        return root;
    }

    public TreeNode constructFromPrePost(int[] preorder, int[] postorder) {
        int n = preorder.length;
        Map<Integer, Integer> mp = new HashMap<>();
        for (int i = 0; i < n; i++) {
            mp.put(postorder[i], i);
        }
        return solve(0, 0, n - 1, preorder, postorder, mp);
    }
}
