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

//Approach-4 (Using Binary Search : upper_bound) O(n*logn)
//I will ba back soon with this approach after understanding it
