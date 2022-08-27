/*
    Company Tags  : Amazon, Accolite, Microsoft
    Leetcode Link : https://leetcode.com/problems/palindromic-substrings/
*/

//Approach-1 (DP)
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        
        vector<vector<bool>> t(n, vector<bool>(n, false));
        
        int count = n; //every character is a pallindrome substring
        
        //t[i][j] = true; means that s[i...j] is a pallindrome
        for(int i = 0; i<n; i++) {
            t[i][i] = true; //every character is a pallindrome substring
        }
        
        for(int L = 2; L<=n; L++) {
            for(int i = 0; i<n-L+1; i++) {
                int j = i + L - 1;
                
                if(s[i] == s[j] && (t[i+1][j-1] || L == 2)) {
                    t[i][j] = true;
                    count++;
                }
                
            }
        }
        
        return count;
    }
};

//Approach-2 : Expand Around Possible Centers (Fastest solution)
class Solution {
public:
    int count = 0;
    void check(string s, int i, int j) {
        while(i >=0 && j < s.length() && s[i] == s[j]) {
            count++;
            i--; //expanding from center   <---i  j--->
            j++; //expanding from center
        }
    }
    int countSubstrings(string s) {
        int n = s.length();
        count = 0;
        
        /*
            Every single character in the string is a center for possible odd-length palindromes: check(s, i, i);
            Every pair of consecutive characters in the string is a center for possible even-length palindromes: check(s, i, i+1);.
        */
        for(int i = 0; i<n; i++) {
            check(s, i, i);
            check(s, i, i+1);
        }
        return count;
    }
};
