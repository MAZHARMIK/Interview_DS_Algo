/*
    Company Tags  : Amazon
    Leetcode Link : https://leetcode.com/problems/max-area-of-island/
    
    NOTE : "Disjoint Set Union" can be used to solve this too. It will help to clear concept of Disjoin Set Data Structure
    Find the Disjoint Set Union approach here : "Interview_DS_Algo/Graph/Disjoin Set"  repository
    Link  : https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Disjoin%20Set/Max%20Area%20of%20Island.cpp
    
*/

//Approach-1 (DFS)
class Solution {
public:
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int dfs(vector<vector<int>>& grid, int i, int j, int &m, int &n) {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
            return 0;
        }
        
        int count = 1;
        grid[i][j] = 0;
        for(vector<int> &dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            count += dfs(grid, i_, j_, m, n);
        }
        
        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    maxArea = max(maxArea, dfs(grid, i, j, m, n));
                }
            }
        }
        
        return maxArea;
    }
};


//Approach-2 (BFS)
class Solution {
public:
    typedef pair<int, int> P;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int m, n;
    
    int bfs(int i, int j, vector<vector<int>>& grid) {
        queue<P> que;
        que.push({i, j});
        grid[i][j] = 0;
        int size = 0;
        
        auto isSafe = [&grid](int& x, int& y) {
            return x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == 1;
        };
        
        while(!que.empty()) {
            P curr = que.front();
            que.pop();
            size++;
            
            for(vector<int> &dir : directions) {
                int x = curr.first + dir[0];
                int y = curr.second + dir[1];

                if(isSafe(x, y)) {
                    grid[x][y] = 0;
                    que.push({x, y});
                }
            }
        }
        return size;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int result = 0;
        
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j] == 1) {
                    result = max(result, bfs(i, j, grid));
                }
            }
        }
        
        return result;
    }
};
