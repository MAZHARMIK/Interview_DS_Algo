/*     Scroll below to see JAVA code    */
/*
    MY YOUTUBE VIDEO ON THIS Qn                : https://www.youtube.com/watch?v=6BAXeAsgeyc
    Company Tags                               : will soon update
    Leetcode Link                              : https://leetcode.com/problems/count-the-number-of-arrays-with-k-matching-adjacent-elements
    
*/

/****************************************************** C++ **************************************************************/
//Approach - Using maths Combinatorics
//T.C : O(log(n-k-1))
//S.C : O(n)
int MOD = 1e9+7;
class Solution {
public:
    //Binary exponentiation T.C : O(log(b))
    int findPower(long long a, long long b) {
        if(b == 0)
            return 1;

        long long half = findPower(a, b/2);
        long long result = (half * half) % MOD;

        if(b%2 == 1) {
            result = (result * a) % MOD;
        }

        return result;
    }

    //nCr ka formula apply karne k lie
    long long nCr(int n, int r, vector<long long>& factorial, vector<long long>& fermatFact) {
        //n!/((n-r)! * r!)) % MOD
        //n! * 
        return factorial[n] * fermatFact[n-r] % MOD * fermatFact[r] % MOD; //O(1)
    }

    int countGoodArrays(int n, int m, int k) {
        vector<long long> factorial(n+1, 1);
        factorial[0] = 1;
        factorial[1] = 1;
        for(int i = 2; i <= n; i++) {
            factorial[i] = (factorial[i-1] * i) % MOD;
        }

        //Inverse factorial precalculate - Fermat's little theorem
        vector<long long> fermatFact(n+1, 1);
        for(int i = 0; i <= n; i++) {
            fermatFact[i] = findPower(factorial[i], MOD-2);
        }

        long long result = nCr(n-1, k, factorial, fermatFact); //n-1Ck

        result = result * m % MOD;

        result = result * findPower(m-1, n-k-1) % MOD; //T.C : log(n-k-1)


        return result;
    }
};


/****************************************************** JAVA **************************************************************/
//Approach - Using maths Combinatorics
//T.C : O(log(n-k-1))
//S.C : O(n)
class Solution {
    static final int MOD = (int)1e9 + 7;

    // Binary exponentiation: a^b % MOD
    public long power(long a, long b) {
        long result = 1;
        a %= MOD;
        while (b > 0) {
            if ((b & 1) == 1)
                result = (result * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return result;
    }

    // nCr % MOD using precomputed factorials and Fermat's inverse
    public long nCr(int n, int r, long[] fact, long[] invFact) {
        return fact[n] * invFact[n - r] % MOD * invFact[r] % MOD;
    }

    public int countGoodArrays(int n, int m, int k) {
        long[] fact = new long[n + 1];
        long[] invFact = new long[n + 1];

        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }

        // Compute inverse factorials using Fermat's Theorem
        for (int i = 0; i <= n; i++) {
            invFact[i] = power(fact[i], MOD - 2);
        }

        long result = nCr(n - 1, k, fact, invFact);  // Choose k positions
        result = result * m % MOD;                   // First element: m options
        result = result * power(m - 1, n - k - 1) % MOD; // Rest elements

        return (int) result;
    }
}
