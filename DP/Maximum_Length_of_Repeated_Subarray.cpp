/*
    Company Tags  : Amazon, Microsoft, Morgan Stanley
    Leetcode Link : https://leetcode.com/problems/maximum-length-of-repeated-subarray/
*/
//Note: This is nothing but "Longest Common Substring"

class Solution {
public:
    int t[1005][1005];
    int maxC = 0;
    int recur_memo(vector<int>& nums1, vector<int>& nums2, int m, int n) {
        if(m == 0 || n == 0)
            return 0;
            
        if(t[m][n] != -1)
            return t[m][n];
        
        if(nums1[m-1] == nums2[n-1]) {
            t[m][n] = 1 + recur_memo(nums1, nums2, m-1, n-1);
            maxC = max(maxC, t[m][n]);
        }
        
        //these below we have to call anyway because we are talking about substring.
        recur_memo(nums1, nums2, m-1, n);
        recur_memo(nums1, nums2, m, n-1);
        
        if(t[m][n] == -1)
            t[m][n] = 0;
        return  t[m][n];
    }
    
    int dp(vector<int>& nums1, vector<int>& nums2, int m, int n) {
        vector<vector<int>> t(m+1, vector<int>(n+1));
        
        int result = 0;
        for(int i = 0; i<m+1; i++) {
            for(int j = 0; j<n+1; j++) {
                if(i == 0 || j == 0)
                    t[i][j] = 0;
                else if(nums1[i-1] == nums2[j-1]) {
                    t[i][j] = 1 + t[i-1][j-1];
                    result = max(result, t[i][j]);
                } else
                    t[i][j] = 0;
            }
        }
        
        return result;
    }
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        memset(t, -1, sizeof(t));
        recur_memo(nums1, nums2, m, n); //resurive+memoization
        return maxC;
        //return dp(nums1, nums2, m, n);
    }
};
