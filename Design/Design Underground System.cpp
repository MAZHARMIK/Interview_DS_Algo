/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=AdRVFQo0l7w
    Company Tags                : Amazon, Bloomberg (Most frequently asked)
    Leetcode Link               : https://leetcode.com/problems/design-underground-system/
*/

class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> checkIn_mp;  //id->{entryStationName, entryTime}
    unordered_map<string, pair<int, int>> checkOut_mp;    //route->{totalTime, count}
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkIn_mp[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto& it                  = checkIn_mp[id];
        int entryTime             = it.second;
        int timeTaken             = t-entryTime;
        string entryStation       = it.first;
        string route              = entryStation + "_" + stationName;
        checkOut_mp[route].first  += timeTaken;
        checkOut_mp[route].second += 1;
        checkIn_mp.erase(id); //to save space
    }
    
    double getAverageTime(string startStation, string endStation) {
        string route =  startStation + "_" + endStation;
        auto&it      = checkOut_mp[route];
        return (double)it.first/it.second;
    }
};
