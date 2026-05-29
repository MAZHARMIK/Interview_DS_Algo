/*         Scroll below to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=6VuCJCcpcZI
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1
*/


/********************************************************************** C++ **********************************************************************/
//Approach - Turn an element to 1 and make all elements 1 using it.
//T.C : O(n^2 * log(M)), M = maximum number
//S.C : O(1)
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int count1 = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 1)
                count1++;
        }

        if(count1 > 0) {
            return n - count1;
        }

        int minStepsTo1 = INT_MAX;
        for(int i = 0; i < n; i++) {
            int GCD = nums[i];
            for(int j = i+1; j < n; j++) {
                GCD = gcd(GCD, nums[j]);
                
                if(GCD == 1) {
                    minStepsTo1 = min(minStepsTo1, j-i);
                    break;
                }
            }
        }

        if(minStepsTo1 == INT_MAX) {
            return -1;
        }
        return minStepsTo1 + (n-1);
    }
};




/********************************************************************** JAVA **********************************************************************/
//Approach - Turn an element to 1 and make all elements 1 using it.
//T.C : O(n^2 * log(M)), M = maximum number
//S.C : O(1)
class Solution {
    public int minOperations(int[] nums) {
        int n = nums.length;

        int count1 = 0;
        for (int num : nums) {
            if (num == 1)
                count1++;
        }

        if (count1 > 0) {
            return n - count1;
        }

        int minStepsTo1 = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            int gcdVal = nums[i];
            for (int j = i + 1; j < n; j++) {
                gcdVal = gcd(gcdVal, nums[j]);

                if (gcdVal == 1) {
                    minStepsTo1 = Math.min(minStepsTo1, j - i);
                    break;
                }
            }
        }

        if (minStepsTo1 == Integer.MAX_VALUE) {
            return -1;
        }

        return minStepsTo1 + (n - 1);
    }

    private int gcd(int a, int b) {
        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }
}
