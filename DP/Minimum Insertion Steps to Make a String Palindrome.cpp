/*         Scroll below to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : Recur + Memo - https://www.youtube.com/watch?v=99S-xuAbwoc
                                  Bottom Up - https://www.youtube.com/watch?v=jEDPdAwnxV0
    Company Tags                : Google, Amazon, Microsoft, Airtel
    Leetcode Link               : https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
*/


/************************************************************ C++ ************************************************************/
//Approach-1 (Recur + Memo - Using Straight Forward Pallindromic Property)
//T.C : O(n*n)
//S.C : O(n*n)
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


//Approach-2 (Bottom Up - Using my favourite Palindrome Blue Print)
//T.C : O(n*n)
//S.C : O(n*n)
class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        //State : dp[i][j] = min insertion to make s[i..j] a palindrome
        
        for (int L = 2; L <= n; L++) {
            for (int i = 0; i < n - L + 1; i++) {
                int j = i + L - 1;
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1];
                } else {
                    dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return dp[0][n - 1];
    }
};

//Approach-3 (Using LCS)
//T.C : O(n*n)
//S.C : O(n*n)
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





/************************************************************ JAVA ************************************************************/
//Approach-1 (Recur + Memo - Using Straight Forward Pallindromic Property)
//T.C : O(n*n)
//S.C : O(n*n)
class Solution {
    private int[][] t;

    private int solve(int i, int j, String s) {
        if (i >= j)
            return 0;

        if (t[i][j] != -1)
            return t[i][j];

        if (s.charAt(i) == s.charAt(j))
            return t[i][j] = solve(i + 1, j - 1, s);

        return t[i][j] = 1 + Math.min(solve(i, j - 1, s), solve(i + 1, j, s));
    }

    public int minInsertions(String s) {
        int n = s.length();
        t = new int[n][n];

        for (int[] row : t)
            Arrays.fill(row, -1);

        return solve(0, n - 1, s);
    }
}




//Approach-2 (Bottom Up - Using my favourite Palindrome Blue Print)
//T.C : O(n*n)
//S.C : O(n*n)
class Solution {
    public int minInsertions(String s) {
        int n = s.length();
        int[][] dp = new int[n][n];
        // State: dp[i][j] = min insertion to make s[i..j] a palindrome
        
        for (int L = 2; L <= n; L++) {
            for (int i = 0; i < n - L + 1; i++) {
                int j = i + L - 1;
                if (s.charAt(i) == s.charAt(j)) {
                    dp[i][j] = dp[i + 1][j - 1];
                } else {
                    dp[i][j] = 1 + Math.min(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return dp[0][n - 1];
    }
}




//Approach-3 (Using LCS)
//T.C : O(n*n)
//S.C : O(n*n)
class Solution {
    private int[][] t;

    private int LCS(String s1, String s2, int m, int n) {
        if (m == 0 || n == 0) {
            return t[m][n] = 0;
        }

        if (t[m][n] != -1) {
            return t[m][n];
        }

        if (s1.charAt(m - 1) == s2.charAt(n - 1)) {
            return t[m][n] = 1 + LCS(s1, s2, m - 1, n - 1);
        }

        return t[m][n] = Math.max(LCS(s1, s2, m, n - 1), LCS(s1, s2, m - 1, n));
    }

    public int minInsertions(String s) {
        int m = s.length();
        t = new int[m + 1][m + 1];
        for (int[] row : t) {
            Arrays.fill(row, -1);
        }

        String temp = new StringBuilder(s).reverse().toString();
        int lcs_length = LCS(s, temp, m, m);

        return m - lcs_length;
    }
}
