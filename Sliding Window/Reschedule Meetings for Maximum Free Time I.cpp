/*         Scroll below to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=JPWBTUyGCnM
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-i
*/


/********************************************************************** C++ **********************************************************************/
//Approach  (Sliding Window)
//T.C : O(n)
//S.C : O(k)
class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> freeArray; //store durations of free gaps

        //ith event
        //ith start - i-1th ka end = free gap duration
        freeArray.push_back(startTime[0]);

        for(int i = 1; i < startTime.size(); i++) {
            freeArray.push_back(startTime[i] - endTime[i-1]);
        }

        freeArray.push_back(eventTime - endTime[endTime.size()-1]);

        //Khandani sliding window

        int i = 0;
        int j = 0;
        int maxSum = 0;
        int currSum = 0;

        int n = freeArray.size();
        while(j < n) {
            currSum += freeArray[j];

            if(i < n && j-i+1 > k+1) {
                currSum -= freeArray[i];
                i++;
            }

            maxSum = max(maxSum, currSum);
            j++;
        }

        return maxSum;
    }
};




/********************************************************************** JAVA **********************************************************************/
//Approach  (Sliding Window)
//T.C : O(n)
//S.C : O(k)
class Solution {
    public int maxFreeTime(int eventTime, int k, int[] startTime, int[] endTime) {
        int n = startTime.length;
        int[] freeArray = new int[n + 1];
        
        // First gap: from time 0 to startTime <sup> </sup>
        freeArray[0] = startTime[0];
        
        // Gaps between consecutive events
        for (int i = 1; i < n; i++) {
            freeArray[i] = startTime[i] - endTime[i - 1];
        }
        
        // Last gap: from endTime[n-1] to eventTime
        freeArray[n] = eventTime - endTime[n - 1];
        
        int maxSum = 0;
        int currSum = 0;
        int left = 0;
        
        // Sliding window to find maximum sum of (k+1) gaps
        for (int right = 0; right < freeArray.length; right++) {
            currSum += freeArray[right];
            
            // Window size should be at most (k+1)
            while (right - left + 1 > k + 1) {
                currSum -= freeArray[left];
                left++;
            }
            
            maxSum = Math.max(maxSum, currSum);
        }
        
        return maxSum;
    }
}
