/*
    Company Tags     : Expedia
    GfG Link         : https://practice.geeksforgeeks.org/problems/foldable-binary-tree/1
*/


/***************************************************************** C++ *****************************************************************/
//T.C : O(n)
//S.C : O(n) (Stack recursion space) else it's O(1)
bool solve(Node* rootL, Node* rootR) {
    if(rootL == NULL && rootR == NULL) {
        return true;
    }
    
    if(rootL == NULL || rootR == NULL) {
        return false;
    }
    
    
    return solve(rootL->left, rootR->right) && solve(rootL->right, rootR->left);

}

//Function to check whether a binary tree is foldable or not.
bool IsFoldable(Node* root) {
    if(!root)
        return true;
        
    
    return solve(root->left, root->right);
}


/***************************************************************** JAVA *****************************************************************/
//T.C : O(n)
//S.C : O(n) (Stack recursion space) else it's O(1)
class Tree
{
    //Function to check whether a binary tree is foldable or not.
    boolean IsFoldable(Node root) {
        if (root == null)
            return true;

        return solve(root.left, root.right);
    }

    boolean solve(Node rootL, Node rootR) {
        if (rootL == null && rootR == null) {
            return true;
        }

        if (rootL == null || rootR == null) {
            return false;
        }

        return solve(rootL.left, rootR.right) && solve(rootL.right, rootR.left);
    } 
}
