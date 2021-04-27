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
        if(t[m][n] != -1)
            return t[m][n];
        
        if(m == 0 || n == 0)
            return 0;
        
        int max_substring_ending_here = 0;
        if(nums1[m-1] == nums2[n-1]) {
            max_substring_ending_here = 1 + recur_memo(nums1, nums2, m-1, n-1);
        }
        
		//May be you find better results if you do (m-1, n) and you end up updating maxC with some LAAARGEST COMMON SUBSTRING LENGTH
        int decrease_m = recur_memo(nums1, nums2, m-1, n);
		
		//OR,
		//May be you find better results if you do (m, n-1) and you end up updating maxC with some LAAARGEST COMMON SUBSTRING LENGTH
        int decrease_n  = recur_memo(nums1, nums2, m, n-1);
        
		//Like I said, you need to keep on finding the maxC in every call you make throughout your journey.
        maxC = max({maxC, max_substring_ending_here, decrease_m, decrease_n});
        
		
		//BUT BUT BUT, you need to return the best you found at this ending stage
        return t[m][n] = max_substring_ending_here;
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
