/*
    MY YOUTUBE VIDEO ON THIS Qn :   BFS - https://www.youtube.com/watch?v=lqjlGGMjSMU
                                    DFS - https://www.youtube.com/watch?v=X1TIkW4C254
    Company Tags                : Apple, Twitter, Meta, Accolite, Amazon, Flipkart, Microsoft, Moonfrog Labs, OYO Rooms
    Leetcode Link               : https://leetcode.com/problems/course-schedule/
    GfG Link                    : https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1?
*/

//Approach-1 (Using BFS Cycle Check - Kahn's Algorithm (Topological Sort)
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


//Approach-2 (Using DFS Cycle Check)
class Solution {
public:
    bool isCycleDFS(unordered_map<int, vector<int>> &adj, int u, vector<bool>& visited, vector<bool>& inRecursion) {
        visited[u] = true;
        inRecursion[u] = true;
        
        
        for(int &v : adj[u]) {
            //if not visited, then we check for cycle in DFS
            if(visited[v] == false && isCycleDFS(adj, v, visited, inRecursion))
                return true;
            else if(inRecursion[v] == true)
                return true;
        }
        
        inRecursion[u] = false;
        return false;
        
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int, vector<int>> adj;
        vector<bool> visited(numCourses, false);
        vector<bool> inRecursion(numCourses, false);
        
        for(auto &vec : prerequisites) {
            int a = vec[0];
            int b = vec[1];
            
            //b ---> a
            adj[b].push_back(a);
        }
        
        for(int i = 0; i<numCourses; i++) {
            if(!visited[i] && isCycleDFS(adj, i, visited, inRecursion))
                return false;
        }
        
        return true;
    }
};
