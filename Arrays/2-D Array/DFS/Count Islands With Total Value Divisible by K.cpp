/*           Scroll below to see JAVA code also   */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=xAMQP-em79w
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/count-islands-with-total-value-divisible-by-k/
*/

/******************************************** C++ ********************************************/
//Approach-1 (Simple DFS)
//T.C : O(m*n)
//S.C : O(1)
class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    long long dfs(int i, int j, vector<vector<int>>& grid) {
        long long sum = grid[i][j];
        grid[i][j] = 0;

        for(vector<int>& dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && grid[i_][j_] > 0) {
                sum += dfs(i_, j_, grid);
            }
        }

        return sum;
    }

    long long bfs() {
        //queue
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        int count=  0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] > 0) {
                    long long sum = dfs(i, j, grid);
                    if(sum % k == 0)
                        count++;
                }
            }
        }

        return count;
    }
};




//Approach-2 (Simple BFS)
//T.C : O(m*n)
//S.C : O(1)
class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    long long bfs(int i, int j, vector<vector<int>>& grid) {
        long long sum = grid[i][j];
        grid[i][j] = 0;

        queue<pair<int, int>> que;
        que.push({i, j});

        while (!que.empty()) {
            auto [r, c] = que.front();
            que.pop();

            for (vector<int>& dir : directions) {
                int i_ = r + dir[0];
                int j_ = c + dir[1];

                if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && grid[i_][j_] > 0) {
                    sum += grid[i_][j_];
                    grid[i_][j_] = 0;
                    que.push({i_, j_});
                }
            }
        }

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    long long sum = bfs(i, j, grid);
                    if (sum % k == 0)
                        count++;
                }
            }
        }

        return count;
    }
};



/******************************************** JAVA ********************************************/
//Approach-1 (Simple DFS)
//T.C : O(m*n)
//S.C : O(1)
class Solution {
    int m, n;
    int[][] directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    long dfs(int i, int j, int[][] grid) {
        long sum = grid[i][j];
        grid[i][j] = 0;

        for (int[] dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && grid[i_][j_] > 0) {
                sum += dfs(i_, j_, grid);
            }
        }

        return sum;
    }

    // Placeholder from your C++ code, filled in. Not called below.
    long bfs(int si, int sj, int[][] grid) {
        long sum = grid[si][sj];
        grid[si][sj] = 0;

        Queue<int[]> queue = new ArrayDeque<>();
        queue.offer(new int[]{si, sj});

        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            for (int[] dir : directions) {
                int i_ = cur[0] + dir[0];
                int j_ = cur[1] + dir[1];

                if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && grid[i_][j_] > 0) {
                    sum += grid[i_][j_];
                    grid[i_][j_] = 0;
                    queue.offer(new int[]{i_, j_});
                }
            }
        }

        return sum;
    }

    public int countIslands(int[][] grid, int k) {
        m = grid.length;
        n = grid[0].length;

        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    long sum = dfs(i, j, grid);
                    if (sum % k == 0)
                        count++;
                }
            }
        }

        return count;
    }
}


//Approach-2 (Simple BFS)
//T.C : O(m*n)
//S.C : O(1)
import java.util.*;

class Solution {
    int m, n;
    int[][] directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    long bfs(int i, int j, int[][] grid) {
        long sum = grid[i][j];
        grid[i][j] = 0;

        Queue<int[]> que = new ArrayDeque<>();
        que.offer(new int[]{i, j});

        while (!que.isEmpty()) {
            int[] cur = que.poll();
            for (int[] dir : directions) {
                int i_ = cur[0] + dir[0];
                int j_ = cur[1] + dir[1];

                if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && grid[i_][j_] > 0) {
                    sum += grid[i_][j_];
                    grid[i_][j_] = 0;
                    que.offer(new int[]{i_, j_});
                }
            }
        }

        return sum;
    }

    public int countIslands(int[][] grid, int k) {
        m = grid.length;
        n = grid[0].length;

        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    long sum = bfs(i, j, grid);
                    if (sum % k == 0)
                        count++;
                }
            }
        }

        return count;
    }
}
