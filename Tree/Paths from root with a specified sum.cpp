/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Nrdm2a5gsr8
    Company Tags                : Microsoft
    GfG Link                    : https://www.geeksforgeeks.org/problems/paths-from-root-with-a-specified-sum/1
*/

/********************************************************************** C++ **********************************************************************/
//T.C : O(n)
//S.C : O(height of tree)
class Solution
{
    public:
    vector<vector<int>> result;
    
    void solve(Node* root, int sum, vector<int>& temp, int curr_sum) {
        if(root == NULL) {
            return;
        }
        
        curr_sum += root->key;
        temp.push_back(root->key);
        
        if(sum == curr_sum) {
            result.push_back(temp);
        }
        
        
        solve(root->left, sum, temp, curr_sum);
        solve(root->right, sum, temp, curr_sum);
        temp.pop_back();
    }
    
    vector<vector<int>> printPaths(Node *root, int sum) {
        vector<int> temp;
        solve(root, sum, temp, 0);
        
        return result;
        
    }
};


/********************************************************************** JAVA **********************************************************************/
//T.C : O(n)
//S.C : O(height of tree)
class Solution
{
    private static ArrayList<ArrayList<Integer>> result = new ArrayList<>();
    private static void solve(Node root, int sum, ArrayList<Integer> temp, int currSum) {
        if (root == null) {
            return;
        }

        currSum += root.data;
        temp.add(root.data);

        if (sum == currSum) {
            result.add(new ArrayList<>(temp));
        }

        solve(root.left, sum, temp, currSum);
        solve(root.right, sum, temp, currSum);
        temp.remove(temp.size() - 1);
    }
    
    public static ArrayList<ArrayList<Integer>> printPaths(Node root, int sum) {
        ArrayList<Integer> temp = new ArrayList<>();
        solve(root, sum, temp, 0);

        return result;
    }
}
