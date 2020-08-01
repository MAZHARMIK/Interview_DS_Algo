/*
    Company Tags  : Flipkart, Amazon, Samsung, MakeMyTrip, Oracle, Adobe
    Question Link : https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
*/

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
