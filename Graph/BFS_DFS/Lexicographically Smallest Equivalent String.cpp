/*         Scroll below to see JAVA code as well        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : DFS - https://www.youtube.com/watch?v=DsAIuJmiT1c
                                  BFS - Let me know if you want a video on this)
                                  DSU - Let me know if you want a video on this)
    Company Tags                : Amazon
    Leetcode Link               : https://leetcode.com/problems/lexicographically-smallest-equivalent-string/
*/


/******************************************************************* C++ ************************************************************************/
//Approach-1 (DFS)
//T.C : O(m* ( V+E)), we try DFS m times
//S.C : O(V+E)
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


//Approach-2 (BFS - Let me know if you want a video on this)


//Approach-3 (DSU - Let me know if you want a video on this)



/******************************************************************* JAVA ************************************************************************/
//Approach-1 (DFS)
//T.C : O(m* ( V+E)), we try DFS m times
//S.C : O(V+E)
class Solution {
    
    private char DFS(Map<Character, List<Character>> adj, char curr, boolean[] visited) {
        visited[curr - 'a'] = true;
        char minChar = curr;

        for (char neighbor : adj.getOrDefault(curr, new ArrayList<>())) {
            if (!visited[neighbor - 'a']) {
                char nextMin = DFS(adj, neighbor, visited);
                if (nextMin < minChar) {
                    minChar = nextMin;
                }
            }
        }

        return minChar;
    }

    public String smallestEquivalentString(String s1, String s2, String baseStr) {
        Map<Character, List<Character>> adj = new HashMap<>();
        
        // Build graph
        for (int i = 0; i < s1.length(); i++) {
            char u = s1.charAt(i);
            char v = s2.charAt(i);
            
            adj.computeIfAbsent(u, k -> new ArrayList<>()).add(v);
            adj.computeIfAbsent(v, k -> new ArrayList<>()).add(u);
        }

        StringBuilder result = new StringBuilder();
        
        for (char ch : baseStr.toCharArray()) {
            boolean[] visited = new boolean[26];
            result.append(DFS(adj, ch, visited));
        }
        
        return result.toString();
    }
}


//Approach-2 (BFS - Let me know if you want a video on this)


//Approach-3 (DSU - Let me know if you want a video on this)


