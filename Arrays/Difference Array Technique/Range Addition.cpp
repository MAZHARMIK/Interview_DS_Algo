/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=ZHNVmtm08WY
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/range-addition/description/
    
    NOTE : This is a premium problem on Leetcode and hence might not be accessible, so find the problem statement below :
    
    Assume you have an array of length n initialized with all 0's and are given k update operations.
    Each operation is represented as a triplet: [startIndex, endIndex, inc] which increments each element of
    subarray A[startIndex ... endIndex] (startIndex and endIndex inclusive) with inc.
    Return the modified array after all k operations were executed.

    Example : 
    Input: length = 5, updates = [[1,3,2],[2,4,3],[0,2,-2]]
    Output: [-2,0,3,5,3]
*/


/************************************************************ C++ ************************************************/
//Approach (Using Difference Array Technique)
//T.C : O(m+n), m = length of queries, n = length of array
//S.C : O(n)
class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> diff(length, 0);  // Initialize the difference array

        // Step 1: Apply updates using the difference array
        for (const auto& update : updates) {
            int start = update[0];
            int end   = update[1];
            int x     = update[2];

            diff[start] += x;      // Add increment at startIndex
            if (end + 1 < length) {
                diff[end + 1] -= x; // Subtract increment after endIndex
            }
        }

        // Step 2: Compute the final array from the difference array
        vector<int> result(length, 0);
        //Or you can, use this diff array itself to return after finding the cumulative sum of it
        int cumSum = 0;
        for (int i = 0; i < length; ++i) {
            cumSum += diff[i];
            result[i] = cumSum;
        }

        return result;
    }
};



/************************************************************ JAVA ************************************************/
//Approach (Using Difference Array Technique)
//T.C : O(m+n), m = length of queries, n = length of array
//S.C : O(n)
class Solution {
    public int[] getModifiedArray(int length, int[][] updates) {
        int[] diff = new int[length]; // Initialize the difference array

        // Step 1: Apply updates using the difference array
        for (int[] update : updates) {
            int start = update[0];
            int end = update[1];
            int x = update[2];

            diff[start] += x; // Add increment at startIndex
            if (end + 1 < length) {
                diff[end + 1] -= x; // Subtract increment after endIndex
            }
        }

        // Step 2: Compute the final array from the difference array
        int[] result = new int[length];
        int cumSum = 0;
        for (int i = 0; i < length; i++) {
            cumSum += diff[i];
            result[i] = cumSum;
        }

        return result;
    }
}
