/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=5uJitfSM3vk
    Company Tags  : Facebook, Amazon, Microsoft, Zoho, Google (3 years ago)
    Leetcode Link : https://leetcode.com/problems/count-and-say/
    GfG Link      : https://practice.geeksforgeeks.org/problems/decode-the-pattern1138/1
*/


class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
            return "1";
        
        
        string say = countAndSay(n-1);
        
        string result = "";
        
        // Just count and store in result and return
        for(int i = 0; i<say.length(); i++) {
            
            int count = 1;
            char ch = say[i];
            
            while(i < say.length()-1 && say[i] == say[i+1]) {
                count++;
                i++;
            }
            
            result += to_string(count) + string(1, say[i]);
            
        }
        
        return result;
        
    }
};
