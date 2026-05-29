/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=P_mC0wOTNV4
    Company Tags                : Google
    Leetcode Link               : https://leetcode.com/problems/ones-and-zeroes
*/


/**************************************************************** C++ ****************************************************************/
//Approach-1 (Recursion and Memoization)
// T.C : O(L * m * n)
//       where L = number of strings, m = max number of 0's allowed, n = max number of 1's allowed
//       For each index (L), we compute at most m*n states once due to memoization.
// S.C : O(L * m * n) for the DP cache + O(L) recursion stack
class Solution {
public:
    int t[101][101][601];
    int solve(vector<pair<int, int>>& count, int m, int n, int index) {
        if(index >= count.size() || (m == 0 && n == 0))
            return 0;
        if(t[m][n][index] != -1)
            return t[m][n][index];
        
        int include = 0;
        if(count[index].first <= m && count[index].second <= n) {
            include = 1 + solve(count, m-count[index].first, n-count[index].second, index+1);
        }
        
        int exclude = solve(count, m, n, index+1);
        
        return t[m][n][index] = max(include, exclude);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int N = strs.size();
        vector<pair<int, int>> count(N);
        int i = 0;\
        for(string str:strs) {
            int countOnes  = 0;
            int countZeros = 0;
            
            for(char ch:str) {
                if(ch == '1')
                    countOnes++;
                else
                    countZeros++;
            }
            
            count[i++] = {countZeros, countOnes};
        }
        
        memset(t, -1, sizeof(t));
        return solve(count, m, n, 0);
    }
};



//Approach-2 (DP-Bottom Up) - I will cover all of these in DP Concepts Playlist Knapsack Series 🙏
// T.C : O(L * m * n)
//       For each string, we iterate over m * n states once.
// S.C : O(m * n)
//       We only use a 2D DP array, no recursion or 3D storage.
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> t(m+1, vector<int>(n+1, 0));
        for(string str:strs) {
            int countOnes  = 0;
            int countZeros = 0;
            
            for(char ch:str) {
                if(ch == '1')
                    countOnes++;
                else
                    countZeros++;
            }
            
            for(int zero = m; zero >= countZeros; zero--) {
                for(int one = n; one >= countOnes; one--) {
                    t[zero][one] = max(t[zero][one], t[zero-countZeros][one-countOnes] + 1); //(exclude(previous value), include)
                }
            }
            
        }
        
        return t[m][n];
    }
};



/**************************************************************** JAVA ****************************************************************/
// Approach-1 (Recursion and Memoization)
// T.C : O(L * m * n)
//       where L = number of strings, m = max number of 0's allowed, n = max number of 1's allowed
//       For each index (L), we compute at most m*n states once due to memoization.
// S.C : O(L * m * n) for the DP cache + O(L) recursion stack
class Solution {
    private int[][][] dp;

    private int solve(int[][] count, int m, int n, int index) {
        if (index >= count.length || (m == 0 && n == 0))
            return 0;

        if (dp[m][n][index] != -1)
            return dp[m][n][index];

        int include = 0;
        if (count[index][0] <= m && count[index][1] <= n) {
            include = 1 + solve(count, m - count[index][0], n - count[index][1], index + 1);
        }

        int exclude = solve(count, m, n, index + 1);

        return dp[m][n][index] = Math.max(include, exclude);
    }

    public int findMaxForm(String[] strs, int m, int n) {
        int L = strs.length;
        int[][] count = new int[L][2]; // count[i][0] = zeros, count[i][1] = ones

        for (int i = 0; i < L; i++) {
            int zeros = 0, ones = 0;
            for (char ch : strs[i].toCharArray()) {
                if (ch == '0')
                    zeros++;
                else
                    ones++;
            }
            count[i][0] = zeros;
            count[i][1] = ones;
        }

        dp = new int[m + 1][n + 1][L];
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                Arrays.fill(dp[i][j], -1);
            }
        }

        return solve(count, m, n, 0);
    }
}


// Approach-2 (DP-Bottom Up)
// T.C : O(L * m * n)
//       For each string, we iterate over m * n states once.
// S.C : O(m * n)
//       We only use a 2D DP array, no recursion or 3D storage.
class Solution {
    public int findMaxForm(String[] strs, int m, int n) {
        int[][] dp = new int[m + 1][n + 1];

        for (String str : strs) {
            int zeros = 0, ones = 0;
            for (char ch : str.toCharArray()) {
                if (ch == '0')
                    zeros++;
                else
                    ones++;
            }

            // Traverse backward to avoid overwriting states we still need
            for (int zero = m; zero >= zeros; zero--) {
                for (int one = n; one >= ones; one--) {
                    dp[zero][one] = Math.max(dp[zero][one], dp[zero - zeros][one - ones] + 1);
                }
            }
        }

        return dp[m][n];
    }
}
