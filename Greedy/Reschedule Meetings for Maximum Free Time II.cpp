/*         Scroll below to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=nRQwEyJBW-I
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-ii
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
        //ith start - i-1th ka end = free gap duration
        freeArray.push_back(startTime[0]);

        for(int i = 1; i < startTime.size(); i++) {
            freeArray.push_back(startTime[i] - endTime[i-1]);
        }

        freeArray.push_back(eventTime - endTime[endTime.size()-1]);

        int n = freeArray.size();
        vector<int> maxRightFree(n, 0);
        vector<int> maxLeftFree(n, 0);
        for(int i = n-2; i >= 0; i--) {
            maxRightFree[i] = max(maxRightFree[i+1], freeArray[i+1]);
        }

        for(int i = 1; i < n; i++) {
            maxLeftFree[i] = max(maxLeftFree[i-1], freeArray[i-1]);
        }


        int result = 0;
        //Iterating on the freeArray
        for(int i = 1; i < n; i++) {
            int currEventTime = endTime[i-1] - startTime[i-1]; //duration of event = d

            //Case-1 Moving completely out
            if(currEventTime <= max(maxLeftFree[i-1], maxRightFree[i])) {
                result = max(result, freeArray[i-1] + currEventTime + freeArray[i]);
            }

            //case-2 shift left or right
            result = max(result, freeArray[i-1] + freeArray[i]);
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
        // Step 1: Compute freeArray (gaps between events)
        int n = startTime.length;
        int[] freeArray = new int[n + 1];
        freeArray[0] = startTime[0];
        for (int i = 1; i < n; i++) {
            freeArray[i] = startTime[i] - endTime[i - 1];
        }
        freeArray[n] = eventTime - endTime[n - 1];

        int m = freeArray.length;
        int[] maxRightFree = new int[m];
        int[] maxLeftFree = new int[m];

        // Step 2: Precompute max free to the right
        for (int i = m - 2; i >= 0; i--) {
            maxRightFree[i] = Math.max(maxRightFree[i + 1], freeArray[i + 1]);
        }
        // Step 3: Precompute max free to the left
        for (int i = 1; i < m; i++) {
            maxLeftFree[i] = Math.max(maxLeftFree[i - 1], freeArray[i - 1]);
        }

        int result = 0;
        // Step 4: Iterate for each possible movement/shift
        for (int i = 1; i < m; i++) {
            int currEventTime = endTime[i - 1] - startTime[i - 1];

            // Case 1: Move completely out
            if (currEventTime <= Math.max(maxLeftFree[i - 1], maxRightFree[i])) {
                result = Math.max(result, freeArray[i - 1] + currEventTime + freeArray[i]);
            }

            // Case 2: Shift left or right
            result = Math.max(result, freeArray[i - 1] + freeArray[i]);
        }

        return result;
    }
}
