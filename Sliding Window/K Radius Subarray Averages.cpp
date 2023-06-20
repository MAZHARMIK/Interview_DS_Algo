/*
      MY YOUTUBE VIDEO ON THIS Qn : <soon>
      Company Tags                : AMAZON
      Leetcode Link               : https://leetcode.com/problems/k-radius-subarray-averages/
*/

//My Approach-2 using Prefix Array is in Array/Cumulative_Sum(Prefix Array) folder Folde. Link below - 
//Link - https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/Cumulative_Sum(Prefix%20Array)/K%20Radius%20Subarray%20Averages.cpp


//Approach-1 : Using Sliding Window
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        
        if(k == 0)
            return nums;
    
        vector<int> result(n, -1);
        
        if(n < 2*k + 1)
            return result;
        
        long long windowSum = 0;
        
        for(int i = 0; i<2*k+1; i++) {
            windowSum += nums[i];
        }
        
        result[k] = windowSum/(2*k+1);
        
        for(int i = 2*k+1; i<n; i++) {
            
            int out_of_window  = nums[i-(2*k+1)];
            int came_to_window = nums[i];
            
            windowSum = windowSum - out_of_window + came_to_window;
            
            result[i-k] = windowSum/(2*k+1);
            
        }
        return result;
    }
};
