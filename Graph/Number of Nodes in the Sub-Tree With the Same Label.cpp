/*
    MY YOUTUBE VIDEO ON THIS Qn : Approach-1 : https://www.youtube.com/watch?v=4seuiuW8c0o
                                  Approach-2 : https://www.youtube.com/watch?v=yZ6IM8Q-0Ac 
    Company Tags                : <soon>
    Leetcode Link               : https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/
*/

//Approach-1 (DFS - adding counts from children at every node)
class Solution {
public:
    vector<int> DFS(unordered_map<int, vector<int>> &adj, int u, int parent, vector<int>& result, string &labels) {
        vector<int> my_count(26, 0);
        char mylabel = labels[u];
        
        my_count[mylabel - 'a'] = 1;
        
        for(int &v : adj[u]) {
            if(v == parent)
                continue;
        
            vector<int> child_count(26, 0);
            child_count = DFS(adj, v, u, result, labels);

            for(int i = 0; i<26; i++) {
                my_count[i] += child_count[i];
            }
        }
        
        result[u] = my_count[mylabel - 'a'];
        
        return my_count;
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
        
        DFS(adj, 0, -1, result, labels);
        
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
