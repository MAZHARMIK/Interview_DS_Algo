/*
    Company Tags  : Google (Exactly this question)
    Leetcode Link : https://leetcode.com/problems/redundant-connection/
*/

/////Approach-1 (DFS)
class Solution {
public:
    bool dfs(map<int, vector<int>>& mp, int start, int end, vector<bool>& visited) {
        visited[start] = true;
        if(start == end)
            return true;
        
        for(int &x : mp[start]) {
            if(!visited[x] && dfs(mp, x, end, visited)) {
                return true;
            }
        }
        return false;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        map<int, vector<int>> mp;
        
        int n = edges.size();
        vector<bool> visited(n+1, false);
        
        for(int i = 0; i<n; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            
            fill(begin(visited), end(visited), false);
            
            //if u and v are already in graph, then we check
            //if this current edge connects them again ?
            //If yes, this edge is unwanted (redundant)
            if(mp.find(u) != mp.end() && mp.find(v) != mp.end()
              && dfs(mp, u, v, visited))
                return edges[i];
            
            //Else, add them to graph
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        
        return {};
    }
};

///////Approach-2 (BFS)
class Solution {
public:
    int n;
    bool bfs(map<int, vector<int>>& mp, int start, int end) {
        vector<bool> visited(n+1, false);
        queue<int> que;
        que.push(start);
        
        while(!que.empty()) {
            int curr = que.front();
            que.pop();
            visited[curr] = true;
            if(curr == end)
                return true;
            
            for(int &x : mp[curr]) {
                if(!visited[x]) {
                    que.push(x);
                }
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        map<int, vector<int>> mp;
        n = edges.size();
        
        for(int i = 0; i<n; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            
            //if u and v are already in graph, then we check
            //if this current edge connects them again ?
            //If yes, this edge is unwanted (redundant)
            if(mp.find(u) != mp.end() && mp.find(v) != mp.end() && bfs(mp, u, v))
                return edges[i];
            
            //Else add them to graph
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        
        return {};
    }
};

//Approach-3 (Union Find with Path compression)
class Solution {
public:
    int find(int x, vector<int>& parent) {
        if(parent[x] != x)
            return parent[x] = find(parent[x], parent); //Path compression
        
        return parent[x];
    }
    
    void Union(int u, int v, vector<int>& parent) {
        parent[u] = v;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1);
        for(int i = 1; i<=n; i++)
            parent[i] = i;
        for(int i = 0; i<n; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            
            int set_u = find(u, parent);
            int set_v = find(v, parent);
            
            if(set_u == set_v) {
                //means they were already connected before
                //So, this edge is redundant
                return edges[i];
            }
            
            //Else, bring them in one subset
            Union(set_u, set_v, parent);
        }
        return {};
    }
};

//Approach-4 (Union Find with Rank and Path Compression)
class Solution {
public:
    int find(int x, vector<vector<int>>& parent) {
        if(parent[x][0] != x)
            return parent[x][0] = find(parent[x][0], parent); //Path Compression
        
        return parent[x][0];
    }
    
    void Union(int u, int v, vector<vector<int>>& parent) {
		//Union by Rank
        //put node of lower rank under node of higher rank
        if(parent[u][1] < parent[v][1]) {
            parent[u][0] = v;
        } else if(parent[u][1] > parent[v][1]) {
            parent[v][0] = u;
        } else {
            parent[u][0] = v;
            parent[u][1]++; //increase rank of v
        }
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> parent(n+1, vector<int>(2, 0));
        //parent[i][0] = parent of i
        //parent[i][1] = rank of i
        
        for(int i = 1; i<=n; i++) {
            parent[i][0] = i;
            parent[i][1] = 0; //initially rank = 0
        }
        
        for(int i = 0; i<n; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            
            int set_u = find(u, parent);
            int set_v = find(v, parent);
            
            if(set_u == set_v) {
                //means they were already connected before
                //So, this edge is redundant
                return edges[i];
            }
            
            //Else, bring them in one subset
            Union(set_u, set_v, parent);
        }
        return {};
    }
};
