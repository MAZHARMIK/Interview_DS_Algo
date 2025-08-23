/*     Scroll below to see JAVA code also   */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=DCGX28SMch4
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-ii
*/


/************************************************** C++ **************************************************/
//Approach (Trying all possible splits and rotating grid to cover other posisble splits as well)
//T.C : O(m^2 * n^2)
//S.C : O(m*n) for rotated matrix
class Solution {
public:

    vector<vector<int>> rotateClockWise(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> rotatedGrid(n, vector<int>(m));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                rotatedGrid[j][m-i-1] = grid[i][j];
            }
        }

        return rotatedGrid;
    }

    int minimumArea(int startRow, int endRow, int startCol, int endCol, vector<vector<int>>& grid) {
        int m = grid.size(); //Rows
        int n = grid[0].size(); //Columns

        int minRow = m;
        int maxRow = -1;
        int minCol = n;
        int maxCol = -1;

        for(int i = startRow; i < endRow; i++) {
            for(int j = startCol; j < endCol; j++) {
                if(grid[i][j] == 1) {
                    minRow = min(minRow, i);
                    maxRow = max(maxRow, i);

                    minCol = min(minCol, j);
                    maxCol = max(maxCol, j);
                }       
            }
        }
        return (maxRow - minRow + 1) * (maxCol - minCol + 1);
    }

    //O(m^2 * n^2)
    int utility(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int result = INT_MAX;

        for(int rowSplit = 1; rowSplit < m; rowSplit++) {
            for(int colSplit = 1; colSplit < n; colSplit++) {

                int top = minimumArea(0, rowSplit, 0, n, grid);
                int bottomLeft = minimumArea(rowSplit, m, 0, colSplit, grid);
                int bottomRight = minimumArea(rowSplit, m, colSplit, n, grid);

                result = min(result, top + bottomLeft + bottomRight);


                int topLeft = minimumArea(0, rowSplit, 0, colSplit, grid);
                int topRight = minimumArea(0, rowSplit, colSplit, n, grid);
                int bottom = minimumArea(rowSplit, m, 0, n, grid);

                result = min(result, topLeft + topRight + bottom);

            }
        }

        for(int split1 = 1; split1 < m; split1++) {
            for(int split2 = split1+1; split2 < m; split2++) {
                int top = minimumArea(0, split1, 0, n, grid);
                int middle = minimumArea(split1, split2, 0, n, grid);
                int bottom = minimumArea(split2, m, 0, n, grid);

                result = min(result, top + middle + bottom);
            }
        }
        return result;
    }

    int minimumSum(vector<vector<int>>& grid) {
        
        int result = utility(grid);

        vector<vector<int>> rotatedGrid = rotateClockWise(grid);

        result = min(result, utility(rotatedGrid));

        return result;

    }
};



/************************************************** JAVA **************************************************/
//Approach (Trying all possible splits and rotating grid to cover other posisble splits as well)
//T.C : O(m^2 * n^2)
//S.C : O(m*n) for rotated matrix
class Solution {

    private int[][] rotateClockWise(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[][] rotatedGrid = new int[n][m];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rotatedGrid[j][m - i - 1] = grid[i][j];
            }
        }
        return rotatedGrid;
    }

    private int minimumArea(int startRow, int endRow, int startCol, int endCol, int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;

        int minRow = m, maxRow = -1, minCol = n, maxCol = -1;

        for (int i = startRow; i < endRow; i++) {
            for (int j = startCol; j < endCol; j++) {
                if (grid[i][j] == 1) {
                    minRow = Math.min(minRow, i);
                    maxRow = Math.max(maxRow, i);
                    minCol = Math.min(minCol, j);
                    maxCol = Math.max(maxCol, j);
                }
            }
        }

        if (maxRow == -1) return 0; // no 1s in this subgrid
        return (maxRow - minRow + 1) * (maxCol - minCol + 1);
    }

    private int utility(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int result = Integer.MAX_VALUE;

        // Case 1: top + bottomLeft + bottomRight
        for (int rowSplit = 1; rowSplit < m; rowSplit++) {
            for (int colSplit = 1; colSplit < n; colSplit++) {
                int top = minimumArea(0, rowSplit, 0, n, grid);
                int bottomLeft = minimumArea(rowSplit, m, 0, colSplit, grid);
                int bottomRight = minimumArea(rowSplit, m, colSplit, n, grid);

                result = Math.min(result, top + bottomLeft + bottomRight);
            }
        }

        // Case 2: topLeft + topRight + bottom
        for (int rowSplit = 1; rowSplit < m; rowSplit++) {
            for (int colSplit = 1; colSplit < n; colSplit++) {
                int topLeft = minimumArea(0, rowSplit, 0, colSplit, grid);
                int topRight = minimumArea(0, rowSplit, colSplit, n, grid);
                int bottom = minimumArea(rowSplit, m, 0, n, grid);

                result = Math.min(result, topLeft + topRight + bottom);
            }
        }

        // Case 3: top + middle + bottom
        for (int split1 = 1; split1 < m; split1++) {
            for (int split2 = split1 + 1; split2 < m; split2++) {
                int top = minimumArea(0, split1, 0, n, grid);
                int middle = minimumArea(split1, split2, 0, n, grid);
                int bottom = minimumArea(split2, m, 0, n, grid);

                result = Math.min(result, top + middle + bottom);
            }
        }

        return result;
    }

    public int minimumSum(int[][] grid) {
        int result = utility(grid);
        int[][] rotatedGrid = rotateClockWise(grid);
        result = Math.min(result, utility(rotatedGrid));
        return result;
    }
}
