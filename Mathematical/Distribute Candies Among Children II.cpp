/*     Scroll below to see JAVA code    */
/*
    MY YOUTUBE VIDEO ON THIS Qn                : https://www.youtube.com/watch?v=eL_3cDp0zjE
    Company Tags                               : will soon update
    Leetcode Link                              : https://leetcode.com/problems/distribute-candies-among-children-ii
    
*/

/****************************************************** C++ **************************************************************/
//Approach - Using maths distribution
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ways = 0;

        //child1
        int minCh1 = max(0, n - 2*limit);
        int maxCh1 = min(n, limit);

        for(int i = minCh1; i <= maxCh1; i++) { //fixing child1 assignment of candies

            int N = n-i; //for ch2 and ch3

            int minCh2 = max(0, N - limit);
            int maxCh2 = min(N, limit);

            ways += maxCh2 - minCh2 + 1;
        }

        return ways;
    }
};



/****************************************************** JAVA **************************************************************/
//Approach - Using maths distribution
//T.C : O(n)
//S.C : O(1)
class Solution {
    public long distributeCandies(int n, int limit) {
        long ways = 0;

        // Loop through possible candies for the first child
        int minCh1 = Math.max(0, n - 2 * limit);
        int maxCh1 = Math.min(n, limit);

        for (int i = minCh1; i <= maxCh1; i++) {
            int remaining = n - i;

            int minCh2 = Math.max(0, remaining - limit);
            int maxCh2 = Math.min(remaining, limit);

            ways += (maxCh2 - minCh2 + 1);
        }

        return ways;
    }
}
