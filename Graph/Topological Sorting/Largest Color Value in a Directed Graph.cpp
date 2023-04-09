/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=V6LnZaX7zpk
    Company Tags                : META
    Leetcode Link               : https://leetcode.com/problems/largest-color-value-in-a-directed-graph/
*/

//Approach-1 (Using Topological Sorting with BFS)
class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        int N = colors.size();
        
        vector<int> indegree(N, 0);
        
        for(auto &vec : edges) {
            int u = vec[0];
            int v = vec[1];
            
            adj[u].push_back(v);
            indegree[v]++;
            
        }
        
        queue<int> que;
        vector<vector<int>> t(N, vector<int>(26, 0));
        
        for(int i = 0; i<N; i++) {
            if(indegree[i] == 0) {
                que.push(i);
                t[i][colors[i]-'a'] = 1;
            }
        }
        
        int answer = 0;
        
        int countNodes = 0;
        
        while(!que.empty()) {
            
            int u = que.front();
            que.pop();
            
            countNodes++;
            
            answer = max(answer, t[u][colors[u]-'a']);
            
            for(int &v : adj[u]) {
                
                for(int i = 0; i<26; i++) {
                    
                    t[v][i] = max(t[v][i], t[u][i] + (colors[v]-'a' == i));
                    
                }
                
                indegree[v]--;
                if(indegree[v] == 0) {
                    que.push(v);
                }
            }
            
        }
        
        if(countNodes < N)
            return -1;
        
        return answer;
    }
};

//Approach-2 (Using DFS - Soon)
