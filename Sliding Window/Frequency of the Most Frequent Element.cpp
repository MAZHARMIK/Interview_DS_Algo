/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : META
    Leetcode Link               : https://leetcode.com/problems/frequency-of-the-most-frequent-element/
*/

/************************************************ C++ *******************************************************/
//Approach-1 (Using sliding window)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        
        int n = nums.size();
        
        int result = 0;
        
        int i = 0;
        long currSum = 0;
        
        for(int j = 0; j<n; j++) {
            
            long target = nums[j];
            currSum   += nums[j];
            
            while((j-i+1)*target - currSum > k) {
                currSum -= nums[i];
                i++;
            }
            
            result = max(result, j-i+1);
            
        }
        return result;
    }
};

//Approach-2 (Improved sliding window)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        
        int n = nums.size();
        
        int result = 0;
        
        int i = 0;
        long currSum = 0;
        
        for(int j = 0; j<n; j++) {
            
            long target = nums[j];
            currSum   += nums[j];
            
            if((j-i+1)*target - currSum > k) {
                currSum -= nums[i];
                i++;
            }
            
            result = max(result, j-i+1);
            
        }
        return result;
    }
};


/************************************************ JAVA *******************************************************/\
//Approach-1 (Using sliding window)
//T.C : O(nlogn)
//S.C : O(1)
public class Solution {
    public int maxFrequency(int[] nums, int k) {
        Arrays.sort(nums);
        
        int n = nums.length;
        
        int result = 0;
        
        int i = 0;
        long currSum = 0;
        
        for (int j = 0; j < n; j++) {
            
            long target = nums[j];
            currSum += nums[j];
            
            while ((j - i + 1) * target - currSum > k) {
                currSum -= nums[i];
                i++;
            }
            
            result = Math.max(result, j - i + 1);
            
        }
        return result;
    }
}


//Approach-2 (Improved sliding window)
//T.C : O(nlogn)
//S.C : O(1)

public class Solution {
    public int maxFrequency(int[] nums, int k) {
        Arrays.sort(nums);
        
        int n = nums.length;
        
        int result = 0;
        
        int i = 0;
        long currSum = 0;
        
        for (int j = 0; j < n; j++) {
            
            long target = nums[j];
            currSum += nums[j];
            
            if ((j - i + 1) * target - currSum > k) {
                currSum -= nums[i];
                i++;
            }
            
            result = Math.max(result, j - i + 1);
            
        }
        return result;
    }
}
