/*
    Company Tags  : Google
    Leetcode Link : https://leetcode.com/problems/delete-operation-for-two-strings/
*/

//Approach-1 (Recursion + Memoization)
class Solution {
public:
    int t[501][501];
    int solve(string s1, string s2, int m, int n) {
        //if any of them gets empty, other string's all characters
		//will have to be deleted
        if(m == 0 || n == 0)
            return m+n;
        
        if(t[m][n] != -1)
            return t[m][n];
        //If equal character, then no deletion
        if(s1[m-1] == s2[n-1])
            return t[m][n] = solve(s1, s2, m-1, n-1);
        
		//check after deleting a character from s1
		//check after deleting a character from s2
		//find minimum steps taken from both 
        return t[m][n] = 1 + min(solve(s1, s2, m-1, n), solve(s1, s2, m, n-1));
    }
    
    int minDistance(string s1, string s2) {
        memset(t, -1, sizeof(t));
        
        int m = s1.length();
        int n = s2.length();
        
        return solve(s1, s2, m, n);
        
    }
};

//Approach-2 (Convert APproach-1 to DP)
class Solution {
public:
    int solve(string s1, string s2, int m, int n) {
        vector<vector<int>> t(m+1, vector<int>(n+1, 0));
        
        for(int row = 0; row<m+1; row++)
            t[row][0] = row;
        
        for(int col = 0; col<n+1; col++)
            t[0][col] = col;
        
        for(int i = 1; i<m+1; i++) {
            for(int j = 1; j<n+1; j++) {
                if(s1[i-1] == s2[j-1])
                    t[i][j] = t[i-1][j-1];
                else
                    t[i][j] = 1 + min(t[i-1][j], t[i][j-1]);
            }
        }
        
        return t[m][n];
    }
    
    int minDistance(string s1, string s2) {
        
        int m = s1.length();
        int n = s2.length();
        
        return solve(s1, s2, m, n);
        
    }
};

//Approach-3 (Using LCS)
class Solution {
public:
    int LCS(string s1, string s2, int m, int n) {
        vector<vector<int>> t(m+1, vector<int>(n+1, 0));
        
        for(int row = 0; row<m+1; row++)
            t[row][0] = 0;
        
        for(int col = 0; col<n+1; col++)
            t[0][col] = 0;
        
        for(int i = 1; i<m+1; i++) {
            for(int j = 1; j<n+1; j++) {
                if(s1[i-1] == s2[j-1])
                    t[i][j] = 1 + t[i-1][j-1];
                else
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
        
        return t[m][n];
    }
    int minDistance(string s1, string s2) {
        
        int m = s1.length();
        int n = s2.length();
        
        int lcs = LCS(s1, s2, m, n);
        
        int deletions_in_s1 = m-lcs;
        int deletions_in_s2 = n-lcs;
        
        return deletions_in_s1 + deletions_in_s2;
    }
};
