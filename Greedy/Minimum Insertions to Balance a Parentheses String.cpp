/*         Scroll down to see JAVA code also                    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=4Tquknq6hvg
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string
*/


/********************************************************************* C++ ****************************************************************/
//Approach (Greedy)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        int result = 0; //insertions

        int count = 0;
        int i = 0;

        while(i < n) {
            if(s[i] == '(') {
                count++;
                i++;
            } else { //')'
                if(count > 0) {
                    count--;
                } else {
                    result++; //adding a '('
                }

                if(i+1 < n && s[i+1] == ')') {
                    i += 2;
                } else {
                    result++; //adding a ')'
                    i++;
                }
            }
        }

        return result + count*2;
    }
};



/********************************************************************* JAVA ****************************************************************/
//Approach (Greedy)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int minInsertions(String s) {
        int n = s.length();
        int result = 0;   // insertions made
        int count = 0;
        int i = 0;

        while (i < n) {
            if (s.charAt(i) == '(') {
                count++;
                i++;
            } else { // ')'
                if (count > 0) {
                    count--;
                } else {
                    result++;   // insert '('
                }

                if (i + 1 < n && s.charAt(i + 1) == ')') {
                    i += 2;     // "))" found
                } else {
                    result++;   // insert ')'
                    i++;
                }
            }
        }

        return result + count * 2;
    }
}
