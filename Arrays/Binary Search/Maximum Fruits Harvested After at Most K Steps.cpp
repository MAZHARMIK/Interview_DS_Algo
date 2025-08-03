/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=9biz4kxyVh8
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/maximum-fruits-harvested-after-at-most-k-steps/
*/



/****************************************************************** C++ ******************************************************************/
//Approach (Binary Search and prefix sum)
//T.C : O(n+klogn)
//S.C : O(n)
class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        vector<int> prefixSum(n);
        vector<int> indices(n);

        // Build prefix sum and extract indices
        for (int i = 0; i < n; i++) {
            indices[i]   = fruits[i][0];
            prefixSum[i] = fruits[i][1] + (i > 0 ? prefixSum[i - 1] : 0);
        }

        int maxFrutis = 0;

        for (int d = 0; d <= k / 2; d++) {
            // Move
            int remain = k - 2 * d;
            int i   = startPos - d;
            int j  = startPos + remain;

            int left  = lower_bound(indices.begin(), indices.end(), i) - indices.begin();
            int right = upper_bound(indices.begin(), indices.end(), j) - indices.begin() - 1;

            if(left <= right) {
                int total = prefixSum[right] - (left > 0 ? prefixSum[left - 1] : 0);
                maxFrutis = max(maxFrutis, total);
            }

            // Second case: move right x, then left (k - 2x)
            i  = startPos - remain;
            j  = startPos + d;
            
            left  = lower_bound(indices.begin(), indices.end(), i) - indices.begin();
            right = upper_bound(indices.begin(), indices.end(), j) - indices.begin() - 1;

            if(left <= right) {
                int total = prefixSum[right] - (left > 0 ? prefixSum[left - 1] : 0);
                maxFrutis = max(maxFrutis, total);
            }
        }

        return maxFrutis;
    }
};


/****************************************************************** JAVA ******************************************************************/
//Approach (Binary Search and prefix sum)
//T.C : O(n+klogn)
//S.C : O(n)
class Solution {
    public int maxTotalFruits(int[][] fruits, int startPos, int k) {
        int n = fruits.length;
        int[] prefixSum = new int[n];
        int[] indices = new int[n];

        // Build prefix sum and extract indices
        for (int i = 0; i < n; i++) {
            indices[i] = fruits[i][0];
            prefixSum[i] = fruits[i][1] + (i > 0 ? prefixSum[i - 1] : 0);
        }

        int maxFrutis = 0;

        for (int d = 0; d <= k / 2; d++) {
            // First case: Move left 'd' steps then pick 'remain' steps
            int remain = k - 2 * d;
            int i = startPos - d;
            int j = startPos + remain;

            // Find the range [i, j] using binary search
            int left = lowerBound(indices, left);
            int right = upperBound(indices, right) - 1;

            if (left <= right) {
                int total = prefixSum[right] - (left > 0 ? prefixSum[left - 1] : 0);
                maxFrutis = Math.max(maxFrutis, total);
            }

            // Second case: Move right 'd' steps then pick 'remain' steps
            remain = k - 2 * d;
            i  = startPos - remain;
            j = startPos + d;

            left = lowerBound(indices, left);
            right = upperBound(indices, right) - 1;

            if (left <= right) {
                int total = prefixSum[right] - (left > 0 ? prefixSum[left - 1] : 0);
                maxFrutis = Math.max(maxFrutis, total);
            }
        }

        return maxFrutis;
    }

    // Helper method to find the lower bound index
    private int lowerBound(int[] arr, int target) {
        int left = 0, right = arr.length;
        while (left < right) {
            int mid = (left + right) / 2;
            if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }

    // Helper method to find the upper bound index
    private int upperBound(int[] arr, int target) {
        int left = 0, right = arr.length;
        while (left < right) {
            int mid = (left + right) / 2;
            if (arr[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
}
