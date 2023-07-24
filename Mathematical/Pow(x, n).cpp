/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=7wcJXZoGKMI
    Company Tags                : Amazon, LinkedIn, Bloomberg 
    Leetcode Link               : https://leetcode.com/problems/powx-n/
*/

/*
    Something to learn : 
Integer contains 32 bits, 1 bit is used for a sign flag (0 is + and 1 is -) and remaining 31 bits for values.
For negative values we can express 2^31 different values (from -1 to -2^31) and for positive values 
it is one value less since we still need to express zero.
So, for positive we can express 2^31-1values with 31 bits, from 1 to 2^31-1. 
That's why max negative and max positive do not match.
So, if n=-2147483648 and we multiply n*-1, 
We will get a number that is greater than Integer.MAX_VALUE as integer range is from -2147483648 to 2147483647
That is why, we convert it to long.
Hope you understood.
*/

class Solution {
public:
    
    double solve(double x, long n) {
        
        if(n == 0)
            return 1;
        
        if(n < 0)
            return 1/solve(x, -n);
        
        
        if(n%2 == 0) {
            return solve(x*x, n/2);
        }
        
        return x*solve(x*x, (n-1)/2);
        
    }
    
    double myPow(double x, int n) {
        return solve(x, (long)n);
    }
};
