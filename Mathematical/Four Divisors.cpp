/*     Scroll below to see JAVA code    */
/*
    MY YOUTUBE VIDEO ON THIS Qn                : https://www.youtube.com/watch?v=MOYYok4_e0I
    Company Tags                               : Capital One, Amazon, Microsoft, Google, Meta
    Leetcode Link                              : https://leetcode.com/problems/four-divisors/description/
    
*/

/****************************************************** C++ **************************************************************/
//Approach - Simple maths - Iterate and find factors
//T.C : O(n * sqrt(maxNumber))
//S.C : O(1)
class Solution {
public:
    int sumIfFourDivisors(int num) {
        int divisors = 0;
        int sum = 0;

        for (int div = 1; div * div <= num; div++) {
            if (num % div == 0) {
                int other = num / div;

                if (div == other) {
                    divisors++;
                    sum += div;
                } else {
                    divisors += 2;
                    sum += (div + other);
                }
            }

            if (divisors > 4) {
                return 0;
            }
        }

        return divisors == 4 ? sum : 0;
    }

    int sumFourDivisors(vector<int>& nums) {
        int result = 0;

        for (int &num : nums) {
            result += sumIfFourDivisors(num);
        }

        return result;
    }
};


/****************************************************** JAVA **************************************************************/
//Approach - Simple maths - Iterate and find factors
//T.C : O(n * sqrt(maxNumber))
//S.C : O(1)
class Solution {

    private int sumIfFourDivisors(int num) {
        int divisors = 0;
        int sum = 0;

        for (int div = 1; div * div <= num; div++) {
            if (num % div == 0) {
                int other = num / div;

                if (div == other) {
                    divisors++;
                    sum += div;
                } else {
                    divisors += 2;
                    sum += div + other;
                }
            }

            if (divisors > 4) {
                return 0;
            }
        }

        return divisors == 4 ? sum : 0;
    }

    public int sumFourDivisors(int[] nums) {
        int result = 0;

        for (int num : nums) {
            result += sumIfFourDivisors(num);
        }

        return result;
    }
}
//ALTERNATE APPROACH

class Solution {

    private static final int MAX = 100001;
    private static int[] spf = new int[MAX];

    static {
        sieve();
    }

    private static void sieve() {
        for (int i = 0; i < MAX; i++)
            spf[i] = i;

        for (int i = 2; i * i < MAX; i++) {
            if (spf[i] == i) { // prime
                for (int j = i * i; j < MAX; j += i) {
                    if (spf[j] == j)
                        spf[j] = i;
                }
            }
        }
    }

    public int sumFourDivisors(int[] nums) {
        int ans = 0;
        for (int n : nums) {
            ans += fourDivisorSum(n);
        }
        return ans;
    }

    private int fourDivisorSum(int n) {
        // Special case: 1 has only 1 divisor
        if (n == 1)
            return 0;

        int p = spf[n];
        int q = n / p;

        // Case 1: p^3
        if (p * p * p == n) {
            return 1 + p + p * p + n;
        }

        // Case 2: p * q (distinct primes, and q > 1)
        if (p != q && q > 1 && spf[q] == q) {
            return 1 + p + q + n;
        }

        return 0;
    }

}
