/*     Scroll below to see JAVA code as well    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=17sXcR5zGSs
    Company Tags                : Goldman Sachs
    Leetcode Link               : https://leetcode.com/problems/corporate-flight-bookings
*/


/******************************************************************************* C++ ************************************************************************************************/
//Approach (Using Line Sweep/Difference Array Technique)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n+2, 0);

        for(auto &b : bookings) {
            int start = b[0];
            int end = b[1];
            int count = b[2];

            diff[start] += count;
            diff[end+1] -= count;
        }

        //Cumulative sum
        vector<int> result;
        int cumSum = 0;
        for(int i = 1; i <= n; i++) {
            cumSum += diff[i];
            result.push_back(cumSum);
        }

        return result;
    }
};




/******************************************************************************* JAVA ************************************************************************************************/
//Approach (Using Line Sweep/Difference Array Technique)
//T.C : O(n)
//S.C : O(n)
class Solution {
    public int[] corpFlightBookings(int[][] bookings, int n) {
        
        int[] diff = new int[n + 2];
        
        for (int[] b : bookings) {
            int start = b[0];
            int end = b[1];
            int count = b[2];
            
            diff[start] += count;
            diff[end + 1] -= count;
        }
        
        // Prefix sum to build result
        int[] result = new int[n];
        int cumSum = 0;
        
        for (int i = 1; i <= n; i++) {
            cumSum += diff[i];
            result[i - 1] = cumSum;  // shift because result is 0-based
        }
        
        return result;
    }
}
