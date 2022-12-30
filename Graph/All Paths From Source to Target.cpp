/*
  MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=9qWMS8GLvdI
  Company Tags                : Amazon, Microsoft
  Leetcode Qn Link            : https://leetcode.com/problems/all-paths-from-source-to-target/
*/


//Approach - 1 (More like a Graph DFS)
class Solution {
public:
    void DFS(vector<vector<int>>& adj, int start, vector<int>& temp,  vector<vector<int>>& result) {
        
        temp.push_back(start);
        if(start == adj.size()-1) {
            result.push_back(temp);
        } else {
            for(auto x:adj[start]) {
                DFS(adj, x, temp, result);
            }
        }
        temp.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& adj) {        
        vector<vector<int>> result;
        for(int x : adj[0]) {
            vector<int> temp;
            temp.push_back(0);
            DFS(adj, x, temp, result);
        }
        return result;
    }
};


//Approach-2 (Similar to approach-1 but a little simple)
class Solution {
public:
    int target;
    void dfs(vector<vector<int>>& adj, int start, vector<int>& temp, vector<vector<int>>& result ) {
        if(start == target) {
            result.push_back(temp);
            return;
        }
        
        for(int &x : adj[start]) {
            temp.push_back(x);
            dfs(adj, x, temp, result);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> temp;
        target = graph.size()-1;
        temp.push_back(0);
        dfs(graph, 0, temp, result);
        
        return result;
    }
};


//Approach-3 (Using BFS)
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        
        int source = 0;
        int target = n-1;
        
        vector<vector<int>> result;
        vector<int> temp;
        
        queue<vector<int>> que;
        temp.push_back(0);
        que.push(temp);
        
        while(!que.empty()) {
            vector<int> currPath = que.front();
            que.pop();
            
            int lastNode = currPath.back();
            
            if(lastNode == target) {
                result.push_back(currPath);
            } else {
                for(int &v : graph[lastNode]) {
                    vector<int> path = currPath;
                    path.push_back(v);
                    que.push(path);
                }
            }
        }
      
        
        return result;
    }
};
