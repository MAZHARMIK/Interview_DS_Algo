/*
  Company Tags : Flipkart, Amazon, Microsoft, Samsung, MakeMyTrip, Oracle, Adobe, BankBazaar, 
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void addEdge(map<int, vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
}

bool isCycleUtil(map<int, vector<int>>& adj, int start, vector<bool>& visited, vector<bool>& inStack) {
    //if not visited, then explore it
    if(visited[start] == false) {
        visited[start] = true;
        inStack[start] = true;

        for(auto x:adj[start]) {
            //if not visited, then we recursively check for cycle
            if(visited[x] == false && isCycleUtil(adj, x, visited, inStack))
                return true;
            else if(inStack[x] == true) //if visited and it's in stack also, then it's a cycle
                return true;

        }
    }
    //After exploring "start" , it will be out of recursion stack
    inStack[start] = false;
    return false;
}

bool isCycle(map<int, vector<int>>& adj, int V) {
    vector<bool> visited(V, false);
    vector<bool> inStack(V, false);

    for(int i = 0 ; i<V; i++) {
        if(isCycleUtil(adj, i, visited, inStack))
            return true;
    }
    return false;
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
    addEdge(adj, 1, 5);

    cout << "This is the graph : \n";
    for(int i = 0; i<V; i++) {
        cout << i << " -> ";
        for(int i:adj[i]) {
            cout << i << " ";
        }
        cout << endl;
    }

    if(isCycle(adj, V))
        cout << "The graph has cycle\n";
    else
      cout << "The graph as no cycle\n";
return 0;
}
