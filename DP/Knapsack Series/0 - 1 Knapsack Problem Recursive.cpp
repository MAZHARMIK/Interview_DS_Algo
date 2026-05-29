/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=97ogFz0NkAo
    Company Tags                : Flipkart, Morgan Stanley, Amazon, Microsoft, Snapdeal, Oracle, PayU, Visa, Directi, GreyOrange, Mobicip, NPCI
    Problem Link                : https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
*/


/**************************************************************** C++ ****************************************************************/
//Approach-1 (Starting from index i = 0 - Recursion + Memoization)
//T.C : O(n*W)
//S.C : O(n*W)
class Solution {
  public:
    int n;
    int t[1001][1001];
    int solve(int i, int W, vector<int>& val, vector<int>& wt) {
        if(i >= n || W == 0)
            return 0;
        
        if(t[i][W] != -1) {
            return t[i][W];
        }
        int take = 0;
        int skip = 0;
        
        //take
        if(wt[i] <= W) {
            take = val[i] + solve(i+1, W - wt[i], val, wt);
        }
        
        skip = solve(i+1, W, val, wt);
        
        return t[i][W] = max(take, skip);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        n = val.size();
        memset(t, -1, sizeof(t));
        return solve(0, W, val, wt);
        
    }
};



//Approach-2 (Starting from n items - Recursion + Memoization)
//T.C : O(n*W)
//S.C : O(n*W)
class Solution {
  public:
    int t[1001][1001];
    int solve(int n, int W, vector<int>& val, vector<int>& wt) {
        if(n <= 0 || W == 0)
            return 0;
        
        if(t[n][W] != -1) {
            return t[n][W];
        }
        int take = 0;
        int skip = 0;
        
        //take
        if(wt[n-1] <= W) {
            take = val[n-1] + solve(n-1, W - wt[n-1], val, wt);
        }
        
        skip = solve(n-1, W, val, wt);
        
        return t[n][W] = max(take, skip);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        memset(t, -1, sizeof(t));
        return solve(n, W, val, wt);
        
    }
};




/**************************************************************** JAVA ****************************************************************/
//Approach-1 (Starting from index i = 0 - Recursion + Memoization)
//T.C : O(n*W)
//S.C : O(n*W)
class Solution {
    int n;
    int[][] t;
    
    private int solve(int i, int W, int[] val, int[] wt) {
        if (i >= n || W == 0) {
            return 0;
        }
        
        if (t[i][W] != -1) {
            return t[i][W];
        }
        
        int take = 0;
        int skip;
        
        // take
        if (wt[i] <= W) {
            take = val[i] + solve(i + 1, W - wt[i], val, wt);
        }
        
        // skip
        skip = solve(i + 1, W, val, wt);
        
        return t[i][W] = Math.max(take, skip);
    }
    
    public int knapsack(int W, int[] val, int[] wt) {
        n = val.length;
        t = new int[n][W + 1];
        
        for (int[] row : t) {
            java.util.Arrays.fill(row, -1);
        }
        
        return solve(0, W, val, wt);
    }
}




//Approach-2 (Starting from n items - Recursion + Memoization)
//T.C : O(n*W)
//S.C : O(n*W)
class Solution {
    int[][] t;
    
    private int solve(int n, int W, int[] val, int[] wt) {
        if (n <= 0 || W == 0) {
            return 0;
        }
        
        if (t[n][W] != -1) {
            return t[n][W];
        }
        
        int take = 0;
        int skip;
        
        // take
        if (wt[n - 1] <= W) {
            take = val[n - 1] + solve(n - 1, W - wt[n - 1], val, wt);
        }
        
        // skip
        skip = solve(n - 1, W, val, wt);
        
        return t[n][W] = Math.max(take, skip);
    }
    
    public int knapsack(int W, int[] val, int[] wt) {
        int n = val.length;
        t = new int[n + 1][W + 1];
        
        for (int[] row : t) {
            java.util.Arrays.fill(row, -1);
        }
        
        return solve(n, W, val, wt);
    }
}
