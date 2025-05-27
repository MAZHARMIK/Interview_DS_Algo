/*     Scroll below to see JAVA code    */
/*
    MY YOUTUBE VIDEO ON THIS Qn                : https://www.youtube.com/watch?v=aSZi159QnvU
    Company Tags                               : will soon update
    Leetcode Link                              : https://leetcode.com/problems/divisible-and-non-divisible-sums-difference
    
*/


/****************************************************** C++ **************************************************************/
//Approach - Constant time using maths
//T.C : O(1)
//S.C : O(1)
class Solution {
public:
    int differenceOfSums(int n, int m) {
        int k = n/m;

        return n*(n+1)/2 - m * k * (k+1);
    }
};


/****************************************************** JAVA **************************************************************/
//Approach - Constant time using maths
//T.C : O(1)
//S.C : O(1)
class Solution {
    public int differenceOfSums(int n, int m) {
         int k = n / m;

        //Using variables for clarity
        int totalSum = n * (n + 1) / 2;
        int divisibleSum = m * k * (k + 1) / 2;
        int nonDivisibleSum = totalSum - divisibleSum;

        return nonDivisibleSum - divisibleSum;
    }
}
