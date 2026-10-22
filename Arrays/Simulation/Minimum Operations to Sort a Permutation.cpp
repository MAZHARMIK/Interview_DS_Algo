/*     Scroll below to see JAVA code also    */
/*
      MY YOUTUBE VIDEO ON THIS Qn : 
      Company Tags                : will update later
      Leetcode Link               : https://leetcode.com/problems/minimum-operations-to-sort-a-permutation
*/


/********************************************************************** C++ ********************************************************/
//Approach - Simulate and analyse cases (Ascending and Descending)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int asc_count = 0;
        int dsc_count = 0;

        for(int i = 1; i < n; i++) {
            asc_count += (nums[i] == (nums[i-1]+1)%n);
            dsc_count += (nums[i-1] == (nums[i]+1)%n);
        }

        if(asc_count == n-1 && nums[0] == 0) { //0, 1, 2, .... n-1
            return 0;
        }

        if(asc_count == n-1) {
            int leftRot  = n - nums[0];
            int rightRot = 1 + (nums.back() + 1) + 1;
            return min(leftRot, rightRot);
        }

        if(dsc_count == n-1) {
            //Mandatory 1 Reverse
            int leftRot = n-nums.back() + 1;

            //x Left Rot + 1 Reverse
            int rightRot = (nums[0]+1)%n + 1;

            return min(leftRot, rightRot);
        }

        return -1;
    }
};




/********************************************************************** JAVA ********************************************************/
//Approach - Simulate and analyse cases (Ascending and Descending)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int minOperations(int[] nums) {
        int n = nums.length;

        int asc_count = 0;
        int dsc_count = 0;

        for(int i = 1; i < n; i++) {
            asc_count += (nums[i] == (nums[i-1]+1)%n) ? 1 : 0;
            dsc_count += (nums[i-1] == (nums[i]+1)%n) ? 1 : 0;
        }

        if(asc_count == n-1 && nums[0] == 0) { //0, 1, 2, .... n-1
            return 0;
        }

        if(asc_count == n-1) {
            int leftRot  = n - nums[0];
            int rightRot = 1 + (nums[n-1] + 1) + 1;
            return Math.min(leftRot, rightRot);
        }

        if(dsc_count == n-1) {
            //Mandatory 1 Reverse
            int leftRot = n - nums[n-1] + 1;

            //x Left Rot + 1 Reverse
            int rightRot = (nums[0]+1)%n + 1;

            return Math.min(leftRot, rightRot);
        }

        return -1;
    }
}
