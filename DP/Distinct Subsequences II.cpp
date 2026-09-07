/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO LINK : 
    Company Tags          : Google
    Leetcode Link         : https://leetcode.com/problems/distinct-subsequences-ii
*/


/*********************************************************** C++ **************************************************/
//Approach-1 (Brute Force Naive Approach) - MLE
//T.C : O(2^n)
//S.C : O(2^n)
class Solution {
public:
    int n;
    unordered_set<string> st;
    int dp[2001];

    void solve(int i, string temp, string &s) {
        if(i == n){
            if(temp.size())
                st.insert(temp);
            return;
        }

        solve(i+1, temp+s[i], s);
        solve(i+1, temp, s);
    }

    int distinctSubseqII(string s) {
        n = s.size();
        solve(0, "", s);
        return st.size();
    }
};



//Approach-2 (Recursion Memo with duplicate handling)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int M = 1e9+7;
    int dp[2001];
    vector<int> prev; //prev[n] = last time when we saw this nth character (1-based indexing)

    int solve(int n) {
        if(n == 0)
            return 1;

        if(dp[n] != -1)
            return dp[n];
        
        int total = (2*solve(n-1)) % M;

        if(prev[n] != 0) {
            int duplicates = solve(prev[n] - 1);
            total = (total - duplicates + M) % M;
        }

        return dp[n] = total;
    }

    int distinctSubseqII(string s) {
        int n = s.length();

        memset(dp, -1, sizeof(dp));
        prev.assign(n+1, 0);

        vector<int> lastSeen(26, 0);
        for(int i = 1; i <= n; i++) {
            int idx = s[i-1] -'a';

            prev[i] = lastSeen[idx];
            lastSeen[idx] = i;
        }

        return (solve(n) - 1 + M) % M;

    }
};



//Approach-3 (Bottom Up with duplicate handling)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int M = 1e9+7;
    int dp[2001];
    vector<int> prev; //prev[n] = last time when we saw this nth character (1-based indexing)

    int distinctSubseqII(string s) {
        int n = s.length();

        memset(dp, -1, sizeof(dp));
        prev.assign(n+1, 0);

        vector<int> lastSeen(26, 0);
        for(int i = 1; i <= n; i++) {
            int idx = s[i-1] -'a';

            prev[i] = lastSeen[idx];
            lastSeen[idx] = i;
        }

        dp[0] = 1; //if(n == 0) return 1;

        for(int i = 1; i <= n; i++) {
            int total = (2 * dp[i-1]) % M;

            if(prev[i] != 0) {
                int duplicates = dp[prev[i] - 1];
                total = (total - duplicates + M) % M;
            }

            dp[i] = total;
        }

        return (dp[n] - 1 + M) % M;

    }
};



/*********************************************************** C++ **************************************************/
//Approach-1 (Brute Force Naive Approach) - MLE
//T.C : O(2^n)
//S.C : O(2^n)
class Solution {
    int n;
    Set<String> st = new HashSet<>();
    int[] dp = new int[2001];
    void solve(int i, String temp, String s) {
        if(i == n){
            if(temp.length() > 0)
                st.add(temp);
            return;
        }
        solve(i+1, temp+s.charAt(i), s);
        solve(i+1, temp, s);
    }
    public int distinctSubseqII(String s) {
        n = s.length();
        solve(0, "", s);
        return st.size();
    }
}


//Approach-2 (Recursion Memo with duplicate handling)
//T.C : O(n)
//S.C : O(n)
class Solution {
    int M = 1000000007;
    int[] dp = new int[2001];
    int[] prev; //prev[n] = last time when we saw this nth character (1-based indexing)
    int solve(int n) {
        if(n == 0)
            return 1;
        if(dp[n] != -1)
            return dp[n];
        
        int total = (int)(2L * solve(n-1) % M);
        if(prev[n] != 0) {
            int duplicates = solve(prev[n] - 1);
            total = (total - duplicates + M) % M;
        }
        return dp[n] = total;
    }
    public int distinctSubseqII(String s) {
        int n = s.length();
        Arrays.fill(dp, -1);
        prev = new int[n+1];
        int[] lastSeen = new int[26];
        for(int i = 1; i <= n; i++) {
            int idx = s.charAt(i-1) - 'a';
            prev[i] = lastSeen[idx];
            lastSeen[idx] = i;
        }
        return (solve(n) - 1 + M) % M;
    }
}


//Approach-3 (Bottom Up with duplicate handling)
//T.C : O(n)
//S.C : O(n)
class Solution {
    int M = 1000000007;
    int[] dp = new int[2001];
    int[] prev; //prev[n] = last time when we saw this nth character (1-based indexing)
    public int distinctSubseqII(String s) {
        int n = s.length();
        Arrays.fill(dp, -1);
        prev = new int[n+1];
        int[] lastSeen = new int[26];
        for(int i = 1; i <= n; i++) {
            int idx = s.charAt(i-1) - 'a';
            prev[i] = lastSeen[idx];
            lastSeen[idx] = i;
        }
        dp[0] = 1; //if(n == 0) return 1;
        for(int i = 1; i <= n; i++) {
            int total = (int)(2L * dp[i-1] % M);
            if(prev[i] != 0) {
                int duplicates = dp[prev[i] - 1];
                total = (total - duplicates + M) % M;
            }
            dp[i] = total;
        }
        return (dp[n] - 1 + M) % M;
    }
}
