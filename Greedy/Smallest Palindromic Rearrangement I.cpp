/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=AKX6wMVZ13U
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/smallest-palindromic-rearrangement-i/
*/


/*********************************************************** C++ **************************************************/
//Approach (Split in hald , Sort and form palindrome)
//T.C : O(n log n)
//S.C : O(1) (ignoring the space taken for sorting internally)
class Solution {
public:
    string smallestPalindrome(string s) {
        int n   = s.length();
        int mid = n/2;

        sort(s.begin(), s.begin() + mid); //note : mid is not included i.e. [begin, mid)

        for (int i = 0; i < mid; i++) {
            s[n - 1 - i] = s[i];
        }

        return s;
    }
};



/*********************************************************** C++ **************************************************/
//Approach (Split in hald , Sort and form palindrome)
//T.C : O(n log n)
//S.C : O(1) (ignoring the space taken for sorting internally)
class Solution {
    public String smallestPalindrome(String s) {
        int n = s.length();
        int mid = n / 2;
        char[] chars = s.toCharArray();
        Arrays.sort(chars, 0, mid); // note: mid is not included i.e. [0, mid)
        for (int i = 0; i < mid; i++) {
            chars[n - 1 - i] = chars[i];
        }
        return new String(chars);
    }
}
