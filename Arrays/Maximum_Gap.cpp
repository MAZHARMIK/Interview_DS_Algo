/*
    Company Tags  : Hunan Asset
    Leetcode Link : https://leetcode.com/problems/maximum-gap/
*/

//APproach-1 O(nlogn)
Simply sort and find the maximum gap


//Approach-2 (In O(n) Time and space)
//You need to know Counting Sort before solving this
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n < 2)
            return 0;
        
        auto mm  = minmax_element(begin(nums), end(nums));
        int minN = *mm.first;
        int maxN = *mm.second;
        
        int bucketSize = ceil((float)(maxN-minN)/(float)(n-1));
        
        vector<int> minBucket(n-1, INT_MAX);
        vector<int> maxBucket(n-1, INT_MIN);
        
        for(int &x : nums) {
            if(x == minN || x == maxN)
                continue;
            
            int bucketIdx = (x-minN)/bucketSize;
            minBucket[bucketIdx] = min(minBucket[bucketIdx], x);
            maxBucket[bucketIdx] = max(maxBucket[bucketIdx], x);
        }
        
        /*
            We cleverly chose the bucketSize in a way
            that no elements inside a bucket will give max gap.
            So, we will find the max gap by finding the gap between
            maximum of current bucket and minimum of next bucket
        */
        
        int maxGap = 0;
        int prev = minN;
        for(int i = 0; i<n-1; i++) {
            if(minBucket[i] == INT_MAX || maxBucket[i] == INT_MIN)
                continue; //They are empty and neber got any element
            
            int currBucketMin = minBucket[i];
            
            maxGap = max(maxGap, currBucketMin-prev);
            prev = maxBucket[i];
        }
        
        maxGap = max(maxGap, maxN-prev);
        
        return maxGap;
        
    }
};
