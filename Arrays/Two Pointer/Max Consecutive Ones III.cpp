/*
    Company Tags  : Google (With some Variations)
    Leetcode Link : https://leetcode.com/problems/max-consecutive-ones-iii/
*/

//Approach-1 (Two Pointer Technique)
class Solution {
public:
     void moveUntilOneCount(vector<int>& nums, int& count, int& i, int& j, int &k) {
        if(count > k) {
            while(j <= i && count > k) {
                if(nums[j] == 0) {
                    count--;
                }
                j++;
            }
        }
    }
    int longestOnes(vector<int>& nums, int k) {
        int  n = nums.size();

        if(k >= n)
            return n;

        int result = 0;
        int count = 0;
        int i = 0, j = 0;
        while(i < n) {
            if(nums[i] == 0) {
                count++;
                moveUntilOneCount(nums, count, i, j, k);
            }
            result = max(result, i-j+1);
            i++;
        }
        return result;
    }
};


//Approach-2 (2 pointer techinique with slight improvement)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int  n = nums.size();

        if(k >= n)
            return n;

        int result = 0;
        int count = 0;
        int i = 0, j = 0;
        while(i < n) {
            if(nums[i] == 0) 
                count++;
            if(count > k) {
                count -= nums[j] == 0 ? 1 : 0; //decrement k only if you are crossing leaving 0 behind
                j++;
            }
            result = max(result, i-j+1);
            i++;
        }
        return result;
    }
};
