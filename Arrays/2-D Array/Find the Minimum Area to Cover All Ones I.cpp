/*     Scroll below to see JAVA code also   */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=fE0x8ZlyG_w
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-i
*/


/************************************************** C++ **************************************************/
//Approach (Just find the minRow, maxRow, minCol and maxCol where we see 1)
//T.C : O(m * m)
//S.C : O(1)
class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size(); //Rows
        int n = grid[0].size(); //Columns

        int minRow = m;
        int maxRow = -1;
        int minCol = n;
        int maxCol = -1;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
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
};



/************************************************** C++ **************************************************/
//Approach (Just find the minRow, maxRow, minCol and maxCol where we see 1)
//T.C : O(m * m)
//S.C : O(1)
class Solution {
    public int minimumArea(int[][] grid) {
        int m = grid.length;          // Rows
        int n = grid[0].length;       // Columns

        int minRow = m;
        int maxRow = -1;
        int minCol = n;
        int maxCol = -1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    minRow = Math.min(minRow, i);
                    maxRow = Math.max(maxRow, i);

                    minCol = Math.min(minCol, j);
                    maxCol = Math.max(maxCol, j);
                }
            }
        }

        return (maxRow - minRow + 1) * (maxCol - minCol + 1);
    }
}
