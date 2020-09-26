/*
    Company Tags  : Google
    Leetcode Link : https://leetcode.com/problems/longest-valid-parentheses/
*/

class Solution {
public:
    //Approach-1
    int usingStack(string s) {
        stack<int> st;
        st.push(-1);
        int maxL = 0;
        int n = s.length();
        for(int i = 0; i<n; i++) {
            if(s[i] == '(') {
                st.push(i);
            } else {
                st.pop(); //that's why pushed -1
                if(st.empty()) {
                    st.push(i);
                } else {
                    maxL = max(maxL, i-st.top());
                }
            }
        }
        return maxL;
    }
    
    //Approach-2
    int withoutStack(string s) {
        int n = s.length();
        int open = 0, close = 0;
        int maxL = 0;
        for(int i = 0; i<n; i++) {
            if(s[i] == '(')
                open++;
            else
                close++;
            
            if(open == close) {
                maxL = max(maxL, 2*open);
            } else if(close>open) {
                open = 0;
                close = 0;
            }
        }
        
        open = 0, close = 0; //wy backwards also ? Think of this example : "(()"
        for(int i = n-1; i>=0; i--) {
            if(s[i] == '(')
                open++;
            else
                close++;
            
            if(open == close) {
                maxL = max(maxL, 2*open);
            } else if(open>close) {
                open = 0;
                close = 0;
            }
        }
        
        return maxL;
    }
    
    int longestValidParentheses(string s) {
        return usingStack(s);
        
        //return withoutStack(s);
    }
};
