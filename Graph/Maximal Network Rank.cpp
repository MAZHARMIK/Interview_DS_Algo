/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=R2sjm5jfwYY
      iPad PDF Notes              : https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/iPad%20PDF%20Notes/Leetcode-1615-Maximal%20Network%20Rank.pdf
      Company Tags                : MICROSOFT
      Leetcode Link               : https://leetcode.com/problems/maximal-network-rank/
*/

************************************************ C++ ********************************************************
//Approach-1 (Simply checking each pair of nodes) - O(V^2)
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int, unordered_set<int>> adj;
        
        for(auto &road : roads) {
            int u = road[0];
            int v = road[1];
            
            adj[u].insert(v);
            adj[v].insert(u);
        }
        
        int maxRank = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                
                int i_rank = adj[i].size();
                int j_rank = adj[j].size();
                
                int rank   = i_rank + j_rank;
                
                if(adj[i].find(j) != adj[i].end()) {
                    rank -= 1;
                }
                
                maxRank = max(maxRank, rank);
                
            }
        }
        
        return maxRank;
    }
};


//Approach-2 (Using degree count & keeping a check if nodes are connected) - T.C. (O(V^2))
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degree(n);
        vector<vector<bool>> connected(n, vector<bool>(n, false));
        
        for(auto &road : roads) {
            int u = road[0];
            int v = road[1];
            
            degree[u]++;
            degree[v]++;
            
            connected[u][v] = true;
            connected[v][u] = true;
        }
        
        int maxRank = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                
                int i_rank = degree[i];
                int j_rank = degree[j];
                
                int rank   = i_rank + j_rank;
                
                if(connected[i][j] || connected[j][i]) {
                    rank -= 1;
                }
                
                maxRank = max(maxRank, rank);
                
            }
        }
        
        return maxRank;
    }
};




************************************************ JAVA ********************************************************
//Approach-1 (Simply checking each pair of nodes) - O(V^2)
class Solution {
    public int maximalNetworkRank(int n, int[][] roads) {
        
        Map<Integer, Set<Integer>> adj = new HashMap<>();
        
        for (int[] road : roads) {
            adj.computeIfAbsent(road[0], k -> new HashSet<>()).add(road[1]);
            adj.computeIfAbsent(road[1], k -> new HashSet<>()).add(road[0]);
        }

        int maxRank = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                
                int i_rank = adj.getOrDefault(i, Collections.emptySet()).size();
                int j_rank = adj.getOrDefault(j, Collections.emptySet()).size();
                
                int rank = i_rank + j_rank;
                
                
                if (adj.getOrDefault(i, Collections.emptySet()).contains(j)) {
                    rank--;
                }
                
                maxRank = Math.max(maxRank, rank);
            }
        }
 
        return maxRank;
    }
}
