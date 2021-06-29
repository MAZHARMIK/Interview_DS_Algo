/*
    Company Tags  : Google
    Leetcode Link : https://leetcode.com/problems/reverse-integer/
*/


class Solution {
public:
    int reverse(int x) {
        int reverse = 0;
        
        while(x) {
            int remain = x%10;
            
            /*
                Because , INT_MAX = 2147483647
                INT_MAX/10 = 214748364
                So, if reverse > 214748364, say 214748365
                then definitely reverse*10 (2147483650) is overflowing
                
                Also, if reverse = INT_MAX/10 = 214748364
                Then reverse*10 = 2147483640
                But then remain must be <= 7 to avoid overflow
            */
            if(reverse > INT_MAX/10 || (reverse == INT_MAX/10 && remain > 7)) {
                return 0;
            }
            
            /*
                Because , INT_MIN = -2147483648
                INT_MIN/10 = -214748364
                So, if reverse < -214748364, say -214748365
                then definitely reverse*10 (-2147483650) is overflowing
                
                Also, if reverse = INT_MIN/10 = -214748364
                Then  reverse*10 = -2147483640
                But then remain must be >= -8 (i.e. -8, -7, -6, -5 etc) to avoid overflow
                Adding those to -2147483640 will not go beyond INT_MIN limit
            */
            if(reverse < INT_MIN/10 || (reverse == INT_MIN/10 && remain < -8)) {
                return 0;
            }
            
            
            reverse *= 10;
            reverse += remain;
            x = x/10;
        }
			
        return reverse;
    }
};
