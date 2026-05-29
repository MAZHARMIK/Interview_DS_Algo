/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=gpHzIs3xXkU
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/detect-cycles-in-2d-grid
*/



/****************************************************************** C++ ******************************************************************/
//Approach-1 (Using DFS)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    bool cycleDetectDFS(int r, int c, int prev_r, int prev_c, 
                    vector<vector<char>>& grid, vector<vector<bool>>& visited ) {

        if(visited[r][c]) {
            return true;
        }

        visited[r][c] = true;

        //explore neighbours
        for(auto &dir : directions) {
            int new_r = r + dir[0]; 
            int new_c = c + dir[1];

            if(new_r >= 0 && new_r < m && new_c >= 0 && new_c < n
                && grid[new_r][new_c] == grid[r][c]) {
                    if(new_r == prev_r && new_c == prev_c)
                        continue;
                    
                    if(cycleDetectDFS(new_r, new_c, r, c, grid, visited)) {
                        return true;
                    }
                }
        }

        return false;

    }
    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j] && cycleDetectDFS(i, j, i, j, grid, visited)) {
                    return true;
                }
            }
        }

        return false;
    }
};



//Approach-2 (Using BFS)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    bool cycleDetectBFS(int r, int c, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        //r, c, prev_r, prev_c
        queue<tuple<int, int, int, int>> que;

        que.push({r, c, -1, -1});
        visited[r][c] = true;

        while(!que.empty()) {
            auto [curr_r, curr_c, prev_r, prev_c] = que.front();
            que.pop();

            //explore neighbours
            for(auto &dir : directions) {
                int new_r = curr_r + dir[0];
                int new_c = curr_c + dir[1];

                if(new_r >= 0 && new_r < m && new_c >= 0 && new_c < n
                && grid[new_r][new_c] == grid[curr_r][curr_c]) {
                    
                    if(new_r == prev_r && new_c == prev_c)
                        continue;
                    
                    if(visited[new_r][new_c])
                        return true;
                    
                    visited[new_r][new_c] = true;

                    que.push({new_r, new_c, curr_r, curr_c});
                }

            }
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j] && cycleDetectBFS(i, j, grid, visited)) {
                    return true;
                }
            }
        }

        return false;
    }
};



/****************************************************************** JAVA ******************************************************************/
//Approach-1 (Using DFS)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
    int m, n;
    int[][] directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
    public boolean cycleDetectDFS(int r, int c, int prev_r, int prev_c,
                                  char[][] grid, boolean[][] visited) {
        
        if (visited[r][c]) {
            return true;
        }

        visited[r][c] = true;

        for (int[] d : directions) {
            int new_r = r + d[0];
            int new_c = c + d[1];

            if (new_r >= 0 && new_r < m && new_c >= 0 && new_c < n
                && grid[new_r][new_c] == grid[r][c]) {

                if (new_r == prev_r && new_c == prev_c) {
                    continue;
                } else {
                    if (cycleDetectDFS(new_r, new_c, r, c, grid, visited)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }

    public boolean containsCycle(char[][] grid) {
        m = grid.length;
        n = grid[0].length;

        boolean[][] visited = new boolean[m][n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    if (cycleDetectDFS(i, j, i, j, grid, visited)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
}



//Approach-2 (Using BFS)
//T.C : O(m*n)
//S.C : O(m*n)
import java.util.*;

class Solution {
    int m, n;
    int[][] directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
    public boolean cycleDetectBFS(int r, int c, char[][] grid, boolean[][] visited) {
        Queue<int[]> q = new LinkedList<>();
        
        // {r, c, prev_r, prev_c}
        q.offer(new int[]{r, c, -1, -1});
        visited[r][c] = true;

        while (!q.isEmpty()) {
            int[] curr = q.poll();
            int curr_r = curr[0];
            int curr_c = curr[1];
            int prev_r = curr[2];
            int prev_c = curr[3];

            for (int[] d : directions) {
                int new_r = curr_r + d[0];
                int new_c = curr_c + d[1];

                if (new_r >= 0 && new_r < m && new_c >= 0 && new_c < n
                    && grid[new_r][new_c] == grid[curr_r][curr_c]) {

                    if (new_r == prev_r && new_c == prev_c) {
                        continue;
                    }

                    if (visited[new_r][new_c]) {
                        return true;
                    }

                    visited[new_r][new_c] = true;
                    q.offer(new int[]{new_r, new_c, curr_r, curr_c});
                }
            }
        }

        return false;
    }

    public boolean containsCycle(char[][] grid) {
        m = grid.length;
        n = grid[0].length;

        boolean[][] visited = new boolean[m][n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    if (cycleDetectBFS(i, j, grid, visited)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
}
