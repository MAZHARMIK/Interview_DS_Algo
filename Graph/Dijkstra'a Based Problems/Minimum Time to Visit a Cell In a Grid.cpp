/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/minimum-time-to-visit-a-cell-in-a-grid
*/


/************************************************************ C++ ************************************************/
//Approach (Using Dijkstra's Algorothm
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
//Approach (Using Dijkstra's Algorothm
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
