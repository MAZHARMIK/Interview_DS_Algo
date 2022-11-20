/*
    MY YOUTUBE VIDEO IN THIS Qn : https://www.youtube.com/watch?v=3AEKyHx3tzU
    Company Tags                : Google, Facebook, Airbnb
    Frequency                   : 66% (As per 2021)
    Leetcode Link               : https://leetcode.com/problems/basic-calculator/
*/

class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int number = 0;
        int result = 0;
        int sign   = 1;
        
        for(int i = 0; i<s.length(); i++) {
            if(isdigit(s[i])) {
                number  = 10*number + (s[i] - '0');
            } else if(s[i] == '+') {
                result += sign*number;
                number  = 0;
                sign = 1; //For further
            } else if(s[i] == '-') {
                result += sign*number;
                number  = 0;
                sign = -1; //For further
            } else if(s[i] == '(') {
                st.push(result);
                st.push(sign);
                result = 0;
                number = 0;
                sign = 1;
            } else if(s[i] == ')') {
                result += sign*number;
                number = 0;
                int top = st.top(); st.pop();
                result *= top;
                top = st.top(); st.pop();
                result += top;
            }
        }
        result += (sign*number);
        return result;
    }
};
