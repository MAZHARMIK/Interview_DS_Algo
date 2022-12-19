/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=mbR1XSXidEE
    Company Tags                : Microsoft, Adobe, Amazon, Morgan Stanley, Samsung
    Leetcode Link               : https://leetcode.com/problems/find-if-path-exists-in-graph/
*/

//NOTE : Soon, I will upload the Union Find approach for this Qn as well

//Using DFS : O(m+n)
class Solution {
public:
    
    bool check(unordered_map<int, vector<int>>& mp, int node, int dest, vector<bool>& visited) {
        if(node == dest)
            return true;
        
        if(visited[node])
            return false;
        
        visited[node] = true;
        for(auto &it : mp[node]) {
            if(check(mp, it, dest, visited))
                return true;
        }
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        if(source == destination)
            return true;
        
        unordered_map<int, vector<int>> mp;
        
        for(vector<int> &vec : edges) {
            int u = vec[0];
            int v = vec[1];
            
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        
        vector<bool> visited(n, false);
        return check(mp, source, destination, visited);
    }
};


//Using BFS : O(m+n)
class Solution {
public:    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> mp;
        
        for(vector<int> &vec : edges) {
            int u = vec[0];
            int v = vec[1];
            
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        
        vector<bool> visited(n, false);
        
        queue<int> que;
        que.push(source);
        visited[source] = true;
        
        while(!que.empty()) {
            int node = que.front();
            que.pop();
            if(node == destination)
                return true;

            for(auto &it : mp[node]) {
                if(!visited[it]) {
                    visited[it] = true;
                    que.push(it);
                }
            }
        }
        
        return false;
    }
};
