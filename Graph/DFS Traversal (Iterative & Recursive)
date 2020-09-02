/*
    Company Tags : Amazon, Samsung, Accolite, Intuit
*/

#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;

void addEdge(map<int, vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
}

void DFS_UTIL(map<int, vector<int>>& adj, int start, vector<bool>& visited) {
    visited[start] = true;
    cout << start << " ";
    
    for(auto i:adj[start]) {
        if(visited[i] == false)
            DFS_UTIL(adj, i, visited);
    }
}

void DFS(map<int, vector<int>>& adj, int V) {
    vector<bool> visited(V, false);
    DFS_UTIL(adj, 2, visited);
    
    /*In case of Unconnected Graph ,we need to Call DFS for every unvisited node to visit all of them
    For that, we can use this commented code below
    for(int i = 0 ; i < V; i++) {
          if(visited[i] == false)
                DFS_UTIL(adj, i, visited);
    }
    */
}


void DFSIter(map<int, vector<int>>& adj, int V) {
    vector<bool> visited(V, false);
    stack<int> stk;
    
    int start = 2;
    stk.push(start);
    while(!stk.empty()) {
        int curr = stk.top();
        stk.pop();
        if(visited[curr] == false) {
            cout << curr << " ";
            visited[curr] = true;
        }
        for(int i : adj[curr]) {
            if(visited[i] == false) {
                stk.push(i);
            }
        }
    }
}

int main() {

    int V = 4;
    map<int, vector<int>> adj;

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 3);

    cout << "This is the graph : \n";
    for(int i = 0; i<V; i++) {
        cout << i << " -> ";
        for(int i:adj[i]) {
            cout << i << " ";
        }
        cout << endl;
    }

    cout << "\nThis is the DFS recursive : \n";
    DFS(adj, V);

    cout << "\nThis is the DFS iterative : \n";
    DFSIter(adj, V);

return 0;
}
