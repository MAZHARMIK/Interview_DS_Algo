/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=E6DeC0Zpdns
    Company Tags                : Amazon, Visa
    Question Link               : https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1
    

*/


//Kosaraju's Algorithm :     Time  : O(V+E), V = # vertices, E = # edges , Space : O(V)
class Solution
{
	public:
	
	void dfsFill(int u, vector<vector<int>>& adj, vector<bool> &visited, stack<int>& st) {
	    visited[u] = true;
	    
	    for(int &v : adj[u]) {
	        
	        if(!visited[v]) {
	            dfsFill(v, adj, visited, st);
	        }
	        
	    }
	    
	    st.push(u);
	}
	
	void dfsTraverse(int u, vector<vector<int>>& adjReversed, vector<bool> &visited) {
	    visited[u] = true;
	    
	    for(int &v : adjReversed[u]) {
	        
	        if(!visited[v]) {
	            dfsTraverse(v, adjReversed, visited);
	        }
	        
	    }

	}
	
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj) {
        stack<int> st;
        vector<bool> visited(V, false);
        
        for(int i = 0; i<V; i++) {
            if(!visited[i]) {
                dfsFill(i, adj, visited, st);
            }
        }
        
        
        vector<vector<int>> adjReversed(V);
        for(int u = 0; u<V; u++) {
            for(int &v : adj[u]) {
                
                //u->v
                //v->u
                adjReversed[v].push_back(u);
                
            }   
        }
        
        int count = 0;
        
        visited = vector<bool>(V, false);
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            if(!visited[node]) {
                dfsTraverse(node, adjReversed, visited);
                count++;
            }
        }
        
        return count;
        
    }
};
