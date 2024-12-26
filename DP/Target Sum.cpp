/*        Scroll below to see JAVA code also        */
/*
    MY YOUTUBE VIDEO LINK : 
    Company Tags          : Google, Facebook, 
    Leetcode Link         : https://leetcode.com/problems/target-sum/
*/


/*************************************************************** C++ ******************************************************/
//Approach-1 (Recursion + Memoization)
//T.C : O(n*target)
//S.C : O(n*target)
class Solution {
public:
    int t[21][1001];
    int subsetSum(vector<int>& nums, int n, int s) {
        if(t[n][s] != -1)
            return t[n][s];
        if(s == 0)
            return 1;
        if(n == 0)
            return 0;
        if(nums[n-1] == 0)
            return t[n][s] = subsetSum(nums, n-1, s);
        
        if(nums[n-1] <= s)
            return t[n][s] = subsetSum(nums, n-1, s-nums[n-1]) + subsetSum(nums, n-1, s);
        else
            return t[n][s] = subsetSum(nums, n-1, s);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(t, -1, sizeof(t));
        int sum   = accumulate(begin(nums), end(nums), 0);
        auto lambda = [&](const int& x) {
            return x == 0;
        };
        int zeros = count_if(begin(nums), end(nums), lambda);
        if(target > sum)
            return 0;
        
        if((sum-target) %2 != 0)
            return 0;
        
        int s1 = (sum-target)/2;
        return pow(2, zeros)*subsetSum(nums, nums.size(), s1);
    }
};

//Approach-2 (Bottom Up DP)
//T.C : O(n*target)
//S.C : O(n*target)
class Solution {
public:
    int subsetSum(vector<int>& nums, int s) {
        int n = nums.size();
        vector<vector<int>> t(n+1, vector<int>(s+1));
        
        for(int col = 0; col < s+1; col++) t[0][col] = 0;
        for(int row = 0; row < n+1; row++) t[row][0] = 1;
        
        for(int i = 1; i<n+1; i++) {
            for(int j = 1; j<s+1; j++) {
                if(nums[i-1] == 0)
                    t[i][j] = t[i-1][j];
                else if(nums[i-1] <= j)
                    t[i][j] = t[i-1][j-nums[i-1]] + t[i-1][j];
                else
                    t[i][j] = t[i-1][j];
            }
        }
        
        return t[n][s];
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum   = accumulate(begin(nums), end(nums), 0);
        auto lambda = [&](const int& x) {
            return x == 0;
        };
        int zeros = count_if(begin(nums), end(nums), lambda);
        if(target > sum)
            return 0;
        
        if((sum-target) %2 != 0)
            return 0;
        
        int s1 = (sum-target)/2;
        /*
            You could also do like this :
            if((sum + target)%2 != 0)
                return 0;
        
            int s1 = (sum + target)/2;
            But since, target can be negative also as per Leetcode (they have recently changed the constraints), 
            you need to do :
            target = abs(target); before finding s1 and the if condition above
        */
        return pow(2, zeros)*subsetSum(nums, s1);
    }
};




/*************************************************************** JAVA ******************************************************/
//Approach-1 (Recursion + Memoization)
//T.C : O(n*target)
//S.C : O(n*target)
class Solution {
    private int[][] t;

    private int subsetSum(int[] nums, int n, int s) {
        if (t[n][s] != -1) {
            return t[n][s];
        }
        if (s == 0) {
            return 1;
        }
        if (n == 0) {
            return 0;
        }
        if (nums[n - 1] == 0) {
            return t[n][s] = subsetSum(nums, n - 1, s);
        }
        if (nums[n - 1] <= s) {
            return t[n][s] = subsetSum(nums, n - 1, s - nums[n - 1]) + subsetSum(nums, n - 1, s);
        } else {
            return t[n][s] = subsetSum(nums, n - 1, s);
        }
    }

    public int findTargetSumWays(int[] nums, int target) {
        int sum = Arrays.stream(nums).sum();
        long zeros = Arrays.stream(nums).filter(x -> x == 0).count();

        if (target > sum) {
            return 0;
        }
        if ((sum - target) % 2 != 0) {
            return 0;
        }

        int s1 = (sum - target) / 2;
        t = new int[nums.length + 1][s1 + 1];
        for (int[] row : t) {
            Arrays.fill(row, -1);
        }

        return (int) Math.pow(2, zeros) * subsetSum(nums, nums.length, s1);
    }
}


//Approach-2 (Bottom Up DP)
//T.C : O(n*target)
//S.C : O(n*target)
class Solution {
    private int subsetSum(int[] nums, int s) {
        int n = nums.length;
        int[][] t = new int[n + 1][s + 1];

        // Initialize the first row to 0 and the first column to 1
        for (int col = 0; col <= s; col++) {
            t[0][col] = 0;
        }
        for (int row = 0; row <= n; row++) {
            t[row][0] = 1;
        }

        // Fill the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= s; j++) {
                if (nums[i - 1] == 0) {
                    t[i][j] = t[i - 1][j];
                } else if (nums[i - 1] <= j) {
                    t[i][j] = t[i - 1][j - nums[i - 1]] + t[i - 1][j];
                } else {
                    t[i][j] = t[i - 1][j];
                }
            }
        }

        return t[n][s];
    }

    public int findTargetSumWays(int[] nums, int target) {
        int sum = Arrays.stream(nums).sum();
        long zeros = Arrays.stream(nums).filter(x -> x == 0).count();

        if (target > sum) {
            return 0;
        }

        if ((sum - target) % 2 != 0) {
            return 0;
        }

        int s1 = (sum - target) / 2;

        // Optional: Adjust for negative targets (if required by constraints)
        // target = Math.abs(target);
        // if ((sum + target) % 2 != 0) return 0;
        // int s1 = (sum + target) / 2;

        return (int) Math.pow(2, zeros) * subsetSum(nums, s1);
    }
}
