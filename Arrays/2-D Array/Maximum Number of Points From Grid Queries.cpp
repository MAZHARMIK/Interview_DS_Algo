/*     Scroll below to see JAVA code also   */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=XBd9vO4N0Js
    Company Tags                : Will update later
    Leetcode Link               : https://leetcode.com/problems/maximum-number-of-points-from-grid-queries/
*/


/************************************************** C++ **************************************************/
//Approach-1 (Using BFS) - TLE
//T.C : O(Q * m * n)
//S.C : O(m * n)
class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int bfs(vector<vector<int>>& grid, int val, int m, int n) {
        queue<pair<int, int>> que;
        que.push({0, 0});

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[0][0] = true;

        int points = 0;
        while(!que.empty()) {
            int N = que.size();

            while(N--) {
                auto [i, j] = que.front();
                que.pop();

                if(grid[i][j] > val) {
                    continue;
                }

                points++;

                for(auto &dir : directions) {
                    int i_ = i + dir[0];
                    int j_ = j + dir[1];

                    if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && !visited[i_][j_] && grid[i_][j_] < val) {
                        que.push({i_, j_});
                        visited[i_][j_] = true;
                    }
                }
            }
        }

        return points;
    }
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size();
        int n = grid[0].size();

        int Q = queries.size();
        vector<int> result(Q, 0);
        for(int i = 0; i < Q; i++) {
            result[i] = bfs(grid, queries[i], m, n);
        }

        return result;
    }
};


//Approach-2 (Using DFS) - TLE
//T.C : O(Q * m * n)
//S.C : O(m * n)
class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int dfs(vector<vector<int>>& grid, int i, int j, int val, vector<vector<bool>>& visited, int m, int n) {
        if(i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || grid[i][j] >= val) {
            return 0;
        }

        visited[i][j] = true;
        int points = 1;

        for(auto &dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            points += dfs(grid, i_, j_, val, visited, m, n);
        }

        return points;
    }

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size();
        int n = grid[0].size();

        int Q = queries.size();
        vector<int> result(Q, 0);
        for(int i = 0; i < Q; i++) {
            vector<vector<bool>> visited(m, vector<bool>(n, false));
            result[i] = dfs(grid, 0, 0, queries[i], visited, m, n);
        }

        return result;
    }
};


//Approach-3 (Optimal Approach using sorting and min-heap)
//T.C : O(QlogQ + m*nlog(m*n)) - Notice that we won't visit any cell more than once. Total cells = m*n and heap can have m*n cells in worst case
//S.C : O(m*n)
class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size();
        int n = grid[0].size();

        int Q = queries.size();
        vector<int> result(Q, 0);

        vector<pair<int, int>> sortedQ;
        for(int i = 0; i < Q; i++) {
            sortedQ.push_back({queries[i], i});
        }

        sort(begin(sortedQ), end(sortedQ));

        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int points = 0;
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;


        for(int i = 0; i < Q; i++) {
            int queryValue = sortedQ[i].first;
            int idx        = sortedQ[i].second;
            while(!pq.empty() && pq.top()[0] < queryValue) {
                int i = pq.top()[1];
                int j = pq.top()[2];
                pq.pop();
                points++;

                for(auto &dir : directions) {
                    int i_ = i + dir[0];
                    int j_ = j + dir[1];
                    if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && !visited[i_][j_]) {
                        pq.push({grid[i_][j_], i_, j_});
                        visited[i_][j_] = true;
                    }
                }
            }
            result[idx] = points;
        }
        
        return result;
    }
};



/************************************************** JAVA **************************************************/
//Approach-1 (Using BFS) - TLE
//T.C : O(Q * m * n)
//S.C : O(m * n)
class SolutionBFS {
    int[][] directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int bfs(int[][] grid, int val, int m, int n) {
        Queue<int[]> que = new LinkedList<>();
        que.offer(new int[]{0, 0});

        boolean[][] visited = new boolean[m][n];
        visited[0][0] = true;

        int points = 0;
        while (!que.isEmpty()) {
            int N = que.size();

            while (N-- > 0) {
                int[] curr = que.poll();
                int i = curr[0], j = curr[1];

                if (grid[i][j] > val) {
                    continue;
                }

                points++;

                for (int[] dir : directions) {
                    int i_ = i + dir[0];
                    int j_ = j + dir[1];

                    if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && !visited[i_][j_] && grid[i_][j_] < val) {
                        que.offer(new int[]{i_, j_});
                        visited[i_][j_] = true;
                    }
                }
            }
        }

        return points;
    }

    public int[] maxPoints(int[][] grid, int[] queries) {
        int m = grid.length;
        int n = grid[0].length;

        int Q = queries.length;
        int[] result = new int[Q];

        for (int i = 0; i < Q; i++) {
            result[i] = bfs(grid, queries[i], m, n);
        }

        return result;
    }
}

// Approach-2 (Using DFS) - TLE
// T.C : O(Q * m * n)
// S.C : O(m * n)
class SolutionDFS {
    int[][] directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int dfs(int[][] grid, int i, int j, int val, boolean[][] visited, int m, int n) {
        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || grid[i][j] >= val) {
            return 0;
        }

        visited[i][j] = true;
        int points = 1;

        for (int[] dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            points += dfs(grid, i_, j_, val, visited, m, n);
        }

        return points;
    }

    public int[] maxPoints(int[][] grid, int[] queries) {
        int m = grid.length;
        int n = grid[0].length;

        int Q = queries.length;
        int[] result = new int[Q];

        for (int i = 0; i < Q; i++) {
            boolean[][] visited = new boolean[m][n];
            result[i] = dfs(grid, 0, 0, queries[i], visited, m, n);
        }

        return result;
    }
}


// Approach-3 (Optimal Approach using sorting and min-heap)
// T.C : O(QlogQ + m*nlog(m*n))
// S.C : O(m*n)
class SolutionOptimal {
    int[][] directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    public int[] maxPoints(int[][] grid, int[] queries) {
        int m = grid.length;
        int n = grid[0].length;
        int Q = queries.length;
        int[] result = new int[Q];

        int[][] sortedQ = new int[Q][2];
        for (int i = 0; i < Q; i++) {
            sortedQ[i][0] = queries[i];
            sortedQ[i][1] = i;
        }
        Arrays.sort(sortedQ, Comparator.comparingInt(a -> a[0]));

        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        boolean[][] visited = new boolean[m][n];
        int points = 0;

        pq.offer(new int[]{grid[0][0], 0, 0});
        visited[0][0] = true;

        for (int i = 0; i < Q; i++) {
            int queryValue = sortedQ[i][0];
            int idx = sortedQ[i][1];

            while (!pq.isEmpty() && pq.peek()[0] < queryValue) {
                int[] top = pq.poll();
                int x = top[1], y = top[2];
                points++;

                for (int[] dir : directions) {
                    int i_ = x + dir[0];
                    int j_ = y + dir[1];
                    if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && !visited[i_][j_]) {
                        pq.offer(new int[]{grid[i_][j_], i_, j_});
                        visited[i_][j_] = true;
                    }
                }
            }
            result[idx] = points;
        }

        return result;
    }
}
