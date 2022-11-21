/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Q4bqto_yG6I
    Company Tags                : Similar Problem asked in Samsung
    Leetcode Link               : https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/
*/

//Simply Use BFS : 
//Time  - O(m*n)
//Space - O(m+n)
class Solution {
public:
    vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        
        queue<pair<int, int>> que;
        que.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+'; //marking it visited
        int steps = 0;
        
        while(!que.empty()) {
            int size = que.size();
            
            while(size--) {
                pair<int, int> temp = que.front();
                que.pop();
                
                if(temp != make_pair(entrance[0], entrance[1]) && 
                   (temp.first == 0 || temp.first == m-1 || temp.second == 0 || temp.second == n-1))
                    return steps;
                
                for(auto &dir : directions) {
                    int i = temp.first  + dir[0];
                    int j = temp.second + dir[1];

                    if(i >= 0 && i < m && j >= 0 && j < n && maze[i][j] != '+') {
                        que.push({i, j});
                        maze[i][j] = '+'; //marking it as visited
                    }
                }
                
            }
            steps++;
        }
        
        return -1;
    }
};
