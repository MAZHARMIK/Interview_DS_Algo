/*
    MY YOUTUBE VIDEO FOR THIS Qn : https://www.youtube.com/watch?v=CboKBIpo640&list=PLpIkg8OmuX-K6A0sEPFxOSJh4_AjCGAFf&index=9
    Company Tags                 : Amazon, FactSet, Hike, Amazon, MakeMyTrip, Qualcomm, Infosys, Microsoft, Google, Salesforce, Flipkart
    GfG Link                     : https://practice.geeksforgeeks.org/problems/next-permutation5226/1
    Leetcode Qn Link             : https://leetcode.com/problems/next-permutation/
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        int i = n-1;
        for(; i>0; i--) {
            if(nums[i] > nums[i-1]) {
                break;
            }
        }
        if(i != 0) {
            int index = i;
            for(int j = n-1; j>=i; j--) {
                if(nums[j] > nums[i-1]) {
                    index = j;
                    break;
                }
            }
            swap(nums[i-1], nums[index]);
        }
        reverse(nums.begin()+i, nums.end());
    }
};


// JAVA Solution
class Solution {
    public void nextPermutation(int[] nums) {
        
        int toBeSwappedIdx = -1;

        for (int i = nums.length - 1; i>0; i--) {
            if (nums[i-1] < nums[i]) {
                toBeSwappedIdx = i-1;
                break;
            }
        }
        if (toBeSwappedIdx != -1) {
            for (int i = nums.length - 1; i > toBeSwappedIdx; i--) { 
                if (nums[i] > nums[toBeSwappedIdx]) {
                    swap(nums, toBeSwappedIdx, i);
                    break;
                }
            }
        }

        reverse(nums, toBeSwappedIdx + 1);
    }

    private void reverse(int[] nums, int start) {
        int i = start, j = nums.length - 1;
        while (i < j) {
            swap(nums, i, j);
            i++;
            j--;
        }
    }

    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
