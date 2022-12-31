/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=eagGLroZXMk
    Company Tags                : Apple, Amazon(on-site), Meta, Microsoft, Salesforce
    Leetcode Link               : https://leetcode.com/problems/unique-paths-iii/
*/

class Solution {
public:
    int m, n;
    int emptyCells;
    int result = 0;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    void dfs(vector<vector<int>>& grid, int curr_count, int i, int j) {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == -1) {
            return;
        }
        
        if(grid[i][j] == 2) {
            if(curr_count == emptyCells) {
                result++;
            }
            return;
        }
        
        
        grid[i][j] = -1;
        for(vector<int> dir:directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            dfs(grid, curr_count+1, i_, j_);
        }
        grid[i][j] = 0;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        emptyCells = 0;
        result = 0;
        
        int start_x = 0;
        int start_y = 0;
        
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j] == 0)
                    emptyCells++;
                
                if(grid[i][j] == 1) {
                    start_x = i;
                    start_y = j;
                }
            }
        }
        
        emptyCells += 1; //walk over every non-obstacle square exactly once.
        int curr_count = 0;
        
        dfs(grid, curr_count, start_x, start_y);
        
        return result;
    }
};
