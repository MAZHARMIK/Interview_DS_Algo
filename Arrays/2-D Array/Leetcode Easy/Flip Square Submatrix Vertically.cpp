/*     Scroll below to see JAVA code also   */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=0OKMEALVx6w
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/flip-square-submatrix-vertically
*/


/******************************************** C++ ********************************************/
//Approach - (Simulation)
//T.C : O(k^2)
//S.C : O(1)
class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        
        int startRow = x;
        int endRow = x+k-1;

        int startCol = y;
        int endCol = y+k-1;

        for(int i = startRow; i <= endRow; i++) {
            for(int j = startCol; j <= endCol; j++) {
                swap(grid[i][j], grid[endRow][j]);
            }
            endRow--;
        }

        return grid;
    }
};



/******************************************** JAVA ********************************************/
//Approach - (Simulation)
//T.C : O(k^2)
//S.C : O(1)
class Solution {
    public int[][] reverseSubmatrix(int[][] grid, int x, int y, int k) {
        int startRow = x;
        int endRow = x + k - 1;

        int startCol = y;
        int endCol = y + k - 1;

        while (startRow < endRow) { //You can use while loop as well which is cleaner that for loop above in C++ code
            for (int j = startCol; j <= endCol; j++) {
                int temp = grid[startRow][j];
                grid[startRow][j] = grid[endRow][j];
                grid[endRow][j] = temp;
            }
            startRow++;
            endRow--;
        }

        return grid;
    }
}
