/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Rt2prDOV2hU
    Company Tags                : Uber
    Leetcode Link               : https://leetcode.com/problems/create-binary-tree-from-descriptions/description
*/


/******************************************************** C++ ********************************************************/
//Simple Approach using map and set
//T.C : O(n), where n is the size of descriptions
//S.C : O(n), size of map and set
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> childSet; //they can never be root of the tree


        for(vector<int>& vec : descriptions) { //O(n)
            int parent = vec[0];
            int child  = vec[1];
            int isLeft = vec[2];

            if(mp.find(parent) == mp.end()) {
                mp[parent] = new TreeNode(parent);
            }

            if(mp.find(child) == mp.end()) {
                mp[child] = new TreeNode(child);
            }

            if(isLeft == 1) { //left child  
                mp[parent]->left = mp[child];
            } else {
                mp[parent]->right = mp[child];
            }

            childSet.insert(child);
        }


        //Find the root
        for(vector<int>& vec : descriptions) { //O(n)
            int parent = vec[0];
            if(childSet.find(parent) == childSet.end()) { //if(!mp.count(parent))
                return mp[parent];
            }
        }

        return NULL; //we will never reach here
    }
};


/******************************************************** JAVA ********************************************************/
//Simple Approach using map and set
//T.C : O(n), where n is the size of descriptions
//S.C : O(n), size of map and set
class Solution {
    public TreeNode createBinaryTree(int[][] descriptions) {
        Map<Integer, TreeNode> mp = new HashMap<>();
        Set<Integer> childSet = new HashSet<>();

        // Create nodes and set up parent-child relationships
        for (int[] description : descriptions) {
            int parent = description[0];
            int child = description[1];
            boolean isLeft = description[2] == 1;

            mp.putIfAbsent(parent, new TreeNode(parent));
            mp.putIfAbsent(child, new TreeNode(child));

            if (isLeft) {
                mp.get(parent).left = mp.get(child);
            } else {
                mp.get(parent).right = mp.get(child);
            }

            childSet.add(child);
        }

        // Find the root node (which is not any child)
        for (int[] description : descriptions) {
            int parent = description[0];
            if (!childSet.contains(parent)) {
                return mp.get(parent);
            }
        }

        return null;
    }
}
