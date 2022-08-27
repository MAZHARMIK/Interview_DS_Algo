/*
    Company Tags  : Accolite, Amazon, Groupon, MakeMyTrip, Microsoft, Qualcomm, Samsung, Visa, Walmart, Zoho
    Leetcode Link : https://leetcode.com/problems/longest-palindromic-substring/
*/

//Elaborated for simplicity
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        
        int maxL  = 0;
        int index = 0;
        
        vector<vector<bool>> t(n, vector<bool>(n));
        //t[i][j] = lps in s[i...j]
        
        maxL = 1; //every letter is a substring and pallindrome as well
        for(int i = 0; i<n; i++) {
            t[i][i] = true;
            /*
                s[0..0] = pallindrome
                s[1..1] = pallindrome
                s[2..2] = pallindrome
                .
                .
                .
            */
        }
        
        for(int L = 2; L<=n; L++) {
            for(int i = 0; i<n-L+1; i++) {
                int j = i + L - 1;
                
                if(s[i] == s[j] && L == 2) {
                    t[i][j] = true;
                    maxL = 2;
                    index = i;
                } else if (s[i] == s[j] && t[i+1][j-1] == true) {
                    t[i][j] = true;
                    if(j-i+1 > maxL) {
                        maxL = j-i+1;
                        index = i;
                    }
                } else {
                    t[i][j] = false;
                }
                
            }    
        }
        
        
        return s.substr(index, maxL);
    }
};



//Simplified solution
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> t(n, vector<bool>(n, false));
        int maxL = 1;
        int start = 0;
        
        for(int i = 0; i<n; i++)
            t[i][i] = true;
      
        
        for(int L = 2; L<=n; L++) {
            for(int i = 0; i<n-L+1; i++) {
                int j = i + L - 1;
                
                if(s[i] == s[j] && (t[i+1][j-1] || L == 2)) {
                    t[i][j] = true;
                    if(L > maxL) {
                        maxL = L;
                        start = i;
                    }
                }
            }
        }
        
        return s.substr(start, maxL);
    }
};
