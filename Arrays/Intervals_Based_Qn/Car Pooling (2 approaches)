class Solution {
public:
    //Time  :  O(n)
    //space :  O(n)
    bool Method2(vector<vector<int>>& trips, int capacity) {
        vector<int> stamps(1001, 0);
        
        for(vector<int> vec:trips) {
            int people_count = vec[0];
            int start_time   = vec[1];
            int end_time     = vec[2];
            
            stamps[start_time] += people_count;
            stamps[end_time]   -= people_count;
            
        }
        
        int total_curr_people = 0;
        
        for(int people_count:stamps) {
            total_curr_people += people_count;
            
            if(total_curr_people > capacity)
                return false;
        }
        return true;
    }
    //Time  : O(nlogn)
    //Space : O(n)
    bool Method1(vector<vector<int>>& trips, int capacity) {
        vector<vector<int>> stamps;
        
        for(vector<int> vec:trips) {
            stamps.push_back({vec[1], 1, vec[0]});  //stamps = {start_time, pickup=1, # people}
            stamps.push_back({vec[2], 0, vec[0]});  //stamps = {end_time,   drop=0,   # people}
        }
        
        sort(stamps.begin(), stamps.end());
        
        int count = 0;
        
        for(vector<int> vec:stamps) {
            if(vec[1] == 1) {
                count += vec[2];
            } else {
                count -= vec[2];
            }
            
            if(count > capacity)
                return false;
        }
        return true;
    }
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        //return Method1(trips, capacity);
        
        return Method2(trips, capacity);
    }
};
