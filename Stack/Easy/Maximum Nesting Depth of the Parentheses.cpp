/*     Scroll down to see jAVA code also   */
/*
    MY YOUTBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=uzP77oJVLos
    Company Tags               : will update soon
    Leetcode Link              : https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/
*/

/******************************************************************* C++ ***********************************************************************/
//Approach-1 (using stack)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int maxDepth(string s) {
        int result = 0;

        stack<char> st;
        
        for (char& ch : s) {
            
            if (ch == '(') {
                st.push(ch);
            } else if (ch == ')') {
                st.pop();
            }
            
            result = max(result, (int)st.size());
        }
        
        return result;
    }
};


//Approach-2 (using constant space)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int maxDepth(string s) {
        int result = 0;
        int openBrackets = 0;

        for (char &ch : s) {
            if (ch == '(') {
                openBrackets++;
            } else if (ch == ')') {
                openBrackets--;
            }
            
            result = max(result, openBrackets);
        }
        
        return result;
    }
};


/******************************************************************* JAVA ***********************************************************************/
//Approach-1 (using stack)
//T.C : O(n)
//S.C : O(n)
public class Solution {
    public int maxDepth(String s) {
        int result = 0;
        Stack<Character> st = new Stack<>();
        
        for (char ch : s.toCharArray()) {
            if (ch == '(') {
                st.push(ch);
            } else if (ch == ')') {
                st.pop();
            }
            
            result = Math.max(result, st.size());
        }
        
        return result;
    }
}


//Approach-2 (using constant space)
//T.C : O(n)
//S.C : O(1)
public class Solution {
    public int maxDepth(String s) {
        int result = 0;
        int openBrackets = 0;

        for (char ch : s.toCharArray()) {
            if (ch == '(') {
                openBrackets++;
            } else if (ch == ')') {
                openBrackets--;
            }
            
            result = Math.max(result, openBrackets);
        }
        
        return result;
    }
}
