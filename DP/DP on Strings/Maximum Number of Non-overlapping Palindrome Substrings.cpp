/*     Scroll below to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS QN : 
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings/
*/


/****************************************************************** C++ **********************************************************/
//Approach-1 (Simple Recursion Memoization)
//T.C : O(n^3)
//S.C : O(n^2)
class Solution {
public:
    bool isPalindrome(const string& s, int i, int j) {
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }

    //max non-overlapping palindromic pieces (length >= k) from s[i..j]
    int solve(const string& s, int k, int i, int j, vector<vector<int>>& t) {
        int n = s.size();
        if (i >= n || j >= n) 
            return 0;
            
        if (t[i][j] != -1) 
            return t[i][j];

        if (isPalindrome(s, i, j)) {
            int growWindow  = solve(s, k, i, j + 1, t);
            int takeIt      = 1 + solve(s, k, j + 1, j + k, t);
            int slideWindow = solve(s, k, i + 1, j + 1, t);

            return t[i][j] = max({growWindow, takeIt, slideWindow});
        }

        int slideWindow = solve(s, k, i + 1, j + 1, t);
        int growWindow  = solve(s, k, i, j + 1, t);

        return t[i][j] = max(slideWindow, growWindow);
    }

    int maxPalindromes(string s, int k) {
        int n = s.size();
        if (k == 1)
            return n; //each character can be a substring

        vector<vector<int>> t(n, vector<int>(n, -1));

        return solve(s, k, 0, k - 1, t);
    }
};


//Approach-2 (Bottom Up of Approach-1 Above)
//T.C : O(n^3)
//S.C : O(n^2)
class Solution {
public:
    bool isPalindrome(const string& s, int i, int j) {
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }

    int maxPalindromes(string s, int k) {
        int n = s.size();
        if (k == 1) 
            return n; //each character can be a substring

        vector<vector<int>> t(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= i; --j) {

                if (isPalindrome(s, i, j)) {
                    int growWindow  = t[i][j + 1];
                    int takeIt      = 1 + (j + k <= n ? t[j + 1][j + k] : 0);
                    int slideWindow = t[i + 1][j + 1];

                    t[i][j] = max({growWindow, takeIt, slideWindow});
                }
                
                int slideWindow = t[i + 1][j + 1];
                int growWindow  = t[i][j + 1];
                t[i][j] = max({t[i][j], slideWindow, growWindow});
            }
        }

        return t[0][k - 1];
    }
};


//Approach-3 (Using My favourite BluePrint for solving palindromic DP problems
//T.C : O(n^2)
//S.C : O(n^2)
class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.length();
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));

        //Palindromic substring Blueprint
        for(int L = 1; L <= n; L++) {
            for(int i = 0; i+L <= n; i++) {
                int j = i + L - 1;

                if(i == j) {
                    isPalindrome[i][i] = true; //Single characters are palindrome
                } else if(i+1 == j) {
                    isPalindrome[i][j] = (s[i] == s[j]); //Strings of 2 Length
                } else {
                    isPalindrome[i][j] = ((s[i] == s[j]) && isPalindrome[i+1][j-1] == true);
                }
            }
        }

        // best[prefixLen] = max non-overlapping valid palindromic substrings from s[0 .. prefixLen-1]
        vector<int> best(n + 1);

        for (int prefixLen = k; prefixLen <= n; ++prefixLen) {
            best[prefixLen] = best[prefixLen - 1];

            for (int startIdx = 0; startIdx + k <= prefixLen; startIdx++) {
                int endIdx = prefixLen - 1;

                if (isPalindrome[startIdx][endIdx]) {
                    best[prefixLen] = max(best[prefixLen], best[startIdx] + 1);
                }
            }
        }

        return best[n];
    }
};
