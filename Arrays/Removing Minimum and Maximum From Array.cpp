/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=rslpUxSz9BI
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/removing-minimum-and-maximum-from-array
*/


/*********************************************************** C++ **************************************************/
//Approach (simple obervation - 3 options only)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minElIdx = min_element(begin(nums), end(nums)) - begin(nums);
        int maxElidx = max_element(begin(nums), end(nums)) - begin(nums);

        int left  = min(minElIdx, maxElidx);
        int right = max(minElIdx, maxElidx);

        return min({left+1+n-right, right+1, n-left});
    }
};



/*********************************************************** JAVA **************************************************/
//Approach (simple obervation - 3 options only)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int minimumDeletions(int[] nums) {
        int n = nums.length;

        int minElIdx = 0, maxElIdx = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[minElIdx]) minElIdx = i;
            if (nums[i] > nums[maxElIdx]) maxElIdx = i;
        }

        int left  = Math.min(minElIdx, maxElIdx);
        int right = Math.max(minElIdx, maxElIdx);

        return Math.min(left + 1 + n - right, Math.min(right + 1, n - left));
    }
}
