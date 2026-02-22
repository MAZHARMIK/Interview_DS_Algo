/*   Scroll below to see JAVA code also  */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=T2eCRsAVLQU
    Company Tags                : Twitter, Amazon
    Leetcode Link               : https://leetcode.com/problems/binary-gap
*/


/******************************************************* C++ *******************************************************/
//Approach-1 (Simple bit checking)
//T.C : ~O(32) i.e. O(1)
//S.C : O(1)
class Solution {
public:
    int binaryGap(int n) {
        int curr = 0;
        int prev = -1;

        int result = 0;

        while(n > 0) {
            if((n&1) > 0) {
                result = (prev != -1) ? max(result, curr - prev) : result;
                prev = curr;
            }

            curr++;
            n >>= 1;
        }

        return result;
    }
};



//Approach-2 (Simple bit checking)
//T.C : ~O(32) i.e. O(1)
//S.C : O(1)
class Solution {
public:
    int binaryGap(int n) {
        int prev = -1;

        int result = 0;

        for(int curr = 0; curr < 32; curr++) {
            if(((n >> curr) & 1) > 0) {
                result = (prev != -1) ? max(result, curr-prev) : result;
                prev = curr;
            }
        }

        return result;
    }
};
