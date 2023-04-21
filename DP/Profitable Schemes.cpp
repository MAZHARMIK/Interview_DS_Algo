/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=ay3MHrS7YbQ
    Company Tags                : AMAZON
    Leetcode Link               : https://leetcode.com/problems/profitable-schemes/
*/

//Approach-1 (Recursion + Memo)
class Solution {
public:
    int t[101][101][101];

    int thresholdProfit;
    int N;
    const int MOD = 1e9+7;
    
    int solve(int i, int p, int people, vector<int>& group, vector<int>& profit) {
        if(people > N)
            return 0;
        
        if(i == group.size()) {
            if(p >= thresholdProfit)
                return t[i][p][people] = 1;
            return t[i][p][people] = 0;
        }
        
        if(t[i][p][people] != -1)
            return t[i][p][people];
        
        long long not_taken = solve(i+1, p, people, group, profit)%MOD;
        
        long long taken = solve(i+1, min(thresholdProfit, p+profit[i]), people+group[i], group, profit)%MOD;
        
        return t[i][p][people] = (taken%MOD + not_taken%MOD)%MOD;
        
    }
    
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(t, -1, sizeof(t));
        N = n;
        thresholdProfit = minProfit;
        return solve(0, 0, 0, group, profit);
        
    }
};


//Approach-2 (Bottom Up)
//<soon>
