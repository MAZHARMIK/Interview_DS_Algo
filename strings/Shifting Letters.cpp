/*
    Company Tags  : Will update soon
    Leetcode Link : https://leetcode.com/problems/shifting-letters/
*/

class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = shifts.size();
        
        //mod 26 is done here because shifting any character 26 times
        //is as good as not shifting it at all
        for(int i = n-2; i>=0; i--)
            shifts[i] = (shifts[i] + shifts[i+1])%26;
        
        for(int i = 0; i < n; i++) {
                   
            int x  = s[i] - 'a';  //to bring into range of 0-26
            x     += shifts[i];   //Now, shift
            x     %= 26;         //wrap it back to 0-26
            x     += 'a';        //Bring back to range of 'a'-'z'
            
            s[i]   = (char)x;
  
        }
        return s;
    }
};
