/*      Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS QN : https://www.youtube.com/watch?v=vGI75BQhDVI
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/maximum-strength-of-k-disjoint-subarrays/
*/


/***************************************************************** C++ *****************************************************************/
//Approach-1 (Recur + Memo)
//T.C : O(n*k*2) ~= O(n*k)
//S.C : O(n*k*2) ~= O(n*k)
class Solution {
public:
    #define ll long long
    vector<vector<vector<ll>>> dp;
    int n;

    ll solve(int i, ll k, vector<int>& nums, bool start_new) {
        if(k == 0)
            return 0;
        if(i >= n) 
            return -1e18;
        
        if (dp[i][k][start_new] != -1)
            return dp[i][k][start_new];

        ll not_take = -1e18;
        ll take     = -1e18;
        
        //CASE : NOT_TAKE
        //Skipping - You can't continue past subarray with skipping current element
        //So, when you skip, you MUST start new subarray
        if (start_new == true) {
            not_take = solve(i + 1, k, nums, true); // skip the present element
        }

        //CASE : TAKE
        if (k%2 != 0) { // if k is odd then add, otherwise subtract
            take = solve(i + 1, k, nums, false) + nums[i] * k; // take and continue the current subarray 
            take = max(take, solve(i + 1, k - 1, nums, true) + nums[i] * k); // take and start new subarray
        } else {
            take = solve(i + 1, k, nums, false) - nums[i] * k;
            take = max(take, solve(i + 1, k - 1, nums, true) - nums[i] * k);
        }

        return dp[i][k][start_new] = max(not_take, take);
    }

    ll maximumStrength(vector<int>& nums, int k) {
        ll ans = 0;
        n = nums.size();

        dp.resize(n + 1, vector<vector<ll>>(k + 1, vector<ll>(2, -1)));
        
        bool start_new = true;

        return solve(0, k, nums, start_new);
    }
};




/***************************************************************** JAVA *****************************************************************/
//Approach-1 (Recur + Memo)
//T.C : O(n*k*2) ~= O(n*k)
//S.C : O(n*k*2) ~= O(n*k)
public class Solution {
    private long[][][] dp;
    private int n;

    private long solve(int i, long k, int[] nums, boolean startNew) {
        if (k == 0)
            return 0;
        if (i >= n)
            return (long) -1e18;

        if (dp[i][(int) k][startNew ? 1 : 0] != (long) -1e18)
            return dp[i][(int) k][startNew ? 1 : 0];

        long notTake = (long) -1e18;
        long take = (long) -1e18;

        // CASE: NOT_TAKE
        // Skipping - You can't continue past subarray with skipping the current element
        // So, when you skip, you MUST start a new subarray
        if (startNew) {
            notTake = solve(i + 1, k, nums, true); // skip the present element
        }

        // CASE: TAKE
        if (k % 2 != 0) { // if k is odd then add, otherwise subtract
            take = solve(i + 1, k, nums, false) + nums[i] * k; // take and continue the current subarray
            take = Math.max(take, solve(i + 1, k - 1, nums, true) + nums[i] * k); // take and start a new subarray
        } else {
            take = solve(i + 1, k, nums, false) - nums[i] * k;
            take = Math.max(take, solve(i + 1, k - 1, nums, true) - nums[i] * k);
        }

        return dp[i][(int) k][startNew ? 1 : 0] = Math.max(notTake, take);
    }

    public long maximumStrength(int[] nums, int k) {
        n = nums.length;
        dp = new long[n + 1][k + 1][2];

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                Arrays.fill(dp[i][j], (long) -1e18);
            }
        }

        boolean startNew = true;

        return solve(0, k, nums, startNew);
    }
}
