/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO LINK : 
    Company Tags          : Google, Twitter
    Frequency             : 71%
    Leetcode Link         : https://leetcode.com/problems/distinct-subsequences/
*/


/*********************************************************** C++ **************************************************/
//Approach-1 (Recursion + MEmoization)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:

    int dp[1001][1001];
    int solve(string& s, string& t, int m, int n) {
        if(n == 0)
            return dp[m][n] = 1;
        if(m == 0)
            return dp[m][n] = 0;
        
        if(dp[m][n] != -1)
            return dp[m][n];
        
        /*
            (rabb) b (it)
            (ra)   b (bbit)
            (rab)  b (bit)
            This can help to understand the if condition below
        */
        if(s[m-1] == t[n-1])
            return dp[m][n] = solve(s, t, m-1, n) + solve(s, t, m-1, n-1);
        else
            return dp[m][n] = solve(s, t, m-1, n);
    }

    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        if(m < n)
            return 0;
        memset(dp, -1, sizeof(dp));
        return solve(s, t, m, n);
    }
};


//Approach-2 (Bottom UP DP)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    typedef unsigned long long ull;
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        if(m < n)
            return 0;
        
        vector<vector<ull>> dp(m+1, vector<ull>(n+1));
        
        //There is one way to generate empty string from given s
        for(int row = 0; row<m+1; row++) {
            dp[row][0] = 1;
        }
        
        //There is zero way to generate non-empty string from given empty s
        for(int col = 1; col<n+1; col++) {
            dp[0][col] = 0;
        }
        
        for(int i = 1; i<m+1; i++) {
            for(int j = 1; j<n+1; j++) {
                if(s[i-1] == t[j-1])
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        
        return dp[m][n];
    }
};

//Approach-3 (Optimized Bottom UP DP)
/*
    If you notice, you are just requiring the previous row's value
    See the if condition    - dp[i-1][j-1] + dp[i-1][j]; //(i-1) points to previous row
    
    See the else condition  - dp[i-1][j]; //(i-1) points to previous row
    
    So, why not simply store previous value in a 1-D array
    We can then solve this qn, using O(m+n) space complexity
*/
//T.C : O(m*n)
//S.C : O(m + n)
class Solution {
public:
    typedef unsigned long long ull;
    
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        if(m < n)
            return 0;

        vector<ull> curr(m+1, 0); //Replace dp[i] with curr
        vector<ull> prev(n+1, 0); //Replace dp[i-1] with prev
        
        prev[0] = curr[0] = 1;
        
        for(int i = 1; i<m+1; i++) {
            
            for(int j = 1; j<n+1; j++) {
                
                if(s[i-1] == t[j-1])
                    curr[j] = prev[j-1] + prev[j];
                else
                    curr[j] = prev[j];
            }
            prev = curr;
        }

        return prev[n];
    }
};



/*********************************************************** JAVA **************************************************/
//Approach-1 (Recursion + MEmoization)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
    int[][] dp = new int[1001][1001];
    int solve(String s, String t, int m, int n) {
        if(n == 0)
            return dp[m][n] = 1;
        if(m == 0)
            return dp[m][n] = 0;
        
        if(dp[m][n] != -1)
            return dp[m][n];
        
        if(s.charAt(m-1) == t.charAt(n-1))
            return dp[m][n] = solve(s, t, m-1, n) + solve(s, t, m-1, n-1);
        else
            return dp[m][n] = solve(s, t, m-1, n);
    }
    public int numDistinct(String s, String t) {
        int m = s.length();
        int n = t.length();
        if(m < n)
            return 0;
        for(int[] row : dp)
            Arrays.fill(row, -1);
        return solve(s, t, m, n);
    }
}



//Approach-2 (Bottom UP DP)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
    public int numDistinct(String s, String t) {
        int m = s.length();
        int n = t.length();
        if(m < n)
            return 0;
        
        long[][] dp = new long[m+1][n+1];
        
        for(int row = 0; row<m+1; row++) {
            dp[row][0] = 1;
        }
        
        for(int col = 1; col<n+1; col++) {
            dp[0][col] = 0;
        }
        
        for(int i = 1; i<m+1; i++) {
            for(int j = 1; j<n+1; j++) {
                if(s.charAt(i-1) == t.charAt(j-1))
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        
        return (int) dp[m][n];
    }
}


//Approach-3 (Optimized Bottom UP DP)
/*
    If you notice, you are just requiring the previous row's value
    See the if condition    - dp[i-1][j-1] + dp[i-1][j]; //(i-1) points to previous row
    
    See the else condition  - dp[i-1][j]; //(i-1) points to previous row
    
    So, why not simply store previous value in a 1-D array
    We can then solve this qn, using O(m+n) space complexity
*/
//T.C : O(m*n)
//S.C : O(m + n)
class Solution {
    public int numDistinct(String s, String t) {
        int m = s.length();
        int n = t.length();
        if(m < n)
            return 0;
        long[] curr = new long[m+1];
        long[] prev = new long[n+1];
        
        prev[0] = curr[0] = 1;
        
        for(int i = 1; i<m+1; i++) {
            
            for(int j = 1; j<n+1; j++) {
                
                if(s.charAt(i-1) == t.charAt(j-1))
                    curr[j] = prev[j-1] + prev[j];
                else
                    curr[j] = prev[j];
            }
            prev = curr.clone();
        }
        return (int) prev[n];
    }
}
