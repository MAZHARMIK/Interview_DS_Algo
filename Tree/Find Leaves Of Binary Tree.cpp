/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=g-gaAYSyt3Q
    Company Tags                : Amazon, Google Onsite(2022)
    Leetcode Premium Qn         : https://leetcode.com/problems/find-leaves-of-binary-tree/ 
*/

//Explanation:
/*
    If you notice in example : {1, 2, 3, 4, 5}
    If we see:
    height of node 4 is 1 from bottom
    height of node 5 is 1 from bottom
    height of node 3 is 1 from bottom

    height of node 2 is 2 from bottom

    height of node 1 is 3 from bottom

    if we store them in a map correspoding to height
    we will have : map<height, {nodes}>
    [1] -> {4, 5, 3}
    [2] -> {2}
    [3] -> {1}

    That's our answer :-)
*/

/****************************************************** C++ ******************************************************/
class Solution {
public:
    map<int, vector<int>> mp; //ordered map will give the result in desired order
    int collectNodeWithHeight(TreeNode* root) {
        if(!root)
            return 0;
        
        int height = 1 + max(collectNodeWithHeight(root->left), 
                             collectNodeWithHeight(root->right)
                             );
        
        mp[height].push_back(root->val);

        return height;
    }
    vector<vector<int>> findLeaves(TreeNode * root) {       
        mp.clear();
        collectNodeWithHeight(root);

        vector<vector<int>> result;
        for(auto &it : mp) {
            result.push_back(it.second);
        }

        return result;
    }
};


/****************************************************** JAVA ******************************************************/
public class Solution {
    private Map<Integer, List<Integer>> mp = new HashMap<>();
    private int collectNodeWithHeight(TreeNode root) {
        if (root == null) {
            return 0;
        }

        int height = 1 + Math.max(collectNodeWithHeight(root.left), collectNodeWithHeight(root.right));
        mp.computeIfAbsent(height, k -> new ArrayList<>()).add(root.val);

        return height;
    }

    public List<List<Integer>> findLeaves(TreeNode root) {
        mp.clear();
        collectNodeWithHeight(root);

        List<List<Integer>> result = new ArrayList<>();
        for (List<Integer> nodes : mp.values()) {
            result.add(nodes);
        }

        return result;
    }
}
