/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=lcFhMgpRPlc
    Company Tags                : will soon update
    Leetcode Link               : https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column
*/


/********************************************************************************* C++ *********************************************************************************/
//Approach - Keep count of ones and zeros in row/col
//T.C : O(m*n)
//S.C : O(m+n) -> Not considering the result space
class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<int> rowOnes(m, 0);
        vector<int> colOnes(n, 0);
        
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                
                if(grid[i][j] == 1) {
                    rowOnes[i]++;
                    colOnes[j]++;
                } 
            }
        }
        
        vector<vector<int>> diff(m, vector<int>(n, 0));
        
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                int onesRowi = rowOnes[i];
                int onesColj = colOnes[j];
                
                int zerosRowi = n-onesRowi;
                int zerosColj = m-onesColj;
                
                diff[i][j] = onesRowi + onesColj - zerosRowi - zerosColj;
            }
        }
        
        return diff;
    }
};


/********************************************************************************* JAVA *********************************************************************************/
//Approach - Keep count of ones and zeros in row/col
//T.C : O(m*n)
//S.C : O(m+n) -> Not considering the result space
class Solution {
    public int[][] onesMinusZeros(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;

        int[] rowOnes = new int[m];
        int[] colOnes = new int[n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    rowOnes[i]++;
                    colOnes[j]++;
                }
            }
        }

        int[][] diff = new int[m][n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int onesRowi = rowOnes[i];
                int onesColj = colOnes[j];

                int zerosRowi = n - onesRowi;
                int zerosColj = m - onesColj;

                diff[i][j] = onesRowi + onesColj - zerosRowi - zerosColj;
            }
        }

        return diff;
    }
}
