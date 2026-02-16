/*   Scroll below to see JAVA code also  */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=wl9OVejxckw
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/reverse-bits
*/


/******************************************************* C++ *******************************************************/
//Approach (Solving bit by bit)
//T.C : O(1)
//S.C : O(1)
class Solution {
public:
    int reverseBits(int n) {
        if (n == 0) return 0;
    
        int result = 0;
        for (int i = 0; i < 32; i++) {
            result <<= 1;
            

            result = (result | (n & 1));
            
            n >>= 1;
        }

        return result;
    }
};



/******************************************************* JAVA *******************************************************/
//Approach (Solving bit by bit)
//T.C : O(1)
//S.C : O(1)
class Solution {
    public int reverseBits(int n) {
        int result = 0;
        
        for (int i = 0; i < 32; i++) {
            result <<= 1;          // shift result left
            
            result |= (n & 1);     // take last bit of n
            
            n >>>= 1;              // unsigned right shift
        }
        
        return result;
    }
}
