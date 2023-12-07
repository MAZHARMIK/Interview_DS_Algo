/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=vkxUVdGgnhU
    Company Tags                : Amazon
    Leetcode Link               : https://leetcode.com/problems/largest-odd-number-in-string/
*/

/****************************************************************** C++ *****************************************************************************/
//Approach - Simple Greedy
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length();
        
        for(int i = n-1; i>=0; i--) {
            
            if((num[i] - '0') % 2 != 0) {
                return num.substr(0, i+1);
            }
        }
        
        return "";
    }
};


/****************************************************************** JAVA *****************************************************************************/
//Approach - Simple Greedy
//T.C : O(n)
//S.C : O(1)
class Solution {
    public String largestOddNumber(String num) {
        int n = num.length();
        
        for (int i = n - 1; i >= 0; i--) {
            if (Character.getNumericValue(num.charAt(i)) % 2 != 0) {
                return num.substring(0, i + 1);
            }
        }
        
        return "";
    }
}
