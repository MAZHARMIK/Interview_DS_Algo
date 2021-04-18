/*
    Company Tags  : Paytm, Morgan Stanley, Accolite, Amazon, Samsung, Snapdeal, Oracle, Synopsys
    Leetcode Link : https://leetcode.com/problems/coin-change/
*/

class Solution {
public:
    
    //Approach-1 (Recusrion+Memoized)
    int t[13][10001];
    int minCoinsToGetAmount_Memoized(vector<int>& coins, int amount, int n) {
        if(t[n][amount] != -1)
            return t[n][amount];
        
        //if there is no coin, then may be if I take infinite coins, I can reach to amount
        if(n == 0)
            return t[n][amount] = INT_MAX-1;
        
        //if amount is 0, minimum coins to get 0 is 0
        if(amount == 0)
            return t[n][amount] = 0;
        
        //if there is only one coin, then we can reach to amount only if it's divisible
        //by that one coin value. Else it's not possible (hence returing invalid INT_MAX-1)
        if(n == 1) {
            if(amount%coins[n-1] == 0)
                return t[n][amount] = amount/coins[n-1];
            else
                return t[n][amount] = INT_MAX-1;
        }
        
        if(coins[n-1] <= amount)
            return t[n][amount] = min( 1+minCoinsToGetAmount_Memoized(coins, amount-coins[n-1], n), //unbounded knapsack
                         minCoinsToGetAmount_Memoized(coins,  amount, n-1));
        else
            return t[n][amount] = minCoinsToGetAmount_Memoized(coins, amount, n-1);
    }
    
    //Approach-2 (Top Down)
    int minCoinsToGetAmount_TopDown(vector<int>& coins, int& amount, int& n) {
        vector<vector<int>> t(n+1, vector<int>(amount+1, 0));
        
        for(int col = 0; col<amount+1; col++) {
            t[0][col] = INT_MAX-1;
        }
        
        for(int row = 1; row<n+1; row++) {
            t[row][0] = 0;
        }
        
        
        for(int col = 1; col<amount+1; col++) {
            if(col%coins[0] == 0)
                t[1][col] = col/coins[0];
            else
                t[1][col] = INT_MAX-1;
        }
        
        for(int i = 2; i<n+1; i++) {
            for(int j = 1; j<amount+1; j++) {
                if(coins[i-1] <= j) {
                    t[i][j] = min(1 + t[i][j-coins[i-1]], t[i-1][j]);
                } else {
                    t[i][j] = t[i-1][j];
                }
            }
        }
        
        return t[n][amount];
        
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        memset(t, -1, sizeof(t));
        //int minCoins = minCoinsToGetAmount_Memoized(coins, amount, n);
        int minCoins = minCoinsToGetAmount_TopDown(coins, amount, n);
        
        return minCoins==(INT_MAX-1)?-1:minCoins;
    }
};
