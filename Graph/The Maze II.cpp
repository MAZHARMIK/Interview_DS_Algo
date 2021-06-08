/*
    Company Tags  : Google, NetEase
    Leetcode Link : https://leetcode.com/problems/the-maze-ii/
    
    Description

    There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up, down,
    left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.
    Given the ball's start position, the destination and the maze, find the shortest distance for the ball to stop at the
    destination. The distance is defined by the number of empty spaces traveled by the ball from the start position (excluded)
    to the destination (included). If the ball cannot stop at the destination, return -1. The maze is represented by a binary
    2D array. 1 means the wall and 0 means the empty space. You may assume that the borders of the maze are all walls.
    The start and destination coordinates are represented by row and column indexes.
    
    1.There is only one ball and one destination in the maze.
    2.Both the ball and the destination exist on an empty space, and they will not be at the same position initially.
    3.The given maze does not contain border (like the red rectangle in the example pictures), but you could assume the border of the maze are all walls.
    4.The maze contains at least 2 empty spaces, and both the width and height of the maze won't exceed 100.
    
    Example :
      Input:  
      (rowStart, colStart) = (0,4)
      (rowDest, colDest)= (4,4)
      0 0 1 0 0
      0 0 0 0 0
      0 0 0 1 0
      1 1 0 1 1
      0 0 0 0 0

      Output:  12
      Explanation:
      (0,4)->(0,3)->(1,3)->(1,2)->(1,1)->(1,0)->(2,0)->(2,1)->(2,2)->(3,2)->(4,2)->(4,3)->(4,4)	
*/

/*
    2 Approaches : DFS, BFS
*/

//Approach-1 (DFS)
class Solution {
public:
    int end_x, end_y;
    int m, n;
    vector<pair<int, int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int t[101][101];

    void DFS(vector<vector<int>> &maze, int x, int y) {
        
        for(pair<int, int> &dir : directions) {
            int steps = 0;
            int x_ = x;
            int y_ = y;

            while(x_ >=  0 && x_ < m && y_ >= 0 && y_ < n && maze[x_][y_] == 0) {
                x_ += dir.first;
                y_ += dir.second;
                steps++;
            }

            x_ -= dir.first;
            y_ -= dir.second;
            steps--;
        
            //I will go to x_,y_ only if I get better result
            //That's why we don't have to keep track of visited nodes in this prpblem
            //If I find that there is a better path to reach (x_, y_) i.e. from (x, y)
            //we update the value and move ahead
            if(t[x][y] + steps < t[x_][y_]) {
                t[x_][y_] = t[x][y] + steps;
                DFS(maze, x_, y_);
            }
        }

    }

    int shortestDistance(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
        end_x = destination[0];
        end_y = destination[1];
        m = maze.size();
        n = maze[0].size();
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                t[i][j]  = INT_MAX;
            }
        }

        t[start[0]][start[1]] = 0;
        DFS(maze, start[0], start[1]);

        
        return t[end_x][end_y] == INT_MAX ? -1 : t[end_x][end_y];

    }
};


//Approach-2 (BFS)
class Solution {
public:
    int end_x, end_y;
    int m, n;
    vector<pair<int, int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int t[101][101];

    int BFS(vector<vector<int>> &maze, int x, int y) {
        queue<pair<int, int>> que;
        que.push({x, y});

        while(!que.empty()) {
            pair<int, int> curr = que.front();
            que.pop();

            for(pair<int, int> &dir : directions) {
                int x_    = curr.first;
                int y_    = curr.second;
                int steps = 0;
                while(x_ >= 0 && x_ < m && y_ >= 0 && y_ < n && maze[x_][y_] == 0) {
                    x_ += dir.first;
                    y_ += dir.second;
                    steps++;
                }

                x_ -= dir.first;
                y_ -= dir.second;
                steps--;

                if(t[curr.first][curr.second] + steps < t[x_][y_]) {
                    t[x_][y_] = t[curr.first][curr.second] + steps;
                    que.push({x_, y_});
                }

            }
        }
    }

    int shortestDistance(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
        end_x = destination[0];
        end_y = destination[1];
        m = maze.size();
        n = maze[0].size();
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                t[i][j]  = INT_MAX;
            }
        }

        t[start[0]][start[1]] = 0;
        BFS(maze, start[0], start[1]);

        
        return t[end_x][end_y] == INT_MAX ? -1 : t[end_x][end_y];
    }
};
