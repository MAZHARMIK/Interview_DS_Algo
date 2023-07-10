/*
    MY YOUTUBE VIDEO ON THEORY OF MINIMUM SPANNING TREE            - https://youtu.be/xxvY2UX7YPg
    MY YOUTUBE VIDEO ON Prim's Algorithm for MINIMUM SPANNING TREE - https://www.youtube.com/watch?v=V9gXzD7g8fw
    Company Tags                                                   - Amazon, Cisco, Samsung
    Qn Link                                                        - https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1
*/


//Approach-1 : Using Priority_queue
class Solution
{
    typedef pair<int, int> P;
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, 0});
        vector<bool> inMST(V, false);
        int sum = 0;
        
        while(!pq.empty()) {
            
            auto p = pq.top();
            pq.pop();
            
            int wt     = p.first;
            int node   = p.second;
            
            if(inMST[node] == true)
                continue;
            
            inMST[node] = true; //added to mst
            sum += wt;
            
            for(auto &tmp : adj[node]) {
                
                int neighbor      = tmp[0];
                int neighbor_wt   = tmp[1];
                
                if(inMST[neighbor] == false) {
                    pq.push({neighbor_wt, neighbor});
                }
 
            }
        }
        
        return sum;
    }
};


//Approach-2 :Without using Priority_queue
int minKey(int V, vector<bool> inMST, vector<int> key) {
    int minValue  = INT_MAX;
    int min_index;
    for(int v = 0; v<V; v++) {
        if(inMST[v] == false && key[v] < minValue) {
            min_index = v;
            minValue  = key[v];
        }
    }
    return min_index;
}

int spanningTree(int V, int E, vector<vector<int>> &graph) {
    vector<int> key(V, INT_MAX);
    vector<int> parent(V);
    vector<bool> inMST(V, false);
    
    parent[0] = -1;
    key[0] = 0; //so that we start from vertex '0'
    /*
        since we need all V vertices in our MST
        0 will be included in the beginning (key[0] = 0 is minimum) ,
        we will need V-1 more vertices to cover whole graph
    */
    for(int count = 1; count <= V-1; count++) {
        int u = minKey(V, inMST, key);
        inMST[u] = true;
        
        for(int v = 0; v<V; v++) {
            if(graph[u][v] != 0 && inMST[v] == false && graph[u][v] < key[v]) {
                key[v]    = graph[u][v];
                parent[v] = u;
            }
        }
    }
    int sum = 0;
    for(int i = 1; i<V; i++) {
        sum += key[i];
    }
    return sum;
}
