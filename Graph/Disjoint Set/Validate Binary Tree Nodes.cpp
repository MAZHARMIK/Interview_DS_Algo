/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=FfA-2CrWVJw
    Company Tags                : META
    Leetcode Link               : https://leetcode.com/problems/validate-binary-tree-nodes/description/
*/

/*
    Find another Binary Tree Solution - https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Tree/Validate%20Binary%20Tree%20Nodes.cpp
*/

/************************************************ C++ ************************************************/
//Approach-1 (Using DSU)
class Solution {
public:
    vector<int> parent;
    int components;

    int find(int x) {
        if(parent[x] == x)
            return x;
        
        return parent[x] = find(parent[x]);
    }

    bool Union(int par, int child) {
        int child_ka_parent  = find(child);
    
        //child_ka_parent != child --> Child had already some other parent
        if(child_ka_parent != child)
            return false;
        
        int parent_ka_parent = find(par);
        //parent_ka_parent == child_ka_parent ---> Parallel edge (It means, already they were connected by another edge)
        if (parent_ka_parent == child_ka_parent) {
            return false;
        }
        
        parent[child] = par;
        components--;
        return true;
    }
    
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        components = n;
        parent.resize(n);
        for(int i = 0; i<n; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < n; i++) {
            if (leftChild[i] >= 0 && !Union(i, leftChild[i])) {
                return false;
            }
            if (rightChild[i] >= 0 && !Union(i, rightChild[i])) {
                return false;
            }
        }
        
        return components == 1;
    }
};

//Approach-2 (Using simple BFS or DFS and Binary Tree Property)
//Find it in my "Binary Tree" repo - https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Tree/Validate%20Binary%20Tree%20Nodes.cpp


/************************************************ JAVA ************************************************/
class Solution {
    private int[] parent;
    private int components;

    private int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    private boolean union(int par, int child) {
        int childParent = find(child);
        if (childParent != child) {
            return false;
        }

        int parentParent = find(par);
        if (parentParent == childParent) {
            return false;
        }

        parent[child] = par;
        components--;
        return true;
    }

    public boolean validateBinaryTreeNodes(int n, int[] leftChild, int[] rightChild) {
        components = n;
        parent = new int[n];
        for(int i = 0; i<n; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1 && !union(i, leftChild[i])) {
                return false;
            }
            if (rightChild[i] != -1 && !union(i, rightChild[i])) {
                return false;
            }
        }

        return components == 1;
    }
}


//Approach-2 (Using simple BFS or DFS and Binary Tree Property)
//Find it in my "Binary Tree" repo - https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Tree/Validate%20Binary%20Tree%20Nodes.cpp
