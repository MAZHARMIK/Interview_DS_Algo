/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=SXU--MPoUe8
      Company Tags                : AMAZON
      Leetcode Link               : https://leetcode.com/problems/unique-binary-search-trees-ii/

      SIMILAR Qn : Leetcode Link -> https://leetcode.com/problems/all-possible-full-binary-trees/
                   YouTube Link  -> https://www.youtube.com/watch?v=lNEI25uT3WM

      Scroll Down to see Java code
    
*/

***********************************    C++    ***********************************
//Approach-1 Recursion - ACCEPTED
class Solution {
public:

    vector<TreeNode*> solve(int start, int end) {
        
        if(start > end) {
            return {NULL};
        }
        
        if(start == end) {
            TreeNode* root = new TreeNode(start);
            return {root};
        }
        
        
        vector<TreeNode*> result;
        for(int i = start; i <= end; i++) {
            
            vector<TreeNode*> leftList  = solve(start, i-1);
            vector<TreeNode*> rightList = solve(i+1, end);
            
            for(TreeNode* leftRoot : leftList) {
                
                for(TreeNode* rightRoot : rightList) {
                    
                    TreeNode* root = new TreeNode(i);
                    root->left  = leftRoot;
                    root->right = rightRoot;
                    
                    result.push_back(root);
                    
                }
                
            }
            
        }
        
        return result;
        
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return solve(1, n);
    }
};


//Approach-2 Recursion + Memo - ACCEPTED
class Solution {
public:
    
    map<pair<int, int>, vector<TreeNode*>> mp;
    
    vector<TreeNode*> solve(int start, int end) {
        
        if(start > end) {
            return {NULL};
        }
        
        if(start == end) {
            TreeNode* root = new TreeNode(start);
            return {root};
        }
        
        if(mp.find({start, end}) != mp.end())
            return mp[{start, end}];
        
        vector<TreeNode*> result;
        for(int i = start; i <= end; i++) {
            
            vector<TreeNode*> leftList  = solve(start, i-1);
            vector<TreeNode*> rightList = solve(i+1, end);
            
            for(TreeNode* leftRoot : leftList) {
                
                for(TreeNode* rightRoot : rightList) {
                    
                    TreeNode* root = new TreeNode(i);
                    root->left  = leftRoot;
                    root->right = rightRoot;
                    
                    result.push_back(root);
                    
                }
                
            }
            
        }
        
        return mp[{start, end}] = result;
        
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return solve(1, n);
    }
};


//Approach-3 (Bottom Up) - sooon





**********************************************************************    JAVA    **********************************************************************
//Approach-1 (Recursion + Memo - Accepted)
class Solution {
    Map<Pair<Integer, Integer>, List<TreeNode>> memo;
    public List<TreeNode> allPossibleBST(int start, int end) {
        List<TreeNode> res = new ArrayList<>();
        if (start > end) {
            res.add(null);
            return res;
        }
        if (memo.containsKey(new Pair<>(start, end))) {
            return memo.get(new Pair<>(start, end));
        }
        
        // Iterate through all values from start to end to construct left and right subtree recursively.
        
        for (int i = start; i <= end; ++i) {
            List<TreeNode> leftSubTrees = allPossibleBST(start, i - 1);
            List<TreeNode> rightSubTrees = allPossibleBST(i + 1, end);

            // Loop through all left and right subtrees and connect them to ith root.
            for (TreeNode left: leftSubTrees) {
                for (TreeNode right: rightSubTrees) {
                    TreeNode root = new TreeNode(i, left, right);
                    res.add(root);
                }
            }
        }
        memo.put(new Pair<>(start, end), res);
        return res;
    }

    public List<TreeNode> generateTrees(int n) {
        memo = new HashMap<>();
        return allPossibleBST(1, n);
    }
}
