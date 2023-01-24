/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=26IT3FYm5h8
      Company Tags                : Zoho, Flipkart, Amazon, Microsoft, OYO Rooms, MAQ Software, Adobe, Nutanix, Belzabar
      Leetcode Link               : https://leetcode.com/problems/snakes-and-ladders/
*/

class Solution {
public:
    int n;
    
    pair<int, int> getCoord(int s) {
        int row = n-1-(s-1)/n;
        
        int col = (s-1)%n;
        
        if((n%2==1 && row%2==1)||(n%2==0 && row%2==0))
            col = n-1-col;
        
        return make_pair(row, col);
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();
        
        int steps = 0;
        queue<int> que;
        
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[n-1][0] = true;
        
        que.push(1);
        vector<bool> seen(n*n+1,false);
        
        
        while(!que.empty()) {
            
            int N = que.size();
            while(N--) {
            
                int x = que.front();
                que.pop();

                if(x == n*n)
                    return steps;

                for(int k = 1; k<=6; k++) {
                    if(x+k > n*n)
                        break;

                    pair<int, int> coord = getCoord(x+k);
                    int r = coord.first;
                    int c = coord.second;
                    if(visited[r][c] == true)
                        continue;

                    visited[r][c] = true;
                    if(board[r][c] == -1)
                        que.push(k+x);
                    else {
                        que.push(board[r][c]);
                    }
                }
            }
            steps++;
        }
        
        return -1;
    }
};
