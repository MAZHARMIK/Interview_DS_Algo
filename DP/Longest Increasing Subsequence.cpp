/*
    Company Tags  : Microsoft
    Leetcode Link : https://leetcode.com/problems/longest-increasing-subsequence/
*/

//Approach-1 (TopDown: Recur+Memo) O(n*n)
class Solution {
public:
    int n;
    int t[2501][2501];
    int lis(vector<int>& nums, int prev_idx, int curr_idx) {
       if(curr_idx == n)
           return 0;
        
        if(prev_idx != -1 && t[prev_idx][curr_idx] != -1)
            return t[prev_idx][curr_idx];
        
        int taken = 0;
        if(prev_idx == -1 || nums[curr_idx] > nums[prev_idx])
            taken = 1 + lis(nums, curr_idx, curr_idx+1);
        
        int not_taken = lis(nums, prev_idx, curr_idx+1);
        
        if(prev_idx != -1)
            t[prev_idx][curr_idx] =  max(taken, not_taken);
        
        return max(taken, not_taken);
            
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(t, -1, sizeof(t));
        n = nums.size();
        return lis(nums, -1, 0);
    }
};

//Approach-2 (Bottom Up DP) O(n*n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> t(n, 1);
        int maxL = 1;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<i; j++) {
                if(nums[j] < nums[i]) {
                    t[i] = max(t[i], t[j]+1);
                    maxL = max(maxL, t[i]);
                }
            }
        }
        
        return maxL;
    }
};

//Approach-3 (Converting the question to Longest Common Subsequence) O(n*n)
class Solution {
public:
    int LCS(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        
        vector<vector<int>> t(m+1, vector<int>(n+1));
        //if length of nums1/num2 is 0, then LCS is 0
        for(int j = 0; j<n; j++) {
            t[0][j] = 0;
        }
        for(int i = 0; i<n; i++) {
            t[i][0] = 0;
        }
        
        for(int i = 1; i<m+1; i++) {
            for(int j = 1; j<n+1; j++) {
                if(nums1[i-1] == nums2[j-1])
                    t[i][j] = 1 + t[i-1][j-1];
                else
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
        
        return t[m][n];
    }
    int lengthOfLIS(vector<int>& nums) {
        //We need unique elements only because we want 'Longest "Increasing" Subseqnece'
        set<int> st(begin(nums), end(nums));
        
        vector<int> nums2(begin(st), end(st));
        
        return LCS(nums, nums2);
        
    }
};

//Approacj-4 (Using concept of Patience Sorting (O(nlogn))
/*
	You can write the code very easily if you understand the dry run below (example):
    Patience Sorting
    
    Input : {3, 10, 2, 1, 20}
    
    sorted : {}
    
----------------------------------
    we are at 3
    Since sorted is empty, insert 3
    sorted : {3}
    
----------------------------------
    We are now at 10
    If we find an element which is greater or equal than 10, we put this 10 under that
    Since, 3 < 10, we can't put 10 under it. So, we create another bucket for 10 (i.e. insert in sorted)
    sorted : {3, 10}
----------------------------------
    We are now at 2
    If we find an element which is greater or equal than 2, we put this 2 under that
    Since, 3 > 2 and 10 > 2 as well, we put 2 under the one which is smallest
    So, we put 2 under 3
    
    sorted : {3, 10}
              |
              2
              
----------------------------------
    We are now at 1
    If we find an element which is greater or equal than 1, we put this 1 under that
    Since, 2 > 1 and 10 > 1 as well, we put 2 under the one which is smallest
    So, we put 1 under 2
    
    sorted : {3, 10}
              |
              2
              |
              1
              
-----------------------------------
    We are now at 20
    If we find an element which is greater or equal than 20, we put this 20 under that
    Since, 1 < 20 and 10 < 20, So, we create another bucket for 20 (i.e. insert in sorted)
    
    sorted : {3, 10, 20}
              |
              2
              |
              1
    
    
    So, we are done.
    If we start from 1 and move to 2 and then to 3, 
    Then to 10 and to 20
    So, at the end you see that the array is sorted.
    
    It's O(nlogn) Because we iterate in Input array and for finding the element just greater than current element
    we take O(logn) time.
    
-----------------------------------
If you notice, for getting an increasing subsequence, we can pick one element from each bucket from sorted.
Example : 
    1, 10, 20
    2, 10, 20
    3, 10, 20
    These are largest inceasing subsequence that we can get. And length will be size of sorted.
    i.e. LIS = size of sorted.
    
    To make things simple, instead of appending 2, 1 under 3, we will replace 3 with current element (2 and then 1)
    i.e. Input : {3, 10, 2, 1, 10}
 sorted =   {3}
    Now I have 10. Since it's greatest, we simply insert it in sorted
 sorted =   {3, 10}
    Now, I have 2. Since it's next greatest is 3, we will replace 3 with 2
 sorted =   {2, 10}
    Now, I have 1. Since it's next greatest is 2, we will replace 2 with 1
 sorted =   {1, 10}
    Now, I have 20. Since it's greatest, we will insert it in sorted
 sorted = {1, 10, 20}
 
 size of sorted = 3 = LIS
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted;
        
        for(int i = 0; i<n; i++) {
            /*
			     Why lower bound ?
				 We want increasing subsequence and  hence 
				 we want to eliminate the duplicates as well.
				 lower_bound returns iterator to "next greater or equal to"
			*/
            auto it = lower_bound(begin(sorted), end(sorted), nums[i]);
            
            if(it == end(sorted))
                sorted.push_back(nums[i]); //greatest : so insert it
            else
                *it = nums[i]; //replace
        }
        
        return (int)sorted.size();
    }
};
