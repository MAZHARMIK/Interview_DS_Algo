/*     Scroll below to see JAVA code as well    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : TBD
    What is Meet In The Middle  : https://www.youtube.com/watch?v=NCr27WYjCH4
    Company Tags                : Will update later
    CSES Link                   : https://leetcode.com/problems/closest-subsequence-sum/description/
*/


/******************************************************************************* C++ ************************************************************************************************/
//Approach (Using MITM)
//T.C : O(n · 2^(n/2))
//S.C : O(2^(n/2))
class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();

        int n1 = n / 2;
        int n2 = n - n1;

        vector<int> sumsA(1LL << n1);
        for (int mask = 0; mask < (1 << n1); mask++) {
            int s = 0;
            for (int i = 0; i < n1; i++)
                if (mask & (1 << i)) s += nums[i];
            sumsA[mask] = s;
        }

        vector<int> sumsB(1LL << n2);
        for (int mask = 0; mask < (1 << n2); mask++) {
            int s = 0;
            for (int i = 0; i < n2; i++)
                if (mask & (1 << i)) s += nums[n1 + i];
            sumsB[mask] = s;
        }

        sort(begin(sumsB), end(sumsB));

        int minValue = INT_MAX;
        for (int sum1 : sumsA) {
            int need = goal - sum1;
            int low  = lower_bound(begin(sumsB), end(sumsB), need) - begin(sumsB);

            if (low < sumsB.size()) {
                int sum2 = sumsB[low];
                int total = sum1 + sum2;
                minValue = min(minValue, abs(total - goal));
            }

            if (low > 0) {
                int sum2 = sumsB[low-1];
                int total = sum1 + sum2;
                minValue = min(minValue, abs(total - goal));
            }
        }

        return minValue;
    }
};



/******************************************************************************* JAVA ************************************************************************************************/
//Approach (Using MITM)
//T.C : O(n · 2^(n/2))
//S.C : O(2^(n/2))
class Solution {
    //returns index of first element >= need (insertion point), i.e. C++ lower_bound
    private int lowerBound(int[] sumsB, int need) {
        int lo = 0, hi = sumsB.length;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (sumsB[mid] < need) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }

    public int minAbsDifference(int[] nums, int goal) {
        int n = nums.length;
        int n1 = n / 2;
        int n2 = n - n1;

        int[] sumsA = new int[1 << n1];
        for (int mask = 0; mask < (1 << n1); mask++) {
            int s = 0;
            for (int i = 0; i < n1; i++)
                if ((mask & (1 << i)) != 0) s += nums[i];
            sumsA[mask] = s;
        }

        int[] sumsB = new int[1 << n2];
        for (int mask = 0; mask < (1 << n2); mask++) {
            int s = 0;
            for (int i = 0; i < n2; i++)
                if ((mask & (1 << i)) != 0) s += nums[n1 + i];
            sumsB[mask] = s;
        }

        Arrays.sort(sumsB);

        int minValue = Integer.MAX_VALUE;
        for (int sum1 : sumsA) {
            int need = goal - sum1;
            int low  = lowerBound(sumsB, need);
        
            if (low < sumsB.length) {
                int sum2 = sumsB[low];
                int total = sum1 + sum2;
                minValue = Math.min(minValue, Math.abs(total - goal));
            }
        
            if (low > 0) {
                int sum2 = sumsB[low - 1];
                int total = sum1 + sum2;
                minValue = Math.min(minValue, Math.abs(total - goal));
            }
        }
        
        return minValue;
    }
}
