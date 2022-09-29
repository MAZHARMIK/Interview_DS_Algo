/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Pbx0Pvyh7D4&list=PLpIkg8OmuX-J8_n8Vy9P9I3KvyDcPMzRU&index=3
    Company Tags                : Amazon, Google(with some variation)
    Leetcode Link               : https://leetcode.com/problems/break-a-palindrome/
*/

class Solution {
public:
    string breakPalindrome(string pal) {
        int n = pal.length();
        if(n == 1) return "";
        
        for(int i = 0; i<n/2; i++) {
            if(pal[i] != 'a') {
                pal[i] = 'a';
                return pal;
            }
        }
        
        pal[n-1] = 'b';
        return pal;
    }
};
