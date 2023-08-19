/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=3tgekNXWXsY
    Company Tags                :  Amazon, Cisco, Samsung
    GfG Link                    : https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1
*/

class Solution
{
	public:
    //DSU Code
    vector<int> parent;
    vector<int> rank;
    
    int find (int x) {
        if (x == parent[x]) 
            return x;
    
        return parent[x] = find(parent[x]);
    }
    
    void Union (int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);
    
        if (x_parent == y_parent) 
            return;
    
        if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if(rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    
    int Kruskal(vector<vector<int>> &vec) {

        int sum = 0;
        for(auto &temp : vec) {
            
            int u = temp[0];
            int v = temp[1];
            int wt = temp[2];
            
            int parent_u = find(u);
            int parent_v = find(v);
            
            if(parent_u != parent_v) {
                Union(u, v);
                sum += wt;
            }
            
        }

	//if(edgesConnexted != V-1) 
	    //"It's not a MST" - REMEMBER THIS ALWAYS if anyone asks you how to check if we formed an MST or not

	    
        return sum;
    }
    
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        
        parent.resize(V);
	    rank.resize(V, 0);
        	    
	    for(int i = 0; i<V; i++)
	        parent[i] = i;

        vector<vector<int>> vec;
        
        
        for(int i = 0; i<V; i++) {
            
            for(auto &temp : adj[i]) {
                
                int u = i;
                int v = temp[0];
                int d = temp[1];

                vec.push_back({u, v, d});
                
            }
            
        }
        
        
        auto lambda = [&](auto &v1, auto &v2) {
            return v1[2] < v2[2];
        };
        
        sort(begin(vec), end(vec), lambda);
        
        return Kruskal(vec);
        
    }
};
