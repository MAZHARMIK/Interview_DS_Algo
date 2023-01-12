/*
    MY YOUTUBE VIDEO ON THIS Qn : <soon>
    Company Tags                : <soon>
    Leetcode Link               : https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/
*/

//Approach-1 (DFS - adding counts from children at every node)
class Solution {
public:
    void DFS(unordered_map<int, vector<int>> &adj, int u, int parent, vector<int>& result, string &labels, vector<int>& count) {
        
        char mylabel = labels[u];
        
        int count_before_exploring_my_subtree = count[mylabel-'a'];
        
        
        //explore my subtree children
        count[mylabel-'a']++;
        for(int &v : adj[u]) {
            if(v == parent)
                continue;
            
            DFS(adj, v, u, result, labels, count);
        }
        
        int count_after_exploring_my_subtree = count[mylabel-'a'];
        result[u] = count_after_exploring_my_subtree - count_before_exploring_my_subtree;
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        unordered_map<int, vector<int>> adj;
        
        for(auto &vec : edges) {
            int u = vec[0];
            int v = vec[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> result(n, 0);
        vector<int> count(26, 0);
        
        DFS(adj, 0, -1, result, labels, count);
        
        return result;
        
    }
};


//Approach-2 (DFS - No need to add count at everynode)
class Solution {
public:
    void DFS(unordered_map<int, vector<int>> &adj, int u, int parent, vector<int>& result, string &labels, vector<int>& count) {
        
        char mylabel = labels[u];
        
        int count_before_exploring_my_subtree = count[mylabel-'a'];
        
        
        //explore my subtree children
        count[mylabel-'a']++;
        for(int &v : adj[u]) {
            if(v == parent)
                continue;
            
            DFS(adj, v, u, result, labels, count);
        }
        
        int count_after_exploring_my_subtree = count[mylabel-'a'];
        result[u] = count_after_exploring_my_subtree - count_before_exploring_my_subtree;
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        unordered_map<int, vector<int>> adj;
        
        for(auto &vec : edges) {
            int u = vec[0];
            int v = vec[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> result(n, 0);
        vector<int> count(26, 0);
        
        DFS(adj, 0, -1, result, labels, count);
        
        return result;
        
    }
};
