/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=5sC5MUcF-Qc
    Company Tags                : META
    Leetcode Link               : https://leetcode.com/problems/number-of-zero-filled-subarrays/
*/

//Approach-1 (Using simple math to calculate count of subarrays)
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long result = 0;
        
        int n = nums.size();
        
        int i = 0;
        while(i < n) {
            
            long long zeros = 0;
            
            if(nums[i] == 0) {
                
                while(i < n && nums[i] == 0) {
                    i++;
                    zeros++;
                }
                
            } else {
                    i++;
            }
            result += (zeros)*(zeros+1)/2;
        }
        
        return result;
        
    }
};

//Approach-2 (Better and clean approach using observation)
//Watch my YouTube video above to see the explanation on why this works
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long result = 0;
        
        int n = nums.size();
        
        int countSubArray = 0;
        
        for(int i = 0; i<n; i++) {
            
            if(nums[i] == 0)
                countSubArray += 1;
            else
                countSubArray = 0;
            
            result += countSubArray;
            
        }
        
        return result;
        
    }
};
