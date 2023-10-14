/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=FkJ2_hr6DRo
    Company Tags                : GOOGLE
    Letcode Link                : https://leetcode.com/problems/painting-the-walls/
*/


/********************************************* C++ *********************************************/
//Approach-1 (Recursion + Memo)
//T.C : O(n^2) - we will visit at max n^2 states
class Solution {
public:
    int n;
    int t[501][501];
    
    int solve(int idx, int remaining, vector<int>& cost, vector<int>& time) {
        
        if(remaining <= 0)
            return 0;
        
        if(idx == n) {
            return 1e9;
        }
        
        if(t[idx][remaining] != -1) {
            return t[idx][remaining];
        }
        
        int paint_i     = cost[idx] + solve(idx+1, remaining - 1 - time[idx], cost, time);
        int not_paint_i = solve(idx+1, remaining, cost, time);
        
        
        return t[idx][remaining] = min(paint_i, not_paint_i);
        
    }
    
    int paintWalls(vector<int>& cost, vector<int>& time) {
        n = cost.size();
        
        memset(t, -1, sizeof(t));
        
        return solve(0, n, cost, time);
        
        
    }
};


//Approach-2 (Bottom Up)
//Sooooon coming with youtube video


/********************************************* JAVA *********************************************/
//Approach-1 (Recursion + Memo)
//T.C : O(n^2) - we will visit at max n^2 states
public class Solution {
    int n;
    int[][] t;

    public int solve(int idx, int remaining, int[] cost, int[] time) {

        if (remaining <= 0)
            return 0;

        if (idx == n) {
            return 1000000000;
        }

        if (t[idx][remaining] != -1) {
            return t[idx][remaining];
        }

        int paint_i = cost[idx] + solve(idx + 1, remaining - 1 - time[idx], cost, time);
        int not_paint_i = solve(idx + 1, remaining, cost, time);

        return t[idx][remaining] = Math.min(paint_i, not_paint_i);
    }

    public int paintWalls(int[] cost, int[] time) {
        n = cost.length;
        t = new int[501][501];
        for (int[] row : t) {
            Arrays.fill(row, -1);
        }

        return solve(0, n, cost, time);
    }
}


//Approach-2 (Bottom Up)
//Sooooon coming with youtube video
