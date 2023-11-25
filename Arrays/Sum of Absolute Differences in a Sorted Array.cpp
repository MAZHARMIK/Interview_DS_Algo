/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=2ENYvJL-Leo
    Company Tags                : Adobe
    Leetcode Link               : https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/
*/

/************************************************************ C++ ***********************************************************/
//Approach-1 (Using Prefix Sum)
//T.C : O(n);
//S.C : O(n) stored prefix Sum
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> prefixSum(n);
        prefixSum[0] = nums[0];
        
        for(int i = 1; i<n; i++) {
            prefixSum[i] = nums[i] + prefixSum[i-1];
        }
        
        vector<int> result(n);
        
        for(int i = 0; i < n; i++) {
            int leftSum   = prefixSum[i] - nums[i];
            int rightSum  = prefixSum[n-1] - prefixSum[i];
            
            int leftCount  = i;
            int rightCount = n-i-1;
            
            int leftTotal  = (leftCount * nums[i]) - leftSum;
            int rightTotal = rightSum - (nums[i]*rightCount);
            
            result[i] = leftTotal + rightTotal;
        }
        
        return result;
        
    }
};


//Approach-2 (Without using extra space for prefix sum)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(begin(nums), end(nums), 0);

        vector<int> result(n);
        int prefixSum = 0;
        
        for(int i = 0; i < n; i++) {
            int leftSum   = prefixSum;
            int rightSum  = sum - prefixSum - nums[i];
            
            int leftCount  = i;
            int rightCount = n-i-1;
            
            int leftTotal  = (leftCount * nums[i]) - leftSum;
            int rightTotal = rightSum - (nums[i]*rightCount);
            
            result[i] = leftTotal + rightTotal;
            prefixSum += nums[i];
        }
        
        return result;
        
    }
};



/************************************************************ JAVA ***********************************************************/
//Approach-1 (Using Prefix Sum)
//T.C : O(n);
//S.C : O(n) stored prefix Sum
public class Solution {
    public int[] getSumAbsoluteDifferences(int[] nums) {
        int n = nums.length;

        int[] prefixSum = new int[n];
        prefixSum[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefixSum[i] = nums[i] + prefixSum[i - 1];
        }

        int[] result = new int[n];

        for (int i = 0; i < n; i++) {
            int leftSum = prefixSum[i] - nums[i];
            int rightSum = prefixSum[n - 1] - prefixSum[i];

            int leftCount = i;
            int rightCount = n - i - 1;

            int leftTotal = (leftCount * nums[i]) - leftSum;
            int rightTotal = rightSum - (nums[i] * rightCount);

            result[i] = leftTotal + rightTotal;
        }

        return result;
    }
}


//Approach-2 (Without using extra space for prefix sum)
//T.C : O(n)
//S.C : O(1)
public class Solution {
    public int[] getSumAbsoluteDifferences(int[] nums) {
        int n = nums.length;
        int sum = Arrays.stream(nums).sum();

        int[] result = new int[n];
        int prefixSum = 0;

        for (int i = 0; i < n; i++) {
            int leftSum = prefixSum;
            int rightSum = sum - prefixSum - nums[i];

            int leftCount = i;
            int rightCount = n - i - 1;

            int leftTotal = (leftCount * nums[i]) - leftSum;
            int rightTotal = rightSum - (nums[i] * rightCount);

            result[i] = leftTotal + rightTotal;
            prefixSum += nums[i];
        }

        return result;
    }
}
