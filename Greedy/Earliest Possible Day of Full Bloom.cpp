/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=kqOVhPfrP_I
    Company Tags                : Google, Amazon, Microsoft, Adobe
    Leetcode Link               : https://leetcode.com/problems/earliest-possible-day-of-full-bloom/
*/

class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        
        vector<pair<int, int>> vec(n); //{plantTime[i], growTime[i]}
        
        for(int i = 0; i<n; i++) {
            vec[i] = {plantTime[i], growTime[i]};
        }
        
         // sort the grow_plant_times of seeds by their growTime in descending order. 
        // It makes sense to plant the seed with maximum growTime first
      
        //sort according to grow time (in descending order)
        auto lambda = [](pair<int, int>& P1, pair<int, int>& P2) {
            return P1.second > P2.second;
        };
        
        sort(vec.begin(), vec.end(), lambda);
        
        
        // a seed is planted only after the seeds having greater bloom time than the current seed are planted. 
        // So essentially, the plant time of a seed is the sum of plant times of all the seeds preceeding this seed 
        // and the plant time of the seed itself
        // we store the plant time of preceeding seeds in the following variable, prevPlantDays
      
        
        int prevPlantDays = 0;
         
        int maxBloomDays  = 0;
        for(int i = 0; i<n; i++) {
            int currPlantTime = vec[i].first;
            int currGrowTime  = vec[i].second;
            
            // adding the plant time of ith seed to the plant times of preceeding seeds 
            // it would take prev_plant_time amount of time to actually plant the ith seed
            prevPlantDays += currPlantTime;
             
          
            // bloom time of ith seed = total plant time of ith seed + grow time of ith seed + 1 
            // (as the flower blooms after last day of it's growth)
            int currPlantBloomTime = prevPlantDays + currGrowTime;
            
            maxBloomDays = max(maxBloomDays, currPlantBloomTime);
        }
        
        return maxBloomDays;
        
    }
};
