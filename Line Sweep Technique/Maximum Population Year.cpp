/*     Scroll below to see JAVA code as well    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=hpbYXxKk-Sg
    Company Tags                : Atlassian, Goldman Sachs, Wayfair, Oracle, Agoda, TripAdvisor, Morgan Stanley, Adobe, Amazon
    Leetcode Link               : https://leetcode.com/problems/maximum-population-year
*/




/******************************************************************************* C++ ************************************************************************************************/
//Approach-1 (Using Difference Array Technique)
//T.C : O(n)
//S.C : O(max year), we took diff array
class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        // Years range from 1950 to 2050
        vector<int> diff(2051, 0);

        //Apply Difference Array Technique
        for (auto &log : logs) {
            int birth = log[0];
            int death = log[1];
            diff[birth] += 1;
            diff[death] -= 1; // not alive in death year
        }

        int maxPop = 0;
        int currPop = 0;
        int result = 1950;

        // Sweep through years
        for (int year = 1950; year <= 2050; year++) {
            currPop += diff[year];
            if (currPop > maxPop) {
                maxPop = currPop;
                result = year;
            }
        }

        return result;
    }
};



//Approach-2 (Using Line Sweep)
//T.C : O(n)
//S.C : O(max year), we took diff array
class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<pair<int,int>> events;

        for (auto &log : logs) {
            events.push_back({log[0], +1}); // birth
            events.push_back({log[1], -1}); // death
        }

        //Sort events
        sort(events.begin(), events.end());

        int curr = 0, maxPop = 0, result = 0;

        for (auto &e : events) {
            curr += e.second;
            if (curr > maxPop) {
                maxPop = curr;
                result = e.first;
            }
        }

        return result;
    }
};




/******************************************************************************* JAVA ************************************************************************************************/
// Approach-1 (Using Difference Array Technique)
// T.C : O(n)
// S.C : O(max year)
class Solution {
    public int maximumPopulation(int[][] logs) {
        int[] diff = new int[2051]; // years: 1950 to 2050

        // Apply difference array
        for (int[] log : logs) {
            int birth = log[0];
            int death = log[1];
            diff[birth] += 1;
            diff[death] -= 1; // not alive in death year
        }

        int currPop = 0;
        int maxPop = 0;
        int result = 1950;

        // Sweep through years
        for (int year = 1950; year <= 2050; year++) {
            currPop += diff[year];
            if (currPop > maxPop) {
                maxPop = currPop;
                result = year;
            }
        }

        return result;
    }
}



// Approach-2 (Using Line Sweep)
// T.C : O(n log n)
// S.C : O(n)
class Solution {
    public int maximumPopulation(int[][] logs) {
        List<int[]> events = new ArrayList<>();

        for (int[] log : logs) {
            events.add(new int[]{log[0], +1}); // birth
            events.add(new int[]{log[1], -1}); // death
        }

        // Sort by year
        // If same year: death (-1) BEFORE birth (+1)
        Collections.sort(events, (a, b) -> {
            if (a[0] == b[0])
                return a[1] - b[1]; // -1 first
            return a[0] - b[0];
        });

        int curr = 0;
        int maxPop = 0;
        int result = 0;

        for (int[] e : events) {
            curr += e[1];
            if (curr > maxPop) {
                maxPop = curr;
                result = e[0];
            }
        }

        return result;
    }
}
