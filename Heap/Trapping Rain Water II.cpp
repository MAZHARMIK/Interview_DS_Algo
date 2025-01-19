/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will soon update
    Leetcode Link               : https://leetcode.com/problems/trapping-rain-water-ii
*/

/************************************************************ C++ ************************************************************/
//Approach (Using Heap - See video for full intuition and thought process)
//T.C : O(m*n log(m*n))
//S.C : O(m*n)
class Solution {
public:
    typedef pair<int, pair<int, int>> PP;
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int trapRainWater(vector<vector<int>>& heightMap) {

        int m = heightMap.size();
        int n = heightMap[0].size();

        priority_queue<PP, vector<PP>, greater<>> boundaryCells;

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int r = 0; r < m; ++r) {
            for (int c : {0, n - 1}) { //0 : left most boundary, cols-1 right most boundary
                boundaryCells.push({heightMap[r][c], {r, c}});
                visited[r][c] = true;
            }
        }

        for (int c = 0; c < n; ++c) {
            for (int r : {0, m - 1}) { //0 : top most boundary, rows-1 bottom most boundary
                boundaryCells.push({heightMap[r][c], {r, c}});
                visited[r][c] = true;
            }
        }

        int trappedWater = 0;

        while (!boundaryCells.empty()) {
            auto [height, cell] = boundaryCells.top();
            boundaryCells.pop();

            int i = cell.first;
            int j = cell.second;

            for (vector<int>& dir : directions) {
                int i_ = i + dir[0];
                int j_ = j + dir[1];


                if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && !visited[i_][j_]) {
                    
                    trappedWater += max(0, height - heightMap[i_][j_]);
                    
                    boundaryCells.push({max(height, heightMap[i_][j_]), {i_, j_}});

                    
                    visited[i_][j_] = true;
                }
            }
        }

        return trappedWater;
    }
};


/************************************************************ JAVA ************************************************************/
//Approach (Using Heap - See video for full intuition and thought process)
//T.C : O(m*n log(m*n))
//S.C : O(m*n)
class Solution {
    public int trapRainWater(int[][] heightMap) {
        int m = heightMap.length;
        int n = heightMap[0].length;

        // Min-heap to store {height, {i, j}}
        PriorityQueue<int[]> boundaryCells = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));

        boolean[][] visited = new boolean[m][n];

        // Add boundary cells (left-most, right-most, top-most, bottom-most)
        for (int row = 0; row < m; row++) {
            boundaryCells.offer(new int[]{heightMap[row][0], row, 0});
            visited[row][0] = true;
            boundaryCells.offer(new int[]{heightMap[row][n - 1], row, n - 1});
            visited[row][n - 1] = true;
        }
        
        for (int col = 0; col < n; col++) {
            boundaryCells.offer(new int[]{heightMap[0][col], 0, col});
            visited[0][col] = true;
            boundaryCells.offer(new int[]{heightMap[m - 1][col], m - 1, col});
            visited[m - 1][col] = true;
        }

        int water = 0;
        // Directions for moving to neighbors (left, right, up, down)
        int[][] directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

        // Process the boundary cells in the min-heap
        while (!boundaryCells.isEmpty()) {
            int[] cell = boundaryCells.poll();
            int height = cell[0];
            int i = cell[1];
            int j = cell[2];

            // Check all 4 neighbors
            for (int[] dir : directions) {
                int i_ = i + dir[0];
                int j_ = j + dir[1];

                if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && !visited[i_][j_]) {
                    water += Math.max(height - heightMap[i_][j_], 0);
                    boundaryCells.offer(new int[]{Math.max(height, heightMap[i_][j_]), i_, j_});
                    visited[i_][j_] = true;
                }
            }
        }

        return water;
    }
}
