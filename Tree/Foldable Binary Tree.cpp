/*
    Company Tags : Expedia
    GfG Link     : https://practice.geeksforgeeks.org/problems/foldable-binary-tree/1
*/


bool solve(Node* rootL, Node* rootR) {
    if(rootL == NULL && rootR == NULL)
        return true;
    
    if(rootL && rootR)
        return solve(rootL->left, rootR->right) &&
               solve(rootL->right, rootR->left) ;
  
    return false;
}

//Function to check whether a binary tree is foldable or not.
bool IsFoldable(Node* root) {
    if(!root)
        return true;
    
    return solve(root->left, root->right);
}
