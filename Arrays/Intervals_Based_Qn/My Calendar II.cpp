/*         Scroll below to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=vySZ_KfjiRU
    Company Tags                : Google
    Leetcode Link               : https://leetcode.com/problems/my-calendar-ii
*/


/**************************************************** C++ ****************************************************/
//Approach-1 : Simle and straight forward
//T.C : O(n)
//S.C : O(n)
class MyCalendarTwo {
public:
    vector<pair<int, int>> doubleOverlappedRegion;
    vector<pair<int, int>> overallBookings;

    bool checkOverlap(int start1, int end1, int start2, int end2) {
        return max(start1, start2) < min(end1, end2);
    }

    pair<int, int> findOverlappedRegion(int start1, int end1, int start2, int end2) {
        return {max(start1, start2), min(end1, end2)};
    }

    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        //check if tripple booking is being created or not
        for(pair<int, int> region : doubleOverlappedRegion) {
            if(checkOverlap(region.first, region.second, start, end)) {
                return false; //tripple booking created
            }
        }

        //check if it is creating double bookings
        for(pair<int, int> booking : overallBookings) {
            if(checkOverlap(booking.first, booking.second, start, end)) {
                doubleOverlappedRegion.push_back(findOverlappedRegion(booking.first, booking.second, start, end));
            }
        }

        overallBookings.push_back({start, end});
        return true;
    }
};



/**************************************************** JAVA ****************************************************/
//Approach-1 : Simle and straight forward
//T.C : O(n)
//S.C : O(n)
class MyCalendarTwo {

    private List<int[]> doubleOverlappedRegion;
    private List<int[]> overallBookings;

    // Constructor initializes the lists
    public MyCalendarTwo() {
        doubleOverlappedRegion = new ArrayList<>();
        overallBookings = new ArrayList<>();
    }

    // Method to check if two intervals overlap
    private boolean checkOverlap(int start1, int end1, int start2, int end2) {
        return Math.max(start1, start2) < Math.min(end1, end2);
    }

    // Method to find the overlapped region between two intervals
    private int[] findOverlappedRegion(int start1, int end1, int start2, int end2) {
        return new int[]{Math.max(start1, start2), Math.min(end1, end2)};
    }

    // Method to book a new event
    public boolean book(int start, int end) {
        // Check if a triple booking is being created or not
        for (int[] region : doubleOverlappedRegion) {
            if (checkOverlap(region[0], region[1], start, end)) {
                return false; // Triple booking created
            }
        }

        // Check if it is creating double bookings
        for (int[] booking : overallBookings) {
            if (checkOverlap(booking[0], booking[1], start, end)) {
                doubleOverlappedRegion.add(findOverlappedRegion(booking[0], booking[1], start, end));
            }
        }

        // Add the current booking to the overall bookings list
        overallBookings.add(new int[]{start, end});
        return true;
    }
}
