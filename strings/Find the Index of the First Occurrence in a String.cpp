/*
    MY YOUTUBE VIDEO ON THIS Qn - <soon>
    Company Tags                - Google, Amazon, Microsoft, Facebook, Qualcomm
    Leetcode Link               - https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
*/

//Using Brute Force naive Approach
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.length();
        int n = needle.length();
        
        for(int i = 0; i <= m-n; i++) { //haystack
            
            for(int j = 0; j < n; j++) { //needle
                
                if(haystack[i+j] != needle[j])
                    break;
                
                if(j == n-1)
                    return i;
                
            }
            
        }
        
        return -1;
    }
};


//Other approaches will be updated soon - KMP, Rabin Karp
