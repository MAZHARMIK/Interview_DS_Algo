/*     Scroll below to see JAVA code also  */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=wHzpM_u7p0s
    Company Tags                : Paytm
    Leetcode Link               : https://leetcode.com/problems/balance-a-binary-search-tree/description
*/


/************************************************************************ C++ ********************************************************/
//Simple approach using inordere tree traversal
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    void inOrder(TreeNode* root, vector<int>& vec) {
        if(!root)
            return;
        
        inOrder(root->left, vec);
        vec.push_back(root->val);
        inOrder(root->right, vec);

    }

    TreeNode* construct(int l, int r, vector<int>& vec) {
        if(l > r)
            return NULL;
        
        int mid = l + (r-l)/2;
        TreeNode* root = new TreeNode(vec[mid]);

        root->left  = construct(l, mid-1, vec);
        root->right = construct(mid+1, r, vec);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> vec;
        inOrder(root, vec);
        int l = 0, r = vec.size()-1;

        return construct(l, r, vec);
    }
};


/************************************************************************ JAVA ********************************************************/
//Simple approach using inordere tree traversal
//T.C : O(n)
//S.C : O(n)
class Solution {
    private void inOrder(TreeNode root, List<Integer> vec) {
        if (root == null) {
            return;
        }
        inOrder(root.left, vec);
        vec.add(root.val);
        inOrder(root.right, vec);
    }

    private TreeNode construct(int l, int r, List<Integer> vec) {
        if (l > r) {
            return null;
        }
        int mid = l + (r - l) / 2;
        TreeNode root = new TreeNode(vec.get(mid));
        root.left = construct(l, mid - 1, vec);
        root.right = construct(mid + 1, r, vec);
        return root;
    }

    public TreeNode balanceBST(TreeNode root) {
        List<Integer> vec = new ArrayList<>();
        inOrder(root, vec);
        return construct(0, vec.size() - 1, vec);
    }
}
