/*           Scroll below to see JAVA code also   */
/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=dMn6NPk9nPw
      COMPANY TAGS                : GOOGLE
      Leetcode Link               : https://leetcode.com/problems/number-of-closed-islands/
*/


/******************************************** C++ ********************************************/
//Approach (Using DFS)
//T.C : O(m*n)
//S.C : O(1), not considering Recursion stack space O(m × n)
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


/******************************************** C++ ********************************************/
//Approach (Using DFS)
//T.C : O(m*n)
//S.C : O(1), not considering Recursion stack space O(m × n)
class Solution {
    private int m, n;

    private boolean dfs(int[][] grid, int r, int c) {
        // Out of bounds: touched the border, so not closed
        if (r < 0 || r >= m || c < 0 || c >= n)
            return false;

        // Water: closed on this side
        if (grid[r][c] == 1)
            return true;

        // Mark as visited
        grid[r][c] = 1;

        // Explore all 4 directions (no short-circuiting, so the full island gets marked)
        boolean left  = dfs(grid, r, c - 1);
        boolean right = dfs(grid, r, c + 1);
        boolean up    = dfs(grid, r - 1, c);
        boolean down  = dfs(grid, r + 1, c);

        return left && right && up && down;
    }

    public int closedIsland(int[][] grid) {
        m = grid.length;
        n = grid[0].length;

        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    if (dfs(grid, i, j)) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
}
