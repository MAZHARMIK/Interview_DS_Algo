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


//Approach-2 (Using Blueprint of Palindrome Strings to conver isPalindrome check to O(1))
//T.C : O(n^2)
//S.C : O(n^3)
class Solution {
public:
    vector<vector<bool>> isPalindrome;

    //max non-overlapping palindromic pieces (length >= k) from s[i..j]
    int solve(const string& s, int k, int i, int j, vector<vector<int>>& t) {
        int n = s.size();
        if (i >= n || j >= n) 
            return 0;
            
        if (t[i][j] != -1) 
            return t[i][j];

        if (isPalindrome[i][j]) { //O(1)
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

        isPalindrome.assign(n+1, vector<bool>(n+1));
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

        vector<vector<int>> t(n, vector<int>(n, -1));

        return solve(s, k, 0, k - 1, t);
    }
};


//Approach-3 (Bottom Up of Approach-1 Above)
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


//Approach-4 (Using Blueprint of Palindrome Strings to conver isPalindrome check to O(1))
//T.C : O(n^3)
//S.C : O(n^2)
class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        if (k == 1) 
            return n; //each character can be a substring

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

        vector<vector<int>> t(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= i; --j) {

                if (isPalindrome[i][j]) {
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


//Approach-5 (using different recursion style + Using BluePrint for solving palindromic DP problems as above for O(1) isPalindrome)
//T.C : O(n^2)
//S.C : O(n^2)
class Solution {
public:
    vector<vector<bool>> isPalindrome;
    vector<int> t;

    int solve(int n, int k) {
        if (n < k) return 0;

        if (t[n] != -1) 
            return t[n];

        int result = solve(n - 1, k); //ignore the current character s[n-1]

        int j = n - 1;
        //end the current palindrome at the current character s[n-1]
        for (int i = 0; j-i+1>=k; i++) {
            if (isPalindrome[i][j]) {
                result = max(result, 1 + solve(i, k));
            }
        }

        return t[n] = result;
    }

    int maxPalindromes(string s, int k) {
        int n = s.length();
        isPalindrome.assign(n, vector<bool>(n, false));

        for (int L = 1; L <= n; L++) {
            for (int i = 0; i + L <= n; i++) {
                int j = i + L - 1;

                if (i == j) {
                    isPalindrome[i][i] = true;
                } else if (i + 1 == j) {
                    isPalindrome[i][j] = (s[i] == s[j]);
                } else {
                    isPalindrome[i][j] = ((s[i] == s[j]) && isPalindrome[i+1][j-1] == true);
                }
            }
        }

        t.assign(n + 1, -1);
        return solve(n, k);
    }
};


//Approach-6 (Bottom-up version of Approach-5 above)
//T.C : O(n^2)
//S.C : O(n^2)
class Solution {
public:
    vector<vector<bool>> isPalindrome;
    vector<int> t;

    int maxPalindromes(string s, int k) {
        int n = s.length();
        isPalindrome.assign(n, vector<bool>(n, false));

        for (int L = 1; L <= n; L++) {
            for (int i = 0; i + L <= n; i++) {
                int j = i + L - 1;

                if (i == j) {
                    isPalindrome[i][i] = true;
                } else if (i + 1 == j) {
                    isPalindrome[i][j] = (s[i] == s[j]);
                } else {
                    isPalindrome[i][j] = ((s[i] == s[j]) && isPalindrome[i+1][j-1] == true);
                }
            }
        }

        t.assign(n + 1, -1);
        //base case
        for(int len = 0; len < k; len++) {
            t[len] = 0; // if (n < k) return 0;
        }

        for (int len = k; len <= n; len++) {

            int result = t[len - 1];      // int result = solve(n - 1, k);

            int j = len - 1;
            for (int i = 0; j-i+1 >= k; i++) {
                if (isPalindrome[i][j]) {
                    result = max(result, 1 + t[i]);   // result = max(result, 1 + solve(i, k));
                }
            }

            t[len] = result;              // return t[n] = result;
        }

        return t[n];                      // return solve(n, k);
    }
};
