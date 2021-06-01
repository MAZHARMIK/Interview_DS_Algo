/*
    Company Tags  : Amazon
    Leetcode Link : https://leetcode.com/problems/max-area-of-island/
*/

class Solution {
public:
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int dfs(vector<vector<int>>& grid, int i, int j, int &m, int &n) {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
            return 0;
        }
        
        int count = 1;
        grid[i][j] = 0;
        for(vector<int> &dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            count += dfs(grid, i_, j_, m, n);
        }
        
        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    maxArea = max(maxArea, dfs(grid, i, j, m, n));
                }
            }
        }
        
        return maxArea;
    }
};
