/*    Scroll below to see JAVA code also  */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/find-a-safe-walk-through-a-grid
*/

/**************************************************** C++ *******************************************/
//Appoach-1 Using Dijkstra's
//T.C : O(E · log V) = O(m·n · log(m·n))
//S.C : O(m*n)
class Solution {
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    typedef pair<int, pair<int,int>> P;

public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();

        priority_queue<P, vector<P>, greater<P>> pq;

        vector<vector<int>> result(m, vector<int>(n, INT_MAX));

        result[0][0] = grid[0][0]; //Source = {0, 0}
        pq.push({result[0][0], {0, 0}});

        while (!pq.empty()) {
            auto [d, cell] = pq.top();
            auto [r, c] = cell;
            pq.pop();

            if (d > result[r][c]) continue;

            for (auto &dir : directions) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;

                if (d + grid[nr][nc] < result[nr][nc]) {
                    result[nr][nc] = d + grid[nr][nc];
                    pq.push({d + grid[nr][nc], {nr, nc}});
                }
            }
        }

        return health - result[m-1][n-1] >= 1;
    }
};


//Appoach-2 (Using 0-1 BFS)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        deque<pair<int,int>> dq;

        result[0][0] = grid[0][0]; //source {0, 0}
        dq.push_front({0, 0});

        while (!dq.empty()) {
            auto [r, c] = dq.front();
            dq.pop_front();

            for (auto &dir : directions) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;

                if (result[r][c] + grid[nr][nc] < result[nr][nc]) {

                    result[nr][nc] = result[r][c] + grid[nr][nc];

                    if (grid[nr][nc] == 0) 
                        dq.push_front({nr, nc});
                    else
                        dq.push_back({nr, nc});
                }
            }
        }

        return health - result[m-1][n-1] >= 1;
    }
};



/**************************************************** JAVA *******************************************/
//Appoach-1 Using Dijkstra's
//T.C : O(E · log V) = O(m·n · log(m·n))
//S.C : O(m*n)
class Solution {
    int[][] directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    public boolean findSafeWalk(List<List<Integer>> grid, int health) {
        int m = grid.size(), n = grid.get(0).size();

        // {cost, r, c}, min-heap ordered by cost
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        int[][] result = new int[m][n];
        for (int[] row : result) Arrays.fill(row, Integer.MAX_VALUE);

        result[0][0] = grid.get(0).get(0); //Source = {0, 0}
        pq.offer(new int[]{result[0][0], 0, 0});

        while (!pq.isEmpty()) {
            int[] top = pq.poll();
            int d = top[0], r = top[1], c = top[2];

            if (d > result[r][c]) continue;

            for (int[] dir : directions) {
                int nr = r + dir[0];
                int nc = c + dir[1];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;

                if (d + grid.get(nr).get(nc) < result[nr][nc]) {
                    result[nr][nc] = d + grid.get(nr).get(nc);
                    pq.offer(new int[]{result[nr][nc], nr, nc});
                }
            }
        }

        return health - result[m-1][n-1] >= 1;
    }
}

//Appoach-2 (Using 0-1 BFS)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
    int[][] directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    public boolean findSafeWalk(List<List<Integer>> grid, int health) {
        int m = grid.size(), n = grid.get(0).size();

        int[][] result = new int[m][n];
        for (int[] row : result) Arrays.fill(row, Integer.MAX_VALUE);

        Deque<int[]> dq = new ArrayDeque<>();
        result[0][0] = grid.get(0).get(0); //source {0, 0}
        dq.offerFirst(new int[]{0, 0});

        while (!dq.isEmpty()) {
            int[] cell = dq.pollFirst();
            int r = cell[0], c = cell[1];

            for (int[] dir : directions) {
                int nr = r + dir[0];
                int nc = c + dir[1];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;

                if (result[r][c] + grid.get(nr).get(nc) < result[nr][nc]) {
                    result[nr][nc] = result[r][c] + grid.get(nr).get(nc);
                    if (grid.get(nr).get(nc) == 0)
                        dq.offerFirst(new int[]{nr, nc});
                    else
                        dq.offerLast(new int[]{nr, nc});
                }
            }
        }

        return health - result[m-1][n-1] >= 1;
    }
}
