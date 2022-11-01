/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=ElWwrlPe0qc
    Company Tags                : Amazon
    Leetcode Link               : https://leetcode.com/problems/where-will-the-ball-fall/
*/

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();    //rows
        int n = grid[0].size(); //columns
        vector<int> result;
        
        for(int ball = 0; ball<n; ball++) {
            
            int row = 0;
            int col = ball;
            bool reached = true;
            while(row < m && col < n) {
                if(grid[row][col] == 1) {
                    if(col==n-1 || grid[row][col+1] == -1) {
                        reached = false;
                        break;
                    }
                    col++;
                } else if(grid[row][col] == -1) {
                    if(col==0 || grid[row][col-1] == 1) {
                        reached = false;
                        break;
                    }
                    col--;
                }
                row++;
            }
            if(reached)
                result.push_back(col);
            else
                result.push_back(-1);
        }
        return result;
        
    }
};
