/*         Scroll down to see JAVA code also           */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/regular-expression-matching/
    NOTE : A separate video will come in which we will solve this using DP. This is for Recursion playlist only
*/

/********************************************************************** C++ **********************************************************************/
//Using Recursion
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



/********************************************************************** JAVA **********************************************************************/
//Using Recursion
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
