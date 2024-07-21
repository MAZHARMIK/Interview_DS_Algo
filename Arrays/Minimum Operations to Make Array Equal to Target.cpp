/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=yX6NHGF_YQ4
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/minimum-operations-to-make-array-equal-to-target/description/
    Easier Version of this Qn   : https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/description/
*/


/************************************************************ C++ ************************************************/
//Simple Approach - Keeping track of prev diff
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();

        long long result = 0;

        int curr = 0;
        int prev = 0;

        for(int i = 0; i < n; i++) {
            curr = target[i] - nums[i];

            //sign change ?
            if((curr > 0 && prev < 0) || (curr < 0 && prev > 0)) {
                result += abs(curr);
            } else if(abs(curr) > abs(prev)) {
                result += abs(curr - prev);
            }

            prev = curr;
        }

        return result;
    }
};



/************************************************************ JAVA ************************************************/
//Simple Approach - Keeping track of prev diff
//T.C : O(n)
//S.C : O(1)
class Solution {
    public long minimumOperations(int[] nums, int[] target) {
        int n = nums.length;
        long result = 0;
        int curr = 0;
        int prev = 0;

        for (int i = 0; i < n; i++) {
            curr = target[i] - nums[i];

            // Check for sign change
            if ((curr > 0 && prev < 0) || (curr < 0 && prev > 0)) {
                result += Math.abs(curr);
            } else if (Math.abs(curr) > Math.abs(prev)) {
                result += Math.abs(curr - prev);
            }

            prev = curr;
        }

        return result;
    }
}
