/*
    Company Tags  : Let me know if you get it. It's an important conceptual question
    Leetcode Link : https://leetcode.com/problems/two-city-scheduling/
*/

//Approach-1 (Greedy)
class Solution {
public:    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        
        /*
            [10,20]   : If we choose A over B : We make profit : 20-10  = 10
            [30,200]  : If we choose A over B : We make profit : 200-30 = 170
            //A finished
            [400,50]  : If we choose B over A : We make profit : 400-50  = 350
            [30,20]   : If we choose B over A : We make profit : 30-20   = 10
            
            We want maximum profit for ourselves
            So, sort in a way that you get max profit
            Then take first half to A
            another half to B
        */
        
        auto lambda = [&](vector<int>& v1, vector<int>& v2) {
            int profit_1 = v1[1] - v1[0];
            int profit_2 = v2[1] - v2[0];
            
            return profit_1>profit_2;
        };
        
        sort(begin(costs), end(costs), lambda);
        
        int cost = 0;
        for(int i = 0; i<n/2; i++) {
            cost += costs[i][0];
        }
        
        for(int i = n/2; i<n; i++) {
            cost += costs[i][1];
        }
        
        return cost;
    }
};

//Approach-2 (Recursion + Memoization)
class Solution {
public:
    int t[51][51];
    int solve_recurMemo(vector<vector<int>>& costs, int A, int B, int n) {
        if(A+B >= n) //At any time index = A+B
            return 0;
        
        if(t[A][B] != -1)
            return t[A][B];
        
        int min_cost = INT_MAX;
        
        if(A < n/2) {
            min_cost = solve_recurMemo(costs, A+1, B, n) + costs[A+B][0];
        }
        if(B < n/2) {
            min_cost = min(min_cost, solve_recurMemo(costs, A, B+1, n) + costs[A+B][1]);
        }

        return t[A][B] = min_cost;
        
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int cost = 0;
        int n = costs.size();
        int A = 0;
        int B = 0;
        memset(t, -1, sizeof(t));
        return solve_recurMemo(costs, 0, 0, n);
    }
};

//Approach-3 (Bottom Up DP)
class Solution {
public:   
    int solve_BottomUp(vector<vector<int>>& costs, int &n) {
        int half = n/2;
        vector<vector<int>> t(half+1, vector<int>(half+1));
        //t[i][j] = min cost for (i+j) people with i people in cityA and j people in cityB
        t[0][0] = 0; //obviously
        
        //cost when i people go to city A and 0 people go to city B (all cost come from aCosti)
        for (int i = 1; i <= half; i++)
            t[i][0] = t[i - 1][0] + costs[i - 1][0];
        
        //cost when j people go to city B and 0 people go to city A (all cost come from bCosti)
        for (int j = 1; j <= half; j++)
            t[0][j] = t[0][j - 1] + costs[j - 1][1];
        
        for(int i = 1; i<half+1; i++) {
            for(int j = 1; j<half+1; j++) {
                int choose_A = costs[i+j-1][0] + t[i-1][j]; //equivalent to : costs[A+B][0] + solve(costs, A+1, B, n);
                int choose_B = costs[i+j-1][1] + t[i][j-1]; //equivalent to : costs[A+B][1] + solve(costs, A, B+1, n);
                t[i][j] = min(choose_A, choose_B);
            }
        }
        
        return t[half][half]; //minimum cost when n/2 people goes to 
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        return solve_BottomUp(costs, n);
    }
};
