/*
    MY YOUTUBE VIDEO ON THIS Qn : DFS - https://www.youtube.com/watch?v=DsAIuJmiT1c
                                  BFS - <soon>
                                  DSU - <soon>
    Company Tags                : <soon>
    Leetcode Link               : https://leetcode.com/problems/lexicographically-smallest-equivalent-string/
*/

//Approach-1 (DFS)
class Solution {
public:
    
    char DFS(unordered_map<char, vector<char>> &adj, char curr, vector<int>& visited) {
        visited[curr-'a'] = 1;
        
        char minChar = curr;
        
        for(char &v : adj[curr]) {
            
            if(visited[v-'a'] == 0)
                minChar = min(minChar, DFS(adj, v, visited));
        }
        
        return minChar;
    }
    
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.length();
        unordered_map<char, vector<char>> adj;
        
        for(int i = 0; i<n; i++) {
            char u = s1[i];
            char v = s2[i];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        
        int m = baseStr.length();
        string result;
        
        for(int i = 0; i<m; i++) {
            char ch = baseStr[i];
            
            vector<int> visited(26, 0);
            
            result.push_back(DFS(adj, ch, visited));
        }
        
        return result;
    }
};


//Approach-2 (BFS - SOON)


//Approach-3 (DSU - SOON)
