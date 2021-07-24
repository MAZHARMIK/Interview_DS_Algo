/*
    Company Tags  : Uber, Facebook, Amazon, Microsoft
    Leetcode Link : https://leetcode.com/problems/meeting-rooms/
    
    Since, It's a Premium question, I am providing the description here as well.
    Description :
    Given an array of meeting time intervals consisting of start and end times [s1, e1], [s2, e2], ... , determine if a person could attend all meetings.

    For example:
    Given [ [0, 30], [5, 10], [15, 20] ],
    return false.
    
    Time Complexity : O(nlogn) due to sorting
*/

//Approach-1
class Solution {
public:
     static bool myFunction(Interval& i1, Interval& i2) {
        return i1.start < i2.start;
        //sorting on the basis of end time also works
     }
    bool canAttendMeetings(vector<Interval> &intervals) {
        if(intervals.size() == 0)
            return true;
        sort(intervals.begin(), intervals.end(), myFunction);
        
        Interval prevInterval = intervals[0];
        for(int i = 1; i<intervals.size(); i++) {
            int currInterval_start = intervals[i].start;
            if(currInterval_start < prevInterval.end) {
                return false;
            } else {
                prevInterval = intervals[i];
            }
        }
        return true;
    }
};


//Approach-2 (Simplification)
/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval> &intervals) {
        auto lambda = [&](Interval& i1, Interval& i2) {
            return i1.start < i2.start;
        };

        sort(begin(intervals), end(intervals), lambda);
        int n = intervals.size();

        for(int i = 0; i<n-1; i++) {
            Interval curr  = intervals[i];
            Interval next  = intervals[i+1];
            
            if(curr.end <= next.start) {
                continue;
            }
            
            if(curr.end > next.start) {
                return false;
            }
        }
        return true;

    }
};
