/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will soon update
    Leetcode Link               : https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-ii
*/

/******************************************************** C++ ********************************************************/
//Approach - Simple using OR property and sliding window
//T.C : O(n)
//S.C : O(1)
class Solution {
public:

    void update(int number, vector<int>& vec, int val) {
        for(int i = 0; i < 32; i++) { //O(32)
            if((number >> i) & 1) {
                vec[i] += val;
            }
        }
    }

    int getDecimalFromBinary(vector<int>& vec) {
        int num = 0;

        for(int i = 0; i < 32; i++) { //O(32)
            if(vec[i] > 0) { //ith position me 1 hai
                num |= (1 << i);
            }
        }

        return num;
    }

    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();

        int result = INT_MAX;

        int i = 0;
        int j = 0;

        vector<int> vec(32, 0);
        //vec[i] = total number of set bits in ith position

        //T.C : O(2*n)
        while(j < n) { //O(n)
            update(nums[j], vec, 1); //adding in the current window

            while(i <= j && getDecimalFromBinary(vec) >= k) {
                result = min(result, j-i+1);
                update(nums[i], vec, -1); //remove the nums[i] from the window
                i++;
            }

            j++;
        }

        return result == INT_MAX ? -1 : result;
    }
};




/******************************************************** JAVA ********************************************************/
//Approach - Simple using OR property and sliding window
//T.C : O(n)
//S.C : O(1)
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class Solution {

    // Updates the 'vec' array based on the set bits in the number.
    private void update(int number, List<Integer> vec, int val) {
        for (int i = 0; i < 32; i++) { // O(32)
            if ((number >> i & 1) == 1) {
                vec.set(i, vec.get(i) + val);
            }
        }
    }

    // Converts the binary representation stored in 'vec' back to a decimal integer.
    private int getDecimalFromBinary(List<Integer> vec) {
        int num = 0;
        for (int i = 0; i < 32; i++) { // O(32)
            if (vec.get(i) > 0) { // ith position has a set bit
                num |= (1 << i);
            }
        }
        return num;
    }

    public int minimumSubarrayLength(int[] nums, int k) {
        int n = nums.length;
        int result = Integer.MAX_VALUE;

        int i = 0;
        int j = 0;

        // Initialize 'vec' with 32 zeros to store bit counts
        List<Integer> vec = new ArrayList<>(Collections.nCopies(32, 0));

        // T.C : O(2 * n)
        while (j < n) { // O(n)
            update(nums[j], vec, 1); // Add nums[j] to the current window

            // Check if the current window has a sum >= k
            while (i <= j && getDecimalFromBinary(vec) >= k) {
                result = Math.min(result, j - i + 1);
                update(nums[i], vec, -1); // Remove nums[i] from the window
                i++;
            }

            j++;
        }

        return result == Integer.MAX_VALUE ? -1 : result;
    }
}
