/*
    Company Tags  : Google
    Leetcode Link : https://leetcode.com/problems/the-maze/
    Description

    There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up,
    down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.
    Given the ball's start position, the destination and the maze, determine whether the ball could stop at the destination.
    The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space. You may assume that the borders
    of the maze are all walls. The start and destination coordinates are represented by row and column indexes.
    
    1.There is only one ball and one destination in the maze.
    2.Both the ball and the destination exist on an empty space, and they will not be at the same position initially.
    3.The given maze does not contain border (like the red rectangle in the example pictures), but you could assume the border of the maze are all walls.
    5.The maze contains at least 2 empty spaces, and both the width and height of the maze won't exceed 100.
    
    Example 1:
    Input:
    map = 
        [
         [0,0,1,0,0],
         [0,0,0,0,0],
         [0,0,0,1,0],
         [1,1,0,1,1],
         [0,0,0,0,0]
        ]
    start = [0,4]
    end = [3,2]
    Output:
    false
*/

/*
Two approaches :  DFS and BFS
*/

class Solution {
public:
    vector<pair<int, int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int end_x, end_y;
    bool visited[101][101];
  
    /********************DFS************************/
    bool DFS(vector<vector<int>> &maze, int x, int y) {
        if(x == end_x && y == end_y) {
            return true;
        }

        if(visited[x][y])
            return false;

        visited[x][y] = true;
        for(pair<int, int>& p : directions) {
             int x_ = x + p.first;
             int y_ = y + p.second;
             
            /*
                The only difference here with normal DFS is that in this case, the neighbors are
                those nodes where the balls hits a wall. That's where it explores other paths.
            */
             while (x_ >= 0 && x_ < maze.size() && y_ >= 0 && y_ < maze[0].size() && maze[x_][y_] == 0) {
                     x_ += p.first;
                     y_ += p.second;
             }

             x_ -= p.first;
             y_ -= p.second;
             if(!visited[x_][y_] && DFS(maze, x_, y_)) {
                 return true;
             }
        }
        return false;
    }

  /********************BFS************************/
    bool BFS(vector<vector<int>> &maze, int x, int y) {
        queue<pair<int, int>> que;
        que.push({x, y});
        visited[x][y] = true;
        while(!que.empty()) {
            pair<int, int> curr = que.front();
            que.pop();
            
            if(curr.first == end_x && curr.second == end_y)
                return true;

            for(pair<int, int>& p : directions) {
                int x_ = curr.first + p.first;
                int y_ = curr.second + p.second;
                
                 /*
                    The only difference here with normal BFS is that in this case, the neighbors are
                    those nodes where the balls hits a wall. That's where it explores other paths.
                */
                while (x_ >= 0 && x_ < maze.size() && y_ >= 0 && y_ < maze[0].size() && maze[x_][y_] == 0) {
                    x_ += p.first;
                    y_ += p.second;
                }

                x_ -= p.first;
                y_ -= p.second;

                if(!visited[x_][y_]) {
                    que.push({x_, y_});
                    visited[x_][y_] = true;
                }
            }
        }

        return false;
    }

    bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
        int x     = start[0];
        int y     = start[1];
        memset(visited, 0, sizeof(visited));
        end_x = destination[0];
        end_y = destination[1];

        return DFS(maze, x, y);
    }
};
