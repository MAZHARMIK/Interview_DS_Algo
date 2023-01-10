/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=WbbYZRr4arw
    Company Tags                : Moonfrog Labs, Flipkart, Morgan Stanley, Accolite, Amazon, Microsoft
*/

//NOTE : This assumes that, we don't have cycle in the given directed graph. You can simply add few things in the same code to check for cycle also
//Or, see this : https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Topological%20Sorting/Course%20Schedule.cpp
class Solution
{
	public:
	
	void DFS(vector<int> adj[], int u, vector<bool>& visited, stack<int>& st) {
	    visited[u] = true;
	    
	    
	    //pehle mere ('u' ke node ke ) bachho ko daalo
	    for(int &v : adj[u]) {
	        if(!visited[v])
	            DFS(adj, v, visited, st);
	    }
	    
	    
	    //ab mujhe daalo stack me
	    st.push(u);
	    
	}
	
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<bool> visited(V, false);
	    stack<int> st;
	    
	    for(int i = 0; i<V; i++) {
	        if(!visited[i])
	            DFS(adj, i, visited, st);
	    }
	    
	    vector<int> result;
	    
	    while(!st.empty()) {
	        result.push_back(st.top());
	        st.pop();
	    }
	    
	    return result;
	}
};
