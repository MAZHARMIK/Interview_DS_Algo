/*     Scroll below to see JAVA code as well    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Xjp4cLpphM0
    Company Tags                : Will update later
    Leetcode Link               : https://leetcode.com/problems/adjacent-increasing-subarrays-detection-ii
*/


/************************************************************ C++ *****************************************************/
//Approach (Using same concept as we did for Adjacent Increasing Subarrays Detection I)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();

        int currRun = 1;
        int prevRun = 0;

        int maxResult = 0;

        for (int i = 1; i < n; i++) {
            if (nums [i] > nums[i-1]) {
                currRun++;
            } else { // increasing order breaks here
                prevRun = currRun;
                currRun = 1;
            }

            maxResult = max(maxResult, currRun/2);
            maxResult = max(maxResult, min(prevRun, currRun));
        }

        return maxResult;
    }
};




/************************************************************ JAVA *****************************************************/
//Approach (Using same concept as we did for Adjacent Increasing Subarrays Detection I)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int maxIncreasingSubarrays(List<Integer> nums) {
        int n = nums.size();

        int currRun = 1;
        int prevRun = 0;
        int maxResult = 0;

        for (int i = 1; i < n; i++) {
            if (nums.get(i) > nums.get(i - 1)) {
                currRun++;
            } else { // increasing order breaks here
                prevRun = currRun;
                currRun = 1;
            }

            maxResult = Math.max(maxResult, currRun / 2);
            maxResult = Math.max(maxResult, Math.min(prevRun, currRun));
        }

        return maxResult;
    }
}
