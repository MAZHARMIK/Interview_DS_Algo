/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=2nRXvlxkU2Y
      Company Tags                : GOOGLE
      Leetcode Link               : https://leetcode.com/problems/minimum-replacements-to-sort-the-array/
*/

************************************************** C++ **************************************************
//Using Greedy Approach - T.C : O(n) , S.C : O(1)
class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        long long result = 0;
        
        for(int i = n-2; i >= 0; i--) {

            int splits = nums[i]/nums[i+1];
            
            if((nums[i]) % nums[i+1] != 0) {
                splits++;
            }
            
            nums[i] = nums[i]/splits;
            result += splits-1;
        }
        
        return result;
    }
};


************************************************** JAVA **************************************************
class Solution {
    public long minimumReplacement(int[] nums) {
        int n = nums.length;
        
        long operations = 0;

        for (int i = n - 2; i >= 0; i--) {
            
            if (nums[i] <= nums[i + 1]) {
                continue;
            }

            long parts = (long)(nums[i]) / (long)nums[i + 1];
            
            if(nums[i] % nums[i+1] != 0)
                parts += 1;

            operations += parts - 1;

            nums[i] = nums[i] / (int)parts;
        }

        return operations;
    }
}
