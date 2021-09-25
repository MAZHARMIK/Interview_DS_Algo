/*
    Company Tags            : Google
    Frequency               : Yet to be known
    Video Explanation Link  : You can raise this request by contacting me on LinkedIn or posting request on Interview_DS_Algo page on LinkedIn. It's FREE
    Leetcode Link           : https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/
*/

class Solution {
public:
    vector<vector<int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> obs(m, vector<int>(n, INT_MAX));
        
        queue<vector<int>> que;
        que.push({0, 0, 0});
        
        obs[0][0] = 0; //Number of obstacles faced till this index (i, j)
        
        int steps = 0;
        while(!que.empty()) {
            int N = que.size();
            
            while(N--) {
                auto curr = que.front(); que.pop();
                int x = curr[0];
                int y = curr[1];
                
                if(x == m-1 && y == n-1) return steps;
                
                for(auto &dir : dirs) {
                    int new_x = x + dir[0];
                    int new_y = y + dir[1];
                    
                    if(new_x >= 0 && new_x < m && new_y >= 0 && new_y < n) {
                        int currObstacle = curr[2] + grid[new_x][new_y];
                        if(currObstacle >= obs[new_x][new_y] || currObstacle > k) continue;
                        
                        obs[new_x][new_y] = currObstacle;
                        que.push({new_x, new_y, currObstacle});
                    }
                }
            }
            
            steps++;
        }
        
        return -1;
    }
};
