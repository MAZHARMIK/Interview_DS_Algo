/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=9mN6Te6Tuj0
    Company Tags                : Amazon, Microsoft, Tesco
    Problem Link                : https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1
*/


/**************************************************************** C++ ****************************************************************/
//Approach-1 (Recursion + Memoization)
//T.C : O(n*target)
//S.C : O(n*target)
class Solution {
  public:
    int t[1001][1001];

    int solve(int n, int sum, vector<int>& arr) {
        if(n == 0)
            return (sum == 0) ? 1 : 0;

        if(t[n][sum] != -1) {
            return t[n][sum];
        }

        int skip = solve(n-1, sum, arr);

        int take = 0;
        if(arr[n-1] <= sum) {
            take = solve(n-1, sum - arr[n-1], arr);
        }

        return t[n][sum] = (take + skip);
    }

    int perfectSum(vector<int>& arr, int target) {
        memset(t, -1, sizeof(t));

        int n = arr.size();

        return solve(n, target, arr);

    }
};


//Approach-2 (Bottom Up)
//T.C : O(n*target)
//S.C : O(n*target)
class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();

        vector<vector<int>> t(n+1, vector<int>(target + 1, 0));

        t[0][0] = 1; //if(n == 0) return target == 0 ? 1 : 0

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= target; j++) {   // j starts at 0, not 1
                int skip = t[i-1][j];

                int take = 0;
                if(arr[i-1] <= j) {
                    take = t[i-1][j - arr[i-1]];
                }

                t[i][j] = (take + skip);
            }
        }

        return t[n][target]; //return solve(n, target)
    }
};



//Approach-3 (Spaze Optimised Bottom Up)
//T.C : O(n*target)
//S.C : O(target)
class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();

        // prev → t[i-1][...]
        // curr → t[i][...]
        vector<int> prev(target + 1, 0), curr(target + 1, 0);

        // Base Case: sum = 0 -> empty subset, exactly 1 way
        prev[0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= target; j++) {   // j starts at 0, not 1
                int skip = 0;
                int take = 0;

                // skip → t[i-1][j]
                skip = prev[j];

                // take → t[i-1][j - arr[i-1]]
                if (arr[i-1] <= j) {
                    take = prev[j - arr[i-1]];
                }

                // t[i][j]
                curr[j] = (skip + take);
            }

            prev = curr;
        }

        return prev[target]; // same as t[n][target]
    }
};




/**************************************************************** JAVA ****************************************************************/
//Approach-1 (Recursion + Memoization)
//T.C : O(n*target)
//S.C : O(n*target)
class Solution {
    static int[][] t = new int[1001][1001];
    
    static int solve(int n, int sum, int[] arr) {
        if(n == 0)
            return (sum == 0) ? 1 : 0;
        
        if(t[n][sum] != -1) {
            return t[n][sum];
        }
        
        int skip = solve(n-1, sum, arr);
        
        int take = 0;
        if(arr[n-1] <= sum) {
            take = solve(n-1, sum - arr[n-1], arr);
        }
        
        return t[n][sum] = (take + skip);
    }
    
    static int perfectSum(int[] arr, int target) {
        for(int[] row : t)
            Arrays.fill(row, -1);
        
        int n = arr.length;
        return solve(n, target, arr);
    }
}

//Approach-2 (Bottom Up)
//T.C : O(n*target)
//S.C : O(n*target)
class Solution {
    static int perfectSum(int[] arr, int target) {
        int n = arr.length;
        
        int[][] t = new int[n+1][target + 1];  // defaults to 0 in Java
        t[0][0] = 1; //if(n == 0) return target == 0 ? 1 : 0
        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= target; j++) {   // j starts at 0, not 1
                int skip = t[i-1][j];
                
                int take = 0;
                if(arr[i-1] <= j) {
                    take = t[i-1][j - arr[i-1]];
                }
                
                t[i][j] = (take + skip);
            }
        }
        
        return t[n][target]; //return solve(n, target)
    }
}

//Approach-3 (Spaze Optimised Bottom Up)
//T.C : O(n*target)
//S.C : O(target)
class Solution {
    static int perfectSum(int[] arr, int target) {
        int n = arr.length;
        
        // prev → t[i-1][...]
        // curr → t[i][...]
        int[] prev = new int[target + 1];
        int[] curr = new int[target + 1];
        
        // Base Case: sum = 0 -> empty subset, exactly 1 way
        prev[0] = 1;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= target; j++) {   // j starts at 0, not 1
                int skip = 0;
                int take = 0;
                
                // skip → t[i-1][j]
                skip = prev[j];
                
                // take → t[i-1][j - arr[i-1]]
                if (arr[i-1] <= j) {
                    take = prev[j - arr[i-1]];
                }
                
                // t[i][j]
                curr[j] = (skip + take);
            }
            prev = curr.clone();  // move current row -> previous row
        }
        
        return prev[target]; // same as t[n][target]
    }
}
