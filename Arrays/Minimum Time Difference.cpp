/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=ftCheG0m85k
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/minimum-time-difference/?envType=daily-question&envId=2024-09-16
*/


/************************************************************ C++ ************************************************/
//Approach-(Simple and straight forward convert to minutes and sort)
//T.C : O(nlogn)
//S.C : O(n)
//NOTE - You can use Bucket sort because input (miniutes) will always be between [0, 1439]
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int> minutes(n);

        for(int i = 0; i < n; i++) {
            string time = timePoints[i];

            string hourSubstr = time.substr(0, 2); //"HH"
            string minSubstr = time.substr(3); //"MM"

            int hourInt = stoi(hourSubstr);
            int minInt  = stoi(minSubstr);

            minutes[i] = hourInt*60 + minInt;
        }

        sort(begin(minutes), end(minutes));

        int result = INT_MAX;
        for(int i = 1; i < n; i++) {
            result = min(result, minutes[i] - minutes[i-1]);
        }

        return min(result, (24*60 - minutes[n-1]) + minutes[0]);
    }
};



/************************************************************ JAVA ************************************************/
//Approach-(Simple and straight forward convert to minutes and sort)
//T.C : O(nlogn)
//S.C : O(n)
//NOTE - You can use Bucket sort because input (miniutes) will always be between [0, 1439]
class Solution {
    public int findMinDifference(List<String> timePoints) {
        int n = timePoints.size();
        int[] minutes = new int[n];

        // Convert timePoints to minutes
        for (int i = 0; i < n; i++) {
            String time = timePoints.get(i);
            String[] parts = time.split(":");

            int hours = Integer.parseInt(parts[0]);
            int mins = Integer.parseInt(parts[1]);

            minutes[i] = hours * 60 + mins;
        }

        // Sort the minutes array
        Arrays.sort(minutes);

        // Initialize result with the maximum possible value
        int result = Integer.MAX_VALUE;

        // Find the minimum difference between adjacent times
        for (int i = 1; i < n; i++) {
            result = Math.min(result, minutes[i] - minutes[i - 1]);
        }

        // Check the circular case (between the first and last times)
        result = Math.min(result, (24 * 60 - minutes[n - 1]) + minutes[0]);

        return result;
    }
}
