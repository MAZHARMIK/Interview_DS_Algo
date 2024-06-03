/*     Scroll below to see JAVA code also  */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=WVDQWJuzLmw
    Company Tags                : AMAZON
    Leetcode Link               : https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/
*/

/**************************************************** C++ ****************************************************/
//Simple iteration
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int appendCharacters(string s, string t) {
        int m = s.length();
        int n = t.length();
        
        int i = 0; //for s
        int j = 0; //for t

        while(i < m && j < n) {
            if(s[i] == t[j]) {
                j++;
            }
            i++;
        }

        return n-j;
    }
};



/**************************************************** JAVA ****************************************************/
//Simple iteration
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int appendCharacters(String s, String t) {
        int m = s.length();
        int n = t.length();
        
        int i = 0; // for s
        int j = 0; // for t

        while (i < m && j < n) {
            if (s.charAt(i) == t.charAt(j)) {
                j++;
            }
            i++;
        }

        return n - j;
    }
}
