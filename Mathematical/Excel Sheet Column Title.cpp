/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=8QfC0elqK1o
      Company Tags                : Facebook, Zenefits, Microsoft
      Leetcode Link               : https://leetcode.com/problems/excel-sheet-column-title/
*/

//T.C : O(log(columnNumber))
class Solution {
public:
    string convertToTitle(int columnNumber) {
        
        string s;
        
        while(columnNumber) {
            columnNumber--;
            
            int remain = columnNumber%26;
            char ch    = remain + 'A';
            s.push_back(ch);
            
            columnNumber /= 26;
            
        }
        
        reverse(begin(s), end(s));
        return s;
        
    }
};
