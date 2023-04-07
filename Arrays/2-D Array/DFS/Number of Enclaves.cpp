/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=dYOm367BdbM
      Company Tags                : AMAZON
      Leetcode Link               : https://leetcode.com/problems/number-of-enclaves/
*/

//Approach-1 (DFS)
class Solution {
public:
    
    int m, n;
    void dfs(vector<vector<int>> &grid, int r, int c) {
        
        if(r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0)
            return;

        
        grid[r][c] = 0;
        
        
        dfs(grid, r, c-1);
        dfs(grid, r, c+1);
        dfs(grid, r-1, c);
        dfs(grid, r+1, c);
        
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        for (int i = 0; i < m; ++i) {
            // First column.
            if (grid[i][0] == 1) {
                dfs(grid, i, 0);
            }
            // Last column.
            if (grid[i][n - 1] == 1) {
                dfs(grid, i, n - 1);
            }
        }

        for (int i = 0; i < n; ++i) {
            // First row.
            if (grid[0][i] == 1) {
                dfs(grid, 0, i);
            }
            // Last row.
            if (grid[m - 1][i] == 1) {
                dfs(grid, m - 1, i);
            }
        }
        
        
        
        int count = 0;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                
                if(grid[i][j] == 1) {
                    count += 1;
                }
                
            }
        }
        
        return count;
    }
};


//Approach-2 (Using BFS)
//will soon share here
