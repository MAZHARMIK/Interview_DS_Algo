/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray
*/


/************************************************************ C++ *****************************************************/
//Approach-1 (2 Pass - Kadane's Algorithm for maxsubarrysum and minsybarraysum)
//T.C : O(2*n) ~= O(n)
//S.C : O(1)
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();

        int currSubSum = nums[0];
        int maxSubSum = nums[0];

        //Kadane's Algo for findig max subarray sum
        for(int i = 1; i < n; i++) {
            currSubSum = max(nums[i], currSubSum + nums[i]);
            maxSubSum = max(maxSubSum, currSubSum);
        }

        //Kadane's Algo for findig min subarray sum
        int minSubSum = nums[0];
        currSubSum = nums[0];
        for(int i = 1; i < n; i++) {
            currSubSum = min(nums[i], currSubSum + nums[i]);
            minSubSum = min(minSubSum, currSubSum);
        }

        return max(maxSubSum, abs(minSubSum));
    }
};


//Approach-2 (1 Pass - Kadane's Algorithm for maxsubarrysum and minsybarraysum inside one for loop)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();

        int maxSum = nums[0];
        int minSum = nums[0];

        int currSumMax = nums[0];
        int currSumMin = nums[0];

        for(int i = 1; i < n; i++) {
            currSumMax = max(nums[i], currSumMax + nums[i]);
            maxSum = max(maxSum, currSumMax);


            currSumMin = min(nums[i], currSumMin + nums[i]);
            minSum     = min(minSum, currSumMin);
        }

        return max(maxSum, abs(minSum));


    }
};


/************************************************************ Java *****************************************************/
//Approach-1 (2 Pass - Kadane's Algorithm for maxsubarrysum and minsybarraysum)
//T.C : O(2*n) ~= O(n)
//S.C : O(1)
class Solution {
    public int maxAbsoluteSum(int[] nums) {
        int n = nums.length;

        int currSubSum = nums[0];
        int maxSubSum = nums[0];

        //Kadane's Algo for finding max subarray sum
        for (int i = 1; i < n; i++) {
            currSubSum = Math.max(nums[i], currSubSum + nums[i]);
            maxSubSum = Math.max(maxSubSum, currSubSum);
        }

        //Kadane's Algo for finding min subarray sum
        int minSubSum = nums[0];
        currSubSum = nums[0];
        for (int i = 1; i < n; i++) {
            currSubSum = Math.min(nums[i], currSubSum + nums[i]);
            minSubSum = Math.min(minSubSum, currSubSum);
        }

        return Math.max(maxSubSum, Math.abs(minSubSum));
    }
}


//Approach-2 (1 Pass - Kadane's Algorithm for maxsubarrysum and minsybarraysum inside one for loop)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int maxAbsoluteSum(int[] nums) {
        int n = nums.length;

        int maxSum = nums[0];
        int minSum = nums[0];

        int currSumMax = nums[0];
        int currSumMin = nums[0];

        for (int i = 1; i < n; i++) {
            //Kadane's Algo for finding max subarray sum
            currSumMax = Math.max(nums[i], currSumMax + nums[i]);
            maxSum = Math.max(maxSum, currSumMax);

            //Kadane's Algo for finding min subarray sum
            currSumMin = Math.min(nums[i], currSumMin + nums[i]);
            minSum = Math.min(minSum, currSumMin);
        }

        return Math.max(maxSum, Math.abs(minSum));
    }
}
