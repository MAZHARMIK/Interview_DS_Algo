/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=yX6NHGF_YQ4
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/description/
    Harder Version of this Qn   : https://leetcode.com/problems/minimum-operations-to-make-array-equal-to-target/description/
*/


/************************************************************ C++ ************************************************/
//Simple Approach - Keeping track of prev diff
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();

        long long result = 0;

        int curr = 0;
        int prev = 0;

        for(int i = 0; i < n; i++) {
            curr = target[i];

            if(abs(curr) > abs(prev)) {
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
    public int minNumberOperations(int[] target) {
        int n = target.length;
        int result = 0;
        int prev = 0;

        for (int i = 0; i < n; i++) {
            int curr = target[i];
            if (curr > prev) {
                result += (curr - prev);
            }
            prev = curr;
        }

        return result;
    }
}
