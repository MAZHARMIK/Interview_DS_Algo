/*     Scroll below to see JAVA code as well    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Google
    Leetcode Link               : https://leetcode.com/problems/my-calendar-ii/
*/


/******************************************************************************* C++ ************************************************************************************************/
//Approach (Using Line Sweep)
//T.C : O(nlogn)
//S.C : O(n) to store events in map
class MyCalendarTwo {
public:
    map<int, int> events;
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        events[startTime]++;
        events[endTime]--;

        int count = 0;

        for(auto &it : events) {
            count += it.second;

            if(count > 2) {
                events[startTime]--;
                events[endTime]++;
                return false;
            }
        }

        return true;
    }
};




/******************************************************************************* JAVA ************************************************************************************************/
//Approach (Using Line Sweep)
//T.C : O(nlogn)
//S.C : O(n) to store events in map
class MyCalendarTwo {

    private TreeMap<Integer, Integer> events;

    public MyCalendarTwo() {
        events = new TreeMap<>();
    }
    
    public boolean book(int startTime, int endTime) {
        // Add this booking optimistically
        events.put(startTime, events.getOrDefault(startTime, 0) + 1);
        events.put(endTime, events.getOrDefault(endTime, 0) - 1);

        int count = 0;

        // Sweep through timeline
        for (int delta : events.values()) {
            count += delta;
            if (count > 2) {
                // Revert changes (since triple booking not allowed)
                events.put(startTime, events.get(startTime) - 1);
                if (events.get(startTime) == 0) {
                    events.remove(startTime);
                }

                events.put(endTime, events.get(endTime) + 1);
                if (events.get(endTime) == 0) {
                    events.remove(endTime);
                }

                return false;
            }
        }

        return true;
    }
}
