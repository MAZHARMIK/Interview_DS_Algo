/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/adjacent-increasing-subarrays-detection-i
*/

/*********************************************************** C++ **************************************************/
//Approach (Loop and keep checking)
//T.C : O(n) 
//S.C : O(1)
class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int currentRun = 1;
        int previousRun = 0;
        int maxAdjacentLen = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                currentRun++;
            } else {
                previousRun = currentRun;
                currentRun = 1;
            }

            int longRunPossible = currentRun / 2;

            int adjacentRunPossible = min(previousRun, currentRun);

            maxAdjacentLen = max({maxAdjacentLen, longRunPossible, adjacentRunPossible}); //see my video for full intuition about it

            if (maxAdjacentLen >= k)
                return true;
        }

        return false;
    }
};



/*********************************************************** JAVA **************************************************/
//Approach (Loop and keep checking)
//T.C : O(n) 
//S.C : O(1)
class Solution {
    public boolean hasIncreasingSubarrays(List<Integer> nums, int k) {
        int n = nums.size();
        int currentRun = 1;
        int previousRun = 0;
        int maxAdjacentLen = 0;

        for (int i = 1; i < n; i++) {
            if (nums.get(i) > nums.get(i - 1)) {
                currentRun++;
            } else {
                previousRun = currentRun;
                currentRun = 1;
            }

            int longRunPossible = currentRun / 2;
            int adjacentRunPossible = Math.min(previousRun, currentRun);
            maxAdjacentLen = Math.max(maxAdjacentLen, Math.max(longRunPossible, adjacentRunPossible));

            if (maxAdjacentLen >= k)
                return true;
        }

        return false;
    }
}
