/*
    MY YOUTUBE VIDEO ON THIS Qn : Recur + Memo - https://www.youtube.com/watch?v=99S-xuAbwoc
                                  Bottom Up - <soon>
    Company Tags                : Google, Amazon, Microsoft, Airtel
    Leetcode Link               : https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
*/

//Approach-1 (Recur + Memo - Using Straight Forward Pallindromic Property)
class Solution {
public:
    int t[501][501];
    int solve(int i, int j, string &s) {
 
        if(i >= j)
            return 0;
        
        if(t[i][j] != -1)
            return t[i][j];
        
        if(s[i] == s[j])
            return t[i][j] = solve(i+1, j-1, s);
        
        return t[i][j] = 1 + min(solve(i, j-1, s), solve(i+1, j, s));
        
    }
    
    int minInsertions(string s) {
        int n = s.length();
        
        memset(t, -1, sizeof(t));
        
        return solve(0, n-1, s);
    }
};


//Approach-2 (Bottom Up - coming soon)

//Approach-3 (Using LCS) - Video Coming Soon
class Solution {
public:
    int t[501][501];
    
    int LCS(string& s1, string& s2, int m, int n) {
        if(m == 0 || n == 0)
            return t[m][n] = 0;
        
        if(t[m][n] != -1)
            return t[m][n];
        
        if(s1[m-1] == s2[n-1])
            return t[m][n] = 1 + LCS(s1, s2, m-1, n-1);
        
        return t[m][n] = max(LCS(s1, s2, m, n-1), LCS(s1, s2, m-1, n));
    }
    
    int minInsertions(string s) {
        int m = s.length();
        
        memset(t, -1, sizeof(t));
        string temp = s;
        reverse(begin(temp), end(temp));
        
        int lcs_length = LCS(s, temp, m, m);
        
        return m - lcs_length;
    }
};
