/*
    MY YOUTUBE VIDEO ON THIS Qn : 
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
        
        for(int i = 2; i * i <= x; i++) {
            
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
//T.C : O((b - a + 1) * sqrt(x) * log(x)).
//S.C : O(1)
class Solution {
    public static long countSum(long x) {
        long count = 0;

        for (int i = 2; i * i <= x; i++) {
            while (x % i == 0) {
                x /= i;
                count++;
            }
        }

        if (x != 1) {
            count++;
        }

        return count;
    }
    
    public static long sumOfPowers(long a, long b) {
        long result = 0;

        while (a <= b) {
            result += countSum(a);
            a++;
        }

        return result;
    }
}
