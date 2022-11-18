/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=oWp--NIqWac&t=16s
    Company Tags                : Microsoft, Google(with variation)
    Leetcode Link               : https://leetcode.com/problems/guess-number-higher-or-lower/
*/

class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n;
        
        while(l <= r) {
            int mid = l + (r-l)/2;
            int val = guess(mid);
            
            if(val == -1) {
                r = mid-1;
            } else if(val == 1) {
                l = mid+1;
            } else {
                return mid;
            }
        }
        
        return -1;
    }
};
