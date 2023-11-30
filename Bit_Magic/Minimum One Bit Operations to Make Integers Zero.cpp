/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=yU6DZSLW4_c
    Company Tags                : LinkedIn
    Leetcode Link               : https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/
*/

//Using mathematical observation - Breaking into smaller sub-problems
//T.C : O(1) -> Constant for loop
//S.C : O(32) ~ O(1)
class Solution {
public:
    int minimumOneBitOperations(int n) {
        if(n == 0)
            return 0;
        
        vector<long long> function(32, 0);
        //function[i] = x
        //Means it will take x operations to make ith bit 1
        function[0] = 1;
        for(int i = 1; i <= 31; i++) {
            function[i] = 2*function[i-1] + 1;
        }
        
        int result = 0;
        int sign  = 1;
        
        for(int i = 30; i >= 0; i--) {
            
            int ith_bit = ((1 << i) & n);
            
            if(ith_bit == 0) {
                continue;
            }
            
            if(sign > 0)
                result += function[i];
            else
                result -= function[i];
            
            sign *= -1;
            
        }
        
        return result;
    }
};


/***************************************************************** JAVA *****************************************************************/
//Using mathematical observation - Breaking into smaller sub-problems
//T.C : O(1) -> Constant for loop
//S.C : O(32) ~ O(1)
public class Solution {
    public int minimumOneBitOperations(int n) {
        if (n == 0) {
            return 0;
        }

        long[] function = new long[32];
        // function[i] = x
        // Means it will take x operations to make the ith bit 1
        function[0] = 1;
        for (int i = 1; i <= 31; i++) {
            function[i] = 2 * function[i - 1] + 1;
        }

        int result = 0;
        int sign = 1;

        for (int i = 30; i >= 0; i--) {
            int ithBit = ((1 << i) & n);

            if (ithBit == 0) {
                continue;
            }

            if (sign > 0) {
                result += function[i];
            } else {
                result -= function[i];
            }

            sign *= -1;
        }

        return result;
    }
}

