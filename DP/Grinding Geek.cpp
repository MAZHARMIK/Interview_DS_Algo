/*
    Company Tags : GeeksForGeeks
    GfG Link     : https://www.geeksforgeeks.org/problems/grinding-geek/1
*/

/****************************************************** C++ ************************************************/
//Approach-1 (Using Recursion + Memo)
//T.C : O(n*total)
//S.C : O(n*total)
class Solution{
    public:
    int t[1001][1001];
    int solve(int i, int total, int n, vector<int>& cost) {
        if(i >= n) {
            return 0;
        }
        if(total <= 0) {
            return 0;
        }
        
        if(t[i][total] != -1) {
            return t[i][total];
        }
        
        int take    = 0;
        int notTake = 0;
        
        if(total >= cost[i]) {
            take = 1 + solve(i+1, total-cost[i] + 0.9*cost[i], n, cost);
        }
        
        notTake = solve(i+1, total, n, cost);
        
        return t[i][total] = max(take, notTake);
    }

    int max_courses(int n, int total, vector<int> &cost) {
        memset(t, -1, sizeof(t));
        return solve(0, total, n, cost);
    }
};


//Approach-2 (Bottom Up)
//T.C : O(n*total)
//S.C : O(n*total)
class Solution{
    public:
    
    int max_courses(int n, int total, vector<int> &cost) {
        vector<vector<int>> t(n+1, vector<int>(total+1));
        // t[i][j] = total count when I have course from i to n-1 index and amount = j
        
        for(int i = n; i >= 0; i--) {
            for(int j = total; j >= 0; j--) {
                if(i == n) {
                    t[i][j] = 0;
                } else {
                    int take    = 0;
                    int notTake = 0;
                    
                    if(j >= cost[i]) {
                        take = 1 + t[i+1][j-cost[i] + 0.9*cost[i]];
                    }
                    
                    notTake = t[i+1][j];
                    
                    t[i][j] = max(take, notTake);
                }
            }
        }
        
        return t[0][total];
        // t[i][j] = total count when I have course from 0 to n-1 index and amount = amount
    }
};



/****************************************************** JAVA ************************************************/
//Approach-1 (Using Recursion + Memo)
//T.C : O(n*total)
//S.C : O(n*total)
class Solution {
    private int[][] t;

    public int max_courses(int n, int total, int[] cost) {
        t = new int[n + 1][total + 1];
        for (int[] row : t) {
            Arrays.fill(row, -1);
        }
        return solve(0, total, n, cost);
    }

    private int solve(int i, int total, int n, int[] cost) {
        if (i >= n) {
            return 0;
        }
        if (total <= 0) {
            return 0;
        }

        if (t[i][total] != -1) {
            return t[i][total];
        }

        int take = 0;
        int notTake = 0;

        if (total >= cost[i]) {
            take = 1 + solve(i + 1, total - cost[i] + (int) (0.9 * cost[i]), n, cost);
        }

        notTake = solve(i + 1, total, n, cost);

        return t[i][total] = Math.max(take, notTake);
    }
}


//Approach-2 (Bottom Up)
//T.C : O(n*total)
//S.C : O(n*total)
class Solution {
    public int max_courses(int n, int total, int[] cost) {
        int[][] t = new int[n + 1][total + 1];
        // t[i][j] = total count when I have course from i to n-1 and amount = j

        for (int i = n; i >= 0; i--) {
            for (int j = total; j >= 0; j--) {
                if (i == n) {
                    t[i][j] = 0;
                } else {
                    int take = 0;
                    int notTake = 0;

                    if (j >= cost[i]) {
                        take = 1 + t[i + 1][j - cost[i] + (int) (0.9 * cost[i])];
                    }

                    notTake = t[i + 1][j];

                    t[i][j] = Math.max(take, notTake);
                }
            }
        }

        return t[0][total];
        // t[i][j] = total count when I have course from 0 to n-1 index and amount = amount
    }
}
