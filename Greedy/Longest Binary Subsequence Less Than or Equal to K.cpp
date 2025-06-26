/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=ca04hcfuGlY
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/longest-binary-subsequence-less-than-or-equal-to-k
*/


/************************************************************ C++ ************************************************/
//Approach-1 (Using Recursion)
//T.C : O(2^n), take and skip
//S.C : O(1) auxiliary space, and O(n) of recursion stack
class Solution {
public:
    int n;

    int solve(const string &s, int k, int i) {
        if (i < 0) 
            return 0;

        int take = 0;
        int bit  = s[i] - '0';
        long long value = (bit == 1 ? (1LL << (n - i - 1)) : 0);

        if (value <= k) {
            take = 1 + solve(s, k - value, i - 1);
        }

        int skip = solve(s, k, i - 1);
        return max(take, skip);
    }

    int longestSubsequence(string &s, int k) {
        n = s.length();
        return solve(s, k, n-1);
    }
};


//Approach-2 (Using Greedy)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int longestSubsequence(string s, int k) {
        int length = 0;
        long long powerValue = 1;
        
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == '0') {
                length++;
            } else if(powerValue <= k) {
                length++;
                k -= powerValue;
            }

            if (powerValue <= k)
                powerValue <<= 1; //powerValue *= 2;
        }
        
        return length;
    }
};



/************************************************************ JAVA **************************************************/
//Approach-1 (Using Recursion)
//T.C : O(2^n), take and skip
//S.C : O(1) auxiliary space, and O(n) of recursion stack
class Solution {
    int n;

    private int solve(String s, int k, int i) {
        if (i < 0)
            return 0;

        int take = 0;
        int bit = s.charAt(i) - '0';
        long value = (bit == 1 ? (1L << (n - i - 1)) : 0);

        if (value <= k) {
            take = 1 + solve(s, (int)(k - value), i - 1);
        }

        int skip = solve(s, k, i - 1);
        return Math.max(take, skip);
    }

    public int longestSubsequence(String s, int k) {
        n = s.length();
        return solve(s, k, n - 1);
    }
}

//Approach-2 (Using Greedy)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int longestSubsequence(String s, int k) {
        int length = 0;
        long powerValue = 1;

        for (int i = s.length() - 1; i >= 0; --i) {
            if (s.charAt(i) == '0') {
                length++;
            } else if (powerValue <= k) {
                length++;
                k -= powerValue;
            }

            if (powerValue <= k) {
                powerValue <<= 1; // powerValue *= 2
            }
        }

        return length;
    }
}
