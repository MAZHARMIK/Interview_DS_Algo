/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=smTnSl6UKi0
    Company Tags                : Amazon
    Leetcode Link               : https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/
*/


//Approach - 1 (Recursion + Memoization)
class Solution {
public:
    int t[301][11];
    int solve(vector<int>& jd, int n, int idx, int d) {
        
        //if you have only 1 day, then you will all the remaining jobs
        //and select the max difficulty as the answer
        if(d == 1) {
            return *max_element(begin(jd)+idx, end(jd));
        }
        
        if(t[idx][d] != -1)
            return t[idx][d];
    
        
        int Max = INT_MIN;
        int result = INT_MAX;
        
        //Try one by one with all possibility
        /*
            Take 1 job in one day
            Take 2 jobs in one day
            Take 3 jobs in one day
            and so on
            
            Then find the optimal one among all the results
        */
        for(int i = idx; i<=n-d; i++) {
            Max = max(Max, jd[i]);
            
            result = min(result, Max + solve(jd, n, i+1, d-1));
        }
        
        return t[idx][d] = result;
    }
    
    int minDifficulty(vector<int>& jd, int d) {
        int n = jd.size();
        
        if(n < d)
            return -1;

        memset(t, -1, sizeof(t));
        
        return solve(jd, n, 0, d);
    }
};



//Approach - 2 (Bottom UP)
//soon
