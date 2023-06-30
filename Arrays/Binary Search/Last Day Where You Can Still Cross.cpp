/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : GOOGLE (on site interview), META
    Leetcode Link               : https://leetcode.com/problems/last-day-where-you-can-still-cross/solution/

*/

//Approach-1 (Using Binary Search + DFS)
class Solution {
public:
    int ROW;
    int COL;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    bool dfs(vector<vector<int>> &grid, int i, int j) {
        
        if(i < 0 || i >= ROW || j < 0 || j >= COL || grid[i][j] == 1) {
            return false;
        }
        
        if(i == ROW-1)
            return true;
        
        grid[i][j] = 1;
        for(vector<int> &dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            
            if(dfs(grid, new_i, new_j))
                return true;
        }
        
        
        return false;
    }
    
    bool canCross(vector<vector<int>>& cells, int day) {
        vector<vector<int>> grid(ROW, vector<int>(COL));
        
        for (int i = 0; i <= day; ++i) {
            int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;
            
            grid[r][c] = 1;
        }
        
        for (int j = 0; j < COL; j++) {
            if (grid[0][j] == 0 && dfs(grid, 0, j)) {
                return true;
            }
        }
        return false;
        
    }
    
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        ROW = row;
        COL = col;
        vector<vector<int>> grid(row, vector<int>(col, 0));
        
        int n = cells.size();
        
        int l = 0;
        int r = cells.size()-1;
        int lastDay = 0;
        
        while( l <= r) {
            
            int mid = l + (r-l)/2;
            
            if(canCross(cells, mid)) {
                lastDay = mid+1;
                l = mid+1;
            } else {
                r = mid-1;
            }
            
        }
        
        return lastDay;
        
    }
};


//Approach-2 (Binary Search + BFS)
//Coming soon



//Approach-3 (Using Union Find)
//Will soon upload in Union Find repo
