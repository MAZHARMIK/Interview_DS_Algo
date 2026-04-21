/*     Scroll below to see JAVA code as well    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=YniLXdtGp5w
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/maximum-sum-obtained-of-any-permutation
*/


/******************************************************************************* C++ ************************************************************************************************/
//Approach (Using Line Sweep/Difference Array Technique)
//T.C : O(n * logn)
//S.C : O(n)
class Solution {
public:
    const int M = 1e9+7;
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n = nums.size();

        vector<int> events(n, 0);
        for(auto &req : requests) {
            int start = req[0];
            int end = req[1];

            events[start] += 1;
            if(end+1 < n)
                events[end+1] -= 1;
        }

        //cumulative sum
        for(int i = 1; i < n; i++) {
            events[i] += events[i-1];
        }


        int result = 0; //maxSum

        sort(begin(nums), end(nums), greater<int>());
        sort(begin(events), end(events), greater<int>());

        for(int i = 0; i < n; i++) {
            result = (result + (1LL * nums[i] * events[i]) % M) % M;
        }
        
        return result;

    }
};



/******************************************************************************* JAVA ************************************************************************************************/
//Approach (Using Line Sweep/Difference Array Technique)
//T.C : O(n * logn)
//S.C : O(n)
class Solution {
    public int maxSumRangeQuery(int[] nums, int[][] requests) {
        int n = nums.length;
        int MOD = 1_000_000_007;

        int[] events = new int[n];

        // Step 1: Difference array marking (line sweep events)
        for (int[] req : requests) {
            int start = req[0];
            int end = req[1];

            events[start] += 1;
            if (end + 1 < n) {
                events[end + 1] -= 1;
            }
        }

        // Step 2: Prefix sum to get frequency of each index
        for (int i = 1; i < n; i++) {
            events[i] += events[i - 1];
        }

        // Step 3: Sort nums and frequencies descending
        Arrays.sort(nums);
        Arrays.sort(events);

        long result = 0;

        // Traverse from back for descending effect
        for (int i = n - 1; i >= 0; i--) {
            long contrib = (long) nums[i] * events[i];
            result = (result + contrib) % MOD;
        }

        return (int) result;
    }
}
