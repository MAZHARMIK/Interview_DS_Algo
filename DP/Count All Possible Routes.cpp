/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=qppd8vx0vK4
    Company Tags                : Zoho
    Leetcode Link               : https://leetcode.com/problems/count-all-possible-routes/
*/


//Approach-1 (Using Recursion + Memoization) - O(n * fuel * n)
class Solution {
public:
    const int MOD = 1e9+7;
    int n;
    int t[101][201];
    
    int solve(vector<int>& locations, int currCity, int finish, int fuel) {
        if (fuel < 0) {
            return 0;
        }

        if(t[currCity][fuel] != -1)
            return t[currCity][fuel];
        
        int ans = 0;
        
        if(currCity == finish)
            ans++;
        
        for (int nextCity = 0; nextCity < locations.size(); nextCity++) {
            
            if (nextCity != currCity) {
                int remaining_fuel = fuel - abs(locations[currCity] - locations[nextCity]);
                
                ans = (ans + solve(locations, nextCity, finish, remaining_fuel)) % MOD;
            }
        }

        return t[currCity][fuel] = ans;
    }

    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        n = locations.size();
        memset(t, -1, sizeof(t));
        return solve(locations, start, finish, fuel);
    }
};


//Approach-2 (Using Bottom Up) - Soon
