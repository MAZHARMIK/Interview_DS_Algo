/*
    Company Tags  : Snapchat, Microsoft, Google
    Leetcode Link : https://leetcode.com/problems/remove-k-digits/
*/

class Solution {
public:
    string removeKdigits(string num, int k) {
        string result = "";
        int n = num.length();
        if(k == n)
            return "0";
        
        result.push_back(num[0]);
        
        for(int i = 1; i<n; i++) {
            while(result != "" && k > 0 && result.back() > num[i]) {
                result.pop_back();
                k--;
            }
            result.push_back(num[i]);
        }
        while(k > 0) {
            result.pop_back();
            k--;
        }
        /*
            "10200"
             1
             For this, result = "0200"
             we need to prune leading 0s

        */

        int i = 0;
        for(; i<result.length(); i++) {
            if(result[i] != '0')
                break;
        }
        
        result = result.substr(i);
        if(result == "")
            result = "0";
        return result;
    }
};
