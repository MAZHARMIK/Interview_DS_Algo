/*
    MY YOUTUBE VIDEO ON THIS Qn : <soon>
    Company Tags                : GOOGLE
    Leetcode link               : https://leetcode.com/problems/minimum-cost-for-tickets/
*/
//Approach-1 (Recursion + Memoized)  [Time : O(max_day)] [Space : O(n)] //n = size of days vector
class Solution {
public:
    int t[366];
    int memoized(vector<int>& days, vector<int>& costs, int& n, int idx) {
        if(idx >= n)
            return 0; //you can't travel, so no cost
                
        if(t[idx] != -1)
            return t[idx];
        
        //if i take 1-day pass at idx
        int cost_1 = costs[0] + memoized(days, costs, n, idx+1);
        
        
        //if i take 7-day pass at idx
        int i          = idx;
        for(; i < n && days[i] < days[idx]+7; i++) {
            //why days[i] < days[idx]+7 and not (days[i] <= days[idx]+7)
            //Because j will get ncreased by one unnecessarily
            /*
                Example : [1, 4, 6, 7, 8]
                If you take 7 day pass on day 1 (idx = 0)
                You would want to stop at idx = 3 at day 7
                but, idx will get incremented one more if we use <=
            */
        }
        int cost_7 = costs[1] + memoized(days, costs, n, i);
        
        
        //if i take 30-day pass at idx
        int j      = idx;

        for(; j < n && days[j] < days[idx]+30; j++) {
        }
        
        int cost_30 = costs[2] + memoized(days, costs, n, j);
        
        
        return t[idx] = min({cost_1, cost_7, cost_30});
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(t, -1, sizeof(t));
        int n = days.size();
        return memoized(days, costs, n, 0);
    }
};

//Approach-2 (Bottom Up DP) [Time : O(max_day)] [Space : O(n)] //n = size of days vector
class Solution {
public:    
    int bottomUp(vector<int>& days, vector<int>& costs) {
        unordered_set<int> st(begin(days), end(days));
        int last_day = days.back();
        
        vector<int> t(last_day+1, 0);
        //t[i] = min cost to reach till day i of your travel plan
        t[0] = 0; //since, on day 0, we spend cost = 0
        
        for(int i = 1; i<=last_day; i++) {
            if(st.find(i) == st.end()) {
                t[i] = t[i-1]; //skip
                continue;
            }
            //you need to filter those days from 1 to 30 which are not in days vector
            t[i] = INT_MAX;
            
            //I come to i either by taking a 1-day pass from jth day
            int day_1_pass = t[max(0, i-1)] + costs[0];

            //I come to i either by taking a 7-day pass from jth day
            int day_7_pass = t[max(0,i-7)] + costs[1];

            //I come to i either by taking a 30-day pass from jth day
            int day_30_pass = t[max(0, i-30)] + costs[2];
            
            t[i] = min({day_1_pass, day_7_pass, day_30_pass});
        }
        
        return t[last_day]; //minimum cost to travel till my last planned day
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return bottomUp(days, costs);     
    }
};
