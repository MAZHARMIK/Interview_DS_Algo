/*   Scroll below to see JAVA code also  */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=OhgrtltB5iM
    Company Tags                : Amazon
    Leetcode Link               : https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation
*/


/******************************************************* C++ *******************************************************/
//Approach (Simple loop and check)
//T.C : O((right - left) * log(num))
//S.C : O(1)
class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        unordered_set<int> primes = { 2, 3, 5, 7, 11, 13, 17, 19 };
        
        int result = 0;

        for (int num = left; num <= right; num++) {
            int setBits = __builtin_popcount(num);
            
            if(primes.count(setBits))
                result += 1;
        }

        return result;
    }
};




/******************************************************* JAVA *******************************************************/
//Approach (Simple loop and check)
//T.C : O((right - left) * log(num))
//S.C : O(1)
class Solution {
    public int countPrimeSetBits(int left, int right) {
        int result = 0;

        HashSet<Integer> primes = new HashSet<Integer>(Arrays.asList(2, 3, 5, 7, 11, 13, 17, 19));

        for(int num = left; num <= right; num++) {
            int setBits = Integer.bitCount(num);

            if(primes.contains(setBits)) {
                result++;
            }
        }

        return result;
    }
}
