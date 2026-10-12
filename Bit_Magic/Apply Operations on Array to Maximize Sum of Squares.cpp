/*   Scroll below to see JAVA code also  */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=b5J2CmPEeeQ
    Company Tags                : Will udpate later
    Leetcode Link               : https://leetcode.com/problems/apply-operations-on-array-to-maximize-sum-of-squares/
*/


/******************************************************* C++ *******************************************************/
//Approach (Bits Observation + Greedy)
//T.C : O(n+k)
//S.C : O(1)
class Solution {
public:
    int MOD = 1e9+7;

    int maxSum(vector<int>& nums, int k) {
        vector<int> count(32, 0);

        for(int &num : nums) {
            for(int b = 0; b < 32; b++) {
                if(num & (1 << b)) {
                    count[b]++; //found a '1' in this bit position b
                }
            }
        }


        long long result = 0;

        while(k--) {
            long long curr = 0;

            for(int b = 0; b < 32; b++) {
                if(count[b] > 0) {
                    count[b]--;

                    curr = (curr | (1 << b));
                }
            }

            result = (result + (curr*curr)) % MOD;
        }

        return result;

    }
};


/******************************************************* JAVA *******************************************************/
//Approach (Bits Observation + Greedy)
//T.C : O(n+k)
//S.C : O(1)
class Solution {
    public int maxSum(List<Integer> nums, int k) {
        final int MOD = 1_000_000_007;
        final int BITS = 30;                  // nums[i] <= 10^9 < 2^30

        // count[b] = number of 1s in bit column b
        int[] count = new int[BITS];

        for (int num : nums) {
            for (int b = 0; b < BITS; b++) {
                if ((num & (1 << b)) != 0) {
                    count[b]++;               // found a '1' in bit position b
                }
            }
        }

        long result = 0;

        while (k-- > 0) {
            long curr = 0;

            for (int b = 0; b < BITS; b++) {
                if (count[b] > 0) {
                    count[b]--;
                    curr |= (1L << b);        // 1L so it is a long, not an int
                }
            }

            result = (result + curr * curr) % MOD;
        }

        return (int) result;
    }
}
