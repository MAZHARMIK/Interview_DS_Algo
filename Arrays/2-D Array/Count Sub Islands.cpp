/*     Scroll below to see JAVA code also   */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=OeaEOoM-g98
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/count-sub-islands
*/


/******************************************** C++ ********************************************/
//Approach-1 (DFS)
//T.C : O(m*n)
//S.C : O(1) //I am not considering the space taken by System Recursion stack
class Solution {
public:

    //DFS
    bool checkSubIsland(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j) {
        if(i < 0 || i >= grid1.size() || j < 0 || j >= grid1[0].size()) {
            return true;
        }
        
        if(grid2[i][j] != 1) { //we only need land
            return true;
        }

        grid2[i][j] = -1; //mark visited

        bool result = (grid1[i][j] == 1); //grid1[i][j] must have 1

        result = result & checkSubIsland(grid1, grid2, i+1, j); //Down
        result = result & checkSubIsland(grid1, grid2, i-1, j); //Up
        result = result & checkSubIsland(grid1, grid2, i, j+1);  //Right
        result = result & checkSubIsland(grid1, grid2, i, j-1); //Left

        return result;

    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        //DFS
        int subIslands = 0;
        int m = grid2.size(); //rows
        int n = grid2[0].size(); //cols

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid2[i][j] == 1 && checkSubIsland(grid1, grid2, i, j)) { //Found an island
                    subIslands++;
                }
            }
        }

        return subIslands;
    }
};



//Approach-2 (BFS)
//T.C : O(m*n)
//S.C : O(m*n) //Queue
class Solution {
public:

    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; //down, up, right , left

    //BFS
    bool checkSubIsland(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j) {
        int m = grid1.size();
        int n = grid1[0].size();

        bool result = true;

        queue<pair<int, int>> que; //{i, j} //BFS me we use queue
        que.push({i, j});
        grid2[i][j] = -1; //mark visited

        while(!que.empty()) {
            auto [x, y] = que.front();
            que.pop();

            if(grid1[x][y] != 1) { //grid1 must have 1 at that same co-ordinate
                result = false;
            }

            for(vector<int>& dir : directions) {
                int newX = x + dir[0];
                int newY = y + dir[1];

                if(newX >= 0 && newX < m && newY >= 0 && newY < n && grid2[newX][newY] == 1) {
                    grid2[newX][newY] = -1; //mark visited
                    que.push({newX, newY});
                }
            }
        }

        return result;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        //DFS
        int subIslands = 0;
        int m = grid2.size(); //rows
        int n = grid2[0].size(); //cols

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid2[i][j] == 1 && checkSubIsland(grid1, grid2, i, j)) { //Found an island
                    subIslands++;
                }
            }
        }

        return subIslands;
    }
};



/******************************************** JAVA ********************************************/
//Approach-1 (DFS)
//T.C : O(m*n)
//S.C : O(1) //I am not considering the space taken by System Recursion stack
class Solution {

    // DFS
    private boolean checkSubIsland(int[][] grid1, int[][] grid2, int i, int j) {
        if (i < 0 || i >= grid1.length || j < 0 || j >= grid1[0].length) {
            return true;
        }

        if (grid2[i][j] != 1) { // we only need to check land (grid2[i][j] == 1)
            return true;
        }

        grid2[i][j] = -1; // mark visited

        boolean result = (grid1[i][j] == 1); // grid1[i][j] must have 1 to be a sub-island

        // Perform DFS in all four directions (down, up, right, left)
        result = result & checkSubIsland(grid1, grid2, i + 1, j); // Down
        result = result & checkSubIsland(grid1, grid2, i - 1, j); // Up
        result = result & checkSubIsland(grid1, grid2, i, j + 1); // Right
        result = result & checkSubIsland(grid1, grid2, i, j - 1); // Left

        return result;
    }

    public int countSubIslands(int[][] grid1, int[][] grid2) {
        int subIslands = 0;
        int m = grid2.length; // number of rows
        int n = grid2[0].length; // number of columns

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid2[i][j] == 1 && checkSubIsland(grid1, grid2, i, j)) { // Found a sub-island
                    subIslands++;
                }
            }
        }

        return subIslands;
    }
}



//Approach-2 (BFS)
//T.C : O(m*n)
//S.C : O(m*n) //Queue
class Solution {

    private final int[][] directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // down, up, right, left

    // BFS
    private boolean checkSubIsland(int[][] grid1, int[][] grid2, int i, int j) {
        int m = grid1.length;
        int n = grid1[0].length;

        boolean result = true;

        Queue<int[]> queue = new LinkedList<>(); // Queue to perform BFS
        queue.offer(new int[]{i, j});
        grid2[i][j] = -1; // mark visited

        while (!queue.isEmpty()) {
            int[] current = queue.poll();
            int x = current[0];
            int y = current[1];

            if (grid1[x][y] != 1) { // grid1 must have 1 at the same coordinate
                result = false;
            }

            for (int[] dir : directions) {
                int newX = x + dir[0];
                int newY = y + dir[1];

                if (newX >= 0 && newX < m && newY >= 0 && newY < n && grid2[newX][newY] == 1) {
                    grid2[newX][newY] = -1; // mark visited
                    queue.offer(new int[]{newX, newY});
                }
            }
        }

        return result;
    }

    public int countSubIslands(int[][] grid1, int[][] grid2) {
        int subIslands = 0;
        int m = grid2.length; // rows
        int n = grid2[0].length; // cols

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid2[i][j] == 1 && checkSubIsland(grid1, grid2, i, j)) { // Found an island
                    subIslands++;
                }
            }
        }

        return subIslands;
    }
}
