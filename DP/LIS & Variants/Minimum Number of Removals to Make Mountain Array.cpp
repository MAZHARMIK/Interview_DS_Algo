/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=LFjC2AW0wf4
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/description/
*/


/**************************************************************** C++ ****************************************************************/
//Approach - Using LIS
//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();

        vector<int> LIS(n, 1);
        vector<int> LDS(n, 1);

        //calculate LIS
        for(int i = 0; i < n; i++) {
            for(int j = i-1; j >= 0; j--) {
                if(nums[i] > nums[j]) {
                    LIS[i] = max(LIS[i], LIS[j] + 1);
                }
            }
        }

        //calculate LDS
        for(int i = n-1; i >= 0; i--) {
            for(int j = i+1; j < n; j++) {
                if(nums[i] > nums[j]) {
                    LDS[i] = max(LDS[i], LDS[j] + 1);
                }
            }
        }


        int minRemovals = n;
        
        for(int i = 0; i < n; i++) { //treat each element as PEak and find removal
            if(LIS[i] > 1 && LDS[i] > 1) //mountain array minimum length tabhi >= 3 aa paega
                minRemovals = min(minRemovals, n - LIS[i] - LDS[i] + 1);
        }

        return minRemovals;
    }
};


/**************************************************************** JAVA ****************************************************************/
//Approach - Using LIS
//T.C : O(n^2)
//S.C : O(n)
class Solution {
    public int minimumMountainRemovals(int[] nums) {
        int n = nums.length;
        int[] LIS = new int[n];
        int[] LDS = new int[n];
        
        // Initialize LIS and LDS with 1
        Arrays.fill(LIS, 1);
        Arrays.fill(LDS, 1);

        // Calculate LIS (Longest Increasing Subsequence)
        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] > nums[j]) {
                    LIS[i] = Math.max(LIS[i], LIS[j] + 1);
                }
            }
        }

        // Calculate LDS (Longest Decreasing Subsequence)
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] > nums[j]) {
                    LDS[i] = Math.max(LDS[i], LDS[j] + 1);
                }
            }
        }

        int minRemovals = n;

        // Iterate over each element treating it as the peak of the mountain
        for (int i = 0; i < n; i++) {
            // Ensure the current position can be a peak (LIS and LDS must be > 1)
            if (LIS[i] > 1 && LDS[i] > 1) {
                minRemovals = Math.min(minRemovals, n - LIS[i] - LDS[i] + 1);
            }
        }

        return minRemovals;
    }
}
