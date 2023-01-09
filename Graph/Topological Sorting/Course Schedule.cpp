/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=lqjlGGMjSMU
    Company Tags                : Apple, Twitter, Meta, Accolite, Amazon, Flipkart, Microsoft, Moonfrog Labs, OYO Rooms
    Leetcode Link               : https://leetcode.com/problems/course-schedule/
    GfG Link                    : https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1?
*/

class Solution {
public:
    
    bool topologicalSortCheck(unordered_map<int, vector<int>> &adj, int n, vector<int> &indegree) {
        queue<int> que;
        
        int count = 0;
        
        for(int i = 0; i<n; i++) {
            if(indegree[i] == 0) {
                count++;
                que.push(i);
            }
        }
        
        
        while(!que.empty()) {
            int u = que.front();
            que.pop();
            
            for(int &v : adj[u]) {
                
                indegree[v]--;
                
                if(indegree[v] == 0) {
                    count++;
                    que.push(v);
                }
                
            }
            
        }
        
        if(count == n) //I was able to visit all nodes (course)
            return true; //i.e. I was able to finish all courses
        
        return false; //means there was a cycle and I couldn't complete all courses
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int, vector<int>> adj;
        
        vector<int> indegree(numCourses, 0); //kahn's algo
        
        for(auto &vec : prerequisites) {
            int a = vec[0];
            int b = vec[1];
            
            //b ---> a
            adj[b].push_back(a);
            
            //arrow ja raha hai 'a' me
            indegree[a]++;
        }
        
        
        //if cycle is present, not possible
        
        return topologicalSortCheck(adj, numCourses, indegree);
    }
};
