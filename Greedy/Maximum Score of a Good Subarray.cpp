/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=2XMBLBdgqW8
    Company Tags                : AMAZON
    Leetcode Link               : https://leetcode.com/problems/maximum-score-of-a-good-subarray/
*/

/****************************************** C++ ******************************************/
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();

        int i = k;
        int j = k;
        int curMin = nums[k];
        
        int result = nums[k];
        
        while(i > 0 || j < n-1) {
            int leftValue;
            int rightValue;
            
            if(i > 0) {
                leftValue = nums[i-1];
            } else {
                leftValue = 0;
            }
            
            if(j < n-1) {
                rightValue = nums[j+1];
            } else {
                rightValue = 0;
            }
            
            if(leftValue < rightValue) { //Check my video for intuition behind this
                j++;
                curMin = min(curMin, nums[j]);
            } else {
                i--;
                curMin = min(curMin, nums[i]);
            }
            
            result = max(result, curMin * (j-i+1));
        }
        
        return result;
    }
};



/****************************************** JAVA ******************************************/
class Solution {
    public int maximumScore(int[] nums, int k) {
        int n = nums.length;
        int i = k;
        int j = k;
        int curMin = nums[k];
        int result = nums[k];
        
        while (i > 0 || j < n - 1) {
            int leftValue = (i > 0) ? nums[i - 1] : 0;
            int rightValue = (j < n - 1) ? nums[j + 1] : 0;

            if (leftValue < rightValue) {
                j++;
                curMin = Math.min(curMin, nums[j]);
            } else {
                i--;
                curMin = Math.min(curMin, nums[i]);
            }

            result = Math.max(result, curMin * (j - i + 1));
        }
        
        return result;
    }
}
