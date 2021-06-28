/*
    Company Tags  : Microsoft
    Leetcode Link : https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
*/

//Approach-1 (With stack)
string removeDupUsingStack(string S) {
        stack<char> st;
        
        for(int i = S.length()-1; i>=0; i--) {
            if(st.empty())
                st.push(S[i]);
            else if(st.top() == S[i]) {
                st.pop();
            } else {
                st.push(S[i]);
            }
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
            if(result.empty()) {
                result.push_back(ch);
            } else if(result.back() == ch) {
                result.pop_back();
            } else {
                result.push_back(ch);
            }
        }
        
        return result;
    }
};

