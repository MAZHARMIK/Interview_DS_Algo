/*
    Company Tags  : Airbnb, Google
    Leetcode Link : https://leetcode.com/problems/add-strings/
*/

class Solution {
public:
    string addStrings(string num1, string num2) {
        int m = num1.length();
        int n = num2.length();
        int carry = 0;
        int i = m-1, j = n-1;
        string result = "";
        
        while(i >= 0 || j >= 0 || carry) {
            int a   = i>=0 ? num1[i--]-'0' : 0;
            int b   = j>=0 ? num2[j--]-'0' : 0;
            int sum = a + b + carry;
            
            result.push_back((sum%10)+'0');
            carry   = sum/10;
        }
        
        reverse(begin(result), end(result));
        return result;
    }
};
