/*
    Company Tags : Moonfrog Labs, Flipkart, Morgan Stanley, Accolite, Amazon, Microsoft
*/

#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;

void addEdge(map<int, vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
}

void topologicalSortUtil(map<int, vector<int>>& adj, int start, stack<int>& stk, vector<bool>& visited) {
    visited[start] = true;

    for(auto x:adj[start]) {
        if(visited[x] == false)
            topologicalSortUtil(adj, x, stk, visited);
    }

    stk.push(start);
}

void topologicalSortDFS(map<int, vector<int>>& adj, int V) {
    vector<bool> visited (V, false);

    stack<int> stk;
    for(int i = 0; i<V; i++) {
        if(visited[i] == false)
            topologicalSortUtil(adj, i, stk, visited);
    }
    while(!stk.empty()) {
        cout << stk.top() << " ";
        stk.pop();
    }
}

int main() {

    int V = 6;
    map<int, vector<int>> adj;
    addEdge(adj, 5, 2);
    addEdge(adj, 5, 0);
    addEdge(adj, 4, 0);
    addEdge(adj, 4, 1);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 1);

    cout << "This is the graph : \n";
    for(int i = 0; i<V; i++) {
        cout << i << " -> ";
        for(int i:adj[i]) {
            cout << i << " ";
        }
        cout << endl;
    }

    cout << "\nThis is the topological Sort : \n";
    topologicalSortDFS(adj, V);

return 0;
}
