/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid
*/



/****************************************************************** C++ ******************************************************************/
//Approach (Using DFS)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    int m, n;

    unordered_map<int, vector<vector<int>>> directions = {
        {1, {{0, -1}, {0, 1}}},
        {2, {{-1, 0}, {1, 0}}},
        {3, {{0, -1}, {1, 0}}},
        {4, {{0, 1}, {1, 0}}},
        {5, {{0, -1}, {-1, 0}}},
        {6, {{-1, 0}, {0, 1}}}
    };

    bool dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited) {
        if(i == m-1 && j == n-1)
            return true;
        
        visited[i][j] = true;

        for(auto &dir : directions[grid[i][j]]) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if(new_i < 0 || new_i >= m || new_j < 0 || new_j >= n || visited[new_i][new_j])
                continue;
            
            //IMPORTANT = can you come back to i and j from new_i and new_j
            for(auto &backDir : directions[grid[new_i][new_j]]) {
                if(new_i + backDir[0] == i &&
                   new_j + backDir[1] == j) {
                        if(dfs(grid, new_i, new_j, visited)) {
                            return true;
                        }
                   }
            }
        }

        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        //T.C : O(m*n)

        return dfs(grid, 0, 0, visited);
    }
};




/****************************************************************** JAVA ******************************************************************/
//Approach (Using DFS)
//T.C : O(m*n)
//S.C : O(m*n)
import java.util.*;

class Solution {

    int m, n;

    Map<Integer, int[][]> directions = new HashMap<>();

    public Solution() {
        directions.put(1, new int[][]{{0, -1}, {0, 1}});
        directions.put(2, new int[][]{{-1, 0}, {1, 0}});
        directions.put(3, new int[][]{{0, -1}, {1, 0}});
        directions.put(4, new int[][]{{0, 1}, {1, 0}});
        directions.put(5, new int[][]{{0, -1}, {-1, 0}});
        directions.put(6, new int[][]{{-1, 0}, {0, 1}});
    }

    public boolean dfs(int[][] grid, int i, int j, boolean[][] visited) {
        if (i == m - 1 && j == n - 1)
            return true;

        visited[i][j] = true;

        for (int[] dir : directions.get(grid[i][j])) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if (new_i < 0 || new_i >= m || new_j < 0 || new_j >= n || visited[new_i][new_j])
                continue;

            // IMPORTANT: check if we can come back
            for (int[] backDir : directions.get(grid[new_i][new_j])) {
                if (new_i + backDir[0] == i && new_j + backDir[1] == j) {
                    if (dfs(grid, new_i, new_j, visited)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }

    public boolean hasValidPath(int[][] grid) {
        m = grid.length;
        n = grid[0].length;

        boolean[][] visited = new boolean[m][n];

        return dfs(grid, 0, 0, visited);
    }
}
