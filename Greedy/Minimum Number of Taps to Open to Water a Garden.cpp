/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=2hzsf3D9Xvw
      Company Tags                : Atlassian, Adobe, Twitter
      Leetcode Link               : https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/
*/

//Approach-1 (Using Greedy approach similar to Jump Game-II)
//TC : O(n)
//SC : O(1)
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> startEnd(n+1, 0);
        
        for(int i = 0; i<ranges.size(); i++) {
            
            int start = max(0, i - ranges[i]);
            int end   = min(n, i + ranges[i]);
            
            startEnd[start] = max(startEnd[start], end);
            
        }
        
        int taps     = 0;
        int currEnd  = 0;
        int maxEnd   = 0;
        
        for(int i = 0; i<n+1; i++) {
            
            if(i > maxEnd)
                return -1;
            
            if(i > currEnd) {
                taps++;
                currEnd = maxEnd;
            }
            
            maxEnd = max(maxEnd, startEnd[i]);
            
        }
        
        return taps;    
    }
};
