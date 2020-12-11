/*
    Company Tags  : Google, Facebook, Expedia, Microsoft
    Leetcode Link : https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        
        //since we need an element atleast 2 times
        if(n<=2) {
            return n;
        }
        
        int left = 2, right = 2;
        //left  = culprit index whom we will always choose if we want to put a new value
        //right = it will iterate over all elements
        while(right < n) {
            if(nums[left-2] != nums[right]) {
                nums[left] = nums[right];
                left++;
                //now culprint index left has been punished, so we need to move on
                //with our new culprit index i.e. i++
            }
            right++;
        }
        return left;
    }
};
