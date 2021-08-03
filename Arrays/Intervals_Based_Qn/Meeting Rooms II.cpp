/*
    Company Tags     : Uber, Facebook, Microsoft, Yelp, Google, Snapchat, Amazon, Cisco
    Leetcode Qn Link : https://leetcode.com/problems/meeting-rooms-ii/
    
    Since, this is a premium question, I am putting the description here as well
    Description:
    Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...]
    (si < ei), find the minimum number of conference rooms required.
    
    Example -
    Input: intervals = [(0,30),(5,10),(15,20)]
    Output: 2
    Explanation:
    We need two meeting rooms
    room1: (0,30)
    room2: (5,10),(15,20)
*/

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

//Approach-1 (Using heap)
class Solution {
public:
    static bool sortComp(Interval& i1, Interval& i2) {
        return i1.start < i2.start;
    }
    struct Compare {
        bool operator() (Interval& i1, Interval& i2) {
            //we want the meeting which ends earliest
            //i.e. ascending order of end_time
            return i1.end > i2.end;
        }
    };
    int minMeetingRooms(vector<Interval> &intervals) {
        int n = intervals.size();
        if(n <= 1)
            return n;
        //why sorting ?
        /*
            We want to handle meetings based on their starting time.
            It ensures that comparison done in priority_queue
            will be definitely correct.
            We won't have to worry about the starting time of
            meetings already running (i.e. meetings that are in priority_queue)
        */
        sort(begin(intervals), end(intervals), sortComp);

        priority_queue<Interval, vector<Interval>, Compare> pq;
        pq.push(intervals[0]); //minimum one room required

        for(int i = 1; i<n; i++) {
            /*if I have to organise a meeting, 
              I will look for the one which ends first
              So that if there is no clash, same room can be occupied
            */

            Interval top = pq.top();
            Interval curr = intervals[i];

            //clash
            if(top.end > curr.start) {
                pq.push(curr);
            } else {
                pq.pop(); //That meeting ends
                pq.push(curr); //I will use same room
            }
        }

        return (int) pq.size();
    }
};


//Approach-2 (Using cronological Order)
class Solution {
public:
    int minMeetingRooms(vector<Interval> &intervals) {
        int n = intervals.size();
        if(n <= 1)
            return n;
        
        vector<int> startTime(n);
        vector<int> endTime(n);
        
        int i = 0;
        for(const Interval& interval : intervals) {
        	startTime[i] = interval.start;
        	endTime[i]   = interval.end;
        	i++;
        }
        
        sort(begin(startTime), end(startTime));
        sort(begin(endTime),   end(endTime));
        
        i = 0;
        int j = 0;
        int count = 0;
        
        while(i < n) {
        	if(startTime[i] < endTime[j]) {
        		count++; //we need one more room
        	} else {
        		j++; //previous room can be used which is over
        	}
        	i++;
        }
        
        return count;
    }
};
