/*     Scroll below to see JAVA code also     */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=qlgeXDM1z7A
    Company Tags                : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/path-with-maximum-gold/description/
*/


/********************************************************* C++ *************************************************/
//Approach - Using DFS
//T.C : O(m*n * 4^(cells with gold))
//S.C : O(cells with gold) - the length of a path through gold will contribute to the recursive call stack
class Solution {
public:
    int m, n;
    vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int DFS(vector<vector<int>>& grid, int i, int j) {

        if(i >= m || i < 0 || j >= n || j < 0 || grid[i][j] == 0) {
            return 0; //Zero gold
        }

        int originalGoldValue = grid[i][j];
        grid[i][j] = 0;

        int maxGold = 0;

        //up, down, left, right
        for(vector<int>& dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            maxGold = max(maxGold, DFS(grid, new_i, new_j));
        }


        grid[i][j] = originalGoldValue;
        return originalGoldValue + maxGold;


    }

    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int maxGold = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] != 0) {
                    //It has gold
                    maxGold = max(maxGold, DFS(grid, i, j));
                }

            }
        }

        return maxGold;
    }
};


/********************************************************* JAVA *************************************************/
//Approach - Using DFS
//T.C : O(m*n * 4^(cells with gold))
//S.C : O(cells with gold) - the length of a path through gold will contribute to the recursive call stack
class Solution {
    int m, n;
    int[][] directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    
    public int DFS(int[][] grid, int i, int j) {
        if(i >= m || i < 0 || j >= n || j < 0 || grid[i][j] == 0) {
            return 0; //Zero gold
        }

        int originalGoldValue = grid[i][j];
        grid[i][j] = 0;

        int maxGold = 0;

        //up, down, left, right
        for(int[] dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            maxGold = Math.max(maxGold, DFS(grid, new_i, new_j));
        }

        grid[i][j] = originalGoldValue;
        return originalGoldValue + maxGold;
    }

    public int getMaximumGold(int[][] grid) {
        m = grid.length;
        n = grid[0].length;

        int maxGold = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] != 0) {
                    //It has gold
                    maxGold = Math.max(maxGold, DFS(grid, i, j));
                }
            }
        }

        return maxGold;
    }
}
