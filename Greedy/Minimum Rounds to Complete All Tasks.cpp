/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=IIalYnjpAJA
    Company Tags                : <soon>
    Leetcode Link               : https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/
*/

//Greedy
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> mp;
        
        for(int &x : tasks) {
            mp[x]++;
        }
        
        int round = 0;
        
        for(auto &it : mp) {
            int count = it.second;
            
            if(count == 1)
                return -1;
            
            if(count % 3 == 0)
                round += count/3;
            else
                round += count/3+1;
        }
        
        return round;
    }
};


