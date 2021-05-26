#include <bits/stdc++.h>
using namespace std;

void addEdge(map<int, vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
}

void BFS(map<int, vector<int>>& adj, int V, int start) {
    vector<int> visited(V, 0);
    queue<int> que;

    que.push(start);
    //Mark a node visited as soon as it's pushed into queue
    visited[start] = 1;
    while(!que.empty()) {
        int curr = que.front();
        cout << curr << " ";
        que.pop();
        for(auto i:adj[curr]) {
            if(visited[i] == 0) {
                que.push(i);
                //Mark a node visited as soon as it's pushed into queue
                visited[i] = 1;
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

    cout << "\nThis is the BFS : \n";
    BFS(adj, V, 0);

return 0;
}
