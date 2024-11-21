/*           Scroll below to see JAVA code also   */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/count-unguarded-cells-in-the-grid
*/

/******************************************** C++ ********************************************/
//Approach-1 (Simple Simulation)
//T.C : O(m*n + G*(m+n)), where G =  size of guards
//S.C : O(m*n), considering the size of grid we took
class Solution {
public:

    void markGaurded(int row, int col, vector<vector<int>>& grid) {
        //UP
        for(int i = row-1; i >= 0; i--) {
            if(grid[i][col] == 2 || grid[i][col] == 3) {
                break;
            }
            grid[i][col] = 1; //Marking it as gaurded
        }

        //Down
        for(int i = row+1; i < grid.size(); i++) {
            if(grid[i][col] == 2 || grid[i][col] == 3) {
                break;
            }
            grid[i][col] = 1; //Marking it as gaurded
        }

        //left
        for(int j = col-1; j >= 0; j--) {
            if(grid[row][j] == 2 || grid[row][j] == 3) {
                break;
            }
            grid[row][j] = 1; //Marking it as gaurded
        }

        //right
        for(int j = col+1; j < grid[0].size(); j++) {
            if(grid[row][j] == 2 || grid[row][j] == 3) {
                break;
            }
            grid[row][j] = 1; //Marking it as gaurded
        }

    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));

        //mark gaurds positions
        for(vector<int>& vec : guards) {
            int i = vec[0];
            int j = vec[1];
            grid[i][j] = 2; //gaurd
        }

        //mark walls positions
        for(vector<int>& vec : walls) {
            int i = vec[0];
            int j = vec[1];
            grid[i][j] = 3; //wall 
        }

        for(vector<int>& gaurd : guards) {
            int i = gaurd[0];
            int j = gaurd[1];
            markGaurded(i, j, grid); //four directions me check karo and mark karo gaurded
        }

        int count = 0;
        //O(m*n)
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) { //ungaurded
                    count++;
                }
            }
        }

        return count;

    }
};


//Approach-2 (DFS)
//T.C : O(m*n + G*(m+n)), where G =  size of guards
//S.C : O(m*n), considering the size of grid we took
class Solution {
public:
    int ROWS;
    int COLS;

    void dfs(vector<vector<int>>& grid, int row, int col, int rows, int cols, int direction) {
        // Boundary check and skipping guarded or walled cells
        if (row < 0 || col < 0 || row >= rows || col >= cols || grid[row][col] == 1 || grid[row][col] == 2) {
            return;
        }

        // Mark the current cell as visited by a guard's line of sight
        grid[row][col] = 3;

        // Continue the DFS in the specified direction
        if (direction == 1) { // UP
            dfs(grid, row - 1, col, rows, cols, direction);
        } else if (direction == 2) { // DOWN
            dfs(grid, row + 1, col, rows, cols, direction);
        } else if (direction == 3) { // LEFT
            dfs(grid, row, col - 1, rows, cols, direction);
        } else { // RIGHT
            dfs(grid, row, col + 1, rows, cols, direction);
        }
    }

    int countUnguarded(int rows, int cols, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        // Initialize the grid
        vector<vector<int>> grid(rows, vector<int>(cols, 0));

        // Mark guard positions
        for (const auto& guard : guards) {
            int i = guard[0];
            int j = guard[1];
            grid[i][j] = 1; // Guard cell
        }

        // Mark wall positions
        for (const auto& wall : walls) {
            int i = wall[0];
            int j = wall[1];
            grid[i][j] = 2; // Wall cell
        }

        // Perform DFS for each guard in all four directions (UP, DOWN, LEFT, RIGHT)
        for (const auto& guard : guards) {
            int guardRow = guard[0];
            int guardCol = guard[1];

            dfs(grid, guardRow - 1, guardCol, rows, cols, 1); // UP
            dfs(grid, guardRow + 1, guardCol, rows, cols, 2); // DOWN
            dfs(grid, guardRow, guardCol - 1, rows, cols, 3); // LEFT
            dfs(grid, guardRow, guardCol + 1, rows, cols, 4); // RIGHT
        }

        // Count unguarded cells
        int unguardedCount = 0;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == 0) {
                    ++unguardedCount;
                }
            }
        }

        return unguardedCount;
    }
};
