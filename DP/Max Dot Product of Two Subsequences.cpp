/*
      MY YOUTUBE VIDEO ON THIS Qn : Recur + memo - https://www.youtube.com/watch?v=Tk70PLqbYH4
                                    Bottom Up - 
      Company Tags                : Soon I will update
      Leetcode Link               : https://leetcode.com/problems/max-dot-product-of-two-subsequences/
*/

//NOTE : This is a variant of LCS (Longest Common Subsequence) Pattern

/*********************************************** C++ ***********************************************/
//Approach-1 (Using concept of LCS - same code)
//T.C : O(m*n)
class Solution {
public:
    int m, n;
    int t[501][501];
    
    int solve(vector<int>& nums1, vector<int>& nums2, int i, int j) {
        if(i == m || j == n)
            return -100000000; //send a large negative number. Don't send 0 because we can have -ve product as well. For example : {-1, -1}, {1, 1}, output should be -1.
        
        if(t[i][j] != -1e9)
            return t[i][j];
        
        int val = nums1[i] * nums2[j];
        
        int take_i_j = solve(nums1, nums2, i+1, j+1) + val;
        
        int take_i = solve(nums1, nums2, i, j+1);
        int take_j = solve(nums1, nums2, i+1, j);
        
        
        return t[i][j] = max({val, take_i_j, take_i, take_j});
        
        
    }
    
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        m = nums1.size();
        n = nums2.size();
        
        for(int i = 0; i<501; i++) {
            for(int j = 0; j < 501; j++) {
                t[i][j] = -1e9;
            }
        }
        
        return solve(nums1, nums2, 0, 0);
    }
};

//Approach-2 (Bottom Up same as LCS)
//T.C : O(m*n)
//Sooooon coming


/*********************************************** JAVA ***********************************************/
//Approach-1 (Using concept of LCS - same code)
//T.C : O(m*n)
class Solution {
    int m, n;
    int[][] t;

    public int maxDotProduct(int[] nums1, int[] nums2) {
        m = nums1.length;
        n = nums2.length;
        t = new int[501][501];

        for (int i = 0; i < 501; i++) {
            Arrays.fill(t[i], -100000000);
        }

        return solve(nums1, nums2, 0, 0);
    }

    public int solve(int[] nums1, int[] nums2, int i, int j) {
        if (i == m || j == n)
            return -100000000;

        if (t[i][j] != -100000000)
            return t[i][j];

        int val = nums1[i] * nums2[j];

        int take_i_j = solve(nums1, nums2, i + 1, j + 1) + val;
        int take_i = solve(nums1, nums2, i, j + 1);
        int take_j = solve(nums1, nums2, i + 1, j);

        t[i][j] = Math.max(val, Math.max(take_i_j, Math.max(take_i, take_j)));
        return t[i][j];
    }
}


//Approach-2 (Bottom Up same as LCS)
//T.C : O(m*n)
//Sooooon coming
