/*
    Company Tags  : Flipkart, Amazon, Samsung, MakeMyTrip, Oracle, Adobe
    Question Link : https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
*/


//Using Queue of Pair {node, parent_of_node}
class Solution {
  public:
    bool isCycleBFS(vector<int> g[], int V, int start, vector<bool>& visited) {
        queue<pair<int, int>> que;
        que.push({start, -1});
        visited[start] = true;
        while(!que.empty()) {
            int curr   = que.front().first;
            int parent = que.front().second;
            que.pop();
            
            for(auto x : g[curr]) {
                if(visited[x] == false) {
                    que.push({x, curr});
                    visited[x] = true;
                }
                else if(x != parent)
                    return true;
            }
        }
        
        return false;
    }

  
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        
        vector<bool> visited(V, false);
        
        for(int i = 0; i<V; i++) {
            if(!visited[i] && isCycleBFS(adj, V, i, visited)) {
                return true;
            }
        }
        
        return false;
        
    }
};


//Using Parent vector
bool isCyclicUtil(vector<int> g[], int V, int start, vector<bool>& visited) {
    vector<int> parent(V, -1);
    queue<int> que;
    que.push(start);
    visited[start] = true;
    while(!que.empty()) {
        int curr = que.front();
        que.pop();
        
        for(auto x : g[curr]) {
            if(visited[x] == false) {
                que.push(x);
                visited[x] = true;
                parent[x] = curr;
            }
            else if(parent[curr] != x)
                return true;
        }
    }
    
    return false;
}

bool isCyclic(vector<int> g[], int V) {
    vector<bool> visited(V, false);
    
    for(int i = 0; i<V; i++) {
        if(visited[i] == false && isCyclicUtil(g, V, i, visited))
            return true;
    }
    return false;
}
