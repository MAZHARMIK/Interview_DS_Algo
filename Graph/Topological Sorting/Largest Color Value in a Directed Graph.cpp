/*            Scroll below to see JAVA code as well        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=V6LnZaX7zpk
    Company Tags                : META
    Leetcode Link               : https://leetcode.com/problems/largest-color-value-in-a-directed-graph/
*/


/***************************************************************** C++ ****************************************************/
//Approach (Using Topological Sorting with BFS)
//T.C : O(V+E)
//S.C : O(V+E)
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



/***************************************************************** JAVA ****************************************************/
//Approach (Using Topological Sorting with BFS)
//T.C : O(V+E)
//S.C : O(V+E)
class Solution {
    public int largestPathValue(String colors, int[][] edges) {
        int N = colors.length();
        Map<Integer, List<Integer>> adj = new HashMap<>();
        int[] indegree = new int[N];
        
        // Build the graph and indegree array
        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj.computeIfAbsent(u, k -> new ArrayList<>()).add(v);
            indegree[v]++;
        }

        Queue<Integer> queue = new LinkedList<>();
        int[][] t = new int[N][26];  // to keep max count of each color per node

        // Initialize the queue with nodes with 0 indegree
        for (int i = 0; i < N; i++) {
            if (indegree[i] == 0) {
                queue.offer(i);
                t[i][colors.charAt(i) - 'a'] = 1;
            }
        }

        int answer = 0;
        int countNodes = 0;

        // Kahn's algorithm for topological sort
        while (!queue.isEmpty()) {
            int u = queue.poll();
            countNodes++;

            for (int i = 0; i < 26; i++) {
                answer = Math.max(answer, t[u][i]);
            }

            List<Integer> neighbors = adj.getOrDefault(u, new ArrayList<>());
            for (int v : neighbors) {
                for (int i = 0; i < 26; i++) {
                    int val = t[u][i] + (colors.charAt(v) - 'a' == i ? 1 : 0);
                    t[v][i] = Math.max(t[v][i], val);
                }

                indegree[v]--;
                if (indegree[v] == 0) {
                    queue.offer(v);
                }
            }
        }

        return countNodes < N ? -1 : answer;
    }
}
