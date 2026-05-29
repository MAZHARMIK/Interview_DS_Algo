/*         Scroll below to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Hr45fl6esng
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/maximum-number-of-operations-to-move-ones-to-the-end
*/


/********************************************************************** C++ **********************************************************************/
//Approach - Greedily moving from left to right
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int maxOperations(string s) {
        int n          = s.length();
        int result     = 0;
        int i          = 0;
        int count1seen = 0;

        while(i < n) {
            if(s[i] == '0') {
                result += count1seen;
                while(i < n && s[i] == '0') //moved till first '0' occurence
                    i++;
            } else {
                count1seen++;
                i++;
            }
        }

        return result;
    }
};




/********************************************************************** JAVA **********************************************************************/
//Approach - Greedily moving from left to right
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int maxOperations(String s) {
        int n = s.length();
        int result = 0;
        int i = 0;
        int count1seen = 0;

        while (i < n) {
            if (s.charAt(i) == '0') {
                result += count1seen;
                while (i < n && s.charAt(i) == '0') { // move until we reach next '1'
                    i++;
                }
            } else {
                count1seen++;
                i++;
            }
        }

        return result;
    }
}
