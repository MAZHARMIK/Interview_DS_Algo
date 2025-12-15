/*     Scroll below to see JAVA code as well    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Will update later
    Leetcode Link               : https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock
*/


/************************************************************ C++ *****************************************************/
//Approach (Simple iterate and accumulate)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long result = 1;
        long long count = 1;

        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i - 1] - prices[i] == 1)
                count++;
            else
                count = 1;
            
            result += count;
        }
        return result;
    }
};



/************************************************************ JAVA *****************************************************/
//Approach (Simple iterate and accumulate)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public long getDescentPeriods(int[] prices) {
        long result = 1;
        long count = 1;

        for (int i = 1; i < prices.length; i++) {
            if (prices[i - 1] - prices[i] == 1) {
                count++;
            } else {
                count = 1;
            }
            result += count;
        }
        return result;
    }
}
