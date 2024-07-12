/*      Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Google, Meta, Amazon
    Leetcode Link               : https://leetcode.com/problems/maximum-score-from-removing-substrings
*/


/**************************************************************** C++ ********************************************************/
//Approach-1 (Using Stack)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n     = s.length();
        int score = 0;

        string maxStr = (x > y) ? "ab" : "ba";
        string minStr = (x < y) ? "ab" : "ba";

        //First Pass
        string temp_first     = removeSubstring(s, maxStr);
        int removedPairsCount = (n - temp_first.length()) / 2;
        score                += removedPairsCount * max(x, y);


        //Second Pass
        string temp_second = removeSubstring(temp_first, minStr);
        removedPairsCount  = (temp_first.length() - temp_second.length()) / 2;
        score             += removedPairsCount * min(x, y);

        return score;
    }

private:
    string removeSubstring(string& s, string& matchStr) {
        stack<char> st;

        for (char &ch : s) {
            if (ch == matchStr[1] && !st.empty() && st.top() == matchStr[0]) {
                st.pop();
            } else {
                st.push(ch);
            }
        }

        string remainStr;
        while (!st.empty()) {
            remainStr.push_back(st.top());
            st.pop();
        }
        reverse(remainStr.begin(), remainStr.end());
        return remainStr;
    }
};



//Approach-2 (Without Stack)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n     = s.length();
        int score = 0;

        string maxStr = (x > y) ? "ab" : "ba";
        string minStr = (x < y) ? "ab" : "ba";

        //First Pass
        string temp_first     = removeSubstring(s, maxStr);
        int L                 = temp_first.length();
        int removedPairsCount = (n - L) / 2;
        score                += removedPairsCount * max(x, y);


        //Second Pass
        string temp_second = removeSubstring(temp_first, minStr);
        removedPairsCount  = (L - temp_second.length()) / 2;
        score             += removedPairsCount * min(x, y);

        return score;
    }

    string removeSubstring(string& inputString, string& matchStr) {
        int j = 0;

        for (int i = 0; i < inputString.size(); i++) {
            inputString[j++] = inputString[i];

            if (j > 1 &&
                inputString[j - 2] == matchStr[0] &&
                inputString[j - 1] == matchStr[1]) {
                j -= 2;
            }
        }

        inputString.erase(inputString.begin() + j, inputString.end());

        return inputString;
    }
};




/**************************************************************** JAVA ***********************************************************/
//Approach-1 (Using Stack)
//T.C : O(n)
//S.C : O(n)
