/*
    Company Tags     : Amazon, Morgan Stanley, Oracle, Paytm, Accolite, Samsung, Snapdeal, Synopsys, visa
    Leetcode Qn Link : https://leetcode.com/problems/coin-change-2/
*/

//Approach-1 (Recusrion+Memoized)
class Solution {
public:
    int solve(vector<int>& S, int n, int sum, vector<vector<int>>& t) {
        //There is only one combination that sum upto sum=0 i.e. when we take 0 coin. So, 1 way
        if(sum == 0)
            return t[n][sum] = 1;
        
        //if(we have no coin then we can't do anything about it. So, 0 way
        if(n == 0 || sum < 0)
            return 0;
        
        if(t[n][sum] != -1)
            return t[n][sum];
        
                                //taken                       //not taken
        return t[n][sum] = (solve(S, n, sum-S[n-1], t) + solve(S, n-1, sum, t));
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> t(n+1, vector<int>(amount+1, -1));
        return solve(coins, n, amount, t);
    }
};

////Approach-2 (Top Down)
class Solution {
public:
    int combi(vector<int>& coins, int amount, int n) {
        vector<vector<int>> t(n+1, vector<int>(amount+1));
        
        for(int i = 0; i<n+1; i++) {
            for(int j = 0; j<amount+1; j++) {
                if(j == 0) {
                    t[i][j] = 1;
                } else if(i == 0) {
                    t[i][j] = 0;
                } else if(coins[i-1] <= j) {
                    t[i][j] = t[i][j-coins[i-1]] + t[i-1][j];
                } else {
                    t[i][j] = t[i-1][j];
                }
            }
        }
        
        return t[n][amount];
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        
        return combi(coins, amount, n);
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
                int remain_amount = j-curr_coin; //Kis kis amount me tumne curr_coin add kara hoga to reach j
                
                //ways[remain_amount] = # ways to get amount "remain_amount"
                
                //ways[j] = # ways to get amount "j"
                ways[j] = ways[j] + ways[remain_amount];
            }
        }
                
        return ways[amount];
    }
};
