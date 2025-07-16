/*     Scroll below to see JAVA code as well    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=u-NffNeqNqk
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-i
*/


/************************************************************ C++ *****************************************************/
//Approach (observing the condition and checking, oddCount, evenCount and alternatingCount
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int countEven = 0, countOdd = 0;
        for (int num : nums) {
            if (num % 2 == 0) countEven++;
            else countOdd++;
        }

        // Try building alternating parity subsequence
        int altLen = 1; // At least one number
        int prevParity = nums[0] % 2;

        for (int i = 1; i < nums.size(); ++i) {
            int currParity = nums[i] % 2;
            if (currParity != prevParity) {
                altLen++;
                prevParity = currParity;
            }
        }

        return max({countEven, countOdd, altLen});
    }
};


/************************************************************ JAVA *****************************************************/
//Approach (observing the condition and checking, oddCount, evenCount and alternatingCount
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int maximumLength(int[] nums) {
        int countEven = 0, countOdd = 0;
        for (int num : nums) {
            if (num % 2 == 0) 
                countEven++;
            else 
                countOdd++;
        }

        int altLen = 1; // At least one number
        int prevParity = nums[0]%2;

        for (int i = 1; i < nums.length; ++i) {
            int currParity = nums[i] % 2;
            if (currParity != prevParity) {
                altLen++;
                prevParity = currParity;
            }
        }

        return Math.max(Math.max(countEven, countOdd), altLen);
    }
}
