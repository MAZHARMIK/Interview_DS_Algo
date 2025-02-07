/*      Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/clear-digits/description/
*/


/********************************************* C++ *********************************************/
//Approach-1 (Brute Force)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    string clearDigits(string s) {
        int i = 0;

        while (i < s.size()) {
            if (isdigit(s[i])) {

                s.erase(i, 1);
                if (i > 0) {
                    s.erase(i - 1, 1);
                    i--;
                }
            } else {
                i++;
            }
        }
        return s;
    }
};


//Approach-2 (Using stack)
//T.C : O(n)
//S.C : O(n) for stack
class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;

        for(char &ch : s) {
            if(ch >= 'a' && ch <= 'z') {
                st.push(ch);
            } else if(!st.empty()) {
                st.pop();
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


//Approach-3 (Using result string to avoid reverse call)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    string clearDigits(string s) {
        string result = "";

        for(char &ch : s) {
            if(ch >= 'a' && ch <= 'z') {
                result.push_back(ch);
            } else if(!result.empty()) {
                result.pop_back();
            }
        }

        return result;
    }
};


//Approach-4 (Solving inplace)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    string clearDigits(string s) {
        int j = 0;

        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                j = max(j - 1, 0); //max used to avoid negative
            } else {
                s[j] = s[i];
                j++;
            }
        }

        s.resize(j);
        return s;
    }
};
