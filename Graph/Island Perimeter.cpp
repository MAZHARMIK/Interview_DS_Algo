/*
    Company Tags  : Google
    Leetcode Link : https://leetcode.com/problems/island-perimeter/
*/

//Approach-1 (DFS)
class Solution {
public:
    int perimeter;
    void dfs(vector<vector<int>>& grid, int i, int j) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) {
            perimeter++;
            return;
        }
        
        if(grid[i][j] == -1)
            return;
        
        grid[i][j] = -1;
        
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        perimeter = 0;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j] == 1) {
                    dfs(grid, i, j);
                    return perimeter;
                }
            }
        }
        
        return perimeter;
    }
};


//Approach-2 (BFS)
class Solution {
public:
    vector<pair<int, int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int bfs(vector<vector<int>>& grid, int i, int j) {
        int perimeter = 0;
        
        queue<pair<int, int>> que;
        que.push({i, j});
        grid[i][j] = -1;
        while(!que.empty()) {
            auto it = que.front();
            que.pop();
            
            for(pair<int, int> &p : directions) {
                int i_ = it.first  + p.first;
                int j_ = it.second + p.second;
                
                if(i_ < 0 || i_ >= grid.size() || j_ < 0 || j_ >= grid[0].size() || grid[i_][j_] == 0)
                    perimeter++;
                else if(grid[i_][j_] == -1) {
                    continue;
                } else {
                    que.push({i_, j_});
                    grid[i_][j_] = -1;
                }
            }
        }
        
        return perimeter;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j] == 1) {
                    return bfs(grid, i, j);
                }
            }
        }
        
        return 0;
    }
};


//Approach-3 (Iterative)
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int perimeter = 0;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j] == 0)
                    continue;
                
                if(i-1 < 0 || grid[i-1][j] == 0) //up
                    perimeter++;
                
                if(i+1 >= m || grid[i+1][j] == 0) //down
                    perimeter++;
                
                if(j-1 < 0 || grid[i][j-1] == 0) //left
                    perimeter++;
                
                if(j+1 >= n || grid[i][j+1] == 0) //right
                    perimeter++;
                
            }
        }
        
        return perimeter;
    }
};
