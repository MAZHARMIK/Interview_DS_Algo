/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=3ssh_mk4LqY
    Company Tags                : Google, Meta, Adobe, Amazon, OYO, Microsoft
    Leetcode Link               : https://leetcode.com/problems/valid-parentheses/
*/

//Approach-1 (Simple and basic approach using stack)
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(char ch:s) {
            if(st.empty() || ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
                continue;
            }
            
            if(ch == ')') {
                if(st.top() == '(')
                    st.pop();
                else
                    return false;
            } else if(ch == '}') {
                if(st.top() == '{')
                    st.pop();
                else
                    return false;
            } else if(ch == ']') {
                if(st.top() == '[')
                    st.pop();
                else
                    return false;
            }
        }
        
        return st.empty();
    }
};

//Approach-2 (Tricky)
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(char ch:s) {
            if (ch == '(')
			    st.push(')');
		    else if (ch == '{')
			    st.push('}');
            else if (ch == '[')
                st.push(']');
            else if (st.empty() || st.top() != ch)
                return false;
            else {
                st.pop();
            }
        }
        
        return st.empty();
    }
};
