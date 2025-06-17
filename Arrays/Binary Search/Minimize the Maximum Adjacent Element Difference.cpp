/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/minimize-the-maximum-adjacent-element-difference/description/
*/



/****************************************************************** C++ ******************************************************************/
//Approach (Binary Search on Answer)
//T.C : O(n * log(D)) where D = r-l+1
//S.C : O(1)
class Solution {
public:
    bool check(vector<int>& nums, int x, int y, int d) {
        int count = 0; //count of -1s
        int prev  = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == -1) {
                //Trying all X in -1s or all Y in -1s
                if(prev != 0 && min(abs(prev-x), abs(prev-y)) > d) {
                    return false;
                }
                count++;
            } else {
                if(count > 0) { //{-1, -1, -1, b}, {a, -1, -1, -1, b}
                    int absDiffResult;
                    if(prev != 0) {
                        //Trying all X in -1s or all Y in -1s
                        absDiffResult = min(
                            max(abs(prev-x), abs(nums[i]-x)),
                            max(abs(prev-y), abs(nums[i]-y))
                        );
                    } else {
                        //Trying all X in -1s or all Y in -1s
                        absDiffResult = min(abs(nums[i] - x), abs(nums[i] - y));
                    }

                    //Trying mixture of X and Y in -1s
                    bool canMixXAndY = (count >= 2 && abs(x-y) <= d);

                    if(absDiffResult > d && !canMixXAndY)
                        return false;
                }

                prev  = nums[i];
                count = 0;
            }
        }

        return true;
    }


    int minDifference(vector<int>& nums) {
        int n = nums.size();

        int min_val    = INT_MAX;
        int max_val    = 0;
        int maxAdsDiff = 0;

        //l and r
        for(int i = 0; i < n-1; i++) {
            if(nums[i] != -1 && nums[i+1] != -1) { //{a, b}
                maxAdsDiff = max(maxAdsDiff, abs(nums[i] - nums[i+1]));
            } else if(!(nums[i] == -1 && nums[i+1] == -1)) { //{-1, a}, {a, -1} , not of {-1, -1}
                int val = max(nums[i], nums[i+1]);
                min_val = min(min_val, val);
                max_val = max(max_val, val);
            }
        }

        int l = maxAdsDiff;
        int r = max_val - min_val;

        int result = maxAdsDiff;
        while(l <= r) {
            int d = l + (r-l)/2;
            int x = min_val + d;
            int y = max_val - d;
            if(check(nums, x, y, d)) {
                result = d;
                r = d-1;
            } else {
                l = d+1;
            }
        }

        return result;
    }
};



/****************************************************************** JAVA ******************************************************************/
//Approach (Binary Search on Answer)
//T.C : O(n * log(D)) where D = r-l+1
//S.C : O(1)
class Solution {

    // Helper function to validate if a given `d` is sufficient
    private boolean check(int[] nums, int x, int y, int d) {
        int count = 0; // Count of -1s
        int prev = 0;

        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == -1) {
                // Trying all X in -1s or all Y in -1s
                if (prev != 0 && Math.min(Math.abs(prev - x), Math.abs(prev - y)) > d) {
                    return false;
                }
                count++;
            } else {
                if (count > 0) { // For patterns like {-1, -1, -1, b}, {a, -1, -1, -1, b}
                    int absDiffResult;
                    if (prev != 0) {
                        // Trying all X in -1s or all Y in -1s
                        absDiffResult = Math.min(
                            Math.max(Math.abs(prev - x), Math.abs(nums[i] - x)),
                            Math.max(Math.abs(prev - y), Math.abs(nums[i] - y))
                        );
                    } else {
                        // Trying all X in -1s or all Y in -1s
                        absDiffResult = Math.min(Math.abs(nums[i] - x), Math.abs(nums[i] - y));
                    }

                    // Trying mixture of X and Y in -1s
                    boolean canMixXAndY = (count >= 2 && Math.abs(x - y) <= d);

                    // If using only x or y gives too big a diff, and we can't mix -> fail
                    if (absDiffResult > d && !canMixXAndY) {
                        return false;
                    }
                }

                prev = nums[i];
                count = 0;
            }
        }

        return true;
    }

    public int minDifference(int[] nums) {
        int n = nums.length;

        int min_val = Integer.MAX_VALUE;
        int max_val = 0;
        int maxAbsDiff = 0;

        // Find bounds for binary search
        for (int i = 0; i < n - 1; i++) {
            int a = nums[i], b = nums[i + 1];
            if (a != -1 && b != -1) {
                // Both known, compute direct diff
                maxAbsDiff = Math.max(maxAbsDiff, Math.abs(a - b));
            } else if (!(a == -1 && b == -1)) {
                // One known, one unknown
                int val = Math.max(a, b);
                min_val = Math.min(min_val, val);
                max_val = Math.max(max_val, val);
            }
        }

        int l = maxAbsDiff;
        int r = max_val - min_val;

        int result = maxAbsDiff;
        while (l <= r) {
            int d = l + (r - l) / 2;
            int x = min_val + d;
            int y = max_val - d;

            if (check(nums, x, y, d)) {
                result = d;
                r = d - 1;
            } else {
                l = d + 1;
            }
        }

        return result;
    }
}
