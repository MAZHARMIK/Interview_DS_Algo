/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=M_YXCATc4ro
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
        
        int left  = 0;
        int right = 2*k;
        int i     = k;
        
        for(int i = left; i <= right; i++) {
            windowSum += nums[i];
        }
        
        
        result[i] = windowSum/(2*k+1);
        
        i++;
        right++; //Shifting window
        
        while(right < n) {
            
            int out_of_window  = nums[left];
            int came_to_window = nums[right];
            
            windowSum = windowSum - out_of_window + came_to_window;
            
            result[i] = windowSum/(2*k+1);
            i++;
            left++;
            right++;
            
        }
        return result;
    }
};

/***************************************************************************Java*************************************************************************/

import java.util.Arrays;

class Solution {
    public int[] getAverages(int[] nums, int k) {
        int n = nums.length;
        if (k == 0) {
            return nums;
        }
        int[] result = new int[n];
        Arrays.fill(result, -1);
        if (n < 2 * k + 1) {
            return result;
        }
        long windowSum = 0;
        int left = 0;
        int right = 2 * k;
        int i = k;
        for (int j = left; j <= right; j++) {
            windowSum += nums[j];
        }
        result[i] = (int) (windowSum / (2 * k + 1));
        i++;
        right++;
        while (right < n) {
            int outOfWindow = nums[left];
            int cameToWindow = nums[right];
            windowSum = windowSum - outOfWindow + cameToWindow;
            result[i] = (int) (windowSum / (2 * k + 1));
            i++;
            left++;
            right++;
        }
        return result;
    }
}

// Time Complexity: O(n)
// Space Complexity: O(n)
