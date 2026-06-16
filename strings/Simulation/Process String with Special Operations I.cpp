/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=SDE8xan15Nw
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/process-string-with-special-operations-i
*/


/**************************************************************** C++ ****************************************************************/
//Approach (Simulation)
//T.C : O(2^n)
//S.C : O(2^n) - the reverse operation creates a temporary string
class Solution {
public:
    string processStr(string s) {
        string result = "";

        for(char &ch : s) {
            if(ch == '*') {
                if(result.length() > 0) result.pop_back();
            } else if(ch == '#') {
                result += result;
            } else if(ch == '%') {
                reverse(begin(result), end(result));
            } else {
                result += ch;
            }
        }

        return result;

    }
};



/**************************************************************** JAVA ****************************************************************/
//Approach (Simulation)
//T.C : O(2^n)
//S.C : O(2^n) - the reverse operation creates a temporary string
public class Solution {

    public String processStr(String s) {
        StringBuilder result = new StringBuilder();
        for (char ch : s.toCharArray()) {
            if (ch == '*') {
                if (result.length() > 0) result.deleteCharAt(result.length() - 1);
            } else if (ch == '#') {
                result.append(result.toString());
            } else if (ch == '%') {
                result.reverse();
            } else {
                result.append(ch);
            }
        }
        return result.toString();
    }
}
