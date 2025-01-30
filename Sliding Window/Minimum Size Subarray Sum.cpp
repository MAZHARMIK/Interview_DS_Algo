/*        Scroll below to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=D2MbogiFXWU
    Company Tags                : Google, Accolite, Amazon, Facebook, Goldman Sachs
    Leetcode Link               : https://leetcode.com/problems/minimum-size-subarray-sum/
    Similar GfG Link            : https://practice.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x5651/1
    Similar Hard Version        : https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Sliding%20Window/Shortest%20Subarray%20with%20Sum%20at%20Least%20K.cpp
*/

/************************************************************ C++ ************************************************************/
//Approach - Using Sliding Window
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        
        int i = 0, j = 0;
        
        int sum = 0;
        int minL = n+1;
        
        while(j < n) {
            sum += nums[j];
            
            while(sum >= target) {
                minL = min(minL, j-i+1);
                sum -= nums[i];
                i++;
            }
            
            j++;
        }
        return minL == n+1 ? 0 : minL;
    }
};



/************************************************************ JAVA ************************************************************/
//Approach - Using Sliding Window
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int n = nums.length;
        int i = 0, j = 0;
        int sum = 0;
        int minL = n + 1;

        while (j < n) {
            sum += nums[j];

            while (sum >= target) {
                minL = Math.min(minL, j - i + 1);
                sum -= nums[i];
                i++;
            }

            j++;
        }

        return minL == n + 1 ? 0 : minL;
    }
}
