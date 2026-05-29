/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=f81qWxDkj0Q
    Company Tags                : Will update later
    Leetcode Link               : https://leetcode.com/problems/maximum-score-from-grid-operations
*/


/**************************************************************** C++ ****************************************************************/
//Approach-1 (Brute Force) - TLE
//T.C : O((n+1)^n * n^2))
//S.C : O(n)
class Solution {
public:
    long long computeScore(vector<int>& h, vector<vector<int>>& grid, int n) {
        long long score = 0;

        for (int j = 0; j < n; j++) {
            for (int i = h[j] + 1; i < n; i++) {

                bool hasBlackNeighbor = false;

                if (j - 1 >= 0 && i <= h[j - 1])
                    hasBlackNeighbor = true;

                if (j + 1 < n && i <= h[j + 1])
                    hasBlackNeighbor = true;

                if (hasBlackNeighbor)
                    score += grid[i][j];
            }
        }

        return score;
    }

    void solve(int col, vector<int>& h, vector<vector<int>>& grid, int n, long long& result) {
        if (col == n) {
            result = max(result, computeScore(h, grid, n));
            return;
        }

        // allow -1 (no operation)
        for (int height = -1; height < n; height++) {
            h[col] = height;
            solve(col + 1, h, grid, n, result);
        }
    }

    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<int> h(n);
        long long result = 0;

        solve(0, h, grid, n, result);

        return result;
    }
};




//Approach-2 (Brute Force with improved computeScore)
//T.C : O((n+1)^n * n))
//S.C : O(n^2)
class Solution {
public:
    using ll = long long;

    ll computeScore(vector<int>& h, vector<vector<ll>>& colPrefSum, int n) {
        ll score = 0;

        for (int col = 0; col < n; col++) {

            int left = (col - 1 >= 0 ? h[col - 1] : -1);
            int right = (col + 1 < n ? h[col + 1] : -1);

            int upper = max(left, right); // highest black neighbor
            int lower = h[col];           // current column height

            if (upper > lower) {
                score += colPrefSum[upper + 1][col + 1]
                       - colPrefSum[lower + 1][col + 1];
            }
        }

        return score;
    }

    void solve(int col, vector<int>& h, vector<vector<ll>>& colPrefSum,
               int n, ll& result) {

        if (col == n) {
            result = max(result, computeScore(h, colPrefSum, n));
            return;
        }

        for (int height = -1; height < n; height++) {
            h[col] = height;
            solve(col + 1, h, colPrefSum, n, result);
        }
    }

    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();
      
        vector<vector<ll>> colPrefSum(n + 1, vector<ll>(n + 1, 0));

        for (int col = 1; col <= n; col++) {
            for (int row = 1; row <= n; row++) {
                colPrefSum[row][col] =
                    colPrefSum[row - 1][col] + grid[row - 1][col-1];
            }
        }

        vector<int> h(n);
        ll result = 0;

        solve(0, h, colPrefSum, n, result);

        return result;
    }
};



//Approach-3 (Most optimal)
//T.C : O(n^3)
//S.C : O(n^2)
class Solution {
public:
    typedef long long ll;
    int n;
    ll t[2][101][101];

    ll solve(bool prevTaken, int prevHeight, int col, vector<vector<int>>& grid, vector<vector<ll>>& colPrefSum) {
        
        if(col == n) {
            return 0;
        }
        
        ll result = 0;

        if(t[prevTaken][prevHeight][col] != -1) {
            return t[prevTaken][prevHeight][col];
        } 

        for(int height = 0; height <= n; height++) {
            ll prevColScore = 0;
            ll currColScore = 0;

            if(!prevTaken && col-1 >= 0 && height > prevHeight) {
                prevColScore += colPrefSum[height][col] - colPrefSum[prevHeight][col];
            }

            if(prevHeight > height) {
                currColScore += colPrefSum[prevHeight][col+1] - colPrefSum[height][col+1];
            }


            ll currColScoreTaken    = currColScore + prevColScore + solve(true, height, col+1, grid, colPrefSum);
            ll currColScoreNotTaken = prevColScore + solve(false, height, col+1, grid, colPrefSum);

            result = max({result, currColScoreTaken, currColScoreNotTaken});
        }

        return t[prevTaken][prevHeight][col] = result;

    }

    long long maximumScore(vector<vector<int>>& grid) {
        n = grid.size();

        memset(t, -1, sizeof(t));


        vector<vector<ll>> colPrefSum(n + 1, vector<ll>(n + 1, 0));

        for(int col = 1; col <= n; col++) {
            for(int row = 1; row <= n; row++) {
                colPrefSum[row][col] = colPrefSum[row-1][col] + grid[row-1][col-1];
            }
        }

        return solve(false, 0, 0, grid, colPrefSum);
    }
};




/**************************************************************** JAVA ****************************************************************/
//Approach-1 (Brute Force) - TLE
//T.C : O((n+1)^n * n^2))
//S.C : O(n)
class Solution {

    int n;

    long computeScore(int[] h, int[][] grid) {
        long score = 0;

        for (int j = 0; j < n; j++) {
            for (int i = h[j] + 1; i < n; i++) {

                boolean hasBlackNeighbor = false;

                if (j - 1 >= 0 && i <= h[j - 1])
                    hasBlackNeighbor = true;

                if (j + 1 < n && i <= h[j + 1])
                    hasBlackNeighbor = true;

                if (hasBlackNeighbor)
                    score += grid[i][j];
            }
        }

        return score;
    }

    void solve(int col, int[] h, int[][] grid, long[] result) {
        if (col == n) {
            result[0] = Math.max(result[0], computeScore(h, grid));
            return;
        }

        for (int height = -1; height < n; height++) {
            h[col] = height;
            solve(col + 1, h, grid, result);
        }
    }

    public long maximumScore(int[][] grid) {
        n = grid.length;

        int[] h = new int[n];
        long[] result = new long[1];

        solve(0, h, grid, result);

        return result[0];
    }
}


//Approach-2 (Brute Force with improved computeScore)
//T.C : O((n+1)^n * n))
//S.C : O(n^2)
class Solution {

    int n;

    long computeScore(int[] h, long[][] colPrefSum) {
        long score = 0;

        for (int col = 0; col < n; col++) {

            int left = (col - 1 >= 0 ? h[col - 1] : -1);
            int right = (col + 1 < n ? h[col + 1] : -1);

            int upper = Math.max(left, right);
            int lower = h[col];

            if (upper > lower) {
                score += colPrefSum[upper + 1][col + 1]
                       - colPrefSum[lower + 1][col + 1];
            }
        }

        return score;
    }

    void solve(int col, int[] h, long[][] colPrefSum, long[] result) {
        if (col == n) {
            result[0] = Math.max(result[0], computeScore(h, colPrefSum));
            return;
        }

        for (int height = -1; height < n; height++) {
            h[col] = height;
            solve(col + 1, h, colPrefSum, result);
        }
    }

    public long maximumScore(int[][] grid) {
        n = grid.length;

        long[][] colPrefSum = new long[n + 1][n + 1];

        for (int col = 1; col <= n; col++) {
            for (int row = 1; row <= n; row++) {
                colPrefSum[row][col] =
                    colPrefSum[row - 1][col] + grid[row - 1][col - 1];
            }
        }

        int[] h = new int[n];
        long[] result = new long[1];

        solve(0, h, colPrefSum, result);

        return result[0];
    }
}



//Approach-3 (Most optimal)
//T.C : O(n^3)
//S.C : O(n^2)
class Solution {

    int n;
    long[][][] t;

    long solve(boolean prevTaken, int prevHeight, int col,
               int[][] grid, long[][] colPrefSum) {

        if (col == n) return 0;

        if (t[prevTaken ? 1 : 0][prevHeight][col] != -1)
            return t[prevTaken ? 1 : 0][prevHeight][col];

        long result = 0;

        for (int height = 0; height <= n; height++) {

            long prevColScore = 0;
            long currColScore = 0;

            if (!prevTaken && col > 0 && height > prevHeight) {
                prevColScore =
                    colPrefSum[height][col] - colPrefSum[prevHeight][col];
            }

            if (prevHeight > height) {
                currColScore =
                    colPrefSum[prevHeight][col + 1] - colPrefSum[height][col + 1];
            }

            long takeCurrent =
                currColScore + prevColScore +
                solve(true, height, col + 1, grid, colPrefSum);

            long skipCurrent =
                prevColScore +
                solve(false, height, col + 1, grid, colPrefSum);

            result = Math.max(result, Math.max(takeCurrent, skipCurrent));
        }

        return t[prevTaken ? 1 : 0][prevHeight][col] = result;
    }

    public long maximumScore(int[][] grid) {
        n = grid.length;

        t = new long[2][101][101];
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 101; j++)
                java.util.Arrays.fill(t[i][j], -1);

        long[][] colPrefSum = new long[n + 1][n + 1];

        for (int col = 1; col <= n; col++) {
            for (int row = 1; row <= n; row++) {
                colPrefSum[row][col] =
                    colPrefSum[row - 1][col] + grid[row - 1][col - 1];
            }
        }

        return solve(false, 0, 0, grid, colPrefSum);
    }
}
