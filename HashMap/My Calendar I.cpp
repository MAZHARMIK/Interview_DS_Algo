/*
    Company Tags  : Google
    Leetcode Link : https://leetcode.com/problems/my-calendar-i/
    
    Note : Is you want an equivalent of TreeMap of Java in C++, use map or set
*/

//Approach-1 Brute Force (O(n^2))
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
class MyCalendar {
public:
    set<pair<int, int>> st;
    MyCalendar() {
        
    }
    
    
    bool book(int start, int end) {
        auto it = st.lower_bound({start, end}); //Find a start which is >= curr.start

        if(it != st.end() && end > it->first)
            return false;
        if(it != st.begin() && start < ((--it)->second))
            return false;
        
        st.insert({start, end});
        return true;
    }
};

//Approach-3 (Set : Upper bound)  : O(nlog(n))
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
