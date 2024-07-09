/*     Scroll below to see JAVA code also    */
/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=g7P8Zkq8P9Q
      Company Tags                : will update soon
      Leetcode Link               : https://leetcode.com/problems/average-waiting-time/description
*/


/********************************************************************** C++ ********************************************************/
//Simple Simulation
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();

        double totalWaitTime = 0;
        int currTime         = 0;

        for(auto &vec : customers) {
            int arrivalTime = vec[0];
            int cookTime   = vec[1];

            if(currTime < arrivalTime) {
                currTime = arrivalTime;
            }

            int waitTime = currTime + cookTime - arrivalTime;

            totalWaitTime += waitTime;

            currTime += cookTime;
        }

        return totalWaitTime/n;
    }
};



/********************************************************************** JAVA ********************************************************/
//Simple Simulation
//T.C : O(n)
//S.C : O(1)
class Solution {
    public double averageWaitingTime(int[][] customers) {
        int n = customers.length;

        double totalWaitTime = 0;
        int currTime = 0;

        for (int[] customer : customers) {
            int arrivalTime = customer[0];
            int cookTime = customer[1];

            if (currTime < arrivalTime) {
                currTime = arrivalTime;
            }

            int waitTime = currTime + cookTime - arrivalTime;

            totalWaitTime += waitTime;

            currTime += cookTime;
        }

        return totalWaitTime / n;
    }
}
