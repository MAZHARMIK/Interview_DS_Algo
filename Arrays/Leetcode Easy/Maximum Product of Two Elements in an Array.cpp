/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=YtmAMnBjUkg
    Company Tags                : will soon update
    Leetcode Link               : https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array
*/


/**************************************************************** C++ ****************************************************************/
//Approach-1 (Keep finding the max current number)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        
        int maxNum = nums[0];
        int result = 0;
        
        for(int i = 1; i<n; i++) {
            result = max(result, (maxNum-1)*(nums[i]-1));
            maxNum = max(maxNum, nums[i]);
        }
        
        return result;
    }
};


//Approach-2 (Find max and secondmax number)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        
        int firstMax  = 0;
        int secondMax = 0;
        
        
        for(int i = 0; i<n; i++) {
            
            if(nums[i] > firstMax) {
                secondMax = firstMax;
                firstMax = nums[i];
            } else {
                secondMax = max(secondMax, nums[i]);
            }
            
        }
        
        return (firstMax-1)*(secondMax-1);
    }
};





/**************************************************************** JAVA ****************************************************************/
//Approach-1 (Keep finding the max current number)
//T.C : O(n)
//S.C : O(1)
public class Solution {
    public int maxProduct(int[] nums) {
        int n = nums.length;

        int maxNum = nums[0];
        int result = 0;

        for (int i = 1; i < n; i++) {
            result = Math.max(result, (maxNum - 1) * (nums[i] - 1));
            maxNum = Math.max(maxNum, nums[i]);
        }

        return result;
    }
}


//Approach-2 (Find max and secondmax number)
//T.C : O(n)
//S.C : O(1)
public class Solution {
    public int maxProduct(int[] nums) {
        int n = nums.length;

        int firstMax = 0;
        int secondMax = 0;

        for (int i = 0; i < n; i++) {

            if (nums[i] > firstMax) {
                secondMax = firstMax;
                firstMax = nums[i];
            } else {
                secondMax = Math.max(secondMax, nums[i]);
            }

        }

        return (firstMax - 1) * (secondMax - 1);
    }
}
