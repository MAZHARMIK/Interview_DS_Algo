/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=6rgO0obJG0k
      Company Tags                : Adobe, Microsoft, Uber
      Leetcode Link               : https://leetcode.com/problems/string-compression-ii/
*/

/************************************************************ C++ ************************************************************/
//Approach-1 (Using Recursion + Memoization)
//T.C : Without Memoization = O(2^n), With Memoization = O(n^2 * k) , we won't visit any char state more than once.
//S.C : O(1) constant space

int t[101][27][101][101]; //It is allocated in Heap
class Solution {
public:
    //int t[101][27][101][101]; //It will allocated in Stack and will give stack overflow
    int solve(string &s, int i, int prev, int freq, int k ){
        if(k < 0)
            return INT_MAX;
        
        if(i >= s.length())
            return 0;
        
        if(t[i][prev][freq][k] != -1) {
            return t[i][prev][freq][k];
        }
        
        int delete_i = solve(s, i+1, prev, freq, k-1);
        
        int keep_i   = 0;
        
        if(s[i] - 'a' == prev) {
             int one_more_added = 0;
             if(freq == 1 || freq == 9 || freq == 99) {
                 one_more_added = 1;
             }
            keep_i = one_more_added + solve(s, i+1, prev, freq+1, k);
        } else {
            keep_i = 1 + solve(s, i+1, s[i]-'a', 1, k);
        }
        
        return t[i][prev][freq][k] = min(delete_i, keep_i);
    }
    
    int getLengthOfOptimalCompression(string s, int k) {
        memset(t, -1, sizeof(t));
        return solve(s, 0, 26, 0, k);
    }
};



/************************************************************ JAVA ************************************************************/
//Approach-1 (Using Recursion + Memoization)
//T.C : Without Memoization = O(2^n), With Memoization = O(n^2 * k) , we won't visit any char state more than once.
//S.C : O(1) constant space
//NOTE - It will pass all test cases 144/144 but will take long time and hence will give TLE
class Solution {
    int[][][][] t;

    public int getLengthOfOptimalCompression(String s, int k) {
        int n = s.length();
        t = new int[n][27][101][101];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 27; j++) {
                for (int p = 0; p < 101; p++) {
                    Arrays.fill(t[i][j][p], -1);
                }
            }
        }

        return solve(s, 0, 26, 0, k);
    }

    private int solve(String s, int i, int prev, int freq, int k) {
        if (k < 0)
            return Integer.MAX_VALUE;

        if (i >= s.length())
            return 0;

        if (t[i][prev][freq][k] != -1) {
            return t[i][prev][freq][k];
        }

        int delete_i = solve(s, i + 1, prev, freq, k - 1);

        int keep_i = 0;

        if (s.charAt(i) - 'a' == prev) {
            int one_more_added = 0;
            if (freq == 1 || freq == 9 || freq == 99) {
                one_more_added = 1;
            }
            keep_i = one_more_added + solve(s, i + 1, prev, freq + 1, k);
        } else {
            keep_i = 1 + solve(s, i + 1, s.charAt(i) - 'a', 1, k);
        }

        return t[i][prev][freq][k] = Math.min(delete_i, keep_i);
    }
}
