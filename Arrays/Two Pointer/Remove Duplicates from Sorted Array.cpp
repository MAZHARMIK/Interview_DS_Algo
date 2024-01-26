/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=06ALbFrgIoQ
    Company Tags                : Facebook, Google, Amazon, Microsoft, Expedia, LinkedIn
    Leetcode Link               : https://leetcode.com/problems/remove-duplicates-from-sorted-array/
*/

/**************************************************************** C++ ****************************************************************/
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int i = 0, j = 1;
        
        while(j < n) {
            if(nums[i] != nums[j]) nums[++i] = nums[j];
            j++;
        }
        
        return i+1;
    }
};


/**************************************************************** JAVA ****************************************************************/
//T.C : O(n)
//S.C : O(1)
public class Solution {
    public int removeDuplicates(int[] nums) {
        int n = nums.length;
        if (n == 0) return 0;
        int i = 0, j = 1;

        while (j < n) {
            if (nums[i] != nums[j]) {
                nums[++i] = nums[j];
            }
            j++;
        }

        return i + 1;
    }
}
