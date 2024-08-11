/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=HCHpyAk1Ekw
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island
*/


/************************************************************ C++ ************************************************/
//Simple Approach - Using "Number Of Islands" concept
//T.C : O((m*n)^2)
//S.C : O(m*n)
class Solution {
public:
    vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int m;
    int n;
    void DFS(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited) {
        if(i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || grid[i][j] == 0)
            return;
        
        visited[i][j] = 1; //mark visited

        for(auto& dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            DFS(grid, new_i, new_j, visited);
        }
    }

    int numberOfIslandsDFS(vector<vector<int>>& grid) {

        vector<vector<bool>> visited(m, vector<bool>(n));
        int islands = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j] && grid[i][j] == 1) { //DFS
                    DFS(grid, i, j, visited);
                    islands += 1;
                }
            }
        }

        return islands;
    } 

    int minDays(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int islands = numberOfIslandsDFS(grid);

        //Grid already disconnected
        if (islands > 1 or islands == 0) {
            return 0;
        } else {
			// check for 1 ans
            for (int i = 0 ; i < m; i ++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 1) {
                        grid[i][j] = 0; //visited
						
                        islands = numberOfIslandsDFS(grid);
						
                        grid[i][j] = 1; //unvisited
                        if (islands > 1 or islands == 0)
                            return 1;
                    }

                }
            }
        }

        return 2; //It's always possible to break an island with 2 moves
    }
};



/************************************************************ JAVA *******************************************************/
//Simple Approach - Using "Number Of Islands" concept
//T.C : O((m*n)^2)
//S.C : O(m*n)
class Solution {
    private final int[][] directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    private int m;
    private int n;

    private void DFS(int[][] grid, int i, int j, boolean[][] visited) {
        if (i < 0 || i >= grid.length || j < 0 || j >= grid[0].length || visited[i][j] || grid[i][j] == 0)
            return;

        visited[i][j] = true; // mark visited

        for (int[] dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            DFS(grid, new_i, new_j, visited);
        }
    }

    private int numberOfIslandsDFS(int[][] grid) {
        boolean[][] visited = new boolean[m][n];
        int islands = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && grid[i][j] == 1) { // DFS
                    DFS(grid, i, j, visited);
                    islands++;
                }
            }
        }

        return islands;
    }

    public int minDays(int[][] grid) {
        m = grid.length;
        n = grid[0].length;
        int islands = numberOfIslandsDFS(grid);

        // Grid already disconnected
        if (islands > 1 || islands == 0) {
            return 0;
        } else {
            // Check for 1 move
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 1) {
                        grid[i][j] = 0; // mark visited
                        
                        islands = numberOfIslandsDFS(grid);
                        
                        grid[i][j] = 1; // unmark visited
                        if (islands > 1 || islands == 0) {
                            return 1;
                        }
                    }
                }
            }
        }

        return 2; // It's always possible to break an island with 2 moves
    }
}
