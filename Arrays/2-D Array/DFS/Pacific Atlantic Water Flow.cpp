/*           Scroll below to see JAVA code also   */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Amazon, Google
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
    //helping variables
    vector<vector<int>> directions{{1,0}, {-1, 0}, {0, 1}, {0, -1}};
    
    void DFS(vector<vector<int>>& matrix, int i, int j, int prev, vector<vector<bool>>& visited) {
        if(i<0 || i >= matrix.size() || j < 0 || j >= matrix[0].size())
            return;
        
        //Why matrix[i][j] < prev ?
        //Ans : Because we are thinking backwards here, i.e. if one wants to flow toward pacific/atlantic from inwards to outwards
        //Then, outwards value should be smaller or equal to inwards(prev) value (from where we are coming i.e. from matrix[i][j])
        if(matrix[i][j] < prev || visited[i][j])
            return;
        visited[i][j] = true;
        for(auto dir:directions) {
            int ni = i + dir[0];
            int nj = j + dir[1];
            
            DFS(matrix, ni, nj, matrix[i][j], visited);
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if(row == 0)
            return {};
        int col = matrix[0].size();
        vector<vector<int>> result;
        vector<vector<bool>> pacific_visited(row, vector<bool>(col));
        vector<vector<bool>> atlantic_visited(row, vector<bool>(col));
        
        //top row and bottom row
        //top    : pacific
        //bottom : atlantic
        for(int j = 0; j<col; j++) {
            DFS(matrix, 0, j, INT_MIN, pacific_visited); //pacific
            DFS(matrix, row-1, j, INT_MIN, atlantic_visited); //atlantic
        }
        
        //left col and right col
        //left   : pacific
        //right  : atlantic
        for(int i = 0; i<row; i++) {
            DFS(matrix, i, 0, INT_MIN, pacific_visited); //pacific
            DFS(matrix, i, col-1, INT_MIN, atlantic_visited); //atlantic
        }
        
        for(int i = 0; i<row; i++) {
            for(int j = 0; j<col; j++) {
                if(pacific_visited[i][j] && atlantic_visited[i][j])
                    result.push_back({i, j});
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
        
        boolean[][] pacific = new boolean[m][n];
        boolean[][] atlantic = new boolean[m][n];
        
        // Start DFS from Pacific border (top row and left column)
        for (int i = 0; i < m; i++) {
            dfs(heights, pacific, i, 0, Integer.MIN_VALUE);
            dfs(heights, atlantic, i, n - 1, Integer.MIN_VALUE);
        }
        for (int j = 0; j < n; j++) {
            dfs(heights, pacific, 0, j, Integer.MIN_VALUE);
            dfs(heights, atlantic, m - 1, j, Integer.MIN_VALUE);
        }
        
        // Collect cells that can reach both oceans
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
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
