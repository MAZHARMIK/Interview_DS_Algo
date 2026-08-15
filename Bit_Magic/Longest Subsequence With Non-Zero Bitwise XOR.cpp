/*   Scroll below to see JAVA code also  */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=t0kb8GtOsWs
    Company Tags                : Will udpate later
    Leetcode Link               : https://leetcode.com/problems/longest-subsequence-with-non-zero-bitwise-xor
*/


/******************************************************* C++ *******************************************************/
//Approach (Simple Observation of XOR property)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();

        int resultXor = 0;
        bool allZero = true;

        for(int &x : nums) {
            resultXor ^= x;
            if(x != 0)
                allZero = false;
        }

        if(allZero)
            return 0;

        return resultXor == 0 ? n-1 : n;
    }
};


/******************************************************* JAVA *******************************************************/
//Approach (Simple Observation of XOR property)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int longestSubsequence(int[] nums) {
        int n = nums.length;

        int resultXor = 0;
        boolean allZero = true;

        for(int x : nums) {
            resultXor ^= x;
            if(x != 0)
                allZero = false;
        }

        if(allZero)
            return 0;
        
        return resultXor == 0 ? n-1 : n;
    }
}
