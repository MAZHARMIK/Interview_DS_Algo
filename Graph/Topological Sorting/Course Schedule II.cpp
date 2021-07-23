/*
    Company Tags  : Accolite, Amazon, Flipkart, Microsoft, Moonfrog Labs, OYO Rooms
    Leetcode Link : https://leetcode.com/problems/course-schedule-ii/
*/

class Solution {
public:
    //using Kahn's Algorithm (TopoSort using BFS)
    vector<int> topologicalSortBFS(unordered_map<int, vector<int>>& adj, int V, vector<int>& indegree) {
        vector<bool> visited(V, 0);
        queue<int> que;
        for(int i = 0; i<V; i++) {
            if(indegree[i] == 0) {
                que.push(i);
                visited[i] = true;
            }
        }
        
        int count = 0;
        vector<int> result;
        while(!que.empty()) {
            int curr = que.front();
            que.pop();
            count++;
            
            for(auto x:adj[curr]) {
                if(visited[x] == false)
                    indegree[x]--;
                if(indegree[x] == 0) {
                    que.push(x);
                    visited[x] = true;
                }
            }
            
            result.push_back(curr);
        }
        if(count != V)
            return {};
        
        return result;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);
        for(auto vec:prerequisites) {
            int x = vec[0];
            int y = vec[1];
            adj[y].push_back(x);
            indegree[x]++;
        }
        
        return topologicalSortBFS(adj, numCourses, indegree);
    }
};
