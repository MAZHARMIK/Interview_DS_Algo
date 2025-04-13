/*     Scroll below to see JAVA code    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will soon update
    Leetcode Link               : https://leetcode.com/problems/count-good-numbers
    Binary Exponentiation Video : https://www.youtube.com/watch?v=D320QeHS0XQ
*/


/****************************************************** C++ **************************************************************/
//Approach (Using Maths)
//T.C : O(log(n))
//S.C : O(1) but note that we use O(log(n)) system stack space of recursion
class Solution {
public:
    const int M = 1e9+7;
    int findPower(long long a, long long b) {
        if(b == 0) {
            return 1;
        }   

        long long half = findPower(a, b/2);
        long long result = (half * half) % M;

        if(b % 2 == 1) {
            result = (result * a) % M;
        }

        return result;
    }

    int countGoodNumbers(long long n) {
        return (long long)findPower(5, (n+1)/2) * findPower(4, n/2) % M;
    }
};


/****************************************************** JAVA **************************************************************/
//Approach (Using Maths)
//T.C : O(log(n))
//S.C : O(1) but note that we use O(log(n)) system stack space of recursion
class Solution {
    static final int M = (int)1e9 + 7;

    private long findPower(long a, long b) {
        if (b == 0) {
            return 1;
        }

        long half = findPower(a, b / 2);
        long result = (half * half) % M;

        if (b % 2 == 1) {
            result = (result * a) % M;
        }

        return result;
    }

    public int countGoodNumbers(long n) {
        long oddPositions = (n + 1) / 2;
        long evenPositions = n / 2;

        long result = (findPower(5, oddPositions) * findPower(4, evenPositions)) % M;
        return (int) result;
    }
}
