/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=1L9C3a38fHU
    Company Tags                : AMAZON
    Leetcode Link               : https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/description/
    Similar Leetcode Porblem    : Leetcode 881. Boats to Save People
*/

/***************************************************************** C++ ******************************************************************************/
//Simple 2-pointer approach
//T.C : O(nlogn) due to sorting
//S.C : O(1)
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(begin(nums), end(nums));

        int maxResult = 0;
        
        int i = 0, j = nums.size()-1;
        
        while(i < j) {
            int sum = nums[i] + nums[j];
            
            maxResult = max(maxResult, sum);
            i++;
            j--;
        }
        
        return maxResult;
        
    }
};




/***************************************************************** JAVA ******************************************************************************/
//Simple 2-pointer approach
//T.C : O(nlogn) due to sorting
//S.C : O(1)
class Solution {
    public int minPairSum(int[] nums) {
        Arrays.sort(nums);

        int maxResult = 0;

        int i = 0, j = nums.length - 1;

        while (i < j) {
            int sum = nums[i] + nums[j];

            maxResult = Math.max(maxResult, sum);
            i++;
            j--;
        }

        return maxResult;
    }
}
