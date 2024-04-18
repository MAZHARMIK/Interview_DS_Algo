/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Google
    Leetcode Link               : https://leetcode.com/problems/island-perimeter/
*/

/*********************************************** C++ **************************************************/
//Approach-1 (DFS)
//T.C : O(m*n)
//S.C : O(1) Auxiliary Space
class Solution {
public:
    int m;
    int n;
    int peri;
    
    void dfs(vector<vector<int>>& grid, int i, int j) {
        
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
            peri++;
            return;
        }
        
        if(grid[i][j] == -1) {
            return;
        }
        
        grid[i][j] = -1; //mark visited
        
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
        
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        m    = grid.size();
        n    = grid[0].size();
        peri = 0;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                
                if(grid[i][j] == 1) {
                    dfs(grid, i, j);
                    return peri;
                }
                
            }
        }
        
        return -1;
    }
};


//Approach-2 (BFS)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    int m;
    int n;

    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    int bfs(vector<vector<int>>& grid, int i, int j) {
        int perim = 0;
        
        queue<pair<int, int>> que;
        que.push({i, j});
        grid[i][j] = -1;
        
        while(!que.empty()) {
            
            auto it = que.front();
            que.pop();
            
            //it.first = i
            //it.second = j
            
            for(auto &dir : directions) {
                int i_ = it.first + dir[0];
                int j_ = it.second + dir[1];
                
                if(i_ < 0 || i_ >= m || j_ < 0 || j_ >= n || grid[i_][j_] == 0)
                    perim++;
                else if(grid[i_][j_] == -1) {
                    continue;
                } else {
                    que.push({i_, j_});
                    grid[i_][j_] = -1;
                }
            }
            
        }
        
        return perim;
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        m    = grid.size();
        n    = grid[0].size();
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                
                if(grid[i][j] == 1) {
                    return bfs(grid, i, j);
                }
                
            }
        }
        
        return -1;
    }
};


//Approach-3 (Iterative)
//T.C : O(m*n)
//S.C : O(1)
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



/*********************************************** JAVA **************************************************/
//Approach-1 (DFS)
//T.C : O(m*n)
//S.C : O(1) Auxiliary Space
class Solution {
    int m;
    int n;
    int peri;
    
    void dfs(int[][] grid, int i, int j) {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
            peri++;
            return;
        }
        
        if(grid[i][j] == -1) {
            return;
        }
        
        grid[i][j] = -1; // mark visited
        
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }
    
    int islandPerimeter(int[][] grid) {
        m = grid.length;
        n = grid[0].length;
        peri = 0;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    dfs(grid, i, j);
                    return peri;
                }
            }
        }
        
        return -1;
    }
}


//Approach-2 (BFS)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
    int m;
    int n;
    int[][] directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    int bfs(int[][] grid, int i, int j) {
        int perim = 0;
        
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{i, j});
        grid[i][j] = -1;
        
        while (!queue.isEmpty()) {
            int[] it = queue.poll();
            
            for (int[] dir : directions) {
                int i_ = it[0] + dir[0];
                int j_ = it[1] + dir[1];
                
                if (i_ < 0 || i_ >= m || j_ < 0 || j_ >= n || grid[i_][j_] == 0)
                    perim++;
                else if (grid[i_][j_] == -1)
                    continue;
                else {
                    queue.offer(new int[]{i_, j_});
                    grid[i_][j_] = -1;
                }
            }
        }
        
        return perim;
    }
    
    int islandPerimeter(int[][] grid) {
        m = grid.length;
        n = grid[0].length;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    return bfs(grid, i, j);
                }
            }
        }
        
        return -1;
    }
}


//Approach-3 (Iterative)
//T.C : O(m*n)
//S.C : O(1)
class Solution {
    public int islandPerimeter(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        
        int perimeter = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    continue;
                
                if (i - 1 < 0 || grid[i - 1][j] == 0) // up
                    perimeter++;
                
                if (i + 1 >= m || grid[i + 1][j] == 0) // down
                    perimeter++;
                
                if (j - 1 < 0 || grid[i][j - 1] == 0) // left
                    perimeter++;
                
                if (j + 1 >= n || grid[i][j + 1] == 0) // right
                    perimeter++;
            }
        }
        
        return perimeter;
    }
}
