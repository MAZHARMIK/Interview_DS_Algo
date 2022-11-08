/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=J43ZIltH3AY
    Company Tags                : Google, Apple, LinkedIn, Microsoft
    Leetcode Link               : https://leetcode.com/problems/make-the-string-great/
*/

class Solution {
public:
    string makeGood(string s) {
        string result = "";
        
        for(char &ch : s) {
            if(ch + 32 == result.back() || ch - 32 == result.back()) {
                result.pop_back();
            } else {
                result.push_back(ch);
            }
        }
        
        return result;
    }
};
