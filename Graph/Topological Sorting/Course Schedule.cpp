/*
    Company Tags  : Accolite, Amazon, Flipkart, Microsoft, Moonfrog Labs, OYO Rooms
    Leetcode Link : https://leetcode.com/problems/course-schedule/
*/

class Solution {
public:
    //we will use Kahn's Algorithm "Topological Sort using BFS"
    bool topoLogicalSort(map<int, vector<int>>& adj, int V, vector<int>& indegree) {
        vector<bool> visited(V, false);
        queue <int> que;
        
        for(int i = 0; i<V; i++) {
            if(indegree[i] == 0) {
                que.push(i);
                visited[i] = true;
            }
        }
        
        int count = 0;
        while(!que.empty()) {
            int curr = que.front();
            que.pop();
            count++;
            for(auto x: adj[curr]) {
                if(visited[x] == false) {
                    indegree[x]--;
                }
                if(indegree[x] == 0) {
                    que.push(x);
                    visited[x] = true;
                }
            }
        }
        
        return (count == V);
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);
        for(auto preq:prerequisites) { 
            int x = preq[0];
            int y = preq[1];
            adj[y].push_back(x);
            indegree[x]++;
        }
        
        //if cycle exists, then Not possible else possible
        return topoLogicalSort(adj, numCourses, indegree);
    }
};
