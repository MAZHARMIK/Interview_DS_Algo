/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/remove-covered-intervals
*/


/*********************************************************** C++ **************************************************/
//Approach (Iterate and find)
//T.C : O(n) 
//S.C : O(1)
class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> result(n, 0);

        for(int i = 0; i < n; i++) {
            int shift = nums[i]%n; //reducing the large shifts within 0..n-1 range

            int newIdx = (i + shift) % n;

            if(newIdx < 0) {
                newIdx += n;
            }

            result[i] = nums[newIdx];
        }

        return result;

    }
};



/*********************************************************** JAVA **************************************************/
//Approach (Iterate and find)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int[] constructTransformedArray(int[] nums) {
        int n = nums.length;
        int[] result = new int[n];

        for (int i = 0; i < n; i++) {
            int shift = nums[i] % n;   // keep shift within array bounds

            int newIdx = (i + shift) % n;

            // Java can still give negative modulo, so fix it
            if (newIdx < 0) {
                newIdx += n;
            }

            result[i] = nums[newIdx];
        }

        return result;
    }
}
