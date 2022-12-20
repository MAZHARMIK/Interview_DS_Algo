/*
    MY YOUTUBE VIDEO ON THIS Qn : <soon>
    Company Tags                : Google
    Leetcode Link               : https://leetcode.com/problems/keys-and-rooms/
*/

//Using DFS : O(m+n)
class Solution {
public:
    int count = 1;
    
    void dfs(vector<vector<int>>& rooms, int u, vector<bool>& visited) {
        visited[u] = true;
        
        for(int& node : rooms[u]) {
            if(!visited[node])
                dfs(rooms, node, visited);
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        
        dfs(rooms, 0, visited);
        
        for(bool x : visited) {
            if(x == false) return false;
        }
        return true;
        
    }
};
