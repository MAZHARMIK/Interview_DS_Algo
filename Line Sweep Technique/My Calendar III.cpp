/*     Scroll below to see JAVA code as well    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=zcMYtmwQNMg
    Company Tags                : Google
    Leetcode Link               : https://leetcode.com/problems/my-calendar-ii/
*/


/******************************************************************************* C++ ************************************************************************************************/
//Approach (Using Line Sweep)
//T.C : O(n * logn), where n = number of events
//S.C : O(n) to store events in map
class Solution {
class MyCalendarThree {
public:
    map<int, int> events;
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        events[startTime] += 1;
        events[endTime] -= 1;

        int count = 0;
        int maxInt = 0;
        for(auto &it : events) {
            count += it.second;
            maxInt = max(maxInt, count);
        }

        return maxInt;
    }
};



/******************************************************************************* JAVA ************************************************************************************************/
//Approach (Using Line Sweep)
//T.C : O(n * logn), where n = number of events
//S.C : O(n) to store events in map
class MyCalendarThree {

    private TreeMap<Integer, Integer> events;

    public MyCalendarThree() {
        events = new TreeMap<>();
    }
    
    public int book(int startTime, int endTime) {
        events.put(startTime, events.getOrDefault(startTime, 0) + 1);
        events.put(endTime, events.getOrDefault(endTime, 0) - 1);

        int count = 0;
        int maxOverlap = 0;

        for (int delta : events.values()) {
            count += delta;
            maxOverlap = Math.max(maxOverlap, count);
        }

        return maxOverlap;
    }
}
