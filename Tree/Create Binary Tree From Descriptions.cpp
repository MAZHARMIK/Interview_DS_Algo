/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/create-binary-tree-from-descriptions/description
*/


/******************************************************** C++ ********************************************************/
//Simple Approach using map and set
//T.C : O(n), where n is the size of descriptions
//S.C : O(n), size of map and set
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes;
        unordered_set<int> childSet;

        // Create nodes and set up parent-child relationships
        for (const auto& description : descriptions) {
            int parent = description[0];
            int child = description[1];
            bool isLeft = description[2] == 1;

            if (nodes.find(parent) == nodes.end()) {
                nodes[parent] = new TreeNode(parent);
            }
            if (nodes.find(child) == nodes.end()) {
                nodes[child] = new TreeNode(child);
            }

            if (isLeft) {
                nodes[parent]->left = nodes[child];
            } else {
                nodes[parent]->right = nodes[child];
            }

            childSet.insert(child);
        }

        // Find the root node (which is not any child)
        for (const auto& description : descriptions) {
            int parent = description[0];
            if (childSet.find(parent) == childSet.end()) {
                return nodes[parent];
            }
        }

        return nullptr;
    }
};



/******************************************************** JAVA ********************************************************/
//Simple Approach using map and set
//T.C : O(n), where n is the size of descriptions
//S.C : O(n), size of map and set
class Solution {
    public TreeNode createBinaryTree(int[][] descriptions) {
        Map<Integer, TreeNode> nodes = new HashMap<>();
        Set<Integer> childSet = new HashSet<>();

        // Create nodes and set up parent-child relationships
        for (int[] description : descriptions) {
            int parent = description[0];
            int child = description[1];
            boolean isLeft = description[2] == 1;

            nodes.putIfAbsent(parent, new TreeNode(parent));
            nodes.putIfAbsent(child, new TreeNode(child));

            if (isLeft) {
                nodes.get(parent).left = nodes.get(child);
            } else {
                nodes.get(parent).right = nodes.get(child);
            }

            childSet.add(child);
        }

        // Find the root node (which is not any child)
        for (int[] description : descriptions) {
            int parent = description[0];
            if (!childSet.contains(parent)) {
                return nodes.get(parent);
            }
        }

        return null;
    }
}
