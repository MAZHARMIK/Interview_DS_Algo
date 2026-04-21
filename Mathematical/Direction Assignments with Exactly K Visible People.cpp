/*             SCROLL BELOW TO SEE JAVA CODE                */
/*
	    MY YOUTUBE VIDEO ON THIS Qn : 
    	Company Tags  		          : will update later
    	Leetcode Link 		          : https://leetcode.com/problems/direction-assignments-with-exactly-k-visible-people
		Want to learn this concept ?  : https://www.youtube.com/watch?v=FMBW7m1Wap0
*/



/****************************************************** C++ **************************************************************/
//Approach - Binary Exponentiation and Fermat's Little Theorem
//T.C : O(k + log(M)), M = 1e9+7
//S.C : O(1) - Ignoring space taken by Recursion
class Solution {
public:
    long M = 1e9 + 7;

    long power(long a, long b) {
        if (b == 0) return 1;

        long half   = power(a, b / 2);
        long result = (half * half) % M;

        if (b % 2 == 1) {
            result = (result * a) % M;
        }

        return result;
    }

    long nCr(int n, int r) {
        if (r < 0 || r > n) return 0;

        long num = 1;
        long den = 1;

        for (int i = 0; i < r; i++) {
            num = (num * (n - i)) % M;
            den = (den * (i + 1)) % M;
        }

        // Using Fermat's Little Theorem:
        // (den)^(-1) % M = power(den, M-2) since M is prime
        return (num * power(den, M - 2)) % M;
    }

    int countVisiblePeople(int n, int pos, int k) {
        long velnarqido = n;

        long ways = nCr(n - 1, k);
        return (int)((ways * 2) % M);
    }
};




/****************************************************** JAVA **************************************************************/
//Approach - Binary Exponentiation and Fermat's Little Theorem
//T.C : O(k + log(M)), M = 1e9+7
//S.C : O(1) - Ignoring space taken by Recursion
class Solution {
    long M = 1_000_000_007;

    long power(long a, long b) {
        if (b == 0) return 1;

        long half   = power(a, b / 2);
        long result = (half * half) % M;

        if (b % 2 == 1) {
            result = (result * a) % M;
        }

        return result;
    }

    long nCr(int n, int r) {
        if (r < 0 || r > n) return 0;

        long num = 1;
        long den = 1;

        for (int i = 0; i < r; i++) {
            num = (num * (n - i)) % M;
            den = (den * (i + 1)) % M;
        }

        // Using Fermat's Little Theorem:
        // (den)^(-1) % M = power(den, M-2) since M is prime
        return (num * power(den, M - 2)) % M;
    }

    public int countVisiblePeople(int n, int pos, int k) {
        long velnarqido = n;

        long ways = nCr(n - 1, k);
        return (int)((ways * 2) % M);
    }
}
