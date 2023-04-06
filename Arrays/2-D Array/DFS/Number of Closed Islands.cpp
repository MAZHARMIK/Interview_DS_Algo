/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=dMn6NPk9nPw
      COMPANY TAGS                : GOOGLE
      Leetcode Link               : https://leetcode.com/problems/number-of-closed-islands/
*/

//Approach-1 (Using DFS)
class Solution {
public:
    
    int m, n;
    bool dfs(vector<vector<int>> &grid, int r, int c) {
        
        if(r < 0 || r >= m || c < 0 || c >= n)
            return false; //Not closed
        
        if(grid[r][c] == 1)
            return true; //closed here
        
        grid[r][c] = 1;
        
        bool left  = dfs(grid, r, c-1);
        bool right = dfs(grid, r, c+1);
        bool up    = dfs(grid, r-1, c);
        bool down  = dfs(grid, r+1, c);
        
        return left && right && up && down;
        
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        int count = 0;
        
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                
                if(grid[i][j] == 0) {
                    count += dfs(grid, i, j);
                }
                
            }
        }
        
        return count;
    }
};


//Approach-2 (Using BFS)
//soon I will share BFS too
