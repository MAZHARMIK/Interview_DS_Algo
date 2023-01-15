/*
    MY YOUTUBE VIDEO ON THIS Qn : DFS - https://www.youtube.com/watch?v=NeU-C1PTWB8
                                  BFS - https://www.youtube.com/watch?v=cvhXZt66VhA
				  DSU - <soon>
    Company Tags                : Facebook, Samsung, Microsoft, Flipkart
    Leetcode Link               : https://leetcode.com/problems/is-graph-bipartite/
    GfG Link                    : https://practice.geeksforgeeks.org/problems/bipartite-graph/1
*/

//Approach-1 (Graph coloring : DFS)
class Solution {
public:

    bool checkBipartiteDFS(vector<int>adj[], int curr, vector<int>& color, int currColor) {
        color[curr] = currColor; //color kardiya curr node ko
        
        //ab jaate hain adjacent nodes par
        for(int &v : adj[curr]) {
            
            if(color[v] == color[curr])
                return false;
            
            if(color[v] == -1) { //never colored (never visited)
                
                int colorOfV = 1 - currColor;
                
                if(checkBipartiteDFS(adj, v, color, colorOfV) == false)
                    return false;
            }
            
        }
        
        return true;
    }

	bool isBipartite(int V, vector<int>adj[]){
	    
	    vector<int> color(V, -1); //no node colored in the start
	    
	    //red = 1
	    //gree = 0
	    
	    for(int i = 0; i<V; i++) {
	        if(color[i] == -1) {
	            if(checkBipartiteDFS(adj, i, color, 1) == false)
	                return false;
	        }
	    }
	    
	    return true;
	    
	}

};



//Approach-2 (Graph coloring : BFS)
class Solution {
public:

    bool checkBipartiteBFS(vector<int>adj[], int curr, vector<int>& color, int currColor) {
        color[curr] = currColor; //color kardiya curr node ko
        
        queue<int> que;
        que.push(curr);
        
        while(!que.empty()) {
            int u = que.front();
            que.pop();
            
            for(int &v : adj[u]) {
                if(color[v] == color[u]) {
                    return false;
                } else if(color[v] == -1) {
                    color[v] = 1 - color[u];
                    que.push(v);
                }
            }
        }
        
        return true;
    }

	bool isBipartite(int V, vector<int>adj[]){
	    
	    vector<int> color(V, -1); //no node colored in the start
	    
	    //red = 1
	    //gree = 0
	    
	    for(int i = 0; i<V; i++) {
	        if(color[i] == -1) {
	            if(checkBipartiteBFS(adj, i, color, 1) == false)
	                return false;
	        }
	    }
	    
	    return true;
	    
	}

};



//Approach-3 (Union Find)
class Solution {
public:
    int find(vector<int>& parent, int i) {
        if(parent[i] == i)
            return i;
        
        return parent[i] = find(parent, parent[i]);
    }
    
    void Union(vector<int>& parent, int x, int y) {
        int x_set = find(parent, x);
        int y_set = find(parent, y);
        
        if(x_set != y_set)
            parent[x_set] = y_set;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> parent(V);
        
        for(int i = 0; i<V; i++)
            parent[i] = i;
        
        for(int i = 0; i<V; i++) {
            //let i = 0 -> {1, 3}
            for(int &x : graph[i]) {
                int u = i; //one end of edge
                int v = x; //another end of edge
                //u and v should be in different sets
                
                int x_set = find(parent, u);
                int y_set = find(parent, v);
                
                if(x_set == y_set) //they can't be in same set
                    return false;
                
                //{1, 3} in one set
                //Choose any one (1 or 3) as the representative of this set
                Union(parent, x, graph[i][0]);
                //parent of every edge will be graph[i][0]
            }
        }
        
        return true;
    }
};
