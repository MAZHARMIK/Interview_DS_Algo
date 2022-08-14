/*
    Company Tags     : Amazon, Goldman Sachs, Microsoft, Google
    Leetcode Qn Link : https://leetcode.com/problems/edit-distance/
*/


//Approach-1 (Using Top Down (Recursive + Memo))
class Solution {
public:
    int t[501][501];
    int solve(string& s1, string& s2, int m, int n) {
        if(m == 0 || n == 0)
            return m+n;
        
        if(t[m][n] != -1)
            return t[m][n];
        
        if(s1[m-1] == s2[n-1])
            return t[m][n] = solve(s1, s2, m-1, n-1);
        else {
            int insertC  = 1 + solve(s1, s2, m, n-1);
            int deleteC  = 1 + solve(s1, s2, m-1, n);
            int replaceC = 1 + solve(s1, s2, m-1, n-1);
            
            return t[m][n] = min({insertC, deleteC, replaceC});
        }
        
    }
    
    int minDistance(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        memset(t, -1, sizeof(t));
        return solve(s1, s2, m, n);
    }
};


//Approach-2 (Using Bottom Up)
class Solution {
public:
    int editDistance(string s1, string s2, int m, int n) {
        vector<vector<int>> t(m+1, vector<int>(n+1));
        
        for(int i = 0; i<m+1; i++) {
            for(int j = 0; j<n+1; j++) {
                if(i == 0 || j == 0)
                    t[i][j] = i+j;
                else if(s1[i-1] == s2[j-1])
                    t[i][j] = t[i-1][j-1];
                else
                    t[i][j] = 1 + min({t[i][j-1], t[i-1][j], t[i-1][j-1]});
            }
        }
        return t[m][n];
    }
    int minDistance(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        
        return editDistance(s1, s2, m, n);
    }
};
