/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/description/
*/


/**************************************************************** C++ ****************************************************************/
//Approach - 1 (Recursion + Memoization)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    int m, n;
    typedef long long ll;
    int MOD = 1e9+7;

    vector<vector<pair<ll, ll>>> t;
    
    pair<ll, ll> solve(int i, int j, vector<vector<int>>& grid) {
        if(i == m-1 && j == n-1) {
            return {grid[i][j], grid[i][j]};
        }

        ll maxVal = LLONG_MIN;
        ll minVal = LLONG_MAX;

        if(t[i][j] != make_pair(LLONG_MIN, LLONG_MAX)) {
            return t[i][j];
        }

        //Down
        if(i+1 < m) {
            auto [downMax, downMin] = solve(i+1, j, grid);
            maxVal = max({maxVal, grid[i][j] * downMax, grid[i][j] * downMin});
            minVal = min({minVal, grid[i][j] * downMax, grid[i][j] * downMin});
        }


        //Right
        if(j+1 < n) {
            auto [rightMax, rightMin] = solve(i, j+1, grid);
            maxVal = max({maxVal, grid[i][j] * rightMax, grid[i][j] * rightMin});
            minVal = min({minVal, grid[i][j] * rightMax, grid[i][j] * rightMin});
        }

        return t[i][j] = {maxVal, minVal};
    }
    int maxProductPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        t = vector<vector<pair<ll, ll>>>(m, vector<pair<ll, ll>>(n, {LLONG_MIN, LLONG_MAX}));
        auto [maxProd, minProd] = solve(0, 0, grid);

        return maxProd < 0 ? -1 : maxProd % MOD;
    }
};


//Approach - 2 (Bottom Up)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    typedef long long ll;
    int MOD = 1e9+7;

    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        

        //bottom up dp lena padega
        vector<vector<pair<ll, ll>>> t(m, vector<pair<ll, ll>>(n));
        //t[i][j] = {maxVal, minVal} to reach from (0, 0) to (i, j)

        t[0][0] = {grid[0][0], grid[0][0]};

        //filling the first row
        for(int j = 1; j < n; j++) {
            t[0][j].first  = t[0][j-1].first  * grid[0][j]; //maxVal
            t[0][j].second = t[0][j-1].second * grid[0][j]; //minVal
        }

        //filling the first column
        for(int i = 1; i < m; i++) {
            t[i][0].first  = t[i-1][0].first  * grid[i][0]; //max Val
            t[i][0].second = t[i-1][0].second * grid[i][0]; //min val
        }

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                ll upMax = t[i-1][j].first;
                ll upMin = t[i-1][j].second;

                ll leftMax = t[i][j-1].first;
                ll leftMin = t[i][j-1].second;

                t[i][j].first  = max({upMax * grid[i][j], upMin * grid[i][j], leftMax * grid[i][j], leftMin * grid[i][j]});
                t[i][j].second = min({upMax * grid[i][j], upMin * grid[i][j], leftMax * grid[i][j], leftMin * grid[i][j]});
            }
        }

        auto [maxProd, minProd] = t[m-1][n-1];

        return maxProd < 0 ? -1 : maxProd % MOD;
    }
};

/**************************************************************** JAVA ****************************************************************/
//Approach - 1 (Recursion + Memoization)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
    int m, n;
    final int MOD = 1000000007;

    // Memoization table for storing (max, min) pairs
    Pair<Long, Long>[][] t;

    public Pair<Long, Long> solve(int i, int j, int[][] grid) {
        // Base case: If we're at the bottom-right corner, return the value
        if (i == m - 1 && j == n - 1) {
            return new Pair<>((long) grid[i][j], (long) grid[i][j]);
        }

        long maxVal = Long.MIN_VALUE;
        long minVal = Long.MAX_VALUE;

        // If already computed, return the memoized result
        if (t[i][j] != null) {
            return t[i][j];
        }

        // Move down
        if (i + 1 < m) {
            Pair<Long, Long> down = solve(i + 1, j, grid);
            maxVal = Math.max(maxVal, Math.max(grid[i][j] * down.getKey(), grid[i][j] * down.getValue()));
            minVal = Math.min(minVal, Math.min(grid[i][j] * down.getKey(), grid[i][j] * down.getValue()));
        }

        // Move right
        if (j + 1 < n) {
            Pair<Long, Long> right = solve(i, j + 1, grid);
            maxVal = Math.max(maxVal, Math.max(grid[i][j] * right.getKey(), grid[i][j] * right.getValue()));
            minVal = Math.min(minVal, Math.min(grid[i][j] * right.getKey(), grid[i][j] * right.getValue()));
        }

        // Memoize results
        t[i][j] = new Pair<>(maxVal, minVal);

        return t[i][j];
    }

    public int maxProductPath(int[][] grid) {
        m = grid.length;
        n = grid[0].length;

        // Initialize the memoization table
        t = new Pair[m][n];

        // Get the result from the top-left corner
        Pair<Long, Long> result = solve(0, 0, grid);

        // If the result is negative, return -1, otherwise return the result modulo MOD
        return result.getKey() < 0 ? -1 : (int) (result.getKey() % MOD);
    }
}


//Approach - 2 (Bottom Up)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
    final int MOD = 1000000007;

    public int maxProductPath(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;

        // Initialize the DP table
        Pair<Long, Long>[][] t = new Pair[m][n];

        // Base case: starting point
        t[0][0] = new Pair<>((long) grid[0][0], (long) grid[0][0]);

        // Fill the first row
        for (int j = 1; j < n; j++) {
            t[0][j] = new Pair<>(t[0][j - 1].getKey() * grid[0][j], t[0][j - 1].getValue() * grid[0][j]);
        }

        // Fill the first column
        for (int i = 1; i < m; i++) {
            t[i][0] = new Pair<>(t[i - 1][0].getKey() * grid[i][0], t[i - 1][0].getValue() * grid[i][0]);
        }

        // Fill the rest of the DP table
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                long upMax = t[i - 1][j].getKey();
                long upMin = t[i - 1][j].getValue();

                long leftMax = t[i][j - 1].getKey();
                long leftMin = t[i][j - 1].getValue();

                t[i][j] = new Pair<>(
                    Math.max(Math.max(upMax * grid[i][j], upMin * grid[i][j]), Math.max(leftMax * grid[i][j], leftMin * grid[i][j])),
                    Math.min(Math.min(upMax * grid[i][j], upMin * grid[i][j]), Math.min(leftMax * grid[i][j], leftMin * grid[i][j]))
                );
            }
        }

        // Get the result from the bottom-right corner
        long maxProd = t[m - 1][n - 1].getKey();

        // If the result is negative, return -1, otherwise return the result modulo MOD
        return maxProd < 0 ? -1 : (int) (maxProd % MOD);
    }
}
