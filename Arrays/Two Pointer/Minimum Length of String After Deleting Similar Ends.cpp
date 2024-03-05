/*         Scroll down to see JAVA code also      */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/
*/


/************************************************************ C++ ************************************************************/
//Using simple 2 Pointers
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        
        int i = 0, j = n-1;
        
        while(i < j && s[i] == s[j]) {
            char ch = s[i];
            
            while(i < j && s[i] == ch) {
                i++;
            }
            
            while(j >= i && s[j] == ch) {
                j--;
            }
        }
        
        return j-i+1;
    }
};


/************************************************************ JAVA ************************************************************/
//Using simple 2 Pointers
//T.C : O(n)
//S.C : O(1)
public class Solution {
    public int minimumLength(String s) {
        int n = s.length();

        int i = 0, j = n - 1;

        while (i < j && s.charAt(i) == s.charAt(j)) {
            char ch = s.charAt(i);

            while (i < j && s.charAt(i) == ch) {
                i++;
            }

            while (j >= i && s.charAt(j) == ch) {
                j--;
            }
        }

        return j - i + 1;
    }
}
