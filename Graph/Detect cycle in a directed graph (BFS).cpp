/*
  MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=74suJP4bwf0
  Company Tags                : Flipkart, Amazon, Microsoft, Samsung, MakeMyTrip, Oracle, Adobe, BankBazaar
  Gfg Link                    : https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
*/


class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int N, vector<int> adj[]) {
        queue<int> que;
	    vector<int> indegree(N, 0);
	    int count = 0;
	    //1
	    for(int u = 0; u<N; u++) {
	        for(int &v : adj[u]) {
	            indegree[v]++;
	        }
	    }
	    
	    //2. Fill que, indegree with 0
	    for(int i = 0; i<N; i++) {
	        if(indegree[i] == 0) {
	            que.push(i);
	            count++;
	        }
	    }
	    
	    //3. Simple BFS
	    while(!que.empty()) {
	        int u = que.front();
	        que.pop();
	        
	        for(int &v : adj[u]) {
	            indegree[v]--;
	            
	            if(indegree[v] == 0) {
	                que.push(v);
	                count++;
	            }
	            
	        }
	    }
	    
	    return count != N;
    }
};
