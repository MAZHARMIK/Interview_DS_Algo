/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Dv_RaUxf5sQ
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/left-and-right-sum-differences/
*/

/*********************************************************** C++ **************************************************/
//Approach (Linear Scan with running prefix and suffix sums)
//T.C : O(n)
//S.C : O(1) , excluding the output array
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();

        int sum = accumulate(begin(nums), end(nums), 0);

        vector<int> result(n);
        int leftSum = 0;

        for(int i = 0; i < n; i++) {
            sum -= nums[i];

            result[i] = abs(leftSum - sum);

            leftSum += nums[i];
        }

        return result;
    }
};

/*********************************************************** JAVA **************************************************/
//Approach (Linear Scan with running prefix and suffix sums)
//T.C : O(n)
//S.C : O(1) , excluding the output array
class Solution {
    public int[] leftRightDifference(int[] nums) {
        int n = nums.length;

        int sum = 0;
        for (int num : nums) sum += num;

        int[] result = new int[n];
        int leftSum = 0;

        for (int i = 0; i < n; i++) {
            sum -= nums[i];

            result[i] = Math.abs(leftSum - sum);

            leftSum += nums[i];
        }

        return result;
    }
}
