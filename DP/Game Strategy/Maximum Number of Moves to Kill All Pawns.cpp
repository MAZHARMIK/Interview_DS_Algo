/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=pz_slLUY7z0
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/maximum-number-of-moves-to-kill-all-pawns/
*/


/**************************************************************** C++ ****************************************************************/
//Approach (BFS + DP with mask : Game Strategy)
//T.C : O(n + n*2^n) //BFS - called n times. Note that it works in a chess board of fixed size and hence takes O(1) time. , solve functions visits n*2^n states in dp
//S.C : O(n*2^n) //space taken by dp array
class Solution {
public:
    vector<vector<int>> directions = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

    void BFS(int x, int y, int index, vector<vector<int>>& minDist, vector<vector<int>>& pos) {
        vector<vector<int>> t(50, vector<int>(50, -1));
        queue<pair<int, int>> que;
        que.push({x, y});
        t[x][y] = 0;

        while(!que.empty()) {
            auto[currX, currY] = que.front();
            que.pop();

            for(auto &dir : directions) {
                int newX = currX + dir[0];
                int newY = currY + dir[1];

                if(newX >= 0 && newX < 50 && newY >= 0 && newY < 50 && t[newX][newY] == -1) {
                    t[newX][newY] = t[currX][currY] + 1;
                    que.push({newX, newY});
                }
            }
        }

        for(int i = 0; i < pos.size(); i++) {
            int x_ = pos[i][0];
            int y_ = pos[i][1];

            minDist[index][i] = t[x_][y_];
        }
    }

    int solve(vector<vector<int>>& minDist, int idx, int mask, int n, bool Alice, int dp[51][1<<15]) {
        if(mask == 0) {
            return 0; //no more moves/steps required
        }

        if(dp[idx][mask] != -1) {
            return dp[idx][mask];
        }

        int result = (Alice == true) ? -1 : 1e9;

        for(int i = 1; i < n; i++) {
            if(mask & (1 << (i-1))) {
                int moves = minDist[idx][i];

                if(Alice == true) {
                    result = max(result, moves + solve(minDist, i, mask ^ (1 << (i-1)), n, !Alice, dp));
                } else {
                    result = min(result, moves + solve(minDist, i, mask ^ (1 << (i-1)), n, !Alice, dp));
                }
            }
        }

        return dp[idx][mask] = result;
    }

    int maxMoves(int kx, int ky, vector<vector<int>>& positions) {
        int n = positions.size();

        vector<vector<int>> pos;
        pos.push_back({kx, ky});
        for(auto &vec : positions) {
            pos.push_back({vec[0], vec[1]});
        }

        //minDist[][]
        vector<vector<int>> minDist(n+1, vector<int>(n+1, 0));

        for(int i = 0; i < pos.size(); i++) {
            int x = pos[i][0];
            int y = pos[i][1];
            BFS(x, y, i, minDist, pos);
        }


        //call solve
        //0th index par knight hai mera in pos array
        bool Alice = true;
        int dp[51][1 << 15];
        memset(dp, -1, sizeof(dp));
        return solve(minDist, 0, (1<<n)-1, pos.size(), Alice, dp);
    }
};


/**************************************************************** JAVA ****************************************************************/
//Approach (BFS + DP with mask : Game Strategy)
//T.C : O()
//S.C : O()
class Solution {
    // Directions for knight moves
    private static final int[][] directions = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
    
    // BFS to calculate minimum distances
    private void BFS(int x, int y, int index, int[][] minDist, List<int[]> pos) {
        int[][] t = new int[50][50];
        for (int[] row : t) Arrays.fill(row, -1);
        
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{x, y});
        t[x][y] = 0;

        while (!queue.isEmpty()) {
            int[] current = queue.poll();
            int currX = current[0];
            int currY = current[1];

            for (int[] dir : directions) {
                int newX = currX + dir[0];
                int newY = currY + dir[1];

                if (newX >= 0 && newX < 50 && newY >= 0 && newY < 50 && t[newX][newY] == -1) {
                    t[newX][newY] = t[currX][currY] + 1;
                    queue.offer(new int[]{newX, newY});
                }
            }
        }

        for (int i = 0; i < pos.size(); i++) {
            int x_ = pos.get(i)[0];
            int y_ = pos.get(i)[1];
            minDist[index][i] = t[x_][y_];
        }
    }

    // Recursively solve using dynamic programming
    private int solve(int[][] minDist, int idx, int mask, int n, boolean Alice, int[][] dp) {
        if (mask == 0) {
            return 0; // no more moves required
        }

        if (dp[idx][mask] != -1) {
            return dp[idx][mask];
        }

        int result = Alice ? -1 : Integer.MAX_VALUE;

        for (int i = 1; i < n; i++) {
            if ((mask & (1 << (i - 1))) != 0) {
                int moves = minDist[idx][i];

                if (Alice) {
                    result = Math.max(result, moves + solve(minDist, i, mask ^ (1 << (i - 1)), n, !Alice, dp));
                } else {
                    result = Math.min(result, moves + solve(minDist, i, mask ^ (1 << (i - 1)), n, !Alice, dp));
                }
            }
        }

        return dp[idx][mask] = result;
    }

    public int maxMoves(int kx, int ky, int[][] positions) {
        int n = positions.length;

        // List of positions including the knight's starting position
        List<int[]> pos = new ArrayList<>();
        pos.add(new int[]{kx, ky});
        for (int[] vec : positions) {
            pos.add(new int[]{vec[0], vec[1]});
        }

        // Initialize minDist array
        int[][] minDist = new int[n + 1][n + 1];

        // Calculate BFS from each position
        for (int i = 0; i < pos.size(); i++) {
            int x = pos.get(i)[0];
            int y = pos.get(i)[1];
            BFS(x, y, i, minDist, pos);
        }

        // Initialize DP array
        int[][] dp = new int[51][1 << 15];
        for (int[] row : dp) Arrays.fill(row, -1);

        // Solve the problem starting from the knight's position (0th index) with all positions available (mask)
        return solve(minDist, 0, (1 << n) - 1, pos.size(), true, dp);
    }
}
