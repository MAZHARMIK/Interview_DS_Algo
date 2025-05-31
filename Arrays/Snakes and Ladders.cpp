/*            Scroll below to see JAVA code as well            */
/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=26IT3FYm5h8
      Company Tags                : Zoho, Flipkart, Amazon, Microsoft, OYO Rooms, MAQ Software, Adobe, Nutanix, Belzabar
      Leetcode Link               : https://leetcode.com/problems/snakes-and-ladders/
*/


/****************************************************************** C++ **************************************************************/
//T.C : O(n^2), The maximum number of cells is n^2 and each cell is visited at most once.
//S.C : O(n^2)
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



/****************************************************************** JAVA **************************************************************/
//T.C : O(n^2), The maximum number of cells is n^2 and each cell is visited at most once.
//S.C : O(n^2)
class Solution {
    int n;

    // Converts cell number to board coordinates considering the zigzag pattern
    private int[] getCoord(int s) {
        int row = n - 1 - (s - 1) / n;
        int col = (s - 1) % n;
        
        if ((n % 2 == 1 && row % 2 == 1) || (n % 2 == 0 && row % 2 == 0)) {
            col = n - 1 - col;
        }
        
        return new int[]{row, col};
    }

    public int snakesAndLadders(int[][] board) {
        n = board.length;
        boolean[][] visited = new boolean[n][n];
        Queue<Integer> queue = new LinkedList<>();
        
        queue.offer(1); // Start from cell 1
        visited[n - 1][0] = true;
        
        int steps = 0;

        while (!queue.isEmpty()) {
            int size = queue.size();
            
            while (size-- > 0) {
                int curr = queue.poll();

                if (curr == n * n) return steps;

                for (int dice = 1; dice <= 6; dice++) {
                    int next = curr + dice;
                    if (next > n * n) break;

                    int[] coord = getCoord(next);
                    int r = coord[0], c = coord[1];
                    
                    if (visited[r][c]) continue;

                    visited[r][c] = true;

                    if (board[r][c] == -1) {
                        queue.offer(next);
                    } else {
                        queue.offer(board[r][c]);
                    }
                }
            }
            steps++;
        }

        return -1;
    }
}
