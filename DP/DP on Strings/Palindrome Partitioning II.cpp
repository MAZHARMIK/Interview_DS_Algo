/*   Scroll down to see JAVA code also  */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=XSe1_koFPzo
    Company Tags                : Amazon
    Leetcode Link               : https://leetcode.com/problems/palindrome-partitioning-ii/
*/


/********************************************* C++ ************************************************************/
//Approach-1 (Recursion + Memoization) - (TLE)
//T.C : O(n^3)
//S.C : O(n^2)
class Solution {
public:
    int t[2001][2001];
    bool isPalindrome(string& s, int i, int j) {
        while(i < j) {
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(string& s, int i, int j) {
        if(i >= j)
            return 0;
        if(t[i][j] != -1)
            return t[i][j];
        
        if(isPalindrome(s, i, j))
            return t[i][j] = 0;
        
        int part = INT_MAX;
        for(int k = i; k<=j-1; k++) {
            int temp = 1 + solve(s, i, k) + solve(s, k+1, j);
            
            part = min(part, temp);
        }
        
        return t[i][j] = part;
    }
    int minCut(string s) {
        int n = s.length();
        memset(t, -1, sizeof(t));
        return solve(s, 0, n-1);
    }
};


//Approach-2 (Bottom-Up) : Accepted
//T.C : O(n^2)
//S.C : O(n^2)
class Solution {
public:
    int solve(string s) {
        int n = s.length();
        vector<int> t(n);
        vector<vector<bool>> P(n, vector<bool>(n, false));
        //P[i][j] = True ; //means str(i,j) is a pallindrome else not
        //Length = 1 are always pallindrome
        for(int i = 0; i<n; i++) {
            P[i][i] = true;
        }
        
        //Length = 2+
        for(int L = 2; L<=n; L++) {
            for(int i = 0; i<n-L+1; i++) {
                int j = i+L-1;
                
                if(L == 2)
                    P[i][j] = (s[i] == s[j]);
                else {
                    P[i][j] = ((s[i] == s[j]) && P[i+1][j-1]);
                }
            }
        }

        //Best example to understand this - "abcb"
        for(int i = 0; i<n; i++) {
            if(P[0][i] == true)
                t[i] = 0;
            else {
                t[i] = INT_MAX;
                for(int k = 0; k<i; k++) {
                    if(P[k+1][i] == true && 1 + t[k] < t[i])
                        t[i] = 1 + t[k];
                }   
            }
        }
        return t[n-1];
    }
    
    int minCut(string s) {
        int n = s.length();
        if(n == 0 || n == 1)
            return 0;
        
        return solve(s);
    }
};



/********************************************* JAVA ************************************************************/
//Approach-1 (Recursion + Memoization) - (TLE)
//T.C : O(n^3)
//S.C : O(n^2)
class Solution {
    private int[][] dp;

    private boolean isPalindrome(String s, int i, int j) {
        while (i < j) {
            if (s.charAt(i) != s.charAt(j)) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    private int solve(String s, int i, int j) {
        if (i >= j) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        if (isPalindrome(s, i, j)) {
            return dp[i][j] = 0;
        }

        int minCuts = Integer.MAX_VALUE;
        for (int k = i; k <= j - 1; k++) {
            int temp = 1 + solve(s, i, k) + solve(s, k + 1, j);
            minCuts = Math.min(minCuts, temp);
        }

        return dp[i][j] = minCuts;
    }

    public int minCut(String s) {
        int n = s.length();
        dp = new int[n][n];

        // Initialize the dp array to -1
        for (int[] row : dp) {
            Arrays.fill(row, -1);
        }

        return solve(s, 0, n - 1);
    }
}


//Approach-2 (Bottom-Up) : Accepted
//T.C : O(n^2)
//S.C : O(n^2)
class Solution {
    public int solve(String s) {
        int n = s.length();
        int[] t = new int[n];
        boolean[][] P = new boolean[n][n];

        // Length = 1 substrings are always palindromes
        for (int i = 0; i < n; i++) {
            P[i][i] = true;
        }

        // Length = 2+ substrings
        for (int L = 2; L <= n; L++) {
            for (int i = 0; i < n - L + 1; i++) {
                int j = i + L - 1;

                if (L == 2) {
                    P[i][j] = (s.charAt(i) == s.charAt(j));
                } else {
                    P[i][j] = (s.charAt(i) == s.charAt(j)) && P[i + 1][j - 1];
                }
            }
        }

        // Compute minimum cuts using dynamic programming
        for (int i = 0; i < n; i++) {
            if (P[0][i]) {
                t[i] = 0;
            } else {
                t[i] = Integer.MAX_VALUE;
                for (int k = 0; k < i; k++) {
                    if (P[k + 1][i] && 1 + t[k] < t[i]) {
                        t[i] = 1 + t[k];
                    }
                }
            }
        }

        return t[n - 1];
    }

    public int minCut(String s) {
        int n = s.length();
        if (n == 0 || n == 1) {
            return 0;
        }

        return solve(s);
    }
}
