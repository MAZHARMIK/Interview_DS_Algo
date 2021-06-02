/*
    Company Tags  : Salesforce, Amazon, Microsoft, Faceook
    Leetcode Link : https://leetcode.com/problems/uncrossed-lines/
*/

//Approach-1 (Recursion + Memoization)
class Solution {
public:
    int m, n;
    int t[501][501];
    int maxLines(vector<int>& nums1, vector<int>& nums2, int i, int j) {
        if(i >= m || j>= n)
            return 0;
        
        if(t[i][j] != -1)
            return t[i][j];
        int lines = 0;
        
        if(nums1[i] == nums2[j]) {
            return t[i][j] = 1 + maxLines(nums1, nums2, i+1, j+1);
        } else {
            int take1 = maxLines(nums1, nums2, i+1, j); //include i, exclude j
            int take2 = maxLines(nums1, nums2, i, j+1); //include j, exclude i
            return t[i][j] =  max(take1, take2);
        }
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        m = nums1.size();
        n = nums2.size();
        memset(t, -1, sizeof(t));
        return maxLines(nums1, nums2, 0, 0);
    }
};

//Approach-2 : (Converting Approach-1 to pure Bottom Up DP)
class Solution {
public:
    int m, n;
    
    int maxLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> t(m+1, vector<int>(n+1));
        
        for(int i = 0; i<m+1; i++) {
            for(int j = 0; j<n+1; j++) {
                if(i == 0 || j == 0)
                    t[i][j] = 0;
                else if(nums1[i-1] == nums2[j-1]) {
                    t[i][j] = 1 + t[i-1][j-1];
                } else {
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
                }
            }
        }
        
        return t[m][n];
    }
    
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        m = nums1.size();
        n = nums2.size();
        return maxLines(nums1, nums2);
    }
};
