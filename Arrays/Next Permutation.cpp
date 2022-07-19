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
