/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : Approach-1 : https://youtu.be/vrbJ7aDuK-A?si=3-8sRu8qdYcJvJf1
                                  Approach-2 : https://www.youtube.com/watch?v=AW-gpXiR5DQ
    Company Tags                : TIKTOK
    Leetcode Link               : https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/description/
*/


/****************************************************** C++ *********************************************/
//Approach-1 (Using Graph and BFS)
//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:

    void makeGraph(TreeNode* root, TreeNode* prev, unordered_map<TreeNode*, vector<TreeNode*>>& adj, 
                    unordered_set<TreeNode*>& st) {

        if(root == NULL) {
            return;
        }

        if(root->left == NULL && root->right == NULL) { //LEAF NODE
            st.insert(root);
        }

        if(prev != NULL) {
            adj[root].push_back(prev);
            adj[prev].push_back(root);
        }

        makeGraph(root->left, root, adj, st);
        makeGraph(root->right, root, adj, st);

    }

    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*, vector<TreeNode*>> adj; //Graph
        unordered_set<TreeNode*> st; //leaf nodes

        makeGraph(root, NULL, adj, st);

        int count = 0; //count of good node pairs

        for(auto &leaf : st) {

            //BFS hit karo and see if you can find another leaf nodes within distance
            queue<TreeNode*> que;
            unordered_set<TreeNode*> visited;
            que.push(leaf);
            visited.insert(leaf);


            for(int level = 0; level <= distance; level++) { //only go till level <= distance
                int size = que.size();
                while(size--) { //level processed
                    TreeNode* curr = que.front();
                    que.pop();

                    if(curr != leaf && st.count(curr)) { 
                        count++;
                    }

                    for(auto &ngbr : adj[curr]) {
                        if(!visited.count(ngbr)) {
                            que.push(ngbr);
                            visited.insert(ngbr);
                        }
                    }
                }
            }
        }
        return count/2;
    }
};



//Approach-2 (Using DFS)
//T.C : O(n*m^2) where m = number of leaf nodes
//S.C : O(n*m) where m = number of leaf nodes
class Solution {
public:

    vector<int> solve(TreeNode* root, int distance, int &goodLeafNodes) {
        if(!root) {
            return {0};
        }

        if(root->left == NULL && root->right == NULL) {
            return {1};
        }

        auto left_d  = solve(root->left, distance, goodLeafNodes);
        auto right_d = solve(root->right, distance, goodLeafNodes);

        for(int &l : left_d) {
            for(int &r : right_d) {
                if((l != 0 && r != 0) && l + r <= distance) {
                    goodLeafNodes++;
                }
            }
        }

        vector<int> curr_d;
        for(int &ld : left_d) {
            if(ld != 0 && ld + 1 <= distance) {
                curr_d.push_back(ld+1);
            }
        }

        for(int &rd : right_d) {
            if(rd != 0 && rd+1 <= distance) {
                curr_d.push_back(rd+1);
            }
        }

        return curr_d;
        
    }

    int countPairs(TreeNode* root, int distance) {
        int goodLeafNodes = 0;
        solve(root, distance, goodLeafNodes);

        return goodLeafNodes;
    }
};


/****************************************************** JAVA *********************************************/
//Approach-1 (Using Graph and BFS)
//T.C : O(n^2)
//S.C : O(n)
class Solution {
    public void makeGraph(TreeNode root, TreeNode prev, Map<TreeNode, List<TreeNode>> adj, Set<TreeNode> leafNodes) {
        if (root == null) {
            return;
        }

        if (root.left == null && root.right == null) { // Leaf node
            leafNodes.add(root);
        }

        if (prev != null) {
            adj.computeIfAbsent(root, k -> new ArrayList<>()).add(prev);
            adj.computeIfAbsent(prev, k -> new ArrayList<>()).add(root);
        }

        makeGraph(root.left, root, adj, leafNodes);
        makeGraph(root.right, root, adj, leafNodes);
    }

    public int countPairs(TreeNode root, int distance) {
        Map<TreeNode, List<TreeNode>> adj = new HashMap<>(); // Graph
        Set<TreeNode> leafNodes = new HashSet<>(); // Leaf nodes

        makeGraph(root, null, adj, leafNodes);

        int count = 0; // Count of good node pairs

        for (TreeNode leaf : leafNodes) {
            // Perform BFS and see if you can find other leaf nodes within distance
            Queue<TreeNode> queue = new LinkedList<>();
            Set<TreeNode> visited = new HashSet<>();
            queue.add(leaf);
            visited.add(leaf);

            for (int level = 0; level <= distance; level++) { // Only go till level <= distance
                int size = queue.size();
                while (size-- > 0) { // Process level
                    TreeNode curr = queue.poll();

                    if (curr != leaf && leafNodes.contains(curr)) {
                        count++;
                    }

                    for (TreeNode neighbor : adj.getOrDefault(curr, new ArrayList<>())) {
                        if (!visited.contains(neighbor)) {
                            queue.add(neighbor);
                            visited.add(neighbor);
                        }
                    }
                }
            }
        }
        return count / 2;
    }
}



//Approach-2 (Using DFS)
//T.C : O(n*m^2) where m = number of leaf nodes
//S.C : O(n*m) where m = number of leaf nodes
public class Solution {

    public List<Integer> solve(TreeNode root, int distance, int[] goodLeafNodes) {
        if (root == null) {
            List<Integer> emptyList = new ArrayList<>();
            emptyList.add(0);
            return emptyList;
        }

        if (root.left == null && root.right == null) {
            List<Integer> leafList = new ArrayList<>();
            leafList.add(1);
            return leafList;
        }

        List<Integer> leftDistances = solve(root.left, distance, goodLeafNodes);
        List<Integer> rightDistances = solve(root.right, distance, goodLeafNodes);

        for (int l : leftDistances) {
            for (int r : rightDistances) {
                if (l != 0 && r != 0 && l + r <= distance) {
                    goodLeafNodes[0]++;
                }
            }
        }

        List<Integer> currentDistances = new ArrayList<>();
        for (int ld : leftDistances) {
            if (ld != 0 && ld + 1 <= distance) {
                currentDistances.add(ld + 1);
            }
        }

        for (int rd : rightDistances) {
            if (rd != 0 && rd + 1 <= distance) {
                currentDistances.add(rd + 1);
            }
        }

        return currentDistances;
    }

    public int countPairs(TreeNode root, int distance) {
        int[] goodLeafNodes = new int[1];
        solve(root, distance, goodLeafNodes);
        return goodLeafNodes[0];
    }
}
