/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=SQ8tY9nxeZU
      Company Tags                : Google, Meta
      Leetcode Link               : https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/

      Similar Problem             : Leetcode - 1004, 487, 485
*/

//Approach-1 (Simple Brute Force) - T.C : O(n^2)
class Solution {
public:
    int n;
    
    int findMax(vector<int>& nums, int skip_idx) {
        
        int currLength = 0;
        int maxLength  = 0;
        
        for(int i = 0; i<n; i++) {
            if(i == skip_idx)
                continue;
            
            if(nums[i] == 1) {
                currLength++;
                maxLength = max(maxLength, currLength);
            } else {
                currLength = 0;
            }
        }
        
        return maxLength;
        
    }
    
    int longestSubarray(vector<int>& nums) {
        n = nums.size();
        int result = 0;
        
        int countZero = 0;
        for(int i = 0; i<n; i++) {
            
            if(nums[i] == 0) {
                countZero++;
                result = max(result, findMax(nums, i));
            }
            
        }
        
        if(countZero == 0)
            return n-1;
        
        return result;
        
    }
};

//Approach-2 (Using Traditional Sliding Window) - O(n)
class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int zeroCount = 0;
        int longestWindow = 0;

        int i = 0;
        
        for (int j = 0; j < nums.size(); j++) {
            zeroCount += (nums[j] == 0);
                          
            // Shrink the window until the zero counts come under the limit.
            while (zeroCount > 1) {
                zeroCount -= (nums[i] == 0);
                i++;
            }
              
            longestWindow = max(longestWindow, j - i);
        }

        return longestWindow;
    }
};


//Approach-3 (Using Better Sliding Window) - O(n))
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0, j = 0;
        
        int last_zero_idx = -1;
        
        int result = 0;
        
        while(j < nums.size()) {
            
            if(nums[j] == 0) {
                i = last_zero_idx+1;
                last_zero_idx = j;
            }
            
            result = max(result, j-i);
            j++;
        }
        
        return result;
    }
};
