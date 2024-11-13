/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/count-the-number-of-fair-pairs
*/


/************************************************************ C++ ************************************************/
//Approach (simple binary search trick)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();

        sort(begin(nums), end(nums)); //nlogn

        long long result = 0;

        for(int i = 0; i < n; i++) { //O(n * logn)
             //o(n)
            int idx = lower_bound(begin(nums) + i + 1, end(nums), lower-nums[i]) - begin(nums); //Gives the firstc element NOT LESS than (lower - nums[i]) //log(n)
            int x   = idx - 1 - i;

            idx = upper_bound(begin(nums) + i + 1, end(nums), upper-nums[i]) - begin(nums); //Gives the firstc element GREATER than (upper - nums[i]) //log(n)

            int y = idx - 1 - i;

            result += (y-x);
        }

        return result;
    }
};




/************************************************************ JAVA ************************************************/
//Approach (simple binary search trick)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
    public long countFairPairs(int[] nums, int lower, int upper) {
        int n = nums.length;
        Arrays.sort(nums); // Sort the array, O(n log n)

        long result = 0;

        for (int i = 0; i < n; i++) { // Iterate through each element, O(n * log n)
            int leftIdx = lowerBound(nums, i + 1, n, lower - nums[i]); // Find the first element not less than (lower - nums[i])
            int rightIdx = upperBound(nums, i + 1, n, upper - nums[i]); // Find the first element greater than (upper - nums[i])

            int x = leftIdx - 1 - i;
            int y = rightIdx - 1 - i;

            result += (y - x);
        }

        return result;
    }

    // Java equivalent of lower_bound in C++
    private int lowerBound(int[] nums, int start, int end, int target) {
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        return start;
    }

    // Java equivalent of upper_bound in C++
    private int upperBound(int[] nums, int start, int end, int target) {
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] <= target) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        return start;
    }
}
