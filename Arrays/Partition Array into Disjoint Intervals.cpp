/*
    Company Tags  : Variation of this question has been asked in "Google and some other companies"
    Leetcode Link : https://leetcode.com/problems/partition-array-into-disjoint-intervals/
*/

//Approach-1 (Brute Force : O(n^2) time)
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        
        int maxE = nums[0];
        
        for(int i = 0; i<n; i++) {
            maxE = max(maxE, nums[i]);
            int j = i+1;
            for(; j<n; j++) {
                if(nums[j] < maxE)
                    break;
            }
            if(j == n)
                return i+1;
        }
        
        return -1;
    }
};


//Approach-2 (Using a very popular concept min-max track from left and right)
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        
        /*
            When the maximum of left-partition is less than minimum of right-partition,
            that's the point where we draw the line of partition
        */
        
        //So calculate minimum from right;
        vector<int> minRight(n);
        minRight[n-1] = nums[n-1];
        for(int i = n-2; i>=0; i--) {
            minRight[i] = min(minRight[i+1], nums[i]);
        }
        
        int maxLeft = nums[0];
        for(int i = 0; i<n-1; i++) {
            maxLeft = max(maxLeft, nums[i]);
            
            if(maxLeft <= minRight[i+1])
                return i+1;
        }
        return -1;
    }
};
