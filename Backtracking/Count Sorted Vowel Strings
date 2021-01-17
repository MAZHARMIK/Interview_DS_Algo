/*
    Leetcode Weekly Contest : 213 (https://leetcode.com/contest/weekly-contest-213/)
*/

class Solution {
public:
    int count(string s, int len, int n, int index) {
        if(len == n)
            return 1;
        
        int c = 0;
        for(int i = index; i<5; i++) {
            len++;
            c += count(s, len, n, i);
            len--;
        }
        
        return c;
    }
    int countVowelStrings(int n) {
        string s     = "aeiou";
        string temp  = "";
        return count(s, 0, n, 0);
    }
};
