/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays
*/


/**************************************************************** C++ ****************************************************************/
//Approach (Recursion + Memoization + sliding window)
//T.C : ~O(n) (Explained in the video above)
//S.C : ~O(n)
class Solution {
private:
    int t[20001][4];

    int helper(vector<int>& sums, int k, int idx, int rem) {
        if (rem == 0) return 0;
        if (idx >= sums.size()) {
            return INT_MIN;
        }

        if (t[idx][rem] != -1) {
            return t[idx][rem];
        }

        int take = sums[idx] + helper(sums, k, idx + k, rem - 1);
        int not_take = helper(sums, k, idx + 1, rem);

        t[idx][rem] = max(take, not_take);
        return t[idx][rem];
    }

    void solve(vector<int>& sums, int k, int idx, int rem, vector<int>& indices) {
        if (rem == 0) return;
        if (idx >= sums.size()) return;

        int take     = sums[idx] + helper(sums, k, idx + k, rem - 1);
        int not_take = helper(sums, k, idx + 1, rem);

        if (take >= not_take) {
            indices.push_back(idx);
            solve(sums, k, idx + k, rem - 1, indices);
        } else {
            solve(sums, k, idx + 1, rem, indices);
        }
    }

public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        // Initialize the memoization array with -1
        memset(t, -1, sizeof(t));

        // Number of possible subarray starting positions
        int n = nums.size() - k + 1;

        vector<int> sums;
        int windowSum = 0;
        int i = 0, j = 0;

        // Slide the window
        while (j < nums.size()) {
            windowSum += nums[j];
            
            // Check if the window size is reached
            if (j - i + 1 == k) {
                sums.push_back(windowSum); // Store the sum of the current window
                windowSum -= nums[i];     // Slide the window forward
                i++;
            }
            j++;
        }

        vector<int> indices;

        // Reconstruct the path to find indices
        solve(sums, k, 0, 3, indices);

        return indices;
    }
};



/**************************************************************** JAVA ****************************************************************/
//Approach (Recursion + Memoization + sliding window)
//T.C : ~O(n) (Explained in the video above)
//S.C : ~O(n)
class Solution {
    private int[][] dp = new int[20001][4];

    private int helper(int[] sums, int k, int idx, int rem) {
        if (rem == 0) return 0;
        if (idx >= sums.length) return Integer.MIN_VALUE;

        if (dp[idx][rem] != -1) {
            return dp[idx][rem];
        }

        int take = sums[idx] + helper(sums, k, idx + k, rem - 1);
        int notTake = helper(sums, k, idx + 1, rem);

        dp[idx][rem] = Math.max(take, notTake);
        return dp[idx][rem];
    }

    private void solve(int[] sums, int k, int idx, int rem, List<Integer> indices) {
        if (rem == 0 || idx >= sums.length) return;

        int take = sums[idx] + helper(sums, k, idx + k, rem - 1);
        int notTake = helper(sums, k, idx + 1, rem);

        if (take >= notTake) {
            indices.add(idx);
            solve(sums, k, idx + k, rem - 1, indices);
        } else {
            solve(sums, k, idx + 1, rem, indices);
        }
    }

    public int[] maxSumOfThreeSubarrays(int[] nums, int k) {
        // Initialize the memoization array with -1
        for (int[] row : dp) {
            Arrays.fill(row, -1);
        }

        int n = nums.length - k + 1;
        int[] sums = new int[n];
        int windowSum = 0;
        int i = 0, j = 0;

        // Calculate window sums
        while (j < nums.length) {
            windowSum += nums[j];

            if (j - i + 1 == k) {
                sums[i] = windowSum;
                windowSum -= nums[i];
                i++;
            }
            j++;
        }

        List<Integer> indices = new ArrayList<>();
        solve(sums, k, 0, 3, indices);

        return indices.stream().mapToInt(Integer::intValue).toArray();
    }
}
