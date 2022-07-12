/*
    Company Tags     : Microsoft, Amazon
    Leetcode Link    : https://leetcode.com/problems/partition-to-k-equal-sum-subsets/
    
    Exact Same Qn    : Matchsticks to Square (Leetcode - 473)
    
*/

//Approach-1 (Using extra O(k) space)
class Solution {
public:
    int n, k;
    int visited[17];
    
    bool possible(vector<int>& nums, int numsIndex, vector<int>& buckets, int bucketsIndex, int& subsetSum) {
        if(buckets[bucketsIndex] == subsetSum) { 
            /*
                I have found that subsetSum which is of size k has been filled till index k-2, so the last subset need
                not be checked because it will definitely contain "target" (since, sum%k == 0)
            */
            
            if(bucketsIndex == k-2)
                return true;
            
            return possible(nums, n-1, buckets, bucketsIndex+1, subsetSum);
        }
        
        for(int i = numsIndex; i>=0; i--) {
            if(visited[i] || buckets[bucketsIndex]+nums[i] > subsetSum)
                continue;
            
            visited[i] = 1;
            buckets[bucketsIndex] += nums[i];
            
            if(possible(nums, i-1, buckets, bucketsIndex, subsetSum))
                return true;
            
            visited[i] = 0;
            buckets[bucketsIndex] -= nums[i];
        }
        
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int K) {
        int sum = accumulate(begin(nums), end(nums), 0);
        
        memset(visited, 0, sizeof(visited));
        n = nums.size();
        k = K;
        
        if(sum%k != 0)
            return false;
        
        int subsetSum = sum/k;
        vector<int> buckets(k, 0);
        int bucketsIndex      = 0;
        int numsIndex         = n-1;
        buckets[bucketsIndex] = nums[numsIndex];
        visited[numsIndex]    = 1;
        
        return possible(nums, numsIndex, buckets, bucketsIndex, subsetSum);
        
    }
};

//Approach-2 (Without using any O(k) space)
class Solution {
public:
    int n;
    int visited[17];
    
    bool possible(vector<int>& nums, int numsIndex, int currSum, int& subsetSum, int k) {
        if(k == 1)
            return true;
        
        if(currSum == subsetSum) {
            return possible(nums, n-1, 0, subsetSum, k-1);
        }
        
        for(int i = numsIndex; i>=0; i--) {
            if(visited[i] || currSum+nums[i] > subsetSum)
                continue;
            
            visited[i] = 1;
            currSum   += nums[i];
            
            if(possible(nums, i+1, currSum, subsetSum, k))
                return true;
            
            visited[i] = 0;
            currSum   -= nums[i];
        }
        
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(begin(nums), end(nums), 0);
        
        memset(visited, 0, sizeof(visited));
        n = nums.size();
        
        if(sum%k != 0)
            return false;
        
        int subsetSum      = sum/k;
        int numsIndex      = n-1;
        int currSum        = nums[numsIndex];
        visited[numsIndex] = 1;
        
        return possible(nums, numsIndex, currSum, subsetSum, k);
        
    }
};
