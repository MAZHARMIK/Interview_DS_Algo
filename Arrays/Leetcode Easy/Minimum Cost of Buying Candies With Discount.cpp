/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=zbnOyj11Eao
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount
*/

/*********************************************************** C++ **************************************************/

//Approach-1 (Sorting + Greedy Skip Every 3rd)
//T.C : O(n log n)
//S.C : O(1)
class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        sort(begin(cost), end(cost), greater<int>());

        int total = 0;

        for (int i = 0; i < n; i++) {
            if (i % 3 != 2)
                total += cost[i];
        }
        return total;
    }
};

/*********************************************************** JAVA **************************************************/

//Approach-1 (Sorting + Greedy Skip Every 3rd)
//T.C : O(n log n)
//S.C : O(1)
class Solution {
    public int minimumCost(int[] cost) {
        int n = cost.length;
        Arrays.sort(cost);

        // Reverse the array to sort in descending order
        for (int l = 0, r = n - 1; l < r; l++, r--) {
            int temp = cost[l];
            cost[l] = cost[r];
            cost[r] = temp;
        }

        int total = 0;

        for (int i = 0; i < n; i++) {
            if (i % 3 != 2)
                total += cost[i];
        }
        return total;
    }
}
