/*    Scroll below to see JAVA code as well    */
/*
    MY YOUTUBE VIDEO ON THIS QN : 
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/remove-outermost-parentheses/
*/

/*************************************************************************** C++ ***************************************************************************/
//Approach (simple traverse and check with count)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    string removeOuterParentheses(string s) {
        int count = 0;

        string result = "";

        for(char &ch : s) {
            if(ch == '(') {
                if(count != 0) result.push_back(ch);

                count++;
            } else {
                count--;
                if(count != 0) result.push_back(ch);
            }
        }

        return result;
    }
};


/*************************************************************************** JAVA ***************************************************************************/
//Approach (simple traverse and check with count)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public String removeOuterParentheses(String s) {
        int count = 0;

        StringBuilder sb = new StringBuilder();

        for(char ch : s.toCharArray()) {
            if(ch == '(') {
                if(count != 0) sb.append(ch);

                count++;
            } else {
                count--;
                if(count != 0) sb.append(ch);
            }
        }

        return sb.toString();
    }
}
