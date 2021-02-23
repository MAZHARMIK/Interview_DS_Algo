/*
    Company Tags  : Google
    Leetcode Link : https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/
*/

class Solution {
public:
    string s1 = "";
    //They wanted to check if you comeup with isSubsequence approach or not
    bool isSubsequence(string& s2) {
        int i = 0;
        int j = 0;
        
        int m = s1.length();
        int n = s2.length();
        
        while(i < m && j < n) {
            if(s1[i] == s2[j])
                j++;
            i++;
        }
        
        return j==n;
    }
    string findLongestWord(string s, vector<string>& d) {
        string result = "";
        s1 = s;
        for(string str:d) {
            if(isSubsequence(str)) {
                if(str.length() > result.length())
                    result = str;
                else if(str.length() == result.length() && str < result)
                    result = str;
            }
        }
        
        return result;
    }
};
