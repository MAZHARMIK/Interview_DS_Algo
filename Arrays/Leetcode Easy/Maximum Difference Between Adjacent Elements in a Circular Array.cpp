/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/maximum-difference-between-adjacent-elements-in-a-circular-array
*/

/*********************************************************** C++ **************************************************/
//Approach - simple iteration
//T.C : O(n) 
//S.C : O(1)
class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();

        int maxDiff = abs(nums[0] - nums[n-1]);

        for(int i = 0; i < n-1; i++) {
            maxDiff = max(maxDiff, abs(nums[i] - nums[i+1]));
        }

        return maxDiff;
    }
};


/*********************************************************** JAVA *****************************************************/
//Approach - simple iteration
//T.C : O(n) 
//S.C : O(1)
class Solution {
    public int maxAdjacentDistance(int[] nums) {
        int n = nums.length;
        int maxDiff = Math.abs(nums[0] - nums[n - 1]);

        for (int i = 0; i < n - 1; i++) {
            maxDiff = Math.max(maxDiff, Math.abs(nums[i] - nums[i + 1]));
        }

        return maxDiff;
    }
}
