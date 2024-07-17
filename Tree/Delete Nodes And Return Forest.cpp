/*         Scroll below to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=z-pX53sYwWI&list=PLpIkg8OmuX-K23LhcamOcDlTBisiNJy5E&index=7
    Company Tags                : Google, Amazon
    Leetcode Qn Link            : https://leetcode.com/problems/delete-nodes-and-return-forest/
*/


/***************************************************************** C++ *****************************************************************/
//Approach -  Using Post Order + set
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    
    TreeNode* deleteHelper(TreeNode* root, unordered_set<int>& st, vector<TreeNode*>& result) {
        if(root == NULL)
            return NULL;
        
        root->left  = deleteHelper(root->left, st, result);
        root->right = deleteHelper(root->right, st, result);
        
        if(st.find(root->val) != st.end()) { //if I have to delete this root, then put root->left and root->right in result
            if(root->left != NULL)
                result.push_back(root->left);
            
            if(root->right != NULL)
                result.push_back(root->right);
            
            return NULL;
        } else {
            return root;
        }
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> result;
        
        unordered_set<int> st;
        
        for(int &num : to_delete) {
            st.insert(num);
        }
        
        deleteHelper(root, st, result); // <-- it will not consider root
        
        //So, check here if root is to be deleted or not
        if(st.find(root->val) == st.end()) {
            result.push_back(root);
        }
        
        
        return result;
    }
};




/***************************************************************** JAVA *****************************************************************/
//Approach -  Using Post Order + set
//T.C : O(n)
//S.C : O(n)
class Solution {
    private TreeNode deleteHelper(TreeNode root, Set<Integer> toDelete, List<TreeNode> result) {
        if (root == null) {
            return null;
        }

        root.left = deleteHelper(root.left, toDelete, result);
        root.right = deleteHelper(root.right, toDelete, result);

        if (toDelete.contains(root.val)) {
            if (root.left != null) {
                result.add(root.left);
            }
            if (root.right != null) {
                result.add(root.right);
            }
            return null;
        } else {
            return root;
        }
    }

    public List<TreeNode> delNodes(TreeNode root, int[] to_delete) {
        List<TreeNode> result = new ArrayList<>();
        Set<Integer> toDelete = new HashSet<>();

        for (int num : to_delete) {
            toDelete.add(num);
        }

        deleteHelper(root, toDelete, result);

        if (!toDelete.contains(root.val)) {
            result.add(root);
        }

        return result;
    }
}
