/*
    MY YOUTUBE VIDEO ON THIS Qn  : https://www.youtube.com/watch?v=FK-Fztwj2gM
    Company Tags                 : will update soon
    Leetcode Link                : https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/
*/


/****************************************************** C++ ******************************************************/
//Approach-1 (Simple and straight forward)
//T.C : O(n)
//S.C : O(1) (I am ignoring stack recursive space, else S.C  will be O(height of tree))
class Solution {
public:
    int result = 0;
    
    void solve(TreeNode* root, vector<int>& temp) {
        if(root != NULL) {
            temp[root->val]++;
            
            if(root->left == NULL && root->right == NULL) {
                int oddFreq = 0;
                for(int i = 1; i <= 9; i++) {
                    if(temp[i]%2 != 0) {
                        oddFreq++;
                    }
                }

                result += oddFreq <= 1;
            }
            
            
            solve(root->left, temp);
            solve(root->right, temp);
            
            temp[root->val]--;

        }
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> temp(10, 0);
        
        solve(root, temp);
        return result;
    }
};

//Approach-2 (Using bit magic)
//T.C : O(n)
//S.C : O(1) (I am ignoring stack recursive space, else S.C  will be O(height of tree))
class Solution {
public:
    int result = 0;
    
    void solve(TreeNode* root, int temp) {
        if(root != NULL) {
            
            temp = temp ^ (1 << root->val);
            
            if(root->left == NULL && root->right == NULL) {
                if((temp & (temp - 1)) == 0) { //Make sure to put (temp & (temp - 1)) entirely in bracket because precedence of == is high
                    result++;
                }
            }
            
            
            solve(root->left, temp);
            solve(root->right, temp);


        }
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {

        solve(root, 0);
        return result;
    }
};




/****************************************************** JAVA ******************************************************/
//Approach-1 (Simple and straight forward)
//T.C : O(n)
//S.C : O(1) (I am ignoring stack recursive space, else S.C  will be O(height of tree))
class Solution {
    private int result = 0;

    public int pseudoPalindromicPaths(TreeNode root) {
        int[] temp = new int[10];
        solve(root, temp);
        return result;
    }

    private void solve(TreeNode root, int[] temp) {
        if (root != null) {
            temp[root.val]++;

            if (root.left == null && root.right == null) {
                int oddFreq = 0;
                for (int i = 1; i <= 9; i++) {
                    if (temp[i] % 2 != 0) {
                        oddFreq++;
                    }
                }

                result += oddFreq <= 1 ? 1 : 0;
            }

            solve(root.left, temp);
            solve(root.right, temp);

            temp[root.val]--;
        }
    }
}


//Approach-2 (Using bit magic)
//T.C : O(n)
//S.C : O(1) (I am ignoring stack recursive space, else S.C  will be O(height of tree))
class Solution {
    private int result = 0;

    public int pseudoPalindromicPaths(TreeNode root) {
        solve(root, 0);
        return result;
    }

    private void solve(TreeNode root, int temp) {
        if (root != null) {
            temp = temp ^ (1 << root.val);

            if (root.left == null && root.right == null) {
                if ((temp & (temp - 1)) == 0) {
                    result++;
                }
            }

            solve(root.left, temp);
            solve(root.right, temp);
        }
    }
}
