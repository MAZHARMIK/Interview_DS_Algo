/*
    Company Tags  : Zappos, MentorGraphics
    Leetcode Link : https://leetcode.com/problems/reverse-words-in-a-string-iii/
*/

class Solution {
public:
    string reverseWords(string &s) {
        stringstream ss(s);

        string result = "";
        string token = "";

        while(ss >> token) {
            reverse(begin(token), end(token));
            result += token + " ";
        }

        return result.substr(0, result.length()-1);
    }
};
