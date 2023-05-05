/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=CAVnGkDzqAs
    Company Tags                : MICROSOFT
    Leetcode Link               : https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
*/

//Sliding window - Separate function to check vowel
class Solution {
public:
    bool isVowel(char &ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    
    int maxVowels(string s, int k) {
        int n = s.length();
        
        int maxV  = 0;
        int count = 0;
        int i = 0, j = 0;
        
        while(j < n) {
            
            if(isVowel(s[j]))
                count++;
            
            if(j-i+1 == k) {
                maxV = max(maxV, count);
                if(isVowel(s[i]))
                    count--;
                i++;
            }
            
            j++;
        }
        
        return maxV;
    }
};


//Sliding Window - Writing a lambda function to check vowel
class Solution {
public:
    
    int maxVowels(string s, int k) {
        
        auto isVowel = [&](char ch) {
            return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
        };
        
        int n = s.length();
        
        int maxV  = 0;
        int count = 0;
        int i = 0, j = 0;
        
        while(j < n) {
            
            if(isVowel(s[j]))
                count++;
            
            if(j-i+1 == k) {
                maxV = max(maxV, count);
                if(isVowel(s[i]))
                    count--;
                i++;
            }
            
            j++;
        }
        
        return maxV;
    }
};
