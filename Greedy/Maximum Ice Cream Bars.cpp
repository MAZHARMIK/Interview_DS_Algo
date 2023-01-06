/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=uY3mWwJvRkA
    Company Tags                : Apply, Amazon, Meta, Microsoft
    Leetcode Link               : https://leetcode.com/problems/maximum-ice-cream-bars/
*/

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(begin(costs), end(costs));
        
        int count = 0;
        
        for(int &cost : costs) {
            if(cost > coins)
                return count;
            else {
                count++;
                coins -= cost;
            }
        }
        
        return count;
    }
};
