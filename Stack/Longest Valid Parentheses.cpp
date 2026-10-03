/*     Scroll below to see JAVA code also   */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Google
    Leetcode Link               : https://leetcode.com/problems/longest-valid-parentheses/
*/


/********************************************************************** C++ **********************************************************************/
//Approach-1 (Using 2 pass)
//T.C : O(n), 2 Pass
//S.C : O(1)
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();

        int open  = 0;
        int close = 0;

        int result = 0;

        for(int i = 0; i < n; i++) {
            if(s[i] == '(') open++;
            else close++;

            if(open == close) {
                result = max(result, open+close);
            } else if(close > open) { //going from left to right, if close is more, it's no more valid
                open  = 0;
                close = 0;
            }
        }

        open  = 0;
        close = 0;
        for(int i = n-1; i >= 0; i--) {
            if(s[i] == '(') open++;
            else close++;

            if(open == close) {
                result = max(result, open+close);
            } else if(open > close) { //going from right to left, if open is more, it's no more valid
                open  = 0;
                close = 0;
            }
        }

        return result;
    }
};


//Approach-2 (Using Stack)
//T.C : O(n) - 1 Pass
//S.C : O(n)
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);

        int maxL = 0;

        int n = s.length();

        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if(st.empty()) {
                    st.push(i);
                } else {
                    maxL = max(maxL, i-st.top());
                }
            }
        }
        return maxL;
    }
};



/********************************************************************** JAVA **********************************************************************/
//Approach-1 (Using 2 pass)
//T.C : O(n), 2 Pass
//S.C : O(1)
class Solution {
    public int longestValidParentheses(String s) {
        int n = s.length();

        int open = 0;
        int close = 0;
        int result = 0;

        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '(') open++;
            else close++;

            if (open == close) {
                result = Math.max(result, open + close);
            } else if (close > open) { //going from left to right, if close is more, it's no more valid
                open = 0;
                close = 0;
            }
        }

        open = 0;
        close = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s.charAt(i) == '(') open++;
            else close++;

            if (open == close) {
                result = Math.max(result, open + close);
            } else if (open > close) { //going from right to left, if open is more, it's no more valid
                open = 0;
                close = 0;
            }
        }

        return result;
    }
}


//Approach-2 (Using Stack)
//T.C : O(n) - 1 Pass
//S.C : O(n)
class Solution {
    public int longestValidParentheses(String s) {
        Deque<Integer> st = new ArrayDeque<>();
        st.push(-1);

        int maxL = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.isEmpty()) {
                    st.push(i);
                } else {
                    maxL = Math.max(maxL, i - st.peek());
                }
            }
        }
        return maxL;
    }
}
