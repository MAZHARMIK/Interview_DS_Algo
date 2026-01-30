/*     Scroll below to see JAVA code as well    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : ClearTrip, Goldman Sachs
    Leetcode Link               : https://leetcode.com/problems/my-calendar-ii/
*/


/******************************************************************************* C++ ************************************************************************************************/
//Approach-1 (Using Line Sweep)
//T.C : O(n)
//S.C : O(n) to store events in map
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int> events;

        for(auto &trip : trips) {
            int count = trip[0];
            int start = trip[1];
            int end   = trip[2];

            events[start] += count;
            events[end] -= count;
        }

        int passCount = 0;

        for(auto &it : events) {
            passCount += it.second;

            if(passCount > capacity)
                return false;
        }

        return true;
    }
};


//Approach-2 (Using Difference Array Technique)
//T.C : O(n)
//S.C : O(1001) ~= O(1)
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int diff[1001] = {0};

        for(auto &trip : trips) {
            int count = trip[0];
            int start = trip[1];
            int end   = trip[2];

            diff[start] += count;
            diff[end]   -= count;
        }

        int cumSum = 0;

        for(int i = 0; i < 1001; i++) {
            cumSum += diff[i];

            if(cumSum > capacity)
                return false;
        }

        return true;
    }
};



/******************************************************************************* JAVA ************************************************************************************************/
//Approach-1 (Using Line Sweep)
//T.C : O(n)
//S.C : O(n) to store events in map
class Solution {
    public boolean carPooling(int[][] trips, int capacity) {
        TreeMap<Integer, Integer> events = new TreeMap<>();

        for (int[] trip : trips) {
            int passengers = trip[0];
            int start = trip[1];
            int end = trip[2];

            events.put(start, events.getOrDefault(start, 0) + passengers);
            events.put(end,   events.getOrDefault(end, 0) - passengers);
        }

        int currentPassengers = 0;

        for (int change : events.values()) {
            currentPassengers += change;
            if (currentPassengers > capacity) {
                return false;
            }
        }

        return true;
    }
}



//Approach-2 (Using Difference Array Technique)
//T.C : O(n)
//S.C : O(1001) ~= O(1)
class Solution {
    public boolean carPooling(int[][] trips, int capacity) {
        int[] diff = new int[1001];

        for (int[] trip : trips) {
            int passengers = trip[0];
            int start = trip[1];
            int end = trip[2];

            diff[start] += passengers;
            diff[end]   -= passengers;
        }

        int currentPassengers = 0;

        for (int i = 0; i < 1001; i++) {
            currentPassengers += diff[i];
            if (currentPassengers > capacity) {
                return false;
            }
        }

        return true;
    }
}
