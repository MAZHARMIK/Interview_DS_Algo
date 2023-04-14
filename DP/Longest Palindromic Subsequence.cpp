/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=M4pfB3G-YQc
    Company Tags                : Amazon, LinkedIn, Paypal, Rivigo, Uber, Google
    Leetcode Link               : https://leetcode.com/problems/longest-palindromic-subsequence/
    GfG Link                    : https://practice.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/1
*/

class Solution {
public:
    //Approach-1 (Using Concept of LCS)
    int LCS(string s1, string s2, int m, int n) {
        vector<vector<int>> t(m+1, vector<int>(m+1));
        
        for(int row = 0; row<m+1; row++) {
            t[row][0] = 0;
        }
        
        for(int col = 0; col<n+1; col++) {
            t[0][col] = 0;
        }
        
        for(int i = 1; i<m+1; i++) {
            for(int j = 1; j<n+1; j++) {
                if(s1[i-1] == s2[j-1]) {
                    t[i][j] = 1 + t[i-1][j-1];
                } else {
                    t[i][j] = max(t[i][j-1], t[i-1][j]);
                }
            }
        }
        
        return t[m][n];
    }
    
    //Approach-2 (Recursion with Memoization)
    int LPS(string s, int i, int j, vector<vector<int>>& t) {
        if(i > j)
            return 0;
        if(i == j)
            return 1;
        
        if(t[i][j] != -1)
            return t[i][j];
        if(s[i] == s[j])
            return t[i][j] = 2 + LPS(s, i+1, j-1, t);
        else
            return t[i][j] = max(LPS(s, i+1, j, t), LPS(s, i, j-1, t));
    }
    
    //Approach-3 (Bottom-Up DP)
    int LPS_Bottom_Up(string s, int n) {
        vector<vector<int>> t(n, vector<int>(n));
        //t[i][j] = longest common subsequence in string from i to j indices;
        //strings of length 1 are always a palindorme
        for(int i = 0; i<n; i++) {
            t[i][i] = 1;
        }
        
        for(int L = 2; L<=n; L++) {
            for(int i = 0; i<n-L+1; i++) {
                int j = i + L - 1;
                
                if(s[i] == s[j] && L == 2)
                    t[i][j] = 2;
                else if(s[i] == s[j]) {
                    t[i][j] = 2 + t[i+1][j-1];
                } else {
                    t[i][j] = max(t[i+1][j], t[i][j-1]);
                }
            }
        }
        return t[0][n-1];
    }
    
    int longestPalindromeSubseq(string s) {
        string s1 = s;
        
        reverse(s1.begin(), s1.end());
        int m = s.length();
        
        return LCS(s, s1, m, m); //Approach-1
        
        vector<vector<int>> t(m+1, vector<int>(m+1, -1));
        return LPS(s, 0, m-1, t); //Approach-2
        
        return LPS_Bottom_Up(s, m); //Approach-3
    }
};
