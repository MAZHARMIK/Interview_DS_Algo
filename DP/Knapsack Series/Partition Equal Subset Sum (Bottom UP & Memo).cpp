/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=vzMvYxo1AO4
    Company Tags                : Amazon, Microsoft
    Problem Link                : https://leetcode.com/problems/partition-equal-subset-sum
*/


/**************************************************************** C++ ****************************************************************/
//Approach-1 (Recursion + Memoization)
//T.C : O(n*sum)
//S.C : O(n*sum)
class Solution {
public:
    int t[201][10001];
    bool isSubsetSum(int n, int sum, vector<int>& arr) {
        if(sum == 0)
            return true;
        
        if(n == 0)
            return false;
        
        if(t[n][sum] != -1) {
            return t[n][sum]; //0 : False , 1 : True
        }
        
        bool skip = isSubsetSum(n-1, sum, arr);
        
        bool take = false;
        if(arr[n-1] <= sum) {
            take = isSubsetSum(n-1, sum - arr[n-1], arr);
        }
        
        return t[n][sum] = take || skip; //True : 1, False : 0
    }

    bool canPartition(vector<int>& nums) {
        memset(t, -1, sizeof(t));
        int n = nums.size();

        int SUM = accumulate(begin(nums), end(nums), 0);

        if(SUM % 2 != 0) {
            return false;
        }

        int S = SUM/2; //S1 == S2 == S

        return isSubsetSum(n, S, nums);
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

    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int SUM = accumulate(begin(nums), end(nums), 0);

        if(SUM % 2 != 0) {
            return false;
        }

        int S = SUM/2; //S1 == S2 == S

        return isSubsetSum(nums, S);
    }
};




/**************************************************************** JAVA ****************************************************************/
//Approach-1 (Recursion + Memoization)
//T.C : O(n*sum)
//S.C : O(n*sum)
class Solution {

    int[][] t;

    public boolean isSubsetSum(int n, int sum, int[] arr) {
        if (sum == 0)
            return true;

        if (n == 0)
            return false;

        if (t[n][sum] != -1) {
            return t[n][sum] == 1;
        }

        boolean skip = isSubsetSum(n - 1, sum, arr);

        boolean take = false;
        if (arr[n - 1] <= sum) {
            take = isSubsetSum(n - 1, sum - arr[n - 1], arr);
        }

        t[n][sum] = (take || skip) ? 1 : 0;
        return take || skip;
    }

    public boolean canPartition(int[] nums) {
        int n = nums.length;

        int SUM = 0;
        for (int num : nums)
            SUM += num;

        if (SUM % 2 != 0)
            return false;

        int S = SUM / 2;

        t = new int[n + 1][S + 1];
        for (int i = 0; i <= n; i++) {
            Arrays.fill(t[i], -1);
        }

        return isSubsetSum(n, S, nums);
    }
}


//Approach-2 (Bottom Up)
//T.C : O(n*sum)
//S.C : O(n*sum)
class Solution {
    public boolean isSubsetSum(int[] arr, int sum) {
        int n = arr.length;

        boolean[][] t = new boolean[n + 1][sum + 1];

        // Base case: sum = 0 is always possible
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

    public boolean canPartition(int[] nums) {
        int n = nums.length;

        int SUM = 0;
        for (int num : nums)
            SUM += num;

        if (SUM % 2 != 0)
            return false;

        int S = SUM / 2;

        return isSubsetSum(nums, S);
    }
}
