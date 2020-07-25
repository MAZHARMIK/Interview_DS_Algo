/*
    Company Tags                        : Accolite, Amazon, Flipkart, Microsoft, Moonfrog Labs, OYO Rooms
    Related Leetcode Qn                 : Course Schedule, Course Schedule II
    Course Schedule (Leetcode - 207)    : https://leetcode.com/problems/course-schedule/
    Course Schedule II (Leetcode - 210) : https://leetcode.com/problems/course-schedule-ii/
    Solution (Course Schedule)          : https://github.com/MAZHARMIK/Leetcode-May-Challenge-2020/blob/master/Course%20Schedule%20(C%2B%2B)
    Solution (Course Schedule II)       : https://github.com/MAZHARMIK/Leetcode-July-Challenge-2020/blob/master/Course%20Schedule%20II%20(C%2B%2B)
    NOTE: This can also be used to check if the graph contains cycle or not (Please see Line:56 below)
*/

#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

void addEdge(map<int, vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
}

void topologicalSortBFS(map<int, vector<int>>& adj, int V) {
    vector<bool> visited(V, false);

    vector<int> indegree(V, 0);

    for(auto vec: adj) {
        for(auto x : vec.second) {
            indegree[x]++;
        }
    }
    queue<int> que;
    for(int i = 0; i<V; i++) {
        if(indegree[i] == 0) {
            visited[i] = true;
            que.push(i);
        }
    }
    vector<int> result;
    int count = 0;
    while(!que.empty()) {
        int curr = que.front();
        que.pop();
        count++;

        for(auto x:adj[curr]) {
            if(visited[x] == false)
                indegree[x]--;
            if(indegree[x] == 0) {
                que.push(x);
                visited[x] = true;
            }
        }

        result.push_back(curr);
    }
    if(count != V) {
        cout << "No topological sorting possible. There is a cycle\n";
        return;
    }
    for(int i : result)
        cout << i << " ";
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

    cout << "\nThis is the topological Sort using Kahn's Algorithm: \n";
    topologicalSortBFS(adj, V);
    
return 0;
}
