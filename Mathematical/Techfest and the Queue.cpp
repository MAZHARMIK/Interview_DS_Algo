/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=-ZKUZU7s5Kw
    Company Tags                : will soon update
    GfG Link                    : https://www.geeksforgeeks.org/problems/techfest-and-the-queue1044/1
*/

/************************************************************************ C++ ****************************************************************************/
//T.C : O((b - a + 1) * sqrt(x) * log(x)).
//S.C : O(1)
class Solution {
public:

    int countSum(int x) {
        int count = 0;
        int temp = x;
        for(int i = 2; i * i <= temp; i++) {
            
            while(x%i == 0) {
                x /= i;
                count++;
            }
            
        }
        if(x != 1) {
            count++;
        }
        return count;
    }

	int sumOfPowers(int a, int b){
	    int result = 0;
	    
	    while(a <= b) {
	        result += countSum(a);
	        a++;
	    }
	    return result;
	}
};


/************************************************************************ JAVA ****************************************************************************/
//JAVA code gives TLE so I have used static array "resultCache" to store the result for different values so that they can be used in future large inputs.
//T.C : O((b - a + 1) * sqrt(x) * log(x)).
//S.C : O(1)
class Solution {
    private static final int MAX_SIZE = 2*100001;
    private static long[] resultCache = new long[MAX_SIZE];

    // Function to count prime factors
    public static long countSum(long x) {
        if (resultCache[(int)x] != 0) {
            return resultCache[(int)x];
        }

        long count = 0;
        long temp = x;

        for (int i = 2; i * i <= temp; i++) {
            while (x % i == 0) {
                x /= i;
                count++;
            }
        }

        if (x != 1) {
            count++;
        }

        // Store the result in the cache
        resultCache[(int)temp] = count;

        return count;
    }

    // Function to calculate sum of powers
    public static long sumOfPowers(long a, long b) {
        long result = 0;

        for (long i = a; i <= b; i++) {
            result += countSum(i);
        }

        return result;
    }
}
