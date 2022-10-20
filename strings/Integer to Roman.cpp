/*
    Company Tags  : Amazon, Facebook, Microsoft, Twitter, Apple, Google, Paypal, Bloomberg, Adobe
    Leetcode Link : https://leetcode.com/problems/integer-to-roman/
*/

class Solution {
public:
    vector<int>    val{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    vector<string> sym{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
  
    string intToRoman(int num) {
        
        string result = "";
        int i = 0;
        while(num > 0) {
            while(num >= val[i]) {
                num -= val[i];
                result += sym[i];
            }
            i++;
        }
        return result;
        
    }
};
