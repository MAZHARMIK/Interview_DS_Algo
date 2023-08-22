/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=8QfC0elqK1o
      Company Tags                : Facebook, Zenefits, Microsoft
      Leetcode Link               : https://leetcode.com/problems/excel-sheet-column-title/
*/

****************************** C++ ******************************
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




****************************** JAVA ******************************
class Solution {
    public String convertToTitle(int columnNumber) {
        StringBuilder result = new StringBuilder();
        
        while(columnNumber > 0) {
            columnNumber--;
            int remain = columnNumber%26;
            

            result.append((char)((remain + 'A')));
            columnNumber = (columnNumber) / 26;
        }
        
        // Reverse it, as we appended characters in reverse order.
        return result.reverse().toString();
    }
}
