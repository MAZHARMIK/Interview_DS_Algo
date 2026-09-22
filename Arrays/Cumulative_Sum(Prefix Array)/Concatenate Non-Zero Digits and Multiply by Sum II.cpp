/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=zmc_FoPw_WQ
    Company Tags                : Will update later
    Leetcode Link               : https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-ii/
*/


/************************************************************ C++ *****************************************************/
//Approach (Pre Storing all relevant Data and using them)
//T.C : O(n+q), n = s.length() and q = total queries
//S.C : O(n)
class Solution {
public:
    int MOD = 1e9+7;
    typedef long long ll;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();

        vector<int> nonZeroCount(n, 0);    // non-zero digits count in s[0..i]
        vector<ll> numberUpTo(n, 0);      // number formed from non-zero digits in s[0..i]
        vector<ll> digitSumUpTo(n, 0);    // digit sum of s[0..i]
        vector<ll> pow10(n + 1, 0);  // 10^i

        pow10[0] = 1;
        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;


        nonZeroCount[0]      = (s[0] != '0') ? 1 : 0;
        numberUpTo[0]   = s[0] - '0';
        digitSumUpTo[0] = s[0] - '0';

        for (int i = 1; i < n; i++) {
            int digit = s[i] - '0';
            nonZeroCount[i] = nonZeroCount[i - 1] + (digit != 0 ? 1 : 0);
        }

        for (int i = 1; i < n; i++) {
            int digit = s[i] - '0';
            if (digit != 0)
                numberUpTo[i] = (numberUpTo[i - 1] * 10 + digit) % MOD;
            else
                numberUpTo[i] = numberUpTo[i - 1];
        }

        for (int i = 1; i < n; i++) {
            digitSumUpTo[i] = digitSumUpTo[i - 1] + (s[i] - '0');
        }

        int q = queries.size();
        vector<int> result(q);

        for (int i = 0; i < q; i++) {
            int l  = queries[i][0];
            int r = queries[i][1];

            int startCount = (l == 0) ? 0 : nonZeroCount[l - 1];
            ll numBefore   = (l == 0) ? 0 : numberUpTo[l - 1];

            int endCount = nonZeroCount[r];
            int subStrLen = endCount - startCount;

            if (subStrLen == 0) {
                result[i] = 0;
                continue;
            }

            ll x   = (numberUpTo[r] - (numBefore * pow10[subStrLen] % MOD) + MOD) % MOD;
            ll sum = digitSumUpTo[r] - ((l == 0) ? 0 : digitSumUpTo[l - 1]);

            result[i] = (int)((x * sum) % MOD);
        }

        return result;
    }
};




/************************************************************ JAVA *****************************************************/
//Approach (Pre Storing all relevant Data and using them)
//T.C : O(n+q), n = s.length() and q = total queries
//S.C : O(n)
class Solution {
    static final long MOD = 1_000_000_007L;

    public int[] sumAndMultiply(String s, int[][] queries) {
        int n = s.length();

        int[]  nonZeroCount = new int[n];      // non-zero digits count in s[0..i]
        long[] numberUpTo   = new long[n];     // number formed from non-zero digits in s[0..i]
        long[] digitSumUpTo = new long[n];     // digit sum of s[0..i]
        long[] pow10        = new long[n + 1]; // 10^i

        pow10[0] = 1;
        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        nonZeroCount[0] = (s.charAt(0) != '0') ? 1 : 0;
        numberUpTo[0]   = s.charAt(0) - '0';
        digitSumUpTo[0] = s.charAt(0) - '0';

        for (int i = 1; i < n; i++) {
            int digit = s.charAt(i) - '0';
            nonZeroCount[i] = nonZeroCount[i - 1] + (digit != 0 ? 1 : 0);
        }

        for (int i = 1; i < n; i++) {
            int digit = s.charAt(i) - '0';
            if (digit != 0)
                numberUpTo[i] = (numberUpTo[i - 1] * 10 + digit) % MOD;
            else
                numberUpTo[i] = numberUpTo[i - 1];
        }

        for (int i = 1; i < n; i++) {
            digitSumUpTo[i] = digitSumUpTo[i - 1] + (s.charAt(i) - '0');
        }

        int q = queries.length;
        int[] result = new int[q];

        for (int i = 0; i < q; i++) {
            int l = queries[i][0];
            int r = queries[i][1];

            int  startCount = (l == 0) ? 0 : nonZeroCount[l - 1];
            long numBefore  = (l == 0) ? 0 : numberUpTo[l - 1];

            int endCount  = nonZeroCount[r];
            int subStrLen = endCount - startCount;

            if (subStrLen == 0) {
                result[i] = 0;
                continue;
            }

            long x   = (numberUpTo[r] - (numBefore * pow10[subStrLen] % MOD) + MOD) % MOD;
            long sum = digitSumUpTo[r] - ((l == 0) ? 0 : digitSumUpTo[l - 1]);

            result[i] = (int) ((x * sum) % MOD);
        }

        return result;
    }
}
