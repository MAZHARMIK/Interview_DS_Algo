/*
    MY YOUTUBE VIDEO ON THIS Qn : BFS - https://www.youtube.com/watch?v=W1WhSN9wAw0
    				  DFS - https://www.youtube.com/watch?v=yiR95dxinjs
    Company Tags                : Accolite, Amazon, Flipkart, Microsoft, Moonfrog Labs, OYO Rooms
    Leetcode Link               : https://leetcode.com/problems/course-schedule-ii/
*/

//Approach-1 (Using BFS Topological Sort Concept)
class Solution {
public:
    //Using Kahn's algorithm
    vector<int> topologicalSortCheck(unordered_map<int, vector<int>> &adj, int n, vector<int> &indegree) {
        queue<int> que;
        int count = 0;
        vector<int> result;
        
        for(int i = 0; i<n; i++) {
            if(indegree[i] == 0) {
                result.push_back(i);
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
                    result.push_back(v);
                    count++;
                    que.push(v);
                }
                
            }
            
        }
        
        if(count != n)
            return {};
        
        return result;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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


//Approach-2 (Using DFS)
class Solution {
public:
    bool hasCycle = false;
    void DFS(unordered_map<int, vector<int>> &adj, int u, vector<bool>& visited, stack<int>& st, vector<bool>& inRecursion) {
	    visited[u] = true;
        inRecursion[u] = true;
	    
	    
	    //pehle mere ('u' ke node ke ) bachho ko daalo
	    for(int &v : adj[u]) {
            if(inRecursion[v] == true) {
                hasCycle = true;
                return;
            }
            
	        if(!visited[v])
	            DFS(adj, v, visited, st, inRecursion);
	    }
	    
	    
	    //ab mujhe daalo stack me
	    st.push(u);
        inRecursion[u] = false;
	    
	}
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<bool> visited(numCourses, false);
        vector<bool> inRecursion(numCourses, false);
        hasCycle = false;
        
        stack<int> st;
        
        for(auto &vec : prerequisites) {
            int a = vec[0];
            int b = vec[1];
            
            //b--->a
            adj[b].push_back(a);
        }
        
        for(int i = 0; i<numCourses; i++) {
            if(!visited[i])
                DFS(adj, i, visited, st, inRecursion);
        }
        
        vector<int> result;
        
        if(hasCycle)
            return {};
        
	    while(!st.empty()) {
	        result.push_back(st.top());
	        st.pop();
	    }
	    
	    return result;
    }
};
