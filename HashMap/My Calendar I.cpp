/*         Scroll below to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Google
    Leetcode Link               : https://leetcode.com/problems/my-calendar-i/
    
    Note : If you want an equivalent of TreeMap of Java in C++, use map or set
*/


/**************************************************** C++ ****************************************************/
//Approach-1 : Brute Force 
//T.C : O(n^2)
//S.C : O(n)
typedef pair<int, int> P;
class MyCalendar {
public:
    
    vector<P> calendar;
    MyCalendar() {

    }
    
    bool book(int start, int end) {
        for(int i = 0; i<calendar.size(); i++) {
            P curr = calendar[i];
            if(!(end <= curr.first || start >= curr.second))
                return false;
        }
        
        calendar.push_back({start, end});
        return true;
    }
};

//Approach - 2 (set : lower_bound) : O(nlog(n))
//T.C : O(nlogn)
//S.C : O(n)
class MyCalendar {
public:
    set<pair<int, int>> st;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        //Find the first event that starts after or st the same time of {start, end}
        auto it = st.lower_bound({start, end}); //Log(N)

        //Check if the current event overlaps with the next event
        if(it != st.end() && it->first < end) {
            return false;
        }

        //Check if the current event overlaps with the previous event
        if(it != st.begin()) {
            auto prevIt = prev(it);
            if(start < prevIt->second) {
                return false;
            }
        }

        st.insert({start, end});
        return true;
    }
};

//Approach-3 (Set : Upper bound)
//T.C : O(nlogn)
//S.C : O(n)
class MyCalendar {
public:
    set<pair<int, int>> st;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it = st.upper_bound({start, end});

        if(it != st.end() && end > it->second) {

            return false;
            
        }
        
        st.insert({end, start});
        return true;
    }
};

//Note : Replace set with map above, it will work as well


/**************************************************** C++ ****************************************************/
//Approach-1 : Brute Force 
//T.C : O(n^2)
//S.C : O(n)
class MyCalendar {

    // List to store the booked intervals
    List<int[]> calendar;

    public MyCalendar() {
        // Initialize the list
        calendar = new ArrayList<>();
    }

    public boolean book(int start, int end) {
        // Check for overlap with every existing booking
        for (int[] curr : calendar) {
            // If there is overlap, return false
            if (!(end <= curr[0] || start >= curr[1])) {
                return false;
            }
        }

        // If no overlap, add the booking to the calendar
        calendar.add(new int[]{start, end});
        return true;
    }
}


//Approach - 2 (set : lower_bound) : O(nlog(n))
//T.C : O(nlogn)
//S.C : O(n)
class MyCalendar {

    // TreeSet to store the booked intervals
    TreeSet<int[]> st;

    public MyCalendar() {
        // Initialize the TreeSet with a custom comparator
        st = new TreeSet<>((a, b) -> a[0] != b[0] ? a[0] - b[0] : a[1] - b[1]);
    }

    public boolean book(int start, int end) {
        // Find the first event that starts after or at the same time of {start, end}
        int[] event = new int[]{start, end};
        int[] next = st.ceiling(event); // O(logN)

        // Check if the current event overlaps with the next event
        if (next != null && next[0] < end) {
            return false;
        }

        // Check if the current event overlaps with the previous event
        int[] prev = st.floor(event);
        if (prev != null && start < prev[1]) {
            return false;
        }

        // If no overlap, add the booking to the set
        st.add(new int[]{start, end});
        return true;
    }
}

//Approach-3 (Set : Upper bound)
//T.C : O(nlogn)
//S.C : O(n)
class MyCalendar {

    // TreeSet to store the booked intervals
    TreeSet<int[]> st;

    public MyCalendar() {
        // Initialize the TreeSet with a custom comparator
        st = new TreeSet<>((a, b) -> a[1] != b[1] ? a[1] - b[1] : a[0] - b[0]);
    }

    public boolean book(int start, int end) {
        // Find the first event where the end time is greater than or equal to start
        int[] event = new int[]{end, start};
        int[] next = st.ceiling(event); // O(logN)

        // Check if the next event overlaps
        if (next != null && next[1] < end) {
            return false;
        }

        // If no overlap, add the booking to the set
        st.add(new int[]{end, start});
        return true;
    }
}
