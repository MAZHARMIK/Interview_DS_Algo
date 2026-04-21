/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Ni9RwDZdzrU
    Company Tags                : Amazon, Microsoft
    Problem Link                : https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
*/


/**************************************************************** C++ ****************************************************************/
//Approach-1 (Recursion + Memoization)
//T.C : O(n*sum)
//S.C : O(n*sum)
class Solution {
  public:
    int t[201][10001];
    
    bool solve(int n, int sum, vector<int>& arr) {
        if(sum == 0)
            return true;
        
        if(n == 0)
            return false;
        
        if(t[n][sum] != -1) {
            return t[n][sum]; //0 : False , 1 : True
        }
        
        bool skip = solve(n-1, sum, arr);
        
        bool take = false;
        if(arr[n-1] <= sum) {
            take = solve(n-1, sum - arr[n-1], arr);
        }
        
        return t[n][sum] = take || skip; //True : 1, False : 0
    }
    
    bool isSubsetSum(vector<int>& arr, int sum) {
        memset(t, -1, sizeof(t));
        int n = arr.size();
        
        return solve(n, sum, arr);
        
    }
};



//Approach-2 (Bottom Up)
//T.C : O(n*sum)
//S.C : O(n*sum)
class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
 
        // dp[i][t] = true if sum t is achievable using first i+1 elements
        vector<vector<bool>> t(n+1, vector<bool>(sum + 1, false));
 
        // Base Case : sum = 0 , return true
        for (int i = 0; i < n+1; i++)
            t[i][0] = true;

 
        // Fill the table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                bool skip = t[i-1][j];
                
                bool take = false;
                if(arr[i-1] <= j) {
                    take = t[i-1][j - arr[i-1]];
                }
                
                t[i][j] = take || skip;
            }
        }
 
        return t[n][sum];
    }
};



//Approach-3 (Space optimised Bottom Up)
//T.C : O(n*sum)
//S.C : O(sum)
class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();

        // prev → t[i-1][...]
        // curr → t[i][...]
        vector<bool> prev(sum + 1, false), curr(sum + 1, false);

        // Base Case: sum = 0, return true
        prev[0] = true; //t[i-1][0] = true
        curr[0] = true; //t[i][0]   = true

        for (int i = 1; i <= n; i++) {

            for (int j = 1; j <= sum; j++) {

                bool skip = false;
                bool take = false;

                // skip → t[i-1][j]
                skip = prev[j];

                // take → t[i-1][j - arr[i-1]]
                if (arr[i-1] <= j) {
                    take = prev[j - arr[i-1]];
                }

                // t[i][j]
                curr[j] = take || skip;
            }

            // move current row -> previous row
            prev = curr;
        }

        return prev[sum]; // same as t[n][sum]
    }
};



/**************************************************************** JAVA ****************************************************************/
//Approach-1 (Recursion + Memoization)
// T.C : O(n * sum)
// S.C : O(n * sum)
class Solution {
    
    int[][] t;
    
    boolean solve(int n, int sum, int[] arr) {
        if (sum == 0)
            return true;
        
        if (n == 0)
            return false;
        
        if (t[n][sum] != -1)
            return t[n][sum] == 1;
        
        boolean skip = solve(n - 1, sum, arr);
        
        boolean take = false;
        if (arr[n - 1] <= sum) {
            take = solve(n - 1, sum - arr[n - 1], arr);
        }
        
        t[n][sum] = (take || skip) ? 1 : 0;
        return take || skip;
    }
    
    public boolean isSubsetSum(int[] arr, int sum) {
        int n = arr.length;
        
        t = new int[n + 1][sum + 1];
        
        for (int i = 0; i <= n; i++) {
            Arrays.fill(t[i], -1);
        }
        
        return solve(n, sum, arr);
    }
}



//Approach-2 (Bottom Up)
// T.C : O(n * sum)
// S.C : O(n * sum)
class Solution {
    
    public boolean isSubsetSum(int[] arr, int sum) {
        int n = arr.length;
        
        boolean[][] t = new boolean[n + 1][sum + 1];
        
        // Base case: sum = 0
        for (int i = 0; i <= n; i++) {
            t[i][0] = true;
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                
                boolean skip = t[i - 1][j];
                
                boolean take = false;
                if (arr[i - 1] <= j) {
                    take = t[i - 1][j - arr[i - 1]];
                }
                
                t[i][j] = take || skip;
            }
        }
        
        return t[n][sum];
    }
}


//Approach-3 (Space optimised Bottom Up)
// T.C : O(n * sum)
// S.C : O(sum)
class Solution {
    
    public boolean isSubsetSum(int[] arr, int sum) {
        int n = arr.length;
        
        boolean[] prev = new boolean[sum + 1];
        boolean[] curr = new boolean[sum + 1];
        
        prev[0] = true;
        curr[0] = true;
        
        for (int i = 1; i <= n; i++) {
            
            for (int j = 1; j <= sum; j++) {
                
                boolean skip = prev[j];
                
                boolean take = false;
                if (arr[i - 1] <= j) {
                    take = prev[j - arr[i - 1]];
                }
                
                curr[j] = take || skip;
            }
            
            // move curr → prev
            prev = curr.clone();
        }
        
        return prev[sum];
    }
}
