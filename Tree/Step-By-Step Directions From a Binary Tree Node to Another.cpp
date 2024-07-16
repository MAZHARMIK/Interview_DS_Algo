/*     Scroll below to see JAVA code also    */
/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=6GXfmgfOGeQ
      Company Tags                : AMAZON
      Leetcode Link               : https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another
*/


/************************************************************ C++ ************************************************************/
//Approach-1 (Using LCA)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, int src, int dest) {
        if(!root)
            return NULL;
        
        if(root->val == src || root->val == dest)
            return root;
        
        TreeNode* l = lowestCommonAncestor(root->left,  src, dest);
        TreeNode* r = lowestCommonAncestor(root->right, src, dest);
        
        if(l && r)
            return root;
        
        return l ? l : r;
    }

    bool findPath(TreeNode* LCA, int target, string& path) {
        if(LCA == NULL) {
            return false;
        }

        if(LCA->val == target) {
            return true;
        }

        //explore Left
        path.push_back('L');
        if(findPath(LCA->left, target, path) == true) {
            return true;
        }

        path.pop_back();

        //explore right
        path.push_back('R');
        if(findPath(LCA->right, target, path) == true) {
            return true;
        }

        path.pop_back();

        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* LCA = lowestCommonAncestor(root, startValue, destValue);

        string lcaTOSrc  = "";
        string lcaTODest = "";

        findPath(LCA, startValue, lcaTOSrc);
        findPath(LCA, destValue, lcaTODest);

        string result = "";

        for(int i = 0; i < lcaTOSrc.length(); i++) {
            result.push_back('U');
        }

        result += lcaTODest;

        return result;
    }
};



//Approach-2 (Without finding LCA)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:

    bool findPath(TreeNode* LCA, int target, string& path) {
        if(LCA == NULL) {
            return false;
        }

        if(LCA->val == target) {
            return true;
        }

        //explore Left
        path.push_back('L');
        if(findPath(LCA->left, target, path) == true) {
            return true;
        }

        path.pop_back();

        //explore right
        path.push_back('R');
        if(findPath(LCA->right, target, path) == true) {
            return true;
        }

        path.pop_back();

        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        
        string rootToSrc  = "";
        string rootToDst = "";

        findPath(root, startValue, rootToSrc); //O(n)
        findPath(root, destValue,  rootToDst); //O(n)


        int l = 0; //commonPathLength
        while(l < rootToSrc.length() && l < rootToDst.length() && rootToSrc[l] == rootToDst[l]) {
            l++;
        }

        string result = "";
        //Add "U"
        for(int i = 0; i < rootToSrc.length() - l; i++) {
            result.push_back('U');
        }

        for(int i = l; i < rootToDst.length(); i++) {
            result.push_back(rootToDst[i]);
        }

        return result;
    }
};



/************************************************************ JAVA ************************************************************/
//Approach-1 (Using LCA)
//T.C : O(n)
//S.C : O(n)
class Solution {

    private TreeNode lowestCommonAncestor(TreeNode root, int src, int dest) {
        if (root == null) {
            return null;
        }
        
        if (root.val == src || root.val == dest) {
            return root;
        }
        
        TreeNode left = lowestCommonAncestor(root.left, src, dest);
        TreeNode right = lowestCommonAncestor(root.right, src, dest);
        
        if (left != null && right != null) {
            return root;
        }
        
        return left != null ? left : right;
    }

    private boolean findPath(TreeNode node, int target, StringBuilder path) {
        if (node == null) {
            return false;
        }

        if (node.val == target) {
            return true;
        }

        path.append('L');
        if (findPath(node.left, target, path)) {
            return true;
        }
        path.deleteCharAt(path.length() - 1);

        path.append('R');
        if (findPath(node.right, target, path)) {
            return true;
        }
        path.deleteCharAt(path.length() - 1);

        return false;
    }

    public String getDirections(TreeNode root, int startValue, int destValue) {
        TreeNode LCA = lowestCommonAncestor(root, startValue, destValue);

        StringBuilder lcaToStart = new StringBuilder();
        StringBuilder lcaToDest = new StringBuilder();

        findPath(LCA, startValue, lcaToStart);
        findPath(LCA, destValue, lcaToDest);

        StringBuilder result = new StringBuilder();

        for (int i = 0; i < lcaToStart.length(); i++) {
            result.append('U');
        }

        result.append(lcaToDest);

        return result.toString();
    }
}




//Approach-2 (Without finding LCA)
//T.C : O(n)
//S.C : O(n)
class Solution {

    private boolean findPath(TreeNode root, int target, StringBuilder path) {
        if (root == null) {
            return false;
        }

        if (root.val == target) {
            return true;
        }

        // Explore left
        path.append('L');
        if (findPath(root.left, target, path)) {
            return true;
        }
        path.deleteCharAt(path.length() - 1);

        // Explore right
        path.append('R');
        if (findPath(root.right, target, path)) {
            return true;
        }
        path.deleteCharAt(path.length() - 1);

        return false;
    }

    public String getDirections(TreeNode root, int startValue, int destValue) {
        StringBuilder rootToSrc = new StringBuilder();
        StringBuilder rootToDst = new StringBuilder();

        findPath(root, startValue, rootToSrc); // O(n)
        findPath(root, destValue, rootToDst);  // O(n)

        int l = 0; // commonPathLength
        while (l < rootToSrc.length() && l < rootToDst.length() && rootToSrc.charAt(l) == rootToDst.charAt(l)) {
            l++;
        }

        StringBuilder result = new StringBuilder();
        // Add "U"
        for (int i = 0; i < rootToSrc.length() - l; i++) {
            result.append('U');
        }

        for (int i = l; i < rootToDst.length(); i++) {
            result.append(rootToDst.charAt(i));
        }

        return result.toString();
    }
}
