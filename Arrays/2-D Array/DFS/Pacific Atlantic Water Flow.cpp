/*           Scroll below to see JAVA code also   */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=t0C4MzNf-1o
    Company Tags                : Google
    Leetcode Link               : https://leetcode.com/problems/pacific-atlantic-water-flow/
*/



/*************************************************************** C++ ***************************************************************/
//Approach - 1
/*
    Do a DFS on every cell and if a cell reaches both (pacific and atlantic), mark them as the result
    TIme Complexity : (m*n)*(m*n)
*/

//Approach - 2 (Better DFS)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    void DFS(vector<vector<int>>& heights, int i, int j, int prevCellVal, vector<vector<bool>>& visited) {
        if(i < 0 || i >= heights.size() || j < 0 || j >= heights[0].size()) { //invalid cell
            return;
        }

        if(heights[i][j] < prevCellVal || visited[i][j])
            return;

        visited[i][j] = true;
        for(auto &dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            DFS(heights, i_, j_, heights[i][j], visited);
        }

    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(); //rows
        int n = heights[0].size(); //cols

        vector<vector<int>> result;

        vector<vector<bool>> pacificVisited(m, vector<bool>(n, false)); //pacificVisited[i][j] = true, means [i][j] water can go to Pacific //m*n
        vector<vector<bool>> atlanticVisited(m, vector<bool>(n, false)); //atlanticVisited[i][j] = true, means [i][j] water can go to atlantic //m*n
        //T.C : O(m*n)
        //S.C : O(m*n)


        //Top Row and Bottom Row
        //Top Row : Pacific connected already
        //Bottom Row : atlantic connected already

        for(int j = 0; j < n; j++) {
            DFS(heights, 0, j, INT_MIN, pacificVisited); //Top Row
            DFS(heights, m-1, j, INT_MIN, atlanticVisited); //Top Row
        }

        //First col and last column
        //First col : Pacific connected already
        //Last col : atlantic connected already
        for(int i = 0; i < m; i++) {
            DFS(heights, i, 0, INT_MIN, pacificVisited); //First column
            DFS(heights, i, n-1, INT_MIN, atlanticVisited); //Last Column
        }


        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(pacificVisited[i][j] && atlanticVisited[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};



/*************************************************************** JAVA ***************************************************************/
//Approach - 1
/*
    Do a DFS on every cell and if a cell reaches both (pacific and atlantic), mark them as the result
    TIme Complexity : (m*n)*(m*n)
*/

//Approach - 2 (Better DFS)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
    // Directions for moving up, down, left, right
    private final int[][] directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        List<List<Integer>> result = new ArrayList<>();
        if (heights == null || heights.length == 0 || heights[0].length == 0) {
            return result;
        }
        
        int m = heights.length;
        int n = heights[0].length;
        
        boolean[][] pacificVisited = new boolean[m][n];
        boolean[][] atlanticVisited = new boolean[m][n];
        
        // Start DFS from pacificVisited border (top row and left column)
        for (int i = 0; i < m; i++) {
            dfs(heights, pacificVisited, i, 0, Integer.MIN_VALUE);
            dfs(heights, atlanticVisited, i, n - 1, Integer.MIN_VALUE);
        }
        for (int j = 0; j < n; j++) {
            dfs(heights, pacificVisited, 0, j, Integer.MIN_VALUE);
            dfs(heights, atlanticVisited, m - 1, j, Integer.MIN_VALUE);
        }
        
        // Collect cells that can reach both oceans
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacificVisited[i][j] && atlanticVisited[i][j]) {
                    result.add(Arrays.asList(i, j));
                }
            }
        }
        
        return result;
    }

    private void dfs(int[][] heights, boolean[][] visited, int i, int j, int prevHeight) {
        int m = heights.length;
        int n = heights[0].length;
        
        // Out of bounds or already visited or not valid move
        if (i < 0 || i >= m || j < 0 || j >= n 
            || visited[i][j] || heights[i][j] < prevHeight) {
            return;
        }
        
        visited[i][j] = true;
        
        // Explore 4 directions
        for (int[] dir : directions) {
            int ni = i + dir[0];
            int nj = j + dir[1];
            dfs(heights, visited, ni, nj, heights[i][j]);
        }
    }
}
