/*
    Company Tags  : Amazon
    Leetcode Link : https://leetcode.com/problems/swim-in-rising-water/
    
    The question can be stated as follows: there are multiple paths from (0, 0) to (n - 1, n - 1),
    each path has a max value from all of the steps .
    And what is smallest of that value res in the path among all of them ?
    
    Similar Question - Leetcode : 1102 (Find the minimum length path with) (Premium Question)
*/

//Approach -1 (Binary Search + BFS) Time : O(n^2 * log(n))
class Solution {
public:
    int n;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int visited[50][50];
    bool reachable(vector<vector<int>>& grid, int i, int j, int mid) {
        if(i < 0 || i >= n || j < 0 || j >= n || visited[i][j] || grid[i][j] > mid)
            return false;
        
        visited[i][j] = 1;
        
        if(i == n-1 && j == n-1)
            return true;
        
        for(vector<int> &dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            
            if(reachable(grid, new_i, new_j, mid))
                return true;
        }
        
        return false;
    }
    
    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        
        int l = grid[0][0], r = n*n-1;
        
        while(l < r) {
            int mid = l + (r-l)/2;
            memset(visited, 0, sizeof(visited));
            
            if(reachable(grid, 0, 0, mid)) {
                r = mid;
            } else {
                l = mid+1;
            }
        }
        
        return l;
    }
};

//Approach-2 Dijkstra's Algo (priority_queue) Time : O(n^2 * log(n))
//In every step, find lowest water level to move forward, so using PQ rather than queue
class Solution {
    class cell {
        public:
            int x;
            int y;
            int timeRequired;
            cell(int x, int y, int timeRe) {
                this->x = x;
                this->y = y;
                this->timeRequired = timeRe;
            }
    };
    
public:
    int m, n;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    int swimInWater(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        int visited[50][50] = {0};
        
        auto lambda = [&](cell& c1, cell& c2) {
            return c1.timeRequired > c2.timeRequired;
        };
        
        priority_queue<cell, vector<cell>, decltype(lambda)> pq(lambda);
        
        pq.push(cell(0, 0, grid[0][0]));
        visited[0][0] = 1;
        int leastTime = grid[0][0];
        
        while(!pq.empty()) {
            cell currCell = pq.top();
            pq.pop();
            
            leastTime = max(leastTime, currCell.timeRequired);
            if(currCell.x == m-1 && currCell.y == n-1)
                break;
            
            for(vector<int>& dir : directions) {
                int new_x = currCell.x + dir[0];
                int new_y = currCell.y + dir[1];
                
                if(new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && !visited[new_x][new_y]) {
                    visited[new_x][new_y] = 1;
                    pq.push(cell(new_x, new_y, grid[new_x][new_y]));
                }
                
            }
        }
        
        return leastTime;
    }
};
