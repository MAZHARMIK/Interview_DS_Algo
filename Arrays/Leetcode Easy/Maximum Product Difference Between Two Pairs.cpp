/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=J-pw9rcKY3Y
    Company Tags                : will soon update here
    Leetcode Link               : https://leetcode.com/problems/maximum-product-difference-between-two-pairs/
*/


/************************************************************ C++ ********************************************************************************/
//Approach-1 (Using sorting)
//T.C : O(nlogn) 
//S.C : O(1)
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        
        return (nums[n-1] * nums[n-2]) - (nums[1] * nums[0]);
    }
};


//Approach-1 (Without sorting)
//T.C : O(n) 
//S.C : O(1)
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int largest = INT_MIN;
        int secondLargest = INT_MIN;
        
        int smallest = INT_MAX;
        int secondSmallest = INT_MAX;
        
        for(int &num : nums) {
            if(num > largest) {
                secondLargest = largest;
                largest = num;
            } else {
                secondLargest = max(secondLargest, num);
            }
            
            if(num < smallest) {
                secondSmallest = smallest;
                smallest = num;
            } else {
                secondSmallest = min(secondSmallest, num);
            }
            
        }
        
        return (largest * secondLargest) - (secondSmallest * smallest);
        
    }
};


/************************************************************ JAVA ********************************************************************************/
//Approach-1 (Using sorting)
//T.C : O(nlogn) 
//S.C : O(1)
public class Solution {
    public int maxProductDifference(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums);
        
        return (nums[n - 1] * nums[n - 2]) - (nums[1] * nums[0]);
    }
}


//Approach-1 (Without sorting)
//T.C : O(n) 
//S.C : O(1)
public class Solution {
    public int maxProductDifference(int[] nums) {
        int largest = Integer.MIN_VALUE;
        int secondLargest = Integer.MIN_VALUE;
        
        int smallest = Integer.MAX_VALUE;
        int secondSmallest = Integer.MAX_VALUE;
        
        for (int num : nums) {
            if (num > largest) {
                secondLargest = largest;
                largest = num;
            } else {
                secondLargest = Math.max(secondLargest, num);
            }
            
            if (num < smallest) {
                secondSmallest = smallest;
                smallest = num;
            } else {
                secondSmallest = Math.min(secondSmallest, num);
            }
        }
        
        return (largest * secondLargest) - (secondSmallest * smallest);
    }
}
