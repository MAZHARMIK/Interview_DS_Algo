/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Gx4-uOkopMA
    Company Tags                : Microsoft
    Leetcode Link               : https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/
*/

//Approach-1 (Visiting all bit one by one and compaing)
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int result = 0;
        
        while( a != 0 || b != 0 || c != 0) {
            
            if( (c & 1) == 1) {
                if((a & 1) == 0 && (b & 1) == 0) {
                    result++;
                }
            } else {
                result += (a & 1) + (b & 1);
            }
            
            a >>= 1;
            b >>= 1;
            c >>= 1;
            
        }
        
        return result;
    }
};


//Approach-2 (Using inbuild function)
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int result = (a | b) ^ c;
        return __builtin_popcount(result) + __builtin_popcount((a & b) & (result));
    }
};
