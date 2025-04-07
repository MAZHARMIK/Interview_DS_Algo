/*            Scroll below to see JAVA code as well            */
/*  
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=G5BGAEYGnWU
    Company tags                : Accolite, Amazon, Adobe, Drishti-Soft
    Leetcode Link               : https://leetcode.com/problems/partition-equal-subset-sum/
*/


/****************************************************************** C++ ******************************************************/
//Approach-1 (Recursion + Memo)
//T.C : O(n*x), where x = totalSum/2
//S.C : O(n*x)
class Solution {
public:
    int t[201][20001];
    bool solve(vector<int>& nums, int i, int x) {
        if(x == 0) {
            return true;
        }

        if(i >= nums.size()) {
            return false;
        }

        if(t[i][x] != -1) {
            return t[i][x];
        }

        bool take = false;
        if(nums[i] <= x) {
            take = solve(nums, i+1, x - nums[i]);
        }

        bool not_take = solve(nums, i+1, x);

        return t[i][x] = take || not_take;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        
        int S = accumulate(begin(nums), end(nums), 0);

        if(S%2 != 0) {
            return false;
        }  
        memset(t, -1, sizeof(t));
        //vector<vecyot<int>> t(n+1, vector<int>(x+1, -1))
        int x = S/2;

        return solve(nums, 0, x);

    }
};


//Approach-2 (Bottom Up) - VIDEO COMING SOON ON THIS
//T.C : O(n*S)
//S.C : O(n*S)
class Solution {
public:
    bool subsetSum(vector<int>& nums, int S) {
        int n = nums.size();
        vector<vector<bool>> t(n+1, vector<bool>(S+1, false));
        
        //It's not possible to get any sum when we have no elements
        for(int col = 0; col<S+1; col++) {
            t[0][col] = false;
        }
        
        //It's always possible to get sum=0
        for(int row = 0; row<n+1; row++) {
            t[row][0] = true;
        }
        
        
        for(int i = 1; i<n+1; i++) {
            for(int j = 1; j<S+1; j++) {
                if(nums[i-1] <= j) {
                    t[i][j] = t[i-1][j-nums[i-1]] || t[i-1][j]; //including || excluding
                } else {
                    t[i][j] = t[i-1][j]; //exluding because we can't pick element which is greater than target sum
                }
            }
        }
        
        return t[n][S];
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int x:nums){
            sum += x;
        }
        
        if(sum%2 != 0)
            return false;
        
        sum = sum/2;
        
        return subsetSum(nums, sum);
    }
};



/****************************************************************** JAVA ******************************************************/
//Approach-1 (Recursion + Memo)
//T.C : O(n*x), where x = totalSum/2
//S.C : O(n*x)
class Solution {
    int[][] t = new int[201][20001];

    boolean solve(List<Integer> nums, int i, int x) {
        if (x == 0) {
            return true;
        }

        if (i >= nums.size()) {
            return false;
        }

        if (t[i][x] != -1) {
            return t[i][x] == 1;
        }

        boolean take = false;
        if (nums.get(i) <= x) {
            take = solve(nums, i + 1, x - nums.get(i));
        }

        boolean not_take = solve(nums, i + 1, x);

        t[i][x] = (take || not_take) ? 1 : 0;
        return take || not_take;
    }

    public boolean canPartition(int[] numsArr) {
        List<Integer> nums = new ArrayList<>();
        for (int num : numsArr) nums.add(num);

        int n = nums.size();
        int S = 0;
        for (int num : nums) {
            S += num;
        }

        if (S % 2 != 0) {
            return false;
        }

        for (int[] row : t) {
            Arrays.fill(row, -1);
        }

        int x = S / 2;

        return solve(nums, 0, x);
    }
}


//Approach-2 (Bottom Up) - VIDEO COMING SOON ON THIS
//T.C : O(n*S)
//S.C : O(n*S)
class Solution {
    public boolean subsetSum(int[] nums, int S) {
        int n = nums.length;
        boolean[][] t = new boolean[n + 1][S + 1];

        //It's not possible to get any sum when we have no elements
        for (int col = 0; col < S + 1; col++) {
            t[0][col] = false;
        }

        //It's always possible to get sum=0
        for (int row = 0; row < n + 1; row++) {
            t[row][0] = true;
        }

        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < S + 1; j++) {
                if (nums[i - 1] <= j) {
                    t[i][j] = t[i - 1][j - nums[i - 1]] || t[i - 1][j]; //including || excluding
                } else {
                    t[i][j] = t[i - 1][j]; //exluding because we can't pick element which is greater than target sum
                }
            }
        }

        return t[n][S];
    }

    public boolean canPartition(int[] nums) {
        int sum = 0;
        for (int x : nums) {
            sum += x;
        }

        if (sum % 2 != 0)
            return false;

        sum = sum / 2;

        return subsetSum(nums, sum);
    }
}
