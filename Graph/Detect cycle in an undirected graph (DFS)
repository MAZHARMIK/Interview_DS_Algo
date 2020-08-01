/*
    Company Tags  : Flipkart, Amazon, Samsung, MakeMyTrip, Oracle, Adobe
    Question Link : https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
*/

bool isCycleUtil(vector<int> g[], int start, vector<bool>& visited, int parent) {
    visited[start] = true;
    
    vector<int>::iterator it;
    for(it = g[start].begin(); it != g[start].end(); it++) {
        if(*it == parent)
            continue;
        if(visited[*it] == true)
            return true;
        if(isCycleUtil(g, *it, visited, start))
            return true;
            
    }
    return false;
}

bool isCyclic(vector<int> g[], int V) {
    vector<bool> visited(V, false);
    
    for(int i = 0; i<V; i++) {
        if(visited[i] == false && isCycleUtil(g, i, visited, -1))
            return true;
    }
    return false;
}

