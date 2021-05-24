/*
    Company Tags  : Amazon, Mu Sigma
    Leetcode Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/submissions/
*/

//Approach-1 (Recursion+Memoization) Time : O(2^n)
class Solution {
public:
    int maxProfitUtil(vector<int>& prices, int index, bool buy, int k, int t[][2][3]) {
        if(index >= prices.size() || k == 0)
            return 0;
        if(t[index][buy][k] != -1)
            return t[index][buy][k];
        int max_profit = 0;
        if(buy) {
            int buys    = maxProfitUtil(prices, index+1, false, k, t) - prices[index];
            int no_buy  = maxProfitUtil(prices, index+1, true, k, t);
            max_profit  = max(buys, no_buy);
        } else {
            int sells    = maxProfitUtil(prices, index+1, true, k-1, t) + prices[index];
            int no_sell  = maxProfitUtil(prices, index+1, false, k, t);
            max_profit   = max(sells, no_sell);
        }
        return t[index][buy][k] = max_profit;
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 1)
            return 0;
        int t[n+1][2][3];
        memset(t,-1,sizeof(t));
        return maxProfitUtil(prices, 0, true, 2, t);
    }
};

//Approach-2 (DP) Time : O(n), Space : O(n)
class Solution {
public:
    int maxP(vector<int>& prices, int& n) {
        if(n <= 1)
            return 0;
        
        vector<int> profit1(n, 0);
        vector<int> profit2(n, 0);
        
        //calculating profit1 from left to right for first transaction
        int BuyMin = prices[0];
        profit1[0] = 0; //If there is only 1 day, you can't buy, you'll be in loss
        
        for(int i = 1; i<n; i++) {
            profit1[i] = max(profit1[i-1], prices[i]-BuyMin);
            BuyMin = min(BuyMin, prices[i]);
        }
        
        //calculating profit2 from right to left for second transaction
        /*
            Why right to left ?
            It will give the result in descending order
            Then finding max while adding (proft1[i] + profit2[i+1]) will be handy
        */
        int SellMax = prices[n-1];
        profit2[n-1] = 0; //You can't sell without buying
        
        for(int i = n-2; i>=0; i--) {
            profit2[i] = max(profit2[i+1], SellMax-prices[i]);
            SellMax    = max(SellMax, prices[i]);
        }
        
        int maxProfit = 0;
        for(int i = 0; i<n; i++) {
            int first_tra  = profit1[i];
            int second_tra = i+1 < n ? profit2[i+1] : 0;
            
            maxProfit = max(maxProfit, first_tra + second_tra);
        }
        return maxProfit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return maxP(prices, n);
    }
};
