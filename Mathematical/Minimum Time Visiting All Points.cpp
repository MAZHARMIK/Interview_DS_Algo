/*
    Company Tags  : Media.net
    Leetcode Link : https://leetcode.com/problems/minimum-time-visiting-all-points/
*/

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& grid) {
        //Key: The time to visit from point (x1, x2) and (y1, y2) is given by
        //min(dx, dy) + abs(dx - dy); //See my answer on Stackoverflow : https://stackoverflow.com/a/68387535/6841676
        //or, max(dx, dy) -> (Just do some board work and you will realise this well :-) )
        int steps = 0;
        for(int i = 1; i<grid.size(); i++) {
            int x1 = grid[i-1][0];
            int y1 = grid[i-1][1];
            
            int x2 = grid[i][0];
            int y2 = grid[i][1];
            
            int dx = abs(x2-x1);
            int dy = abs(y2-y1);
            
            //steps += min(dx, dy) + abs(dx-dy);
            steps += max(dx, dy);
            
        }
        
        return steps;
        
    }
};
