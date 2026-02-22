/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS QN : https://www.youtube.com/watch?v=5DACQK9kud0
    Company Tags                : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/shortest-palindrome
*/

/*********************************************************************** C++ ************************************************************/
//Approach (Using simple substring check for Prefix and Suffix)
//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(begin(rev), end(rev));

        //T.C : O(n^2)
        //S.C : O(n)
        for(int i = 0; i < s.length(); i++) {

            if(!memcmp(s.c_str(), rev.c_str() + i, s.length()-i)) { //prefix in s == suffix in rev
                return rev.substr(0, i) + s;
            }
        }

        return rev + s;
    }
};


//Approach (Using LPS in KMP)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    // Function to compute the LPS (Longest Proper Prefix which is also Suffix) array
    void computeLPS(string pattern, vector<int>& lps) {
        int M = pattern.length();
        int len = 0; // Length of the previous longest prefix & suffix
    
        lps[0] = 0; // Because there is no proper suffix and prefix of pattern[0..0]
    
        int i = 1;
        while (i < M) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1]; 
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(begin(rev), end(rev));

        string temp = s + "-" + rev;

        vector<int> LPS(temp.length(), 0); //O(n)
        computeLPS(temp, LPS);

        int longestLPSLength = LPS[temp.length()-1]; //temp.back();

        string culprit = rev.substr(0, s.length() - longestLPSLength); //O(n)

        return culprit + s;
    }
};



/*********************************************************************** JAVA ************************************************************/
//Approach (Using simple substring check for Prefix and Suffix)
//T.C : O(n^2)
//S.C : O(n)
class Solution {

    public String shortestPalindrome(String s) {
        int length = s.length();
        String reversedString = new StringBuilder(s).reverse().toString();

        // Iterate through the string to find the longest palindromic prefix
        for (int i = 0; i < length; i++) {
            if (
                s.substring(0, length - i).equals(reversedString.substring(i))
            ) {
                return new StringBuilder(reversedString.substring(0, i))
                    .append(s)
                    .toString();
            }
        }
        return "";
    }
}


//Approach (Using LPS in KMP)
//T.C : O(n)
//S.C : O(n)
class Solution {
    // Function to compute the LPS (Longest Proper Prefix which is also Suffix) array
    public void computeLPS(String pattern, int[] lps) {
        int M = pattern.length();
        int len = 0; // Length of the previous longest prefix & suffix

        lps[0] = 0; // Because there is no proper suffix and prefix of pattern[0..0]

        int i = 1;
        while (i < M) {
            if (pattern.charAt(i) == pattern.charAt(len)) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1]; 
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    public String shortestPalindrome(String s) {
        String rev = new StringBuilder(s).reverse().toString();  // Reverse the string

        String temp = s + "-" + rev;  // Concatenate s and reversed s with a separator

        int[] LPS = new int[temp.length()];  // Create LPS array of size temp.length()
        computeLPS(temp, LPS);  // Compute the LPS array for the combined string

        int longestLPSLength = LPS[temp.length() - 1];  // The last value of LPS array

        // Get the culprit (i.e., the part from reversed string that needs to be added to make s a palindrome)
        String culprit = rev.substring(0, s.length() - longestLPSLength);

        return culprit + s;  // Return the shortest palindrome
    }
}
