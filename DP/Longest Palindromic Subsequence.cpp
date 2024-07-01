/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : Recursion + Memo and Normal Bottom Up    = https://www.youtube.com/watch?v=M4pfB3G-YQc
                                  Using my favourite Blue Print Bottom Up  = https://www.youtube.com/watch?v=WIhQ5NOzCKM

    Company Tags                : Amazon, LinkedIn, Paypal, Rivigo, Uber, Google
    Leetcode Link               : https://leetcode.com/problems/longest-palindromic-subsequence/
    GfG Link                    : https://practice.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/1
*/


/******************************************************** C++ ********************************************************/
//Approach-1 (Recursion + Memoization)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    int t[1001][1001];
    int LPS(string& s, int i, int j) {
        if(i > j)
            return 0;
        if(i == j)
            return 1;
        
        if(t[i][j] != -1)
            return t[i][j];
        if(s[i] == s[j])
            return t[i][j] = 2 + LPS(s, i+1, j-1);
        else
            return t[i][j] = max(LPS(s, i+1, j), LPS(s, i, j-1));
    }
    
    int longestPalindromeSubseq(string s) {
        int m = s.length();
        memset(t, -1, sizeof(t));
        
        return LPS(s, 0, m-1); //Approach-1
        
    }
};


//Approach-2 (Bottom Up - My Favourite Blue Print of Pallindrome Qns)
//T.C : O(n*n)
//S.C : O(n*n)
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();

        vector<vector<int>> t(n, vector<int>(n));
        //t[i][j] = LPS in s[i...j]

        for(int i = 0; i < n; i++) {
            t[i][i] = 1; // 1 length is always a palindrome
        }

        for(int L = 2; L<=n; L++) {
            for(int i = 0; i < n-L+1; i++) {
                int j = i + L - 1;

                if(s[i] == s[j]) {
                    t[i][j] = 2 + t[i+1][j-1];
                } else {
                    t[i][j] = max(t[i][j-1], t[i+1][j]);
                }
            }
        }

        return t[0][n-1]; //LPS of whole string s[0..n-1]

    }
};


//Approach-3 (Using LCS Concept)
//T.C : O(m*n)
//S.C : O(m*n)
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
    
    int longestPalindromeSubseq(string s) {
        string s1 = s;
        
        reverse(s1.begin(), s1.end());
        int m = s.length();
        
        return LCS(s, s1, m, m); //Approach-1
        
    }
};



/******************************************************** JAVA ********************************************************/
//Approach-1 (Recursion + Memoization)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
    int[][] t = new int[1001][1001];

    public int LPS(String s, int i, int j) {
        if (i > j)
            return 0;
        if (i == j)
            return 1;

        if (t[i][j] != -1)
            return t[i][j];
        if (s.charAt(i) == s.charAt(j))
            return t[i][j] = 2 + LPS(s, i + 1, j - 1);
        else
            return t[i][j] = Math.max(LPS(s, i + 1, j), LPS(s, i, j - 1));
    }

    public int longestPalindromeSubseq(String s) {
        int m = s.length();
        for (int[] row : t) {
            Arrays.fill(row, -1);
        }
        return LPS(s, 0, m - 1); // Approach-1
    }
}


//Approach-2 (Bottom Up)
//T.C : O(n*n)
//S.C : O(n*n)
class Solution {
    public int longestPalindromeSubseq(String s) {
        int n = s.length();

        int[][] t = new int[n][n];
        // t[i][j] = longest common subsequence in string from i to j indices;
        // strings of length 1 are always a palindrome
        for (int i = 0; i < n; i++) {
            t[i][i] = 1;
        }

        for (int L = 2; L <= n; L++) {
            for (int i = 0; i < n - L + 1; i++) {
                int j = i + L - 1;

                if (s.charAt(i) == s.charAt(j) && L == 2)
                    t[i][j] = 2;
                else if (s.charAt(i) == s.charAt(j)) {
                    t[i][j] = 2 + t[i + 1][j - 1];
                } else {
                    t[i][j] = Math.max(t[i + 1][j], t[i][j - 1]);
                }
            }
        }
        return t[0][n - 1];
    }
}


//Approach-3 (Using LCS Concept)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
    // Approach-1 (Using Concept of LCS)
    public int LCS(String s1, String s2, int m, int n) {
        int[][] t = new int[m + 1][n + 1];

        for (int row = 0; row < m + 1; row++) {
            t[row][0] = 0;
        }

        for (int col = 0; col < n + 1; col++) {
            t[0][col] = 0;
        }

        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                if (s1.charAt(i - 1) == s2.charAt(j - 1)) {
                    t[i][j] = 1 + t[i - 1][j - 1];
                } else {
                    t[i][j] = Math.max(t[i][j - 1], t[i - 1][j]);
                }
            }
        }

        return t[m][n];
    }

    public int longestPalindromeSubseq(String s) {
        String s1 = new StringBuilder(s).reverse().toString();
        int m = s.length();

        return LCS(s, s1, m, m); // Approach-1
    }
}
