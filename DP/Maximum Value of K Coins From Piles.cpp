/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=sH276uTmZ80
      Company Tags                : META
      Leetcode Link               : https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/
*/

//Approach-1 (Recursion + Memoization) - Time : O(k*n)
class Solution {
public:
    
    int n;
    int t[1001][2001];
    int solve(int i, vector<vector<int>>& piles, int k) {
        
        if(i >= n)
            return 0;
        
        if(t[i][k] != -1)
            return t[i][k];
        
        
        int not_taken = solve(i+1, piles, k);
        
        int taken = 0;
        
        //Taking - all possible configurations (1, 2, ... k)
        int sum = 0;
        for(int j = 0; j < min((int)piles[i].size(), k); j++) {
            
            sum += piles[i][j];
            
            if(k - (j+1) >= 0) {
                taken = max(taken, sum + solve(i+1, piles, k-(j+1)));
            }
            
        }
        
        return t[i][k] = max(taken, not_taken);
        
    }
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        
        n = piles.size();
        
        memset(t, -1, sizeof(t));
        
        return solve(0, piles, k);
        
    }
};


//Approach-2 (Using Bottomm Up) : Time : O(k*n), where s = total coins
class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        
        vector<vector<int>> t(n + 1, vector<int>(k + 1));
        
        for(int i = 1; i<= n; i++) {
            
            for(int coins = 0; coins <= k; coins++) {
                
                int sum = 0;
                for(int currCoins = 0; currCoins <= min((int)piles[i - 1].size(), coins); currCoins++) {
                    
                    if(currCoins > 0)
                        sum += piles[i-1][currCoins-1];
                    
                    t[i][coins] = max(t[i][coins], sum + t[i-1][coins - currCoins]);
                    
                }
                
                
            }
            
        }
        
        return t[n][k];
        
    }
};
