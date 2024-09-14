/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=xhKpOhtqAnM
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and
*/


/************************************************************ C++ ************************************************/
//Approach-(Simple Observation of AND property)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal = 0;
        int result = 0;
        int streak = 0;

        for (int num : nums) {
            if (num > maxVal) {
                maxVal = num;
                result = 0;
                streak = 0;
            }

            if (maxVal == num) {
                streak++;
            } else {
                streak = 0;
            }

            result = max(result, streak);
        }

        return result;
    }
};


/************************************************************ JAVA ************************************************/
//Approach-(Simple Observation of AND property)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int longestSubarray(int[] nums) {
        int maxVal = 0;
        int result = 0;
        int streak = 0;

        for(int num : nums) {
            if(num > maxVal) {
                maxVal = num;
                result = 0;
                streak = 0;
            }

            if(maxVal == num) {
                streak++;
            } else {
                streak = 0;
            }

            result = Math.max(result, streak);
        }

        return result;
    }
}
