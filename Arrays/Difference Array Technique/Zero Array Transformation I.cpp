/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/zero-array-transformation-i
*/


/************************************************************ C++ ************************************************/
//Approach - Straight Forward Difference Array Technique
//T.C : O(Q + n)
//S.C : O(Q + n)
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        //Step-1 Make diff array using query
        vector<int> diff(n, 0);
        for(auto &query : queries) {
            int start = query[0];
            int end   = query[1];
            int x     = 1;

            diff[start] += x;
            if(end+1 < n) {
                diff[end+1] -= x;
            }
        }

        //Step-2. Find cumulative effect on each index
        vector<int> result(n, 0);
        int cumSum = 0;
        for(int i = 0; i < n; i++) {
            cumSum += diff[i];
            result[i] = cumSum;
        }

        for(int i = 0; i < n; i++) {
            if(result[i] < nums[i]) { //nums[i] won't become 0 ever
                return false;
            }
        }

        return true;
    }
};


/************************************************************ JAVA ************************************************/
//Approach - Straight Forward Difference Array Technique
//T.C : O(Q + n)
//S.C : O(Q + n)
class Solution {
    public boolean isZeroArray(int[] nums, int[][] queries) {
        int n = nums.length;

        // Step 1: Make difference array using queries
        int[] diff = new int[n];
        for (int[] query : queries) {
            int start = query[0];
            int end = query[1];
            int x = 1;

            diff[start] += x;
            if (end + 1 < n) {
                diff[end + 1] -= x;
            }
        }

        // Step 2: Compute cumulative effect on each index
        int[] result = new int[n];
        int cumSum = 0;
        for (int i = 0; i < n; i++) {
            cumSum += diff[i];
            result[i] = cumSum;
        }

        // Step 3: Check if each value can reach 0
        for (int i = 0; i < n; i++) {
            if (result[i] < nums[i]) {
                return false; // nums[i] won't become 0
            }
        }

        return true;
    }
}
