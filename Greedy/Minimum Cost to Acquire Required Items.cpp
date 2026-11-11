/*         Scroll down to see JAVA code also                    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=WK_kd0RDd8k
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/minimum-cost-to-acquire-required-items/
*/


/********************************************************************* C++ ****************************************************************/
//Approach (Greedy)
//T.C : O(1)
//S.C : O(1)
class Solution {
public:
    typedef long long ll;

    ll minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        // Case A: bundle is costlier than buying item separately
        if (cost1 + cost2 <= costBoth) {
            return 1LL * cost1 * need1 + 1LL * cost2 * need2;
        }

        // Case B: bundle is better
        // Buy bundles as much as you can
        int both     = min(need1, need2);
        ll total = 1LL * both * costBoth;

        need1 -= both;
        need2 -= both;

        // Pending ones
        if(need1 > 0)
            total += 1LL * need1 * min(cost1, costBoth);
        else if(need2 > 0)
            total += 1LL * need2 * min(cost2, costBoth);

        return total;
    }
};



/********************************************************************* JAVA ****************************************************************/
//Approach (Greedy)
//T.C : O(1)
//S.C : O(1)
class Solution {
    public long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        // Case A: bundle is costlier than buying items separately
        if (cost1 + cost2 <= costBoth) {
            return 1L * cost1 * need1 + 1L * cost2 * need2;
        }

        // Case B: bundle is better
        // Buy bundles as much as you can
        int both = Math.min(need1, need2);
        long total = 1L * both * costBoth;

        need1 -= both;
        need2 -= both;

        // Pending ones
        if (need1 > 0) {
            total += 1L * need1 * Math.min(cost1, costBoth);
        } else if (need2 > 0) {
            total += 1L * need2 * Math.min(cost2, costBoth);
        }

        return total;
    }
}
