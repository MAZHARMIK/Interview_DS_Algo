/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=kOt2VNsU0FE
      Company Tags                : MICROSOFT
      Leetcode Link               : https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/
*/


//Approach-1 : Using DFS - (Remaining Nodes concept)
class Solution {
public:
    
    void dfs(int u, unordered_map<int, vector<int>> &adj, vector<bool>& visited, long long &sizeOfComponent) {
        visited[u] = true;
        sizeOfComponent++;
        
        for(int &v : adj[u]) {
            
            if(!visited[v]) {
                dfs(v, adj, visited, sizeOfComponent);
            }
            
        }
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        
        for(auto &vec : edges) {
            
            int u = vec[0];
            int v = vec[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> visited(n, false);
        long long remainingNodes = n;
        
        long long result = 0;
        
        for(int i = 0; i<n; i++) {
            if(!visited[i]) {
                
                long long sizeOfComponent = 0;
                
                dfs(i, adj, visited, sizeOfComponent);
                
                result += (sizeOfComponent) * (remainingNodes-sizeOfComponent);
                
                remainingNodes -= sizeOfComponent;
                
            }
        }
        
        return result;
    }
};


//Approach-2 : Using DFS (Calculating duplicates and divide by 2)
class Solution {
public:
    
    void dfs(int u, unordered_map<int, vector<int>> &adj, vector<bool>& visited, long long &sizeOfComponent) {
        visited[u] = true;
        sizeOfComponent++;
        
        for(int &v : adj[u]) {
            
            if(!visited[v]) {
                dfs(v, adj, visited, sizeOfComponent);
            }
            
        }
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        
        for(auto &vec : edges) {
            
            int u = vec[0];
            int v = vec[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> visited(n, false);
        
        long long result = 0;
        
        for(int i = 0; i<n; i++) {
            if(!visited[i]) {
                
                long long sizeOfComponent = 0;
                
                dfs(i, adj, visited, sizeOfComponent);
                
                result += (sizeOfComponent) * (n-sizeOfComponent);
                
            }
        }
        
        return result/2;
    }
};

//Approach-3 : Using BFS 
class Solution {
public:
    
    void bfs(int u, unordered_map<int, vector<int>> &adj, vector<bool>& visited, long long &Size) {
        
        queue<int> que;
        que.push(u);
        
        visited[u] = true;
        Size++;
        
        while(!que.empty()) {
            
            int x = que.front();
            que.pop();
            
            for(int &v : adj[x]) {
                
                if(!visited[v]) {
                    visited[v] = true;
                    que.push(v);
                    Size++;
                }
                
            }
            
        }
        
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        
        unordered_map<int, vector<int>> adj;
        
        for(auto &vec : edges) {
            
            int u = vec[0];
            int v = vec[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
            
        }
        
        vector<bool> visited(n, false);
        
        long long remainingNodes = n;
        
        long long result = 0;
        
        for(int i = 0; i<n; i++) {
            
            if(!visited[i]) {
                
                long long Size = 0;
                
                bfs(i, adj, visited, Size);
                
                result += (Size) * (remainingNodes - Size);
                
                remainingNodes -= Size;
            }
            
        }
        
        return result;
        
    }
};


//Approach - 4 : DSU (In mo DS repo - Link below)
//https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Disjoint%20Set/Count%20Unreachable%20Pairs%20of%20Nodes%20in%20an%20Undirected%20Graph.cpp
