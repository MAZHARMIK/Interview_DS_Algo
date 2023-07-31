/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Hstr9Wpa5Sc
      Company Tags                : TripleByte, 
      Leetcode Link               : https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/
      Similar Qns                 : Edit Distance                    - https://leetcode.com/problems/edit-distance/
                                    Delete Operation for Two Strings - https://leetcode.com/problems/delete-operation-for-two-strings/
*/

//Approach-1 (Using Recursion + Memo (Top Down)) - O(m*n)
class Solution {
public:
    int m, n;
    
    int t[1001][1001];
    
    int solve(string &s1, string &s2, int i, int j) {
        if(i >= m && j >= n)
            return 0;
        
        if(t[i][j] != -1)
            return t[i][j];
        
        if(i >= m) {
            return t[i][j] = s2[j] + solve(s1, s2, i, j+1);
        } else if(j >= n) {
            return t[i][j] = s1[i] + solve(s1, s2, i+1, j);
        }
        
        if(s1[i] == s2[j])
            return t[i][j] = solve(s1, s2, i+1, j+1);
        
        int take_s1_i = s1[i] + solve(s1, s2, i+1, j);
        int take_s2_j = s2[j] + solve(s1, s2, i, j+1);
        
        return t[i][j] = min(take_s1_i, take_s2_j);
    }
    
    int minimumDeleteSum(string s1, string s2) {
        m = s1.length();
        n = s2.length();
        
        memset(t, -1, sizeof(t));
        
        return solve(s1, s2, 0, 0);
    }
};


//Approach-2 (Using Bottom Up)
//soon
