/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=VeOUal3_s6c
    Company Tags                : Microsoft, Paytm, Samsung
    Leetcode Link               : https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
*/

//Approach-1 (With stack)
string removeDupUsingStack(string S) {
        stack<char> st;
        
        for(int i = S.length()-1; i>=0; i--) {
            if(st.empty() || st.top() != S[i])
                st.push(S[i]);
            else
                st.pop();
        }
    
        string result = "";
        while(!st.empty()) {
            result += st.top();
            st.pop();
        }
        return result;
    }

//Appraoch-2 (Without stack)
class Solution {
public:
    string removeDuplicates(string s) {
        string result = "";
        
        for(char &ch : s) {
            if(result.empty() || result.back() != ch) {
                result.push_back(ch);
            } else {
                result.pop_back();
            }
        }
        
        return result;
    }
};

