/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=x4cRwVEFwHc
    Company Tags                : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/minimum-cost-to-cut-a-stick/
*/

//Approach-1 (Recursion + Memoization) : O(m^3) --- m = size of cuts
/*
Why O(m^3) = The number of states in our DP is the number of possible combinations of (left, right), which is O(m^2). 
For each subproblem cost(left, right), we need to try all possible cutting positions between new_cuts[left] and new_cuts[right], 
resulting in an additional factor of m. Therefore, the overall time complexity is O(m^3).
*/

class Solution {
public:
    int t[103][103];
    int solve(vector<int>& cuts, int left, int right) {
        
        if(right - left == 1)
            return 0;
        
        if(t[left][right] != -1)
            return t[left][right];
        
        int result = INT_MAX;
        
        for(int index = left+1; index <= right-1; index++) {
            
            int cost = solve(cuts, left, index) + solve(cuts, index, right) + (cuts[right] - cuts[left]);
            
            result = min(result, cost);
            
        }
        
        return t[left][right] = result;
        
    }
    
    int minCost(int n, vector<int>& cuts) {
        sort(begin(cuts), end(cuts));
        
        cuts.insert(begin(cuts), 0);
        cuts.push_back(n);
        memset(t, -1, sizeof(t));
        return solve(cuts, 0, cuts.size()-1);
       
        
    }
};


//Approach-2 (Using Bottom Up)
//<soon>
