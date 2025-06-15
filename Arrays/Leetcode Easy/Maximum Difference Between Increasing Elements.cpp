/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/maximum-difference-between-increasing-elements/description/
*/

/*********************************************************** C++ **************************************************/
//Approach (Simple iteration)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int minElementi = nums[0];
        int maxDiff = -1;

        for(int j = 1; j < n; j++) {
            if(nums[j] > minElementi) {
                maxDiff = max(maxDiff, nums[j] - minElementi);
            } else {
                minElementi = nums[j];
            }
        }

        return maxDiff;
    }
};

/*********************************************************** C++ **************************************************/
//Approach (Simple iteration)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int maximumDifference(int[] nums) {
        int n = nums.length;
        int minElement = nums[0];
        int maxDiff = -1;

        for (int j = 1; j < n; j++) {
            if (nums[j] > minElement) {
                maxDiff = Math.max(maxDiff, nums[j] - minElement);
            } else {
                minElement = nums[j];
            }
        }

        return maxDiff;
    }
}
