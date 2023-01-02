/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=DrVLI_NXaic
    Company Tags                : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/detect-capital/
*/

//Approach-1 (Simple Checks)
//NOTE :  YOU can also use isupper() C++ function to check capital
class Solution {
public:
    bool allCapitals(string word) {
        for(char ch:word) {
            if(ch <'A' || ch >'Z')
                return false;
        }
        return true;
    }
    bool allSmall(string word) {
        for(char ch:word) {
            if(ch <'a' || ch >'z')
                return false;
        }
        return true;
    }
    
    bool detectCapitalUse(string word) {
        if(allCapitals(word) || allSmall(word) || allSmall(word.substr(1)))
            return true;
        return false;
    }
};


//Approach-2 (Small and simple)
class Solution {
public:
    bool detectCapitalUse(string word) {
        int countCapitals = 0;
        
        for(char &ch : word) {
            if(isupper(ch))
                countCapitals++;
        }
        
        if(countCapitals == 0)
            return true;
        
        if(countCapitals == word.length())
            return true;
        
        if(countCapitals == 1 && isupper(word[0]))
            return true;
        
        return false;
    }
};
