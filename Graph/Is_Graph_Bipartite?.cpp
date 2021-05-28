/*
    Company Tags  : Facebook, Samsung
    Leetcode Link : https://leetcode.com/problems/is-graph-bipartite/
*/

//Approach-1 (Graph coloring : DFS)
class Solution {
public:
    bool validColor_DFS(vector<vector<int>>& graph, vector<int>& color, int x, int c) {
        if(color[x] != 0) {
            //if already colored, then it better be colored with c
            return color[x] == c;
        }
        
        color[x] = c;
        //Now, I will try to color the neighbors with -c
        for(int &node : graph[x]) {
            if(!validColor_DFS(graph, color, node, -c))
                return false;
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, 0);
        /*
            0  -> not colored (not visited)
            1  -> Blue colored
            -1 -> Red colored
        */
        
        for(int i = 0; i<V; i++) {
            if(color[i] == 0 && !validColor_DFS(graph, color, i, 1))
                return false;
        }
        
        return true;
    }
};

//Approach-2 (Graph coloring : BFS)
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, 0);
        /*
            0  -> not colored (not visited)
            1  -> Blue colored
            -1 -> Red colored
        */
        
        //Do a DFS and keep coloring.
        //During DFS keep track if we are able to color or not
        for(int i = 0; i<V; i++) {
            
            if(color[i] != 0)
                continue;
            
            //Do a BFS on ith node
            queue<int> que;
            que.push(i);
            color[i] = 1;
            //Now, I will try to color adjacent nodes with -1 (i.e. -color[i])
            
            while(!que.empty()) {
                int curr = que.front();
                que.pop();
                
                for(int &node : graph[curr]) {
                    //if it's already colored, it better be colored with opposite color of parent
                    if(color[node] == color[curr])
                        return false;
                    
                    else if(color[node] == 0) {
                        color[node] = -color[curr];
                        que.push(node);
                    }
                }
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
