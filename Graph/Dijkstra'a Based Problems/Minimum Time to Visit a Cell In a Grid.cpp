/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=2H9CVEmmMUM
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/minimum-time-to-visit-a-cell-in-a-grid
*/


/************************************************************ C++ ************************************************/
//Approach-1 (Using Dijkstra's Algorothm) - STORING RESULT IN 2D Matrix
//T.C : O(m*n log(m*n))
//S.C : O(m*n)
class Solution {
public:
    vector<vector<int>> direction{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    #define P pair<int, pair<int, int>>

    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if (grid[0][1] > 1 && grid[1][0] > 1)
            return -1;
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        priority_queue<P, vector<P>, greater<P>> pq;
        
        pq.push({grid[0][0], {0, 0}}); // Start at top-left corner
        result[0][0] = 0;
        while (!pq.empty()) {
            // Get the current time, row, and column
            int time = pq.top().first;
            int row  = pq.top().second.first;
            int col  = pq.top().second.second;
            pq.pop();
            
            // Reached destination
            if (row == m - 1 && col == n - 1)
                return result[m-1][n-1];
            
            // Mark the current cell as visited
            if (visited[row][col]) continue;
            visited[row][col] = true;
            
            // Explore the neighboring cells
            for (auto dir: direction) {
                int r = row + dir[0];
                int c = col + dir[1];
                if (r < 0 || r >= m || c < 0 || c >= n || visited[r][c])
                    continue;
                
                if (grid[r][c] <= time+1) {
                    pq.push({time+1, {r, c}});
                    result[r][c] = time+1;
                } else if ((grid[r][c]-time)%2==0) {
                    pq.push({grid[r][c]+1, {r, c}});
                    result[r][c] = grid[r][c]+1;
                } else {
                    pq.push({grid[r][c], {r, c}});
                    result[r][c] = grid[r][c];
                }
            }
        }
        return -1;
    }
};

//Approach-2 (Using Dijkstra's Algorothm) - Without Storing result in a 2D Matrix
//T.C : O(m*n log(m*n))
//S.C : O(m*n)
class Solution {
public:
    vector<vector<int>> direction{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    #define P pair<int, pair<int, int>>

    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if (grid[0][1] > 1 && grid[1][0] > 1)
            return -1;
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<P, vector<P>, greater<P>> pq;
        
        pq.push({grid[0][0], {0, 0}}); // Start at top-left corner
        while (!pq.empty()) {
            // Get the current time, row, and column
            int time = pq.top().first;
            int row  = pq.top().second.first;
            int col  = pq.top().second.second;
            pq.pop();
            
            // Reached destination
            if (row == m - 1 && col == n - 1)
                return time;
            
            // Mark the current cell as visited
            if (visited[row][col]) continue;
            visited[row][col] = true;
            
            // Explore the neighboring cells
            for (auto dir: direction) {
                int r = row + dir[0];
                int c = col + dir[1];
                if (r < 0 || r >= m || c < 0 || c >= n || visited[r][c])
                    continue;
                
                if (grid[r][c] <= time+1)
                    pq.push({time+1, {r, c}});
                else if ((grid[r][c]-time)%2==0)
                    pq.push({grid[r][c]+1, {r, c}});
                else
                    pq.push({grid[r][c], {r, c}});
            }
        }
        return -1;
    }
};


/************************************************************ JAVA ***************************************************/
//Approach-1 (Using Dijkstra's Algorothm) - STORING RESULT IN 2D Matrix
//T.C : O(m*n log(m*n))
//S.C : O(m*n)
class Solution {
    private static final int[][] directions = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

    public int minimumTime(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;

        // If both initial moves require more than 1 second, return -1
        if (grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }

        boolean[][] visited = new boolean[m][n];
        int[][] result = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result[i][j] = Integer.MAX_VALUE;
            }
        }

        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> Integer.compare(a[0], b[0]));
        pq.offer(new int[] { grid[0][0], 0, 0 });
        result[0][0] = 0;

        while (!pq.isEmpty()) {
            int[] curr = pq.poll();
            int time = curr[0], row = curr[1], col = curr[2];

            // Reached destination
            if (row == m - 1 && col == n - 1) {
                return result[m - 1][n - 1];
            }

            if (visited[row][col]) continue;
            visited[row][col] = true;

            for (int[] dir : directions) {
                int r = row + dir[0];
                int c = col + dir[1];

                if (r < 0 || r >= m || c < 0 || c >= n || visited[r][c]) {
                    continue;
                }

                int nextTime;
                if (grid[r][c] <= time + 1) {
                    nextTime = time + 1;
                } else if ((grid[r][c] - time) % 2 == 0) {
                    nextTime = grid[r][c] + 1;
                } else {
                    nextTime = grid[r][c];
                }

                if (nextTime < result[r][c]) {
                    result[r][c] = nextTime;
                    pq.offer(new int[] { nextTime, r, c });
                }
            }
        }

        return -1;
    }
}


//Approach-2 (Using Dijkstra's Algorothm) - Without Storing result in a 2D Matrix
//T.C : O(m*n log(m*n))
//S.C : O(m*n)
class Solution {
    private final int[][] direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    public int minimumTime(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;

        // If the immediate neighbors of the start point are both inaccessible, return -1
        if (grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }

        boolean[][] visited = new boolean[m][n];
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> Integer.compare(a[0], b[0]));

        // Start at the top-left corner with time grid[0][0]
        pq.add(new int[]{grid[0][0], 0, 0});

        while (!pq.isEmpty()) {
            int[] curr = pq.poll();
            int time = curr[0];
            int row = curr[1];
            int col = curr[2];

            // Reached destination
            if (row == m - 1 && col == n - 1) {
                return time;
            }

            // Skip if cell already visited
            if (visited[row][col]) continue;
            visited[row][col] = true;

            // Explore the neighboring cells
            for (int[] dir : direction) {
                int r = row + dir[0];
                int c = col + dir[1];

                if (r < 0 || r >= m || c < 0 || c >= n || visited[r][c]) {
                    continue;
                }

                if (grid[r][c] <= time + 1) {
                    pq.add(new int[]{time + 1, r, c});
                } else if ((grid[r][c] - time) % 2 == 0) {
                    pq.add(new int[]{grid[r][c] + 1, r, c});
                } else {
                    pq.add(new int[]{grid[r][c], r, c});
                }
            }
        }
        return -1;
    }
}
