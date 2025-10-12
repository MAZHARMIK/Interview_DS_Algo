/*      SCROLL BELOW TO SEE JAVA CODE AS WELL    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will soon update
    Leetcode Link               : https://leetcode.com/problems/find-sum-of-array-product-of-magical-sequences
*/


/************************************************************ C++ ***************************************************************************/
//Approach : Usin Recursion + Memo with Bit Memoization (Digit DP)
//T.C : 
//S.C : 
class Solution {
public:
    typedef long long ll;
    const int MOD = 1e9+7;
    int N, K;

    map<tuple<ll, int , int, int>, ll> memo;

    vector<ll> fact;
    vector<ll> invFact;

    ll findPower(ll a, ll b) {
        if(b == 0)
            return 1;
        
        ll half = findPower(a, b/2);
        ll result = (half * half) % MOD;

        if(b%2 == 1) {
            result = (result * a) % MOD;
        }

        return result;
    }

    //nCr % MOD
    ll nCr(int n, int r) {
        //nCr = n! * inv(n-r)! * inv(r)!
        return (((fact[n] * invFact[r]) % MOD) * invFact[n-r]) % MOD;
    }

    ll solve(ll binarySum, int m, int k, int i, vector<int>& nums) {
        auto key = make_tuple(binarySum, m, k, i);

        if(memo.count(key)) {
            return memo[key];
        }

        if(m == 0 && __builtin_popcount(binarySum) == k) {
            return 1;
        }

        if(m == 0 || i >= N) {
            return 0;
        }

        ll totalSum = 0;

        //Skip index i
        totalSum = (totalSum + solve((binarySum >> 1), m, k - (binarySum & 1), i+1, nums)) % MOD;

        //Take index i freq number of times
        for(int freq = 1; freq <= m; freq++) {
            ll newBinarySum = binarySum + freq;

            ll prod = solve((newBinarySum >> 1), m - freq, k - (newBinarySum & 1), i+1, nums);

            prod = (findPower(nums[i], freq) % MOD * prod % MOD) % MOD;

            prod = (prod * nCr(m, freq)) % MOD;

            totalSum = (totalSum + prod) % MOD;
        }

        return memo[key] = totalSum;
    }

    int magicalSum(int m, int k, vector<int>& nums) {
        K = k;
        N = nums.size();

        //Precompute factoriala and inverse factorials
        fact.assign(m+1, 1);
        invFact.assign(m+1, 1);

        for(int i = 2; i <= m; i++) {
            fact[i] = (fact[i-1] * i) % MOD;
        }

        //Fermat's little theorem for inverse factorials
        for(int i = 0; i <= m; i++) {
            invFact[i] = findPower(fact[i], MOD-2);
        }

        return (int)(solve(0, m, k, 0, nums) % MOD);

    }
};



/************************************************************ JAVA ***************************************************************************/
//Approach : Usin Recursion + Memo with Bit Memoization (Digit DP)
//T.C : 
//S.C : 
class Solution {
    static final int MOD = 1_000_000_007;
    int N, K;
    long[] fact, invFact;
    Map<String, Long> memo;

    // Fast exponentiation (binary exponentiation)
    long findPower(long a, long b) {
        if (b == 0) return 1;
        long half = findPower(a, b / 2);
        long result = (half * half) % MOD;
        if (b % 2 == 1) result = (result * a) % MOD;
        return result;
    }

    // Compute nCr % MOD
    long nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        return (((fact[n] * invFact[r]) % MOD) * invFact[n - r]) % MOD;
    }

    long solve(long binarySum, int m, int k, int i, int[] nums) {
        String key = binarySum + "," + m + "," + k + "," + i;
        if (memo.containsKey(key)) return memo.get(key);

        if (m == 0 && Long.bitCount(binarySum) == k)
            return 1;
        if (m == 0 || i >= N)
            return 0;

        long totalSum = 0;

        // Option 1: skip current element
        totalSum = (totalSum + solve(binarySum >> 1, m, k - (int)(binarySum & 1), i + 1, nums)) % MOD;

        // Option 2: use current element multiple times
        for (int freq = 1; freq <= m; freq++) {
            long newBinarySum = binarySum + freq;
            long prod = solve(newBinarySum >> 1, m - freq, k - (int)(newBinarySum & 1), i + 1, nums);

            prod = (findPower(nums[i], freq) % MOD * prod % MOD) % MOD;
            prod = (prod * nCr(m, freq)) % MOD;
            totalSum = (totalSum + prod) % MOD;
        }

        memo.put(key, totalSum);
        return totalSum;
    }

    public int magicalSum(int m, int k, int[] nums) {
        this.K = k;
        this.N = nums.length;

        fact = new long[m + 1];
        invFact = new long[m + 1];
        memo = new HashMap<>();

        fact[0] = 1;
        for (int i = 1; i <= m; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }

        for (int i = 0; i <= m; i++) {
            invFact[i] = findPower(fact[i], MOD - 2);
        }

        return (int)(solve(0L, m, k, 0, nums) % MOD);
    }
}
