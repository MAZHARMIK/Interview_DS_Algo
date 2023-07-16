/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=hsr7KolYDH0
    Company Tags                : META
    Leetcode Link               : https://leetcode.com/problems/min-cost-to-connect-all-points/
*/

//Approach-1 (Using Priority_queue and Adjacency list representation of graph) - Prim's Algorithm
typedef pair<int, int> P;
class Solution {
public:
    int minMST(vector<vector<P>>& adj, int V) {
        priority_queue<P, vector<P>, greater<P>> pq; //minheap
        pq.push({0, 0}); //{weight, vertex}
        
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
                
                int neighbor      = tmp.first;
                int neighbor_wt   = tmp.second;
                
                if(inMST[neighbor] == false) {
                    pq.push({neighbor_wt, neighbor});
                }
 
            }
        }
        
        return sum;
    }
    
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        
        vector<vector<P>> adj(V);
        
        for(int i = 0; i < V; i++) {
            for(int j = i+1; j<V; j++) {
                int x1 = points[i][0];
                int y1 = points[i][1];
                
                int x2 = points[j][0];
                int y2 = points[j][1];
                
                int d = abs(x1-x2) + abs(y1-y2);
                
                adj[i].push_back({j, d});
                adj[j].push_back({i, d});
            }
        }
        
        return minMST(adj, V);
        
    }
};


//Approach-2 (Using 2-D matrix graph) - Prim's Algorithm
class Solution {
public:
    int minKey(vector<bool>& inMST, vector<int>& key) {
        int minIndex = 0;
        int minVal   = INT_MAX;
        for(int i = 0; i<key.size(); i++) {
            if(!inMST[i] && key[i] < minVal) {
                minIndex = i;
                minVal   = key[i];
            }
        }
        return minIndex;
    }
    int MST(vector<vector<int>>& graph, int V) {
        vector<int>  key(V, INT_MAX);
        vector<bool> inMST(V, false);
        key[0] = 0;
        
        for(int count = 1; count<=V-1; count++) {
            int u    = minKey(inMST, key);
            inMST[u] = true;
            
            for(int v = 0; v<V; v++) {
                if(graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                    key[v] = graph[u][v];
                }
            }
        }
        
        int cost = 0;
        for(int i : key) {
            cost +=i;
        }
        return cost;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> graph(n, vector<int>(n));
        
        for(int i = 0; i<n-1; i++) {
            for(int j = i+1; j<n; j++) {
                vector<int> p1 = points[i];
                vector<int> p2 = points[j];
                int md         = abs(p1[0]-p2[0]) + abs(p1[1] - p2[1]);
                graph[i][j]    = md;
                graph[j][i]    = md;
            }
        }
        
        return MST(graph, n);
    }
};
