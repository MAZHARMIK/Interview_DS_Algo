/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : Recur+Memo - https://www.youtube.com/watch?v=w0mB7tEv17k 
                                : Bottom Up  - https://www.youtube.com/watch?v=EtbCd9iETno
    Company Tags                : Google, Amazon
    Leetcode Link               : https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/
*/


/**************************************************************** C++ ****************************************************************/
//Approach-1 (Recur + Memo)
//T.C : O(n*k + m*k)
//S.C : O(m*k)
class Solution {
public:
    int m;
    int k;
    const int MOD = 1e9+7;
    int t[1001][1001];
    
    int solve(int i, int j, vector<vector<long long>>& freq, string &target) {
        if(i == m)
            return 1;
        
        if(j == k)
            return 0;
        
        if(t[i][j] != -1)
            return t[i][j];
        
        int not_taken = solve(i, j+1, freq, target)%MOD;
        
        int taken     = (freq[target[i] - 'a'][j] * solve(i+1, j+1, freq, target))%MOD;
        
        
        return t[i][j] = (not_taken + taken)%MOD;
    }
    
    int numWays(vector<string>& words, string target) {
        
        k = words[0].size();
        m = target.length();
        
        vector<vector<long long>> freq(26, vector<long long>(k));
        
        for(int col = 0; col < k; col++) {
            
            for(string &word : words) {
                
                freq[word[col] - 'a'][col]++;
                
            }
            
        }
        memset(t, -1, sizeof(t));
        return solve(0, 0, freq, target);
    }
};


//Approach-2 (Bottom Up DP)
//T.C : O(n*k + m*k)
//S.C : O(m*k)
class Solution {
public:
    const int MOD = 1e9+7;
    int numWays(vector<string>& words, string target) {
        
        int k = words[0].size();
        int m = target.length();
        
        vector<vector<long long>> freq(26, vector<long long>(k));
        
        for(int col = 0; col < k; col++) {
            
            for(string &word : words) {
                
                freq[word[col] - 'a'][col]++;
                
            }
            
        }
        
        vector<vector<long long>> dp(m+1, vector<long long>(k+1));
        //t[i][j] = total ways of forming target of length i using j leftmost columns
        
        dp[0][0] = 1;
        
        for(int i = 0; i <= m; i++) { //target of length i
            for(int j = 0; j <= k; j++) { //using j left most columns
                
                //Not taken
                if(j < k)
                    dp[i][j+1]  = (dp[i][j+1] + dp[i][j])%MOD;
                
                //Taken
                if(i < m && j < k)
                    dp[i+1][j+1] = (dp[i+1][j+1] + freq[target[i] - 'a'][j] * dp[i][j])%MOD;
                
                
            }
        }
        
        return dp[m][k];
    }
};



/**************************************************************** JAVA ****************************************************************/
//Approach-1 (Recur + Memo)
//T.C : O(n*k + m*k)
//S.C : O(m*k)
class Solution {
    public int numWays(String[] words, String target) {
        int MOD = 1_000_000_007;
        int k = words[0].length();
        int m = target.length();

        // Precompute frequency of each character in each column
        long[][] freq = new long[26][k];
        for (String word : words) {
            for (int col = 0; col < k; col++) {
                freq[word.charAt(col) - 'a'][col]++;
            }
        }

        // DP array: dp[i][j] = ways to form first i chars of target using first j columns
        long[][] dp = new long[m + 1][k + 1];
        dp[0][0] = 1; // Base case: 1 way to form empty target

        for (int i = 0; i <= m; i++) { // target length
            for (int j = 0; j <= k; j++) { // columns
                // Not taken
                if (j < k) {
                    dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % MOD;
                }
                // Taken
                if (i < m && j < k) {
                    dp[i + 1][j + 1] = (dp[i + 1][j + 1] + freq[target.charAt(i) - 'a'][j] * dp[i][j]) % MOD;
                }
            }
        }

        return (int) dp[m][k];
    }
}


//Approach-2 (Bottom Up)
//T.C : O(n*k + m*k)
//S.C : O(m*k)
class Solution {
    public int numWays(String[] words, String target) {
        int MOD = 1_000_000_007;
        int k = words[0].length();
        int m = target.length();

        // Precompute frequency of each character in each column
        long[][] freq = new long[26][k];
        for (String word : words) {
            for (int col = 0; col < k; col++) {
                freq[word.charAt(col) - 'a'][col]++;
            }
        }

        // DP array: dp[i][j] = ways to form first i chars of target using first j columns
        long[][] dp = new long[m + 1][k + 1];
        dp[0][0] = 1; // Base case: 1 way to form empty target

        for (int i = 0; i <= m; i++) { // Target length
            for (int j = 0; j <= k; j++) { // Columns
                // Not taken
                if (j < k) {
                    dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % MOD;
                }
                // Taken
                if (i < m && j < k) {
                    dp[i + 1][j + 1] = (dp[i + 1][j + 1] + freq[target.charAt(i) - 'a'][j] * dp[i][j]) % MOD;
                }
            }
        }

        return (int) dp[m][k];
    }
}
