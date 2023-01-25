/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Vn-voe1XNtQ
    Company Tags                : <soon>
    Leetcode Link               : https://leetcode.com/problems/find-closest-node-to-given-two-nodes/
*/


//Approach-1 (BFS)
class Solution {
public:
    int n;
    
    void bfs(vector<int>& edges, int startNode, vector<int>& dist_node) {
        queue<int> que;
        que.push(startNode);
        dist_node[startNode] = 0;
        vector<bool> visited(n, false);
        visited[startNode] = true;
        
        while(!que.empty()) {
            int u = que.front();
            que.pop();
            
            int v = edges[u];
            
            if(v != -1 && !visited[v]) {
                visited[v] = true;
                dist_node[v] = 1 + dist_node[u];
                que.push(v);
            }
        }
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        n = edges.size();
        
        vector<int> dist1(n, INT_MAX);
        vector<int> dist2(n, INT_MAX);
        
        bfs(edges, node1, dist1);
        bfs(edges, node2, dist2);
        
        
        int minDistNode    = -1;
        int minDistTillNow = INT_MAX;
        for (int i = 0; i < n; i++) {
            
            int maxD = max(dist1[i], dist2[i]);
            
            if (minDistTillNow > maxD) {
                minDistNode = i;
                minDistTillNow = maxD;
            }
        }

        return minDistNode;
        
    }
};


//Approach-2 (DFS)
class Solution {
public:
    int n;
    
    void dfs(vector<int>& edges, int startNode, vector<int>& dist_node, vector<bool>& visited) {
        visited[startNode] = true;
        
        int v = edges[startNode];
        
        if(v != -1 && !visited[v]) {
            visited[v] = true;
            dist_node[v] = 1 + dist_node[startNode];
            dfs(edges, v, dist_node, visited);
        }
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        n = edges.size();
        
        vector<int> dist1(n, INT_MAX);
        vector<int> dist2(n, INT_MAX);
        vector<bool> visited1(n, false);
        vector<bool> visited2(n, false);
        dist1[node1] = 0;
        dist2[node2] = 0;
        
        dfs(edges, node1, dist1, visited1);
        dfs(edges, node2, dist2, visited2);
        
        
        int minDistNode    = -1;
        int minDistTillNow = INT_MAX;
        for (int i = 0; i < n; i++) {
            
            int maxD = max(dist1[i], dist2[i]);
            
            if (minDistTillNow > maxD) {
                minDistNode = i;
                minDistTillNow = maxD;
            }
        }

        return minDistNode;
        
    }
};
