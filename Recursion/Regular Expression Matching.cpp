/*         Scroll down to see JAVA code also           */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=3vbBrl-LeDc
    Company Tags                : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/regular-expression-matching/
    NOTE : A separate video will come in which we will solve this using DP (Botton Up). This is for Recursion playlist only
*/

/********************************************************************** C++ **********************************************************************/
//Approach-1 (Using Recursion - TLE for C++)
//T.C : In worst case, the function may recursively call itself twice for each character in the pattern (due to *), leading to an exponential number of recursive calls.
        //Hence, time complexity will be approaximately O(2^(max(n, m))). where n , m are lengths of s and p respectively.
//S.C : O(m) - Recursion stack space : where m = length of pattern (maximum depth of recursion tree)
        //NOTE : We are passing substr to isMatch every time and hence they are being copied to x and p so, we will be creating O(2^(max(n, m))) number of substrings.
class Solution {
public:
    
    bool isMatch(string text, string pattern) {
        if (pattern.length() == 0) {
            return text.length() == 0;
        }

        bool first_char_matched = false;
        if(text.length() > 0 && (pattern[0] == text[0] || pattern[0] == '.')) {
            first_char_matched = true;
        }
        
        //Best example to understand : s = "aaab", p = "a*b"
        if (pattern.length() >= 2 && pattern[1] == '*') {
            return (isMatch(text, pattern.substr(2)) ||
                    (first_char_matched && isMatch(text.substr(1), pattern)));
        } else {
            return first_char_matched && isMatch(text.substr(1), pattern.substr(1));
        }
    }
};


//Approach-2 (Recursion + Memoization)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    int t[21][21];

    bool solve(int i, int j, string& text, string& pattern) {
        if (j == pattern.length())
            return i == text.length();
            
        if (t[i][j] != -1) {
            return t[i][j];
        }
        
        bool ans = false;

        bool first_match = (i < text.length() &&
                            (pattern[j] == text[i] || pattern[j] == '.'));

        if (j + 1 < pattern.length() && pattern[j + 1] == '*') {
            ans = (solve(i, j + 2, text, pattern) ||
                   (first_match && solve(i + 1, j, text, pattern)));
        } else {
            ans = first_match && solve(i + 1, j + 1, text, pattern);
        }

        return t[i][j] = ans;
    }
    
    bool isMatch(string text, string pattern) {
        memset(t, -1, sizeof(t));
        return solve(0, 0, text, pattern);
    }
};



/********************************************************************** JAVA **********************************************************************/
//Approach-1 (Using Recursion)
//T.C : In worst case, the function may recursively call itself twice for each character in the pattern (due to *), leading to an exponential number of recursive calls.
        //Hence, time complexity will be approaximately O(2^(max(n, m))). where n , m are lengths of s and p respectively.
//S.C : O(m) - Recursion stack space : where m = length of pattern (maximum depth of recursion tree)
        //NOTE : We are passing substr to isMatch every time and hence they are being copied to x and p so, we will be creating O(2^(max(n, m))) number of substrings.
public class Solution {
    public boolean isMatch(String text, String pattern) {
        if (pattern.length() == 0) {
            return text.length() == 0;
        }

        boolean firstCharMatched = false;
        if (text.length() > 0 && (pattern.charAt(0) == text.charAt(0) || pattern.charAt(0) == '.')) {
            firstCharMatched = true;
        }

        // Best example to understand: s = "aaab", p = "a*b"
        if (pattern.length() >= 2 && pattern.charAt(1) == '*') {
            return (isMatch(text, pattern.substring(2)) ||
                    (firstCharMatched && isMatch(text.substring(1), pattern)));
        } else {
            return firstCharMatched && isMatch(text.substring(1), pattern.substring(1));
        }
    }
}


//Approach-2 (Recursion + Memoization)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
    int[][] t;

    public boolean solve(int i, int j, String text, String pattern) {
        if (j == pattern.length()) {
            return i == text.length();
        }

        if (t[i][j] != -1) {
            return t[i][j] == 1;
        }

        boolean ans = false;

        boolean first_match = (i < text.length() &&
                (pattern.charAt(j) == text.charAt(i) || pattern.charAt(j) == '.'));

        if (j + 1 < pattern.length() && pattern.charAt(j + 1) == '*') {
            ans = (solve(i, j + 2, text, pattern) ||
                    (first_match && solve(i + 1, j, text, pattern)));
        } else {
            ans = first_match && solve(i + 1, j + 1, text, pattern);
        }

        return (t[i][j] = ans ? 1 : 0) == 1;
    }

    public boolean isMatch(String text, String pattern) {
        t = new int[21][21];
        for (int[] row : t) {
            Arrays.fill(row, -1);
        }
        return solve(0, 0, text, pattern);
    }
}
