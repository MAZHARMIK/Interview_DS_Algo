/*
    MY YOUTUBE VIEDO ON THIS Qn : 
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
    void generate(string curr, int idx, string digits, vector<string>& result, unordered_map<int, string>& mp) {
        if(idx == digits.length()) {
            result.push_back(curr);
            return;
        }
        
        string str = mp[digits[idx]-'0'];
        
        for(int i = 0; i<str.length(); i++) {
            curr.push_back(str[i]);                    //Do
            generate(curr, idx+1, digits, result, mp); //Explore
            curr.pop_back();                           //Undo
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0)
            return {};
        vector<string> result;
        unordered_map<int, string> mp;
        mp[0] = "0";
        mp[1] = "1";
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        generate("", 0, digits, result, mp);
        
        return result;
    }
};
