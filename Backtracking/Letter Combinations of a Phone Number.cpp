/*
    MY YOUTUBE VIEDO ON THIS Qn : https://www.youtube.com/watch?v=vgnhZzw-kfU
    Company Tags                : Microsoft, Meta, Epic Systems, Amazon, Flipkart
    Leetcode Link               : https://leetcode.com/problems/letter-combinations-of-a-phone-number/
*/

//Backtracking - Khandani template
/*
    Each digit can be presented at most by 4 letters. On each iteration we go over all 4 of them. And we do this N (the number of digits) time. 
    The complexity would be at most O(4^N)
    But, you you still have to traverse the entire string and do the same amount of operations, so it's O(n • 4^N).
*/
class Solution {
public:
    vector<string> result;
    
    void solve(int idx, string &digits, string &temp, unordered_map<char, string> &mp) {
        
        if(idx >= digits.length()) {
            result.push_back(temp);
            return;
        }
        
        
        char ch = digits[idx];
        string str = mp[ch];
        
        for(int i = 0; i<str.length(); i++) {
            
            //Do
            temp.push_back(str[i]);
            solve(idx+1, digits, temp, mp);
            temp.pop_back();
            
        }
        
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0)
            return {};
        
        unordered_map<char, string> mp;
        
        mp['2'] =  "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        
        string temp = "";
        
        solve(0, digits, temp, mp);
        
        return result;
    }
};
