/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO LINK : 
    Company Tags          : Will update later
    Leetcode Link         : https://leetcode.com/problems/number-of-sets-of-k-non-overlapping-line-segments/
*/


/*********************************************************** C++ **************************************************/
//Approach-1 (Recursion Memo) - TLE
//T.C : O(n^2 * k)
//S.C : O(n*K)
class Solution {
public:
    const int MOD = 1e9+7;
    int t[1001][1001];
    
    int solve(int n, int k, int i) {
        if (k == 0) 
            return 1;

        if (i >= n) 
            return 0;

        if (t[k][i] != -1) 
            return t[k][i];

        // take: start a segment at point i, ending at some j > i
        long long take = 0;
        for (int j = i+1; j < n; j++) 
            take = (take + solve(n, k-1, j)) % MOD;

        // skip: don't start a segment at point i, move to i+1
        long long skip = solve(n, k, i+1) % MOD;

        return t[k][i] = take + skip;
    }

    int numberOfSets(int n, int k) {
        memset(t, -1, sizeof(t));
        return solve(n, k, 0) % MOD;
    }
};


//Approach-2 (Recursion Memo) - TLE
//T.C : O(n^2 * k)
//S.C : O(n*K)
class Solution {
public:
    int M = 1e9 + 7;
    int dp[1001][1001];

    int numberOfSets(int n, int K) {

        for (int i = 0; i <= n; i++) {
            dp[0][i] = (i < n) ? 1 : 0;
        }

        for (int k = 1; k <= K; k++) {

            for (int i = n - 1; i >= 0; i--) {
                
                int skip = dp[k][i + 1];

                int take = 0;
                for (int j = i + 1; j < n; j++) {
                    take = (take + dp[k - 1][j]) % MOD;
                }

                dp[k][i] = (take + skip) % MOD;
            }
        }

        return dp[K][0];
    }
};


//Approach-3 (Bottom Up + PrevRow Sum Precomputed)
//T.C : O(n * k)
//S.C : O(n * K)
class Solution {
public:
    int M = 1e9 + 7;
    int dp[1001][1001];

    int numberOfSets(int n, int K) {

        for (int i = 0; i <= n; i++) {
            dp[0][i] = (i < n) ? 1 : 0;
        }

        for (int k = 1; k <= K; k++) {

            vector<int> prevRowSum(n + 1, 0);

            //prevRowSum[x] = dp[k-1][x] + dp[k-1][x+1] + ... + dp[k-1][n-1]
            for (int x = n - 1; x >= 0; x--) {
                prevRowSum[x] = (prevRowSum[x + 1] + dp[k - 1][x]) % MOD;
            }

            for (int i = n - 1; i >= 0; i--) {
                
                int skip = dp[k][i + 1];

                int take = prevRowSum[i+1];
                //dp[k-1][i+1] + dp[k-1][i+2] ...... + dp[k-1][n-1]

                dp[k][i] = (take + skip) % MOD;
            }
        }

        return dp[K][0];
    }
};


//Approach-4 (Combinatorics + Binary Exponentiation + Fermat's Little Theorem)
//T.C : O((n+k) * log(MOD)) ~= O(n+k)
//S.C : O(n + K)
#define ll long long
class Solution {
public:
    vector<ll> fact;
    vector<ll> invFact;
    const int MOD = 1e9+7;

    //Binary Exponentiation
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

    int numberOfSets(int n, int k) {
        //Precompute factoriala and inverse factorials
        fact.assign(n+k, 1);
        invFact.assign(n+k, 1);

        for(int i = 2; i < n+k; i++) {
            fact[i] = (fact[i-1] * i) % MOD;
        }

        //Fermat's little theorem for inverse factorials
        for(int i = 0; i < n+k; i++) {
            invFact[i] = findPower(fact[i], MOD-2);
        }

        return nCr(n+k-1, 2*k);
    }
};



/*********************************************************** JAVA **************************************************/
//Approach-1 (Recursion Memo) - TLE
//T.C : O(n^2 * k)
//S.C : O(n*K)
class Solution {
    int MOD = 1_000_000_007;
    int[][] t = new int[1001][1001];

    public int solve(int n, int k, int i) {
        if (k == 0) 
            return 1;

        if (i >= n) 
            return 0;

        if (t[k][i] != -1)
            return t[k][i];

        // take: start a segment at point i, ending at some j > i
        long take = 0;
        for (int j = i + 1; j < n; j++)
            take = (take + solve(n, k - 1, j)) % MOD;

        // skip: don't start a segment at point i, move to i+1
        long skip = solve(n, k, i + 1) % MOD;

        return t[k][i] = (int) ((take + skip) % MOD);
    }

    public int numberOfSets(int n, int k) {
        for (int[] row : t)
            Arrays.fill(row, -1);
        return solve(n, k, 0) % MOD;
    }
}


//Approach-2 (Recursion Memo) - TLE
//T.C : O(n^2 * k)
//S.C : O(n*K)
class Solution {
    int MOD = 1_000_000_007;
    int[][] dp = new int[1001][1001];

    public int numberOfSets(int n, int K) {

        for (int i = 0; i <= n; i++) {
            dp[0][i] = (i < n) ? 1 : 0;
        }

        for (int k = 1; k <= K; k++) {

            for (int i = n - 1; i >= 0; i--) {

                int skip = dp[k][i + 1];

                int take = 0;
                for (int j = i + 1; j < n; j++) {
                    take = (int) ((take + dp[k - 1][j]) % MOD);
                }

                dp[k][i] = (take + skip) % MOD;
            }
        }

        return dp[K][0];
    }
}


//Approach-3 (Bottom Up + PrevRow Sum Precomputed)
//T.C : O(n * k)
//S.C : O(n * K)
class Solution {
    int MOD = 1_000_000_007;
    int[][] dp = new int[1001][1001];

    public int numberOfSets(int n, int K) {

        for (int i = 0; i <= n; i++) {
            dp[0][i] = (i < n) ? 1 : 0;
        }

        for (int k = 1; k <= K; k++) {

            int[] prevRowSum = new int[n + 1];

            //prevRowSum[x] = dp[k-1][x] + dp[k-1][x+1] + ... + dp[k-1][n-1]
            for (int x = n - 1; x >= 0; x--) {
                prevRowSum[x] = (int) ((prevRowSum[x + 1] + dp[k - 1][x]) % MOD);
            }

            for (int i = n - 1; i >= 0; i--) {

                int skip = dp[k][i + 1];

                int take = prevRowSum[i + 1];
                //dp[k-1][i+1] + dp[k-1][i+2] ...... + dp[k-1][n-1]

                dp[k][i] = (take + skip) % MOD;
            }
        }

        return dp[K][0];
    }
}


//Approach-4 (Combinatorics + Binary Exponentiation + Fermat's Little Theorem)
//T.C : O((n+k) * log(MOD)) ~= O(n+k)
//S.C : O(n + K)
class Solution {
    long[] fact;
    long[] invFact;
    final int MOD = 1_000_000_007;

    //Binary Exponentiation
    public long findPower(long a, long b) {
        if (b == 0)
            return 1;

        long half = findPower(a, b / 2);
        long result = (half * half) % MOD;

        if (b % 2 == 1) {
            result = (result * a) % MOD;
        }

        return result;
    }

    //nCr % MOD
    public long nCr(int n, int r) {
        //nCr = n! * inv(n-r)! * inv(r)!
        return (((fact[n] * invFact[r]) % MOD) * invFact[n - r]) % MOD;
    }

    public int numberOfSets(int n, int k) {
        //Precompute factorials and inverse factorials
        fact = new long[n + k];
        invFact = new long[n + k];
        Arrays.fill(fact, 1);
        Arrays.fill(invFact, 1);

        for (int i = 2; i < n + k; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }

        //Fermat's little theorem for inverse factorials
        for (int i = 0; i < n + k; i++) {
            invFact[i] = findPower(fact[i], MOD - 2);
        }

        return (int) nCr(n + k - 1, 2 * k);
    }
}
