/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=ZsGTpXm966E
    Company Tags                : Google
    Leetcode Link               : https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
    
    Please see the "Disjoint Set" solution : https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Disjoint%20Set/Most%20Stones%20Removed%20with%20Same%20Row%20or%20Column.cpp
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
