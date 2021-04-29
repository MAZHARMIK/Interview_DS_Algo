/*
    Company Tags  : Google (Modified version of this question : Video Call Round)
    Leetcode Link : https://leetcode.com/problems/meeting-scheduler/
    
    Since it's a premium question, hence the question is provided below :
    
    Description :
    Given the availability time slots arrays slots1 and slots2 of two people and a meeting duration duration,
    return the earliest time slot that works for both of them and is of duration duration

    If there is no common time slot that satisfies the requirements, return an empty array. The format of a time
    slot is an array of two elements [start, end] representing an inclusive time range from start to end. It is guaranteed
    that no two availability slots of the same person intersect with each other. That is, for any two time slots 
    [start1, end1] and [start2, end2] of the same person, either start1 > end2 or start2 > end1.

    Example 1: slots1 = {{10,50},{60, 120}, {148,210}}, slots2 = {{0,15},{60, 70}}, duration = 8

    Input: slots1 = Output: [68,68]

    Example 2:

    Input: slots1 = [[10,50],[60, 120], [148,210]], slots2 = [[0,15], [60,70]], duration = 12

    Output: []

*/

//Approach : We basically have to find the intersection and during which see if you can get an interval intersection of duration "duration"

class Solution {
public:
     vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
          //sort based on the starting time
          sort(slots1.begin(), slots1.end());
          sort(slots2.begin(), slots2.end());
          
          int m = slots1.size();
          int n = slots2.size();
          int i = 0, j = 0;
          
          while(i < m && j < n) {
              //find intersection
              int start = max(slots1[i][0], slots2[j][0]);
              int end   = min(slots1[i][1], slots2[j][1]);
              
              if(end-start >= duration) {
                  return {start, start+duration};
              } else {
                   if(slots1[i][1] == end)
                        i++;
                   if(slots2[j][1] == end)
                        j++;
              }
          }

          return {};
     }
};
