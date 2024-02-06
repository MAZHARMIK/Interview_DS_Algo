/*                                Scroll down to see JAVA code also                                            */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Lzvqu8WPNh8
    Company Tags                : Flipkart, Microsoft
    GfG Link                    : https://www.geeksforgeeks.org/problems/node-at-distance/1
*/

/*************************************************************************** C++ ***************************************************************************/
//Approach-1 (Storing all root-leaf paths)
//T.C : O(n)
//S.C : O(n*h) - where "n" is the number of nodes in the tree, and "h" is the height of the tree. 
//This is because there can be at most n/2 leaf nodes in a binary tree, and each path from root to leaf may have a length of up to h.
class Solution {
    public:
    vector<vector<Node*>> paths;
    void storeRootToLeaf(Node* root, vector<Node*>& temp) {
        if(!root) {
            return;
        }
        
        temp.push_back(root);
        if(!root->left && !root->right) {
            paths.push_back(temp);
        }
        storeRootToLeaf(root->left, temp);
        storeRootToLeaf(root->right, temp);
        temp.pop_back();
    }
    
    //Function to return count of nodes at a given distance from leaf nodes.
    int printKDistantfromLeaf(Node* root, int k) {
        paths.clear();
        vector<Node*> temp;
    	storeRootToLeaf(root, temp);
    	unordered_set<Node*> st;
    	
    	for(vector<Node*> &vec : paths) {
    	    int n = vec.size();
    	    if(n - k > 0) {
    	        st.insert(vec[n-k-1]);
    	    }
    	}
    	
    	return st.size();
    }
};


//Approach-2 (Without storing all root-leaf paths)
//T.C : O(n)
//S.C : O(h)
class Solution {
    public:
    
    void solve(Node* root, int level, unordered_set<Node*>& result, vector<Node*>& path, int& k) {
        if(!root) {
            return;
        }
        
        path.push_back(root);
        if(!root->left && !root->right) {
            if(level - k >= 0) {
                result.insert(path[level-k]);
            }
        }
        
        solve(root->left, level+1, result, path, k);
        solve(root->right, level+1, result, path, k);
        path.pop_back();
    }
    
    //Function to return count of nodes at a given distance from leaf nodes.
    int printKDistantfromLeaf(Node* root, int k) {
        vector<Node*> path;
        unordered_set<Node*> result;
    	
    	solve(root, 0, result, path, k);

    	return result.size();
    }
};



/*************************************************************************** JAVA ***************************************************************************/
//Approach-1 (Storing all root-leaf paths)
//T.C : O(n)
//S.C : O(n*h) - where "n" is the number of nodes in the tree, and "h" is the height of the tree. 
//This is because there can be at most n/2 leaf nodes in a binary tree, and each path from root to leaf may have a length of up to h.
class Solution {
    List<List<Node>> paths = new ArrayList<>();

    // Function to store root-to-leaf paths in the paths list.
    void storeRootToLeaf(Node root, List<Node> temp) {
        if (root == null) {
            return;
        }

        temp.add(root);
        if (root.left == null && root.right == null) {
            paths.add(new ArrayList<>(temp));
        }
        storeRootToLeaf(root.left, temp);
        storeRootToLeaf(root.right, temp);
        temp.remove(temp.size() - 1);
    }

    // Function to return count of nodes at a given distance from leaf nodes.
    int printKDistantfromLeaf(Node root, int k) {
        paths.clear();
        List<Node> temp = new ArrayList<>();
        storeRootToLeaf(root, temp);
        Set<Node> set = new HashSet<>();

        for (List<Node> nodeList : paths) {
            int n = nodeList.size();
            if (n - k > 0) {
                set.add(nodeList.get(n - k - 1));
            }
        }

        return set.size();
    }
}



//Approach-2 (Without storing all root-leaf paths)
//T.C : O(n)
//S.C : O(h)
class Solution {
    public int printKDistantfromLeaf(Node root, int k) {
        List<Node> path = new ArrayList<>();
        Set<Node> result = new HashSet<>();
        solve(root, 0, result, path, k);

        return result.size();
    }

    private void solve(Node root, int level, Set<Node> result, List<Node> path, int k) {
        if (root == null) {
            return;
        }

        path.add(root);
        if (root.left == null && root.right == null) {
            if (level - k >= 0) {
                result.add(path.get(level - k));
            }
        }

        solve(root.left, level + 1, result, path, k);
        solve(root.right, level + 1, result, path, k);
        path.remove(path.size() - 1);
    }
}
