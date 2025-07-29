/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=7ZOmJlTI2Z0
    Company Tags                : will soon update
    Leetcode Link               : https://leetcode.com/problems/smallest-subarrays-with-maximum-bitwise-or
*/

/******************************************************** C++ ********************************************************/
//Approach (Using frequency count and Xor Property)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();

        vector<int> result(n);
        
        vector<int> setBitIndex(32, -1);
        //setBitIndex[j] = i, it means that jth bit can be set via element at index i in nums

        for(int i = n-1; i >= 0; i--) {

            //nums[i] = binary rep
            int endIndex = i;
            for(int j = 0; j < 32; j++) {
                if(!(nums[i] & (1 << j))) { //if jth bit is not set
                    if(setBitIndex[j] != -1) {
                        endIndex = max(endIndex, setBitIndex[j]);
                    }
                } else {
                    setBitIndex[j] = i;
                }
            }

            result[i] = endIndex - i + 1;
        }

        return result;

    }
};



/******************************************************** JAVA ********************************************************/
//Approach (Using frequency count and Xor Property)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int[] smallestSubarrays(int[] nums) {
        int n = nums.length;
        int[] result = new int[n];
        int[] setBitIndex = new int[31];
        Arrays.fill(setBitIndex, -1);

        for (int i = n - 1; i >= 0; i--) {
            int endIndex = i;
            for (int j = 0; j < 31; j++) {
                if ((nums[i] & (1 << j)) == 0) {
                    if (setBitIndex[j] != -1) {
                        endIndex = Math.max(endIndex, setBitIndex[j]);
                    }
                } else {
                    setBitIndex[j] = i;
                }
            }
            result[i] = endIndex - i + 1;
        }

        return result;
    }
}
