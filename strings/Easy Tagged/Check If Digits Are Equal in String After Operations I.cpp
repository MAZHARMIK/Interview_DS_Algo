/*    Scroll below to see JAVA code as well    */
/*
    MY YOUTUBE VIDEO ON THIS QN : 
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/check-if-digits-are-equal-in-string-after-operations-i
*/

/*************************************************************************** C++ ***************************************************************************/
//Approach (simple traverse and check)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.length();

        while(n > 2) {

            for(int i = 0; i < n-1; i++) {
                s[i] = (((s[i] - '0') + (s[i+1] - '0')) % 10) + '0';
            }

            n--;
        }

        return s[0] == s[1];
    }
};



/*************************************************************************** JAVA ***************************************************************************/
//Approach (simple traverse and check)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
    public boolean hasSameDigits(String s) {
        int n = s.length();
        StringBuilder sb = new StringBuilder(s);

        while (n > 2) {
            for (int i = 0; i < n - 1; i++) {
                int a = sb.charAt(i) - '0';
                int b = sb.charAt(i + 1) - '0';
                int sum = (a + b) % 10;
                sb.setCharAt(i, (char)(sum + '0'));
            }
            n--;
        }

        return sb.charAt(0) == sb.charAt(1);
    }
}
