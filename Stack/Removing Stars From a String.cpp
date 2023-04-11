/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=s1pcdsRCVDg
    Company Tags                : MICROSOFT
    Leetcode Link               : https://leetcode.com/problems/removing-stars-from-a-string/
*/

//Approach-1 (Using Stack)
class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        
        for(char &ch : s) {
            
            if(ch == '*') {
                st.pop();
            } else {
                st.push(ch);
            }
            
        }
        
        string result = "";
        
        while(!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        
        reverse(begin(result), end(result));
        return result;
    }
};

//Approach-2 (using string as stack)
class Solution {
public:
    string removeStars(string s) {
        string result = "";
        
        for(char &ch : s) {
            
            if(ch == '*') {
                result.pop_back();
            } else {
                result.push_back(ch);
            }
            
        }
        
        return result;
    }
};

//Approach-3 (Using Two pointers)
class Solution {
public:
    string removeStars(string s) {
        vector<char> ch(s.size());
        int j = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '*') {
                j--;
            } else {
                ch[j++] = s[i];
            }
        }

        string result = "";
        for (int i = 0; i < j; i++) {
            result.push_back(ch[i]);
        }

        return result;
    }
};
