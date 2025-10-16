/*     Scroll below to see JAVA code    */
/*
    MY YOUTUBE VIDEO ON THIS Qn                : https://www.youtube.com/watch?v=S-y-PphOh2Q
    Company Tags                               : will soon update
    Leetcode Link                              : https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations
    
*/

//NOTE : Adding value to any number doesn’t change its remainder modulo value, so what really matters is the frequency of each remainder when the numbers are divided by value.

/****************************************************** C++ **************************************************************/
//Approach - Observation about Modulo(%) values
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> mp;

        for(int &num : nums) {
            int r = ((num % value) + value) % value;

            mp[r]++;
        }

        int MEX = 0;

        while(mp[(MEX % value)] > 0) {
            mp[(MEX % value)]--;

            MEX++;
        }

        return MEX;
    }
};



/****************************************************** JAVA **************************************************************/
//Approach - Observation about Modulo(%) values
//T.C : O(n)
//S.C : O(n)
class Solution {
    public int findSmallestInteger(int[] nums, int value) {
        HashMap<Integer, Integer> map = new HashMap<>();

        // Count occurrences of each normalized remainder
        for (int num : nums) {
            int r = ((num % value) + value) % value; // ensures non-negative remainder
            map.put(r, map.getOrDefault(r, 0) + 1);
        }

        int MEX = 0;

        // Increment MEX while we have available remainders
        while (map.getOrDefault(MEX % value, 0) > 0) {
            map.put(MEX % value, map.get(MEX % value) - 1);
            MEX++;
        }

        return MEX;
    }
}
