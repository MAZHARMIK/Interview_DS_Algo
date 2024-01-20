/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=FmHxY2104hc
      Company Tags                : Microsoft
      GfG Link                    : https://www.geeksforgeeks.org/problems/distribute-candies-in-a-binary-tree/1
*/

/****************************************************************** C++ ****************************************************************************************/
//T.C : O(n)
//S.C : O(height of tree due to recursion)
class Solution
{
    public:
    
    int solve(Node* root, int &moves) {
        if(root == NULL) {
            return 0;
        }
        
        int l = solve(root->left, moves);
        int r = solve(root->right, moves);
        
        int total_extra_candies = (l + r + root->key) - 1;
        
        moves += abs(l) + abs(r);
        
        return total_extra_candies;
    }
    
    int distributeCandy(Node* root) {
        int moves = 0;
        if(!root->left && !root->right) {
            return 0;
        }
        solve(root, moves);
        
        return moves;
    }
};




/****************************************************************** JAVA ****************************************************************************************/
//T.C : O(n)
//S.C : O(height of tree due to recursion)
class Solution
{
    public static int distributeCandy(Node root) {
        if (root == null || (root.left == null && root.right == null)) {
            return 0;
        }

        int[] moves = {0};
        solve(root, moves);

        return moves[0];
    }
    private static int solve(Node root, int[] moves) {
        if (root == null) {
            return 0;
        }

        int l = solve(root.left, moves);
        int r = solve(root.right, moves);

        int totalExtraCandies = (l + r + root.data) - 1;

        moves[0] += Math.abs(l) + Math.abs(r);

        return totalExtraCandies;
    }
}
