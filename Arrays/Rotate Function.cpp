/*     Scroll below to see JAVA code as well    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Will update later
    Leetcode Link               : https://leetcode.com/problems/rotate-function
*/


/************************************************************ C++ *****************************************************/
//Approach (Compute relation and find F(K+1) from F(K) and so on
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        int F = 0;

        for(int i = 0; i < n; i++) {
            sum += nums[i];
            F += i*nums[i];
        }

        int result = F;

        for(int k = 0; k <= n-1; k++) {
            int newF = F + sum - n*nums[n-1-k];

            result = max(result, newF);

            F = newF;
        }

        return result;
    }
};



/************************************************************ JAVA *****************************************************/
//Approach (Compute relation and find F(K+1) from F(K) and so on
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int maxRotateFunction(int[] nums) {
        int n = nums.length;

        int sum = 0;
        int F = 0;

        // Initial sum and F(0)
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            F += i * nums[i];
        }

        int result = F;

        // Compute next rotations using recurrence
        for (int k = 0; k < n; k++) {
            int newF = F + sum - n * nums[n - 1 - k];
            result = Math.max(result, newF);
            F = newF;
        }

        return result;
    }
}
