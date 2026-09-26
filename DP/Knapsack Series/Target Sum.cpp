/*        Scroll below to see JAVA code also        */
/*
    MY YOUTUBE VIDEO LINK : 
    Company Tags          : Google, Meta
    Leetcode Link         : https://leetcode.com/problems/target-sum/
*/


/*************************************************************** C++ ******************************************************/
//Approach-1 (Recursion Memo same as Count Subset Sum)
//T.C : O(n*sum), sum = (totalSum + target)/2;
//S.C : O(n*sum)
class Solution {
public:
    int t[21][1001];

    int count_subset(int n, int sum, vector<int>& arr) {
        if(n == 0)
            return (sum == 0) ? 1 : 0;

        if(t[n][sum] != -1) {
            return t[n][sum];
        }

        int skip = count_subset(n-1, sum, arr);

        int take = 0;
        if(arr[n-1] <= sum) {
            take = count_subset(n-1, sum - arr[n-1], arr);
        }

        return t[n][sum] = (take + skip);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        memset(t, -1, sizeof(t));
        int n = nums.size();
        int sum = 0;
        
        target = abs(target);

        for(const int& x : nums) {
            sum += x;
        }
        
        if((sum + target)%2 != 0)
            return 0;
        
        int s1 = (sum + target)/2;
        return count_subset(n, s1, nums);
    }
};


//Approach-2 (Bottom Up same as Count Subset Sum)
//T.C : O(n*sum), sum = (totalSum + target)/2;
//S.C : O(n*sum)
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        int sum = 0;
        
        target = abs(target);

        for(const int& x : nums) {
            sum += x;
        }
        
        if((sum + target)%2 != 0)
            return 0;
        
        int s1 = (sum + target)/2;

        vector<vector<int>> t(n+1, vector<int>(s1 + 1, 0));

        t[0][0] = 1; //if(n == 0) return target == 0 ? 1 : 0

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= s1; j++) {   // j starts at 0, not 1
                int skip = t[i-1][j];

                int take = 0;
                if(nums[i-1] <= j) {
                    take = t[i-1][j - nums[i-1]];
                }

                t[i][j] = (take + skip);
            }
        }

        return t[n][s1]; //return solve(n, s1)
    }
};


//Approach-3 (Spaze Optimised Bottom Up same as count subset sum)
//T.C : O(n*sum), sum = (totalSum + target)/2;
//S.C : O(sum), sum = (totalSum + target)/2;
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        int sum = 0;
        
        target = abs(target);

        for(const int& x : nums) {
            sum += x;
        }
        
        if((sum + target)%2 != 0)
            return 0;
        
        int s1 = (sum + target)/2;

        vector<int> prev(s1 + 1, 0), curr(s1 + 1, 0);

        // Base Case: sum = 0 -> empty subset, exactly 1 way
        prev[0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= s1; j++) {   // j starts at 0, not 1
                int skip = 0;
                int take = 0;

                // skip → t[i-1][j]
                skip = prev[j];

                // take → t[i-1][j - nums[i-1]]
                if (nums[i-1] <= j) {
                    take = prev[j - nums[i-1]];
                }

                // t[i][j]
                curr[j] = (skip + take);
            }

            prev = curr;
        }

        return prev[s1]; // same as t[n][target]
    }
};



/*************************************************************** JAVA ******************************************************/
//Approach-1 (Recursion Memo same as Count Subset Sum)
//T.C : O(n*sum), sum = (totalSum + target)/2;
//S.C : O(n*sum)
class Solution {
    int[][] t = new int[21][1001];

    int count_subset(int n, int sum, int[] arr) {
        if(n == 0)
            return (sum == 0) ? 1 : 0;

        if(t[n][sum] != -1) {
            return t[n][sum];
        }

        int skip = count_subset(n-1, sum, arr);

        int take = 0;
        if(arr[n-1] <= sum) {
            take = count_subset(n-1, sum - arr[n-1], arr);
        }

        return t[n][sum] = (take + skip);
    }

    public int findTargetSumWays(int[] nums, int target) {
        for(int[] row : t)
            Arrays.fill(row, -1);

        int n = nums.length;
        int sum = 0;

        target = Math.abs(target);

        for(int x : nums) {
            sum += x;
        }

        if((sum + target) % 2 != 0)
            return 0;

        int s1 = (sum + target) / 2;
        return count_subset(n, s1, nums);
    }
}


//Approach-2 (Bottom Up same as Count Subset Sum)
//T.C : O(n*sum), sum = (totalSum + target)/2;
//S.C : O(n*sum)
class Solution {
    public int findTargetSumWays(int[] nums, int target) {
        int n = nums.length;

        int sum = 0;

        target = Math.abs(target);

        for(int x : nums) {
            sum += x;
        }

        if((sum + target) % 2 != 0)
            return 0;

        int s1 = (sum + target) / 2;

        int[][] t = new int[n+1][s1 + 1];  // defaults to 0 in Java

        t[0][0] = 1; //if(n == 0) return target == 0 ? 1 : 0

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= s1; j++) {   // j starts at 0, not 1
                int skip = t[i-1][j];

                int take = 0;
                if(nums[i-1] <= j) {
                    take = t[i-1][j - nums[i-1]];
                }

                t[i][j] = (take + skip);
            }
        }

        return t[n][s1]; //return solve(n, s1)
    }
}


//Approach-3 (Spaze Optimised Bottom Up same as count subset sum)
//T.C : O(n*sum), sum = (totalSum + target)/2;
//S.C : O(sum), sum = (totalSum + target)/2;
class Solution {
    public int findTargetSumWays(int[] nums, int target) {
        int n = nums.length;

        int sum = 0;

        target = Math.abs(target);

        for(int x : nums) {
            sum += x;
        }

        if((sum + target) % 2 != 0)
            return 0;

        int s1 = (sum + target) / 2;

        int[] prev = new int[s1 + 1];
        int[] curr = new int[s1 + 1];

        // Base Case: sum = 0 -> empty subset, exactly 1 way
        prev[0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= s1; j++) {   // j starts at 0, not 1
                int skip = 0;
                int take = 0;

                // skip → t[i-1][j]
                skip = prev[j];

                // take → t[i-1][j - nums[i-1]]
                if (nums[i-1] <= j) {
                    take = prev[j - nums[i-1]];
                }

                // t[i][j]
                curr[j] = (skip + take);
            }

            prev = curr.clone();  // move current row -> previous row
        }

        return prev[s1]; // same as t[n][target]
    }
}
