/*
      MY YOUTUBE VIDEO ON THIS Qn : 4-D Memoization - https://www.youtube.com/watch?v=6rgO0obJG0k
                                    2-D Memoization - https://www.youtube.com/watch?v=Br3MiKmZRnc
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


//Approach-2 (Using 2D Memoization)
//T.C : O(n*k) we will visit at max n*k states after memoization
//S.C : O(n*k)
class Solution {
public:
    int n;
    vector<vector<int>> t;
    int solve(int i, int k, string &s) {
        if(k < 0) {
            return 100000;
        }

        if(i >= n || (n-i) <= k) {
            return 0;
        }

        if(t[i][k] != -1) {
            return t[i][k];
        }

        int delete_i = solve(i+1, k-1, s);

        int keep_i = INT_MAX;
        
        int deleted  = 0;
        int freq     = 0;
        int addition = 0;

        for(int j = i; j < n && deleted <= k; j++) {
            if(s[j] == s[i]) {
                freq++;
                if(freq == 2 || freq == 10 || freq == 100) {
                    addition++;
                }
            } else {
                deleted++;
            }

            keep_i = min(keep_i, 1 + addition + solve(j+1, k-deleted, s));
        }

        return t[i][k] = min(delete_i, keep_i);
    }
    int getLengthOfOptimalCompression(string s, int k) {
        n = s.length();
        t = vector<vector<int>>(n + 1, vector<int>(k + 1, -1));
        return solve(0, k, s);
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


//Approach-2 (Using 2D Memoization) - ACCEPTED
//T.C : O(n*k) we will visit at max n*k states after memoization
//S.C : O(n*k)
class Solution {
    private int n;
    private int[][] t;

    public int solve(int i, int k, String s) {
        if (k < 0) {
            return 100000;
        }

        if (i >= n || (n - i) <= k) {
            return 0;
        }

        if (t[i][k] != -1) {
            return t[i][k];
        }

        int delete_i = solve(i + 1, k - 1, s);

        int keep_i = Integer.MAX_VALUE;

        int deleted = 0;
        int freq = 0;
        int addition = 0;

        for (int j = i; j < n && deleted <= k; j++) {
            if (s.charAt(j) == s.charAt(i)) {
                freq++;
                if (freq == 2 || freq == 10 || freq == 100) {
                    addition++;
                }
            } else {
                deleted++;
            }

            keep_i = Math.min(keep_i, 1 + addition + solve(j + 1, k - deleted, s));
        }

        return t[i][k] = Math.min(delete_i, keep_i);
    }

    public int getLengthOfOptimalCompression(String s, int k) {
        n = s.length();
        t = new int[n + 1][k + 1];
        for (int[] row : t) {
            Arrays.fill(row, -1);
        }
        return solve(0, k, s);
    }
}
