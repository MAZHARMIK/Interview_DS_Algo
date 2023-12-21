/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=MihxAUNFac0
    Company Tags                : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/buy-two-chocolates/
*/

//Approach (Simply find min and second min to check 2 chocolates price)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int minPrice    = INT_MAX;
        int secMinPrice = INT_MAX;
        
        for(int &price : prices) {
            if(price < minPrice) {
                secMinPrice = minPrice;
                minPrice    = price;
            } else {
                secMinPrice = min(secMinPrice, price);
            }
        }
        
        if(minPrice + secMinPrice > money)
            return money;
        
        return money - (minPrice + secMinPrice);
    }
};



//Approach (Simply find min and second min to check 2 chocolates price)
//T.C : O(n)
//S.C : O(1)
public class Solution {
    public int buyChoco(int[] prices, int money) {
        int minPrice = Integer.MAX_VALUE;
        int secMinPrice = Integer.MAX_VALUE;

        for (int price : prices) {
            if (price < minPrice) {
                secMinPrice = minPrice;
                minPrice = price;
            } else {
                secMinPrice = Math.min(secMinPrice, price);
            }
        }

        if (minPrice + secMinPrice > money) {
            return money;
        }

        return money - (minPrice + secMinPrice);
    }
}
