/*         Scroll down to see JAVA code also                    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Q9FTKzkAYHk
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/maximum-number-of-items-from-sale-ii
*/


/********************************************************************* C++ ****************************************************************/
//Approach (Greedily Pick "2 copy" items ensuring price < 2*cheapest_price)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        //count of each factor in items
        vector<int> freq(n + 1, 0);
        int cheapest_price = INT_MAX;
        for (auto& vec : items) {
            int f = vec[0];
            int p = vec[1];
            freq[f]++;
            cheapest_price = min(cheapest_price, p);
        }

        // factorSum[f] = how many items have a factor that is a multiple of f (including f itself)
        vector<int> factorSum(n + 1, 0); //f -> f, 2f, 3f....
        for (int f = 1; f <= n; f++) {
            for (int k = f; k <= n; k += f) {
                factorSum[f] += freq[k];
            }
        }

        // Store items which can give "2 copy" but ensure that its price < 2*cheapest_price
        //Later we sort on the basis of price - cheapest first
        vector<pair<int, int>> units;
        for (auto& vec : items) {
            int f = vec[0];
            int p = vec[1];

            int cnt = factorSum[f] - 1;          // exclude the item itself
            
            if (cnt > 0 && p < 2LL * cheapest_price)
                units.push_back({p, cnt});
        }

        sort(begin(units), end(units));

        int result = 0;

        for (auto& [price, factorCount] : units) {
            int k = min(factorCount, budget / price);
            budget -= k * price;
            result += 2 * k; //each item creates "2 copy" for us
        }

        result += budget / cheapest_price; //buy cheapest one with remaining budget
        return result;
    }
};



/********************************************************************* JAVA ****************************************************************/
//Approach (Greedily Pick "2 copy" items ensuring price < 2*cheapest_price)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
    public int maximumSaleItems(int[][] items, int budget) {
        int n = items.length;

        // count of each factor in items
        int[] freq = new int[n + 1];
        int cheapestPrice = Integer.MAX_VALUE;
        for (int[] vec : items) {
            int f = vec[0];
            int p = vec[1];
            freq[f]++;
            cheapestPrice = Math.min(cheapestPrice, p);
        }

        // factorSum[f] = how many items have a factor that is a multiple of f (including f itself)
        int[] factorSum = new int[n + 1]; // f -> f, 2f, 3f....
        for (int f = 1; f <= n; f++) {
            for (int k = f; k <= n; k += f) {
                factorSum[f] += freq[k];
            }
        }

        // Store items which can give "2 copy" but ensure that its price < 2*cheapestPrice
        // Later we sort on the basis of price - cheapest first
        List<int[]> units = new ArrayList<>();
        for (int[] vec : items) {
            int f = vec[0];
            int p = vec[1];

            int cnt = factorSum[f] - 1; // exclude the item itself

            if (cnt > 0 && p < 2L * cheapestPrice)
                units.add(new int[]{p, cnt});
        }

        units.sort((a, b) -> Integer.compare(a[0], b[0]));

        int result = 0;

        for (int[] unit : units) {
            int price = unit[0];
            int factorCount = unit[1];

            int k = Math.min(factorCount, budget / price);
            budget -= k * price;
            result += 2 * k; // each item creates "2 copy" for us
        }

        result += budget / cheapestPrice; // buy cheapest one with remaining budget
        return result;
    }
}
