/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=qDtW0HRvNc0
    Company Tags                : will soon update
    Leetcode Link               : https://leetcode.com/problems/maximum-xor-for-each-query
*/

/******************************************************** C++ ********************************************************/
//Approach - Simply using XOR properties
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();

        vector<int> result(n);

        //step-1 : Find the total xor
        int XOR = 0;
        for(int i = 0; i < n; i++) {
            XOR ^= nums[i];
        }

        //To find flip, first find the mask having all bits set to 1
        int mask = ((1 << maximumBit) - 1);

        for(int i = 0; i < n; i++) {
            int k = XOR ^ mask; //this will give me the flipped value of XOR i.e. my best K
            result[i] = k;

            XOR = (XOR ^ nums[n-1-i]);
        }

        return result;


    }
};



/******************************************************** JAVA ********************************************************/
//Approach - Simply using XOR properties
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int[] getMaximumXor(int[] nums, int maximumBit) {
        int n = nums.length;
        int[] result = new int[n];

        // Step 1: Calculate the total XOR of all elements in nums
        int XOR = 0;
        for (int num : nums) {
            XOR ^= num;
        }

        // Create a mask with all bits set to 1, based on maximumBit
        int mask = (1 << maximumBit) - 1;

        // Calculate the result by finding the maximum XOR for each element
        for (int i = 0; i < n; i++) {
            // XOR ^ mask will give the flipped value of XOR, which is the best K
            result[i] = XOR ^ mask;

            // Update XOR by removing the last element in the reversed order
            XOR ^= nums[n - 1 - i];
        }

        return result;
    }
}
