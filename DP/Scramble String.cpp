/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Fx96uB9EIDQ
    Company Tags                : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/scramble-string/
*/


//Appoach-1 (Recursion + Memo)
class Solution {
public:
    unordered_map<string, bool> mp;
    bool solve(string s1, string s2) {

        if(s1 == s2) //both string empty covered here too
            return true;
        if(s1.length() != s2.length())
            return false;

        string key = s1 + "_" + s2;
        if(mp.find(key) != mp.end())
            return mp[key];

        bool result = false;
        int n = s1.length();
        for(int i = 1; i<n; i++) {
            /*
            Example : "great"  "eatgr"
            if swapped at i = 2
            we compare s1.substr(0, i) i.e "gr"  with s2.substr(n-i, i) i.e. "gr"
            && s1.substr(i, n-i) i.e "eat"  with s2.substr(0, n-i) i.e. "eat"
            */

            bool swapped = solve(s1.substr(0, i), s2.substr(n-i, i)) &&
                           solve(s1.substr(i, n-i), s2.substr(0, n-i));
            if(swapped) { //if we find they are scrambled, we don't need to check further
                result = true;
                break;
            }
            /*
            Example : "great"  "great"
            if not swapped at i = 2
            we compare s1.substr(0, i) i.e "gr"  with s2.substr(0, i) i.e. "gr"
            && s1.substr(i, n-i) i.e "eat"  with s2.substr(i, n-i) i.e. "eat"
            */

            bool not_swapped = solve(s1.substr(0, i), s2.substr(0, i)) &&
                               solve(s1.substr(i, n-i), s2.substr(i, n-i));
            if(not_swapped) { //if we find they are scrambled, we don't need to check further
                result = true;
                break;
            }

        }

        return mp[key] = result;
    }
    bool isScramble(string &s1, string &s2) {
        mp.clear();
        return solve(s1, s2);
    }
};

// Appoach-2 (Bottom-Up Dynamic Programming)

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        if (n != s2.size()) return false;
        if (s1 == s2) return true;
        // dp[k][i][j] means whether s1.substr(i, k) is a scramble of s2.substr(j, k)
        vector<vector<vector<bool>>> dp(n + 1, vector<vector<bool>>(n, vector<bool>(n, false)));
        // Initialize the dp array for k = 1
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[1][i][j] = (s1[i] == s2[j]);
            }
        }
        // Iterate over the lengths of the substrings
        for (int k = 2; k <= n; ++k) {
            // Iterate over possible starting indices of substrings in s1
            for (int i = 0; i <= n - k; ++i) {
                // Iterate over possible starting indices of substrings in s2
                for (int j = 0; j <= n - k; ++j) {
                    // Check if substrings of length k starting at i and j are scrambled
                    for (int m = 1; m < k; ++m) {
                        // Case 1: Without swapping
                        if (dp[m][i][j] && dp[k - m][i + m][j + m]) {
                            dp[k][i][j] = true;
                            break;
                        }
                        // Case 2: With swapping
                        if (dp[m][i][j + k - m] && dp[k - m][i + m][j]) {
                            dp[k][i][j] = true;
                            break;
                        }
                    }
                }
            }
        }
        return dp[n][0][0];
    }
};

// Time Complexity: O(n ^ 4)
// Space Complexity: O(n ^ 3)
