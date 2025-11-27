/*     Scroll below to see JAVA code as well    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=pPxqRNyUbIs
    Company Tags                : Will update later
    Leetcode Link               : https://leetcode.com/problems/maximum-subarray-sum-with-length-divisible-by-k
*/


/************************************************************ C++ *****************************************************/
//Approach (Using Kadane's Algorithm Concept)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long> prefSum(n);
        prefSum[0] = nums[0];

        for(int i = 1; i < n; i++) {
            prefSum[i] = prefSum[i-1] + nums[i];
        }

        long long result = LLONG_MIN;

        for(int start = 0; start < k; start++) {
            long long currSum = 0;

            int i = start;

            while(i < n && i + k - 1 < n) {
                int j = i + k - 1;

                long long subSum = prefSum[j] - ((i > 0) ? prefSum[i-1] : 0);

                currSum = max(subSum, currSum + subSum);

                result = max(result, currSum);

                i += k;
            }
        }

        return result;
    }
};



/************************************************************ JAVA *****************************************************/
//Approach (Using Kadane's Algorithm Concept)
//T.C : O(n)
//S.C : O(n)
class Solution {
    public long maxSubarraySum(int[] nums, int k) {
        int n = nums.length;

        long[] prefSum = new long[n];
        prefSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefSum[i] = prefSum[i - 1] + nums[i];
        }

        long result = Long.MIN_VALUE;

        for (int start = 0; start < k; start++) {
            long currSum = 0;

            int i = start;
            while (i < n && i + k - 1 < n) {
                int j = i + k - 1;

                long subSum = prefSum[j] - (i > 0 ? prefSum[i - 1] : 0);

                currSum = Math.max(subSum, currSum + subSum);

                result = Math.max(result, currSum);

                i += k;
            }
        }

        return result;
    }
}
