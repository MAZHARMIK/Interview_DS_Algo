/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=yt6bi_g4C0I
    Company Tags                : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/shortest-path-to-get-all-keys/
*/

class Solution {
public:
    
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        queue<vector<int>> que; //{x, y, steps, current_key_status_decimal}
        int count = 0;
        for(int i = 0; i<m; i++) {
            
            for(int j = 0; j<n; j++) {
                
                if(grid[i][j] == '@') {
                    que.push({i, j, 0, 0});
                } else if(grid[i][j] >= 'a' && grid[i][j] <= 'f') {
                    count++;
                }
                
            }
            
        }
        
        /*
            If we have 3 keys - '111'  - Decimal value = 8 = 2^3 - 1
            If we have 4 keys - '1111' - Decimal value = 15 = 2^4 - 1
        */
        
        int final_key_status_decimal = pow(2, count) - 1;
        
        
        int visited[m][n][final_key_status_decimal+1];
        memset(visited, 0, sizeof(visited));
        
        while(!que.empty()) {
            
            auto temp = que.front();
            que.pop();
            
            int i                            = temp[0];
            int j                            = temp[1];
            int steps                        = temp[2];
            int current_key_status_decimal   = temp[3];
            
            if(current_key_status_decimal == final_key_status_decimal) {
                return steps;
            }
            
            for(vector<int> & dir : directions) {
                
                int new_i = i + dir[0];
                int new_j = j + dir[1];
                
                if(new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && grid[new_i][new_j] != '#') {
                    char ch = grid[new_i][new_j];
                        
                    if(grid[new_i][new_j] >= 'A' && grid[new_i][new_j] <= 'F') { //Lock
                        
                        if(visited[new_i][new_j][current_key_status_decimal] == 0 && 
                          ((current_key_status_decimal >> (ch-'A')) & 1) == 1) { //Already have that key then we unlock
                            visited[new_i][new_j][current_key_status_decimal] = 1;
                            que.push({new_i, new_j, steps+1, current_key_status_decimal});
                        }
                        
                    } else if(grid[new_i][new_j] >= 'a' && grid[new_i][new_j] <= 'f') { //Key
                        
                        int newKey_status_decimal = current_key_status_decimal | (1 << (ch - 'a'));
                        
                        if(visited[new_i][new_j][newKey_status_decimal] == 0) {
                            visited[new_i][new_j][newKey_status_decimal] = 1;
                            que.push({new_i, new_j, steps+1, newKey_status_decimal});
                        }
                        
                    } else {
                        if(visited[new_i][new_j][current_key_status_decimal] == 0) {
                            visited[new_i][new_j][current_key_status_decimal] = 1;
                            que.push({new_i, new_j, steps+1, current_key_status_decimal});
                        }
                    }
                    
                }
                
            }
            
        }
        
        return -1;
    }
};
