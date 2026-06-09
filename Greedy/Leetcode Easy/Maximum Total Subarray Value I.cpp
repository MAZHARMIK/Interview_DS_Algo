/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=V9162iPEJFc
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/maximum-total-subarray-value-i/
*/

/*********************************************************** C++ **************************************************/
//Approach (Linear Scan - find max and min)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int maxEl = INT_MIN;
        int minEl = INT_MAX;

        for(int &num : nums) {
            maxEl = max(maxEl, num);
            minEl = min(minEl, num);
        }

        return 1LL*(maxEl - minEl)*k;
    }
};


/*********************************************************** JAVA **************************************************/
//Approach (Linear Scan - find max and min)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public long maxTotalValue(int[] nums, int k) {
        int maxEl = Integer.MIN_VALUE;
        int minEl = Integer.MAX_VALUE;

        for(int num : nums) {
            maxEl = Math.max(maxEl, num);
            minEl = Math.min(minEl, num);
        }

        return (long)(maxEl - minEl) * k;
    }
}
