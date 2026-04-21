/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=do3fgZMPiGs
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/xor-after-range-multiplication-queries-i
*/

/*********************************************************** C++ **************************************************/
//Approach (Straight forward simulation)
//T.C : O(n*q),  n = nums.size(), and q = queries.size()
//S.C : O(1)
class Solution {
public:
    int M = 1e9 + 7;

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for (auto &query : queries) {
            int l = query[0];
            int r = query[1];
            int k = query[2];
            int v = query[3];

            while (l <= r) {
                nums[l] = (1LL * nums[l] * v) % M;
                l += k;
            }
        }

        int result = 0;
        for (int &num : nums) {
            result ^= num;
        }
        
        return result;
    }
};



/*********************************************************** JAVA **************************************************/
//Approach (Straight forward simulation)
//T.C : O(n*q),  n = nums.size(), and q = queries.size()
//S.C : O(1)
class Solution {
    int M = (int)1e9 + 7;
    public int xorAfterQueries(int[] nums, int[][] queries) {
        for (int[] query : queries) {
            int l = query[0];
            int r = query[1];
            int k = query[2];
            int v = query[3];

            while (l <= r) {
                nums[l] = (int)((1L * nums[l] * v) % M);
                l += k;
            }
        }

        int result = 0;
        for (int num : nums) {
            result ^= num;
        }

        return result;
    }
}
