/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=uY3mWwJvRkA
    Company Tags                : Apply, Amazon, Meta, Microsoft
    Leetcode Link               : https://leetcode.com/problems/maximum-ice-cream-bars/
*/


/*********************************************************** C++ **************************************************/
//Approach-1 (Normal Sorting and greedily choosing)
//T.C : O(n log n)
//S.C : O(1) (ignoring the space taken for sorting internally)
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


//Approach-2 (Counting Sorting and greedily choosing)
//T.C : O(maxCost)
//S.C : O(1) (ignoring the space taken for sorting internally)
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxCost = *max_element(begin(costs), end(costs));
        
        // count[c] = how many ice creams cost exactly c
        vector<int> count(maxCost + 1, 0);
        for (int cost : costs)
            count[cost]++;
        
        int total = 0;
        for (int cost = 1; cost <= maxCost; cost++) {
            if (count[cost] == 0)
                continue;
            
            if (coins < cost)
                break;
            
            // Jitna possible hai buy kar lo
            int buy_kiya = min(count[cost], coins / cost);
            total += buy_kiya;
            coins -= buy_kiya * cost;
        }
        
        return total;
    }
};

/*********************************************************** JAVA **************************************************/
//Approach-1 (Normal Sorting and greedily choosing)
//T.C : O(n log n)
//S.C : O(1) (ignoring the space taken for sorting internally)
class Solution {
    public int maxIceCream(int[] costs, int coins) {
        Arrays.sort(costs);
        
        int count = 0;
        
        for (int cost : costs) {
            if (cost > coins)
                return count;
            else {
                count++;
                coins -= cost;
            }
        }
        
        return count;
    }
}


//Approach-2 (Counting Sorting and greedily choosing)
//T.C : O(maxCost)
//S.C : O(1) (ignoring the space taken for sorting internally)
class Solution {
    public int maxIceCream(int[] costs, int coins) {
        int maxCost = 0;
        for (int cost : costs)
            maxCost = Math.max(maxCost, cost);
        
        // count[c] = how many ice creams cost exactly c
        int[] count = new int[maxCost + 1];
        for (int cost : costs)
            count[cost]++;
        
        int total = 0;
        for (int cost = 1; cost <= maxCost; cost++) {
            if (count[cost] == 0)
                continue;
            
            if (coins < cost)
                break;
            
            // Jitna possible hai buy kar lo
            int buy_kiya = Math.min(count[cost], coins / cost);
            total += buy_kiya;
            coins -= (long) buy_kiya * cost > coins ? 0 : buy_kiya * cost;
        }
        
        return total;
    }
}
