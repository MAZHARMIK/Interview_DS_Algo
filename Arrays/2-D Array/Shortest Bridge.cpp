/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=GSE0-dReL6Y
    Company Tags                : MICROSOFT
    Leetcode Link               : https://leetcode.com/problems/shortest-bridge/
    
    Similar Problems : 
    
    Leetcode 286. Walls and Gates
    Leetcode 417. Pacific Atlantic Water Flow (Very Good Problem)
    Leetcode 994. Rotting Oranges
    Leetcode 1162. As Far from Land as Possible
    Leetcode 1765. Map of Highest Peak

    
*/

//Using combination of DFS -> BFS
//NOTE : You can also use combination of BFS -> BFS
class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {
                {-1,0},
        {0,-1},         {0,1},
                {1, 0}
    };
    
    bool isSafe(int i, int j) {
        return (i < m && i >= 0 && j < n && j >= 0);
    }
    
    void dfs(vector<vector<int>>& grid, int i, int j, set<pair<int, int>>& visitedCell) {
        if(!isSafe(i, j) || grid[i][j] == 0 || visitedCell.find({i, j}) != visitedCell.end()) {
            return;
        }
        
        visitedCell.insert({i, j});
        
        for(auto &dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            
            dfs(grid, i_, j_, visitedCell);
        }
    }
    
    int bfs(vector<vector<int>>& grid, set<pair<int, int>>& visitedCell) {
        queue<pair<int, int>> que;
        
        for(auto &it : visitedCell) {
            
            que.push({it});
            
        }
        
        int level = 0;
        
        while(!que.empty()) {
            int L = que.size();
            
            while(L--) {
                pair<int, int> P = que.front();
                que.pop();
                
                for(auto &dir : directions) {
                    int i_ = P.first + dir[0];
                    int j_ = P.second + dir[1];

                    if(isSafe(i_, j_) && visitedCell.find({i_, j_}) == visitedCell.end()) {
                        if(grid[i_][j_] == 1) //found another island
                            return level;
                        
                        visitedCell.insert({i_, j_});
                        que.push({i_, j_});
                    }
                }
                
            }
            level++;
        }
        
        return level;
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        set<pair<int, int>> visitedCell;
        
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                
                if(grid[i][j] == 1) {
                    dfs(grid, i, j, visitedCell); //It will mark one island visited
                    return bfs(grid, visitedCell);
                }
                
            }
        }
        
        return -1;
    }
};
