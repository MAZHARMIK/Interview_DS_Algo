/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : American Express
    Leetcode Link               : https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-i
*/

/*********************************************************** C++ **************************************************/
//Approach (Just find minimums)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();

        int firstMin  = nums[0];
        int secondMin = INT_MAX;
        int thirdMin  = INT_MAX;

        for(int i = 1; i < n; i++) {
            if(nums[i] < secondMin) {
                thirdMin  = secondMin;
                secondMin = nums[i];
            } else if(nums[i] < thirdMin) {
                thirdMin = nums[i];
            }
        }

        return firstMin + secondMin + thirdMin;
    }
};



/*********************************************************** JAVA **************************************************/
//Approach (Just find minimums)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int minimumCost(int[] nums) {
        int n = nums.length;

        int firstMin = nums[0];
        int secondMin = Integer.MAX_VALUE;
        int thirdMin = Integer.MAX_VALUE;

        for (int i = 1; i < n; i++) {
            if (nums[i] < secondMin) {
                thirdMin = secondMin;
                secondMin = nums[i];
            } else if (nums[i] < thirdMin) {
                thirdMin = nums[i];
            }
        }

        return firstMin + secondMin + thirdMin;
    }
}
