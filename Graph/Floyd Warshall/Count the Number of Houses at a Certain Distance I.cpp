/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Uhy8lnno7hE
    Company Tags                : will soon update
    Leetcode Link               : https://leetcode.com/problems/count-the-number-of-houses-at-a-certain-distance-i/
*/


/**************************************************************** C++ ****************************************************************/
//T.C : O(n^3)
//S.C : O(n^2)
class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<vector<int>> grid(n+1, vector<int>(n+1, 100000));
        
        for(int j = 1; j < n; j++) {
            grid[j][j+1] = 1;
            grid[j+1][j] = 1;
        }
        grid[x][y] = 1;
        grid[y][x] = 1;
        
        for(int via = 1; via <= n; via++) {
            
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= n; j++) {
                    
                   grid[i][j] = min(grid[i][j], grid[i][via] + grid[via][j]);
                    
                }
            }
        }
        
        vector<int> result(n);
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {

                if(i != j) {
                    int val = grid[i][j];
                    result[val-1]++;
                }

            }
        }
        
        return result;
        
    }
};

/**************************************************************** JAVA ****************************************************************/
//T.C : O(n^3)
//S.C : O(n^2)
public class Solution {
    public int[] countOfPairs(int n, int x, int y) {
        int[][] grid = new int[n + 1][n + 1];

        for (int[] row : grid) {
            Arrays.fill(row, 100000);
        }

        for (int j = 1; j < n; j++) {
            grid[j][j + 1] = 1;
            grid[j + 1][j] = 1;
        }
        grid[x][y] = 1;
        grid[y][x] = 1;

        for (int via = 1; via <= n; via++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    grid[i][j] = Math.min(grid[i][j], grid[i][via] + grid[via][j]);
                }
            }
        }

        int[] result = new int[n];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i != j) {
                    int val = grid[i][j];
                    result[val - 1]++;
                }
            }
        }

        return result;
    }
}
