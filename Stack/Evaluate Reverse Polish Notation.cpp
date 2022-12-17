/*
    MY YOUTUBE VIDEO ON THIS Qn : <soon>
    Company Tags                : Apple, Microsoft, Flipkart, Amazon, LinkedIn
    Leetcode Link               : https://leetcode.com/problems/evaluate-reverse-polish-notation/
*/

class Solution {
public:
    int operate(int &a, int &b, const string &s) {
        if(s == "+")
            return a+b;
        
        if(s == "-")
            return a-b;
        
        if(s == "*")
            return (long)a*(long)b;
        
        if(s == "/")
            return a/b;
        
        return -1;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int result = 0;
        for(const string& s:tokens) {
            if(s == "+" || s == "-" || s == "*" || s == "/") {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                
                result = operate(a, b, s);
                st.push(result);
            } else {
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};
