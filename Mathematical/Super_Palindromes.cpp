/*
    Company Tags  : Let me know if you get it :-)
    Leetcode Link : https://leetcode.com/problems/super-palindromes/
*/

typedef unsigned long long ull;
class Solution {
public:
    bool isPallindrome(ull n) {
        ull num = n, rev = 0;
        while(num) {
            rev = rev*10 + num%10;
            num /= 10;
        }
        
        return rev == n;
    }
    
    ull getNextPallindrome(ull num, ull a) {
        while(a > 0) {
            num = (num*10) + (a%10);
            a /= 10;
        }
        return num;
    }
        
    int superpalindromesInRange(string left, string right) {
        ull l     = stoull(left);
        ull r     = stoull(right);
        ull sqr_l = sqrt(l);
        ull sqr_r = sqrt(r);
        int count = 0;
        //Since, max limit of right = 10^18
        //So, max limit of sqr_r    = 10^9
        //We look for odd length palindrome and check if their square is palindrome or not
        //We look for even length palindrome and check if their square is palindrome or not
        //From a number say 12, we generate next palindrome 121 and 1221
        //So reduced our contraints to a large extent
        ull pal_number;
        /*
            1  -> 1   and 11
            2  -> 2   and 22   ... so on
            12 -> 121 and 1221 ... so on
            And we check is these number square to a palindrome number
            The pal_number that I will be generating using i
            (example for i = 12, we generate 121 and 1221), should be <= sqr_r
            because square of that number should not exceed right limit.
            And should be >= sqrl_l (because in a limit of [4, 10000], we don't want 1,2,3 as the pal_number)
        */
        for(ull i = 1; (pal_number = getNextPallindrome(i, i/10)) <= sqr_r; i++) {
            
            if(pal_number >= sqr_l && pal_number <= sqr_r && isPallindrome(pal_number*pal_number))
                count++;
            
            pal_number = getNextPallindrome(i, i);
                
            if(pal_number >= sqr_l && pal_number <= sqr_r && isPallindrome(pal_number*pal_number))
                count++;
        }
        
        
        return count;
        
    }
};
