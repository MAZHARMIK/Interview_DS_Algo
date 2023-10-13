/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=_59HE5lVuLg
    Company Tags  		: Amazon
    Leetcode Link 		: https://leetcode.com/problems/min-cost-climbing-stairs/
*/

//Approach-0 (Apply recursion)
/*At every stair, you take 2 decision : Time (O(2^n))*/
class Solution {
public:
    int solve(vector<int>& cost, int idx) {
        if(idx >= cost.size())
            return 0; //when you reach top, you don't have to pay anything

        int move_one = cost[idx] + solve(cost, idx+1);
        int move_two = cost[idx] + solve(cost, idx+2);
        
        return min(move_one, move_two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        return min(solve(cost, 0), solve(cost, 1));
    }
};

//Approach-1 (Recursion + Memo) Time : O(n)
class Solution {
public:
    int t[1001];
    int solve(vector<int>& cost, int idx) {
        if(idx >= cost.size())
            return 0;
        if(t[idx] != -1)
            return t[idx];
			
        int move_one = cost[idx] + solve(cost, idx+1);
        int move_two = cost[idx] + solve(cost, idx+2);
        
        return t[idx] = min(move_one, move_two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        memset(t, -1, sizeof(t));
        return min(solve(cost, 0), solve(cost, 1));
    }
};

//Approach-2 (Bottom Up DP) Time (O(n))
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n == 2)
            return min(cost[0], cost[1]);

        //You can alos take a different vector to store result. I have modified same vector.
        for(int i = 2; i<n; i++) {

            cost[i] = cost[i] + min(cost[i-1], cost[i-2]);

        }

        return min(cost[n-1], cost[n-2]);

        
    }
};

//Approach-3 (Avoiding O(n) extra space from Approach-2)
//Since, t[i] only depends on its two previsous results (t[i-1], t[i-2])
//So, store previsous results in two variables
class Solution {
public:
    int solve(vector<int>& cost, int n) {
        if(n == 2)
            return min(cost[0], cost[1]);
        
        int t0 = cost[0];
        int t1 = cost[1];
        
        for(int i = 2; i<n; i++) {
            int temp = cost[i] + min(t0, t1);
            
            t0 = t1;
            t1 = temp;
        }
        
        return min(t0, t1);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        return solve(cost, n);
    }
};
