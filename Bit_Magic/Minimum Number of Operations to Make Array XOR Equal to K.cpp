/*    Scroll below to see JVAA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn - https://www.youtube.com/watch?v=rCDKurGjTGg
    Compnay Tags                - Amazon
    Leetcode Link               - https://leetcode.com/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k/description/
*/


/********************************************* C++ *********************************************/
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int totalXor = 0;
        
        for(int &num : nums) {
            totalXor ^= num;
        }
        
        
        int diff = (totalXor ^ k);
        
        return __builtin_popcount(diff);
        
    }
};



/********************************************* JAVA *********************************************/
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int minOperations(int[] nums, int k) {
        int totalXor = 0;
        for (int num : nums) {
            totalXor ^= num;
        }
        
        int diff = (totalXor ^ k);
        return Integer.bitCount(diff);
    }
}
