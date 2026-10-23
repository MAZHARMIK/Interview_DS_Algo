/*   Scroll below to see JAVA code also  */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=t9qkP1cDzC4
    Company Tags                : Will udpate later
    Leetcode Link               : https://leetcode.com/problems/maximum-k-to-sort-a-permutation/
*/


/******************************************************* C++ *******************************************************/
//Approach (Bits Observation )
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();

        int K = -1; //"1111111" (all bits set)

        for(int i = 0; i < n; i++) {
            if(nums[i] != i) {
                K = (K & nums[i]);
            }
        }

        return K == -1 ? 0 : K;
    }
};



/******************************************************* C++ *******************************************************/
//Approach (Bits Observation )
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int sortPermutation(int[] nums) {
        int n = nums.length;

        int K = -1; // all bits set (0xFFFFFFFF)

        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                K &= nums[i];
            }
        }

        return K == -1 ? 0 : K;
    }
}
