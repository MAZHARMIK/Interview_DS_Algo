/*         Scroll below to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
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
        vector<int> gapArray;

        gapArray.push_back(startTime[0]);

        for (int i = 1; i < startTime.size(); ++i) {
            gapArray.push_back(startTime[i] - endTime[i - 1]);
        }
        
        gapArray.push_back(eventTime - endTime.back());

        int maxSum = 0;
        int currSum = 0;
        int i = 0;
        int j = 0;
        int n = gapArray.size();
        while (j < n) {
            currSum += gapArray[j];

            while(i < n && j - i + 1 > k + 1) {
                currSum -= gapArray[i];
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
        int[] gapArray = new int[n + 1];
        
        // First gap: from time 0 to startTime <sup> </sup>
        gapArray[0] = startTime[0];
        
        // Gaps between consecutive events
        for (int i = 1; i < n; i++) {
            gapArray[i] = startTime[i] - endTime[i - 1];
        }
        
        // Last gap: from endTime[n-1] to eventTime
        gapArray[n] = eventTime - endTime[n - 1];
        
        int maxSum = 0;
        int currSum = 0;
        int left = 0;
        
        // Sliding window to find maximum sum of (k+1) gaps
        for (int right = 0; right < gapArray.length; right++) {
            currSum += gapArray[right];
            
            // Window size should be at most (k+1)
            while (right - left + 1 > k + 1) {
                currSum -= gapArray[left];
                left++;
            }
            
            maxSum = Math.max(maxSum, currSum);
        }
        
        return maxSum;
    }
}
