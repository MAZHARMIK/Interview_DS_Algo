/*
    Company Tags     : Amazon, Morgan Stanley, Oracle, Paytm, Accolite, Samsung, Snapdeal, Synopsys, visa
    Leetcode Qn Link : https://leetcode.com/problems/coin-change/
*/

//Approach-1 (Recusrion+Memoized)
class Solution {
public:
    int solve(vector<int>& S, int n, int sum, vector<vector<int>>& t) {
        if(sum == 0)
            return t[n][sum] = 1;
        if(n == 0 || sum < 0)
            return 0;
        
        if(t[n][sum] != -1)
            return t[n][sum];
        
        return t[n][sum] = (solve(S, n, sum-S[n-1], t) + solve(S, n-1, sum, t));
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> t(n+1, vector<int>(amount+1, -1));
        return solve(coins, n, amount, t);
    }
};

//Approach-2 (Top Down)
class Solution {
public:
    int solve(vector<int>& coins, int n, int s) {
        vector<vector<int>> t(n+1, vector<int>(s+1));
    
        for(int col = 0; col<s+1; col++)
            t[0][col] = INT_MAX-1;
        for(int row = 1; row<n+1; row++)
            t[row][0] = 0;
        
        for(int col = 1; col<s+1; col++) {
            if(col%coins[0] == 0)
                t[1][col] = col/coins[0];
            else
                t[1][col] = INT_MAX-1;
        }
        
        for(int i = 2; i<n+1; i++) {
            for(int j = 1; j<s+1; j++) {
                if(coins[i-1] <= j) {
                    t[i][j] = min(1+t[i][j-coins[i-1]], t[i-1][j]);
                } else {
                    t[i][j] = t[i-1][j];
                }
            }
        }
        
        return t[n][s];
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int result = solve(coins, coins.size(), amount);
        if(result == INT_MAX-1)
            return -1;
        return result;
    }
};


//Approach-3 (Bottom up)
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        
        vector<int> ways(amount+1);
        //ways[i] = total # ways to get amount = i;
        //so, for amount = 0, we have one way {}
        ways[0] = 1;
        
        //take each coin one by one and see
        for(int i = 0; i<n; i++) {
            //I select a coin coins[i] and find # ways to get coins[i], coins[i]+1...until amount
            int curr_coin = coins[i];
            for(int j = curr_coin; j<=amount ; j++) {
                int remain_amount = j-curr_coin;
                
                //ways[remain_amount] = # ways to get remain_amount
                
                //ways[j] = # to get amount j
                ways[j] = ways[j] + ways[remain_amount];
            }
        }
                
        return ways[amount];
    }
};
