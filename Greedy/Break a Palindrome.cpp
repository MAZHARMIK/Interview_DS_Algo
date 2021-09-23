/*
    Company Tags            : Amazon
    Frequency               : Yet to be known
    Video Explanation Link  : You can raise this request by contacting me on LinkedIn or posting request on Interview_DS_Algo page on LinkedIn. It's FREE
    Leetcode Link           : https://leetcode.com/problems/break-a-palindrome/
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
