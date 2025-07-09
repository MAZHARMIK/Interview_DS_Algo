/*         Scroll below to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-ii/submissions/1691929382/
*/


/********************************************************************** C++ **********************************************************************/
//Approach (Greedily trying moving each event)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {

        vector<int> freeArray; //store durations of free gaps

        //ith event
        //ith start - (i-1)th ka end = free gap duration
        freeArray.push_back(startTime[0]);

        for(int i = 1; i < startTime.size(); i++) {
            freeArray.push_back(startTime[i] - endTime[i-1]);
        }

        freeArray.push_back(eventTime - endTime[endTime.size()-1]);

        // Step 2: Precompute the largest free time to the right of each index
        int n = freeArray.size();
        vector<int> maxRight(n, 0);
        for (int i = n - 2; i >= 0; i--) {
            maxRight[i] = max(maxRight[i + 1], freeArray[i + 1]);
        }

        // Step 3: Try moving each meeting and calculate max free time
        int result = 0, maxLeft = 0;
        for (int i = 1; i < n; ++i) {
            int duration = endTime[i - 1] - startTime[i - 1];  // Duration of the (i-1)th meeting

            //Move the meeting to another free spot
            //But, check if moving is possible or not
            if (duration <= max(maxLeft, maxRight[i])) {
                result = max(result, freeArray[i - 1] + duration + freeArray[i]);
            }

            // Case 2: Merge left and right free time (always possible)
            result = max(result, freeArray[i - 1] + freeArray[i]);

            // Update maxLeft for the next iteration
            maxLeft = max(maxLeft, freeArray[i - 1]);
        }

        return result;
    }
};



/********************************************************************** JAVA **********************************************************************/
//Approach (Greedily trying moving each event)
//T.C : O(n)
//S.C : O(n)
class Solution {
    public int maxFreeTime(int eventTime, int[] startTime, int[] endTime) {
        // Prepare freeArray to store free gaps
        int nEvents = startTime.length;
        int[] freeArray = new int[nEvents + 1];

        // 1st free gap: before the first event
        freeArray[0] = startTime[0];
        // gaps between events
        for (int i = 1; i < nEvents; i++) {
            freeArray[i] = startTime[i] - endTime[i - 1];
        }
        // gap after the last event
        freeArray[nEvents] = eventTime - endTime[nEvents - 1];

        int n = freeArray.length;
        int[] maxRight = new int[n];
        // Precompute max free time to the right
        maxRight[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            maxRight[i] = Math.max(maxRight[i + 1], freeArray[i + 1]);
        }

        int result = 0, maxLeft = 0;
        // Try moving each meeting and calculate max free time
        for (int i = 1; i < n; ++i) {
            int duration = endTime[i - 1] - startTime[i - 1];

            // Move the meeting to another free spot if possible
            if (duration <= Math.max(maxLeft, maxRight[i])) {
                result = Math.max(result, freeArray[i - 1] + duration + freeArray[i]);
            }

            // Merge left and right free time (always possible)
            result = Math.max(result, freeArray[i - 1] + freeArray[i]);

            // Update maxLeft for the next iteration
            maxLeft = Math.max(maxLeft, freeArray[i - 1]);
        }

        return result;
    }
}
