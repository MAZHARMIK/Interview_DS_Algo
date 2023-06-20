/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=RSE_GB0eBZY
      Company Tags                : AMAZON
      Leetcode Link               : https://leetcode.com/problems/k-radius-subarray-averages/
*/

//My Approach-2 is in Sliding Window Folder - https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Sliding%20Window/K%20Radius%20Subarray%20Averages.cpp

//Approach-1 (Using Prefix Array)
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        
        if(k == 0)
            return nums;
    
        vector<int> result(n, -1);
        
        if(n < 2*k + 1)
            return result;
        
        vector<long long> prefixSum(n, 0);
        prefixSum[0] = nums[0];
        
        for(int i = 1; i<n; i++) {
            prefixSum[i] = prefixSum[i-1] + nums[i];
            
        }

        for(int i = k; i<n-k; i++) {
            
            int left_idx  = i-k;
            int right_idx = i+k;
            
            long long sum = prefixSum[right_idx];
            
            if(left_idx > 0)
                sum -= prefixSum[left_idx-1];
            
            
            int avg = sum/(2*k+1);
            
            result[i] = avg;
            
            
        }
        
        return result;
        
    }
};
