/*
    MY YOUTUBE VIDEO ON THIS Qn : <soon>
    Company Tags                : Google
    Leetcode Link               : https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
    
    Please see the "Disjoint Set" Folder to find "Disjoint Set" Solution for this Qn - SOON
*/

class Solution {
public:
    int n ;
    void dfs(vector<vector<int>>& stones, int index, vector<bool>& visited) {
        visited[index] = true;
        
        for(int i = 0; i<n; i++) {
            if(!visited[i] &&
               ((stones[i][0] == stones[index][0]) || (stones[i][1] == stones[index][1]))) {
                dfs(stones, i, visited);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        n = stones.size();
        vector<bool> visited(n, false);
        
        int count = 0;
        for(int i = 0; i<n; i++) {
            if(visited[i])
                continue;
            dfs(stones, i, visited);
            count++;
        }
        
        return n - count;
    }
};
