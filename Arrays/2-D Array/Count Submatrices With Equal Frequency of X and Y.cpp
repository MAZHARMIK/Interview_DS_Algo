/*     Scroll below to see JAVA code also   */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=YEF2r0XEpTo
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/count-submatrices-with-equal-frequency-of-x-and-y
    Same as Leetcode 3070       : https://www.youtube.com/watch?v=sWNfDG1kyrA
*/


/************************************************** C++ **************************************************/
//Approach (Using Same Cumulative Sum of Submatrices Concept we used in Leetcode 3070)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> cumSumX(m, vector<int>(n, 0));
        vector<vector<int>> cumSumY(m, vector<int>(n, 0));

        int count = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                cumSumX[i][j] = (grid[i][j] == 'X');
                cumSumY[i][j] = (grid[i][j] == 'Y');

                if(i-1 >= 0) {
                    cumSumX[i][j] += cumSumX[i-1][j];
                    cumSumY[i][j] += cumSumY[i-1][j];
                }

                if(j-1 >= 0) {
                    cumSumX[i][j] += cumSumX[i][j-1];
                    cumSumY[i][j] += cumSumY[i][j-1];
                }

                if(i-1 >= 0 && j-1 >= 0) {
                    cumSumX[i][j] -= cumSumX[i-1][j-1];
                    cumSumY[i][j] -= cumSumY[i-1][j-1];
                }
                
                if(cumSumX[i][j] == cumSumY[i][j] && cumSumX[i][j] > 0) {
                    count++;
                }
                

            }
        }

        return count;
    }
};




/************************************************** JAVA **************************************************/
//Approach (Using Same Cumulative Sum of Submatrices Concept we used in Leetcode 3070)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
    public int numberOfSubmatrices(char[][] grid) {
        int m = grid.length;
        int n = grid[0].length;

        int[][] cumSumX = new int[m][n];
        int[][] cumSumY = new int[m][n];

        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                cumSumX[i][j] = (grid[i][j] == 'X') ? 1 : 0;
                cumSumY[i][j] = (grid[i][j] == 'Y') ? 1 : 0;

                if (i - 1 >= 0) {
                    cumSumX[i][j] += cumSumX[i - 1][j];
                    cumSumY[i][j] += cumSumY[i - 1][j];
                }

                if (j - 1 >= 0) {
                    cumSumX[i][j] += cumSumX[i][j - 1];
                    cumSumY[i][j] += cumSumY[i][j - 1];
                }

                if (i - 1 >= 0 && j - 1 >= 0) {
                    cumSumX[i][j] -= cumSumX[i - 1][j - 1];
                    cumSumY[i][j] -= cumSumY[i - 1][j - 1];
                }

                if (cumSumX[i][j] == cumSumY[i][j] && cumSumX[i][j] > 0) {
                    count++;
                }
            }
        }

        return count;
    }
}
