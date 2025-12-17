/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Will update later
    Leetcode Link               : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-v
*/


/**************************************************************** C++ ****************************************************************/
//Approach-1 (Recursion + Memoization)
//T.C : O(n * k)
//S.C : O(n * k)
class Solution {
public:
    long long t[1001][501][3];

    // CASE:
    // 0 -> You have not bought anything and you have not short-sold anything.
    // 1 -> Normal transaction - you had bought, now you will sell normally
    // 2 -> Short selling transaction - you had sold, now you will buy back
    long long solve(int i, int k, int CASE, vector<int>& prices) {

        if (i == prices.size()) {
            if (CASE == 0)
                return 0;
            return INT_MIN; //an unfinished transaction is invalid.
        }

        if (t[i][k][CASE] != INT_MIN)
            return t[i][k][CASE];

        long long take = INT_MIN;
        long long dontTake;

        // Do nothing today
        dontTake = solve(i + 1, k, CASE, prices);

        // Take action
        if (k > 0) {
            if (CASE == 1) {
                // Sell today (complete normal transaction)
                take = prices[i] + solve(i + 1, k - 1, 0, prices);
            }
            else if (CASE == 2) {
                // Buy back today (complete short transaction)
                take = -prices[i] + solve(i + 1, k - 1, 0, prices);
            }
            else {
                // CASE == 0: start a transaction
                take = max(
                    -prices[i] + solve(i + 1, k, 1, prices), // buy (normal)
                     prices[i] + solve(i + 1, k, 2, prices)  // short sell
                );
            }
        }

        return t[i][k][CASE] = max(take, dontTake);
    }

    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();

        for (int i = 0; i < n; i++)
            for (int j = 0; j <= k; j++)
                for (int l = 0; l < 3; l++)
                    t[i][j][l] = INT_MIN;

        return solve(0, k, 0, prices);
    }
};


//Approach-2 (Bottom Up)
//T.C : O(n * k)
//S.C : O(n * k)
class Solution {
public:
    long long maximumProfit(vector<int>& prices, int K) {
        int n = prices.size();

        long long t[1001][501][3];

        // Base case: i == n
        for (int k = 0; k <= K; k++) {
            t[n][k][0] = 0;
            t[n][k][1] = INT_MIN;
            t[n][k][2] = INT_MIN;
        }

        // Fill table bottom-up
        for (int i = n - 1; i >= 0; i--) {
            for (int k = 0; k <= K; k++) {
                
                //Don't take any action
                t[i][k][0] = t[i + 1][k][0];

                //Take action
                // CASE 0: no transaction in progress
                if (k > 0) {
                    t[i][k][0] = max(
                        t[i][k][0],
                        max(
                            -prices[i] + t[i + 1][k][1], // buy
                             prices[i] + t[i + 1][k][2]  // short sell
                        )
                    );
                }

                // CASE 1: holding long
                t[i][k][1] = t[i + 1][k][1]; // hold
                if (k > 0) {
                    t[i][k][1] = max(
                        t[i][k][1],
                        prices[i] + t[i + 1][k - 1][0]  // sell
                    );
                }

                // CASE 2: holding short
                t[i][k][2] = t[i + 1][k][2]; // hold
                if (k > 0) {
                    t[i][k][2] = max(
                        t[i][k][2],
                        -prices[i] + t[i + 1][k - 1][0] // buy back
                    );
                }
            }
        }

        // Start from day 0, k transactions, no open position
        return t[0][K][0];
    }
};




/**************************************************************** JAVA ****************************************************************/
//Approach-1 (Recursion + Memoization)
//T.C : O(n * k)
//S.C : O(n * k)
class Solution {

    // t[i][k][CASE]
    // CASE:
    // 0 -> No open transaction
    // 1 -> Holding long (bought, waiting to sell)
    // 2 -> Holding short (sold, waiting to buy back)
    long[][][] t;

    long solve(int i, int k, int CASE, int[] prices) {

        if (i == prices.length) {
            if (CASE == 0)
                return 0;
            return Long.MIN_VALUE / 2; // unfinished transaction is invalid
        }

        if (t[i][k][CASE] != Long.MIN_VALUE)
            return t[i][k][CASE];

        long take = Long.MIN_VALUE;
        long dontTake;

        // Do nothing today
        dontTake = solve(i + 1, k, CASE, prices);

        // Take action
        if (k > 0) {
            if (CASE == 1) {
                // Sell today (complete normal transaction)
                take = prices[i] + solve(i + 1, k - 1, 0, prices);
            }
            else if (CASE == 2) {
                // Buy back today (complete short transaction)
                take = -prices[i] + solve(i + 1, k - 1, 0, prices);
            }
            else {
                // CASE == 0: start a transaction
                take = Math.max(
                        -prices[i] + solve(i + 1, k, 1, prices), // buy
                         prices[i] + solve(i + 1, k, 2, prices)  // short sell
                );
            }
        }

        return t[i][k][CASE] = Math.max(take, dontTake);
    }

    public long maximumProfit(int[] prices, int k) {
        int n = prices.length;
        t = new long[n][k + 1][3];

        // Initialize memo table
        for (int i = 0; i < n; i++)
            for (int j = 0; j <= k; j++)
                for (int l = 0; l < 3; l++)
                    t[i][j][l] = Long.MIN_VALUE;

        return solve(0, k, 0, prices);
    }
}



//Approach-2 (Bottom Up)
//T.C : O(n * k)
//S.C : O(n * k)
class Solution {
    public long maximumProfit(int[] prices, int K) {
        int n = prices.length;

        long[][][] t = new long[n + 1][K + 1][3];

        // Base case: i == n
        for (int k = 0; k <= K; k++) {
            t[n][k][0] = 0;
            t[n][k][1] = Long.MIN_VALUE / 2;
            t[n][k][2] = Long.MIN_VALUE / 2;
        }

        // Fill table bottom-up
        for (int i = n - 1; i >= 0; i--) {
            for (int k = 0; k <= K; k++) {

                // CASE 0: no open transaction
                t[i][k][0] = t[i + 1][k][0]; // do nothing
                if (k > 0) {
                    t[i][k][0] = Math.max(
                            t[i][k][0],
                            Math.max(
                                    -prices[i] + t[i + 1][k][1], // buy
                                     prices[i] + t[i + 1][k][2]  // short sell
                            )
                    );
                }

                // CASE 1: holding long
                t[i][k][1] = t[i + 1][k][1]; // hold
                if (k > 0) {
                    t[i][k][1] = Math.max(
                            t[i][k][1],
                            prices[i] + t[i + 1][k - 1][0] // sell
                    );
                }

                // CASE 2: holding short
                t[i][k][2] = t[i + 1][k][2]; // hold
                if (k > 0) {
                    t[i][k][2] = Math.max(
                            t[i][k][2],
                            -prices[i] + t[i + 1][k - 1][0] // buy back
                    );
                }
            }
        }

        // Start from day 0, K transactions, no open position
        return t[0][K][0];
    }
}
