/*     Scroll below to see JAVA code as well    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Amazon, Uber, Meta
    Leetcode Link               : https://leetcode.com/problems/meeting-rooms-ii/   (Premium Locked)
    GfG Link                    : https://www.geeksforgeeks.org/problems/attend-all-meetings-ii/1
*/




/******************************************************************************* C++ ************************************************************************************************/
//Approach (Using Line Sweep)
//T.C : O(nlogn)
//S.C : O(n) to store events in map
class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        int n = start.size();
        
        map<int, int> events;
        for(int i = 0; i < n; i++) {
            int startPoint = start[i];
            int endPoint   = end[i];
            
            events[startPoint]++;
            events[endPoint]--;
        }
        
        int result = 0;
        int count = 0;
        
        for(auto& p : events){
            count   += p.second;
            result  = max(result, count);
        }
        return result;
    }
};



/******************************************************************************* JAVA ************************************************************************************************/
//Approach (Using Line Sweep)
//T.C : O(nlogn)
//S.C : O(n) to store events in map
class Solution {
    public int minMeetingRooms(int[] start, int[] end) {
        int n = start.length;

        // Ordered map: time -> change in active meetings
        TreeMap<Integer, Integer> events = new TreeMap<>();

        for (int i = 0; i < n; i++) {
            events.put(start[i], events.getOrDefault(start[i], 0) + 1);
            events.put(end[i],   events.getOrDefault(end[i],   0) - 1);
        }

        int overlaps = 0;
        int maxOverlaps = 0;

        for (int delta : events.values()) {
            overlaps += delta;
            maxOverlaps    = Math.max(maxOverlaps, overlaps);
        }

        return maxOverlaps;
    }
}
