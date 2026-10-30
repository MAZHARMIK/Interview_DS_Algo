/*    Scroll below to see JAVA code also  */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=sDdQ1-9TNP0
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/network-recovery-pathways/
*/


/**************************************************** C++ *******************************************/
//Appoach Using Dijkstra's
//Let V = n, E = edges.length, k = max count length, usually Dijkstra is O(E * log(V)), in this problem, E = E*K and V = n*K
//T.C : O(E*K * log(n*K))
//S.C : O(V+E) = O(n*K + E*k)
class Solution {
public:
    typedef tuple<int, int, int>  T ;   // {dist, node, count}

    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {

        unordered_map<int, vector<vector<int>>> adj;
        for (auto &edge : edges) {
            int u  = edge[0];
            int v  = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt});
        }

        // result[node][count] = min cost to reach node with 'count' consecutive identical chars
        vector<vector<int>> result(n, vector<int>(k + 1, INT_MAX));

        priority_queue<T, vector<T>, greater<T>> pq;

        result[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [d, node, count] = pq.top();
            pq.pop();

            if (d > result[node][count]) 
                continue;

            if (node == n - 1) 
                return d;

            for (auto &vec : adj[node]) {
                int adjNode = vec[0];
                int wt      = vec[1];

                int newRun = (labels[adjNode] == labels[node]) ? count + 1 : 1;
                
                if (newRun > k) 
                    continue;

                int newDist = d + wt;
                if (newDist < result[adjNode][newRun]) {
                    result[adjNode][newRun] = newDist;
                    pq.push({newDist, adjNode, newRun});
                }
            }
        }

        return -1;
    }
};



/**************************************************** JAVA *******************************************/
//Appoach Using Dijkstra's
//Let V = n, E = edges.length, k = max count length, usually Dijkstra is O(E * log(V)), in this problem, E = E*K and V = n*K
//T.C : O(E*K * log(n*K))
//S.C : O(V+E) = O(n*K + E*k)
