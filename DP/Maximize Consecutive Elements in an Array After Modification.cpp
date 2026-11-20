/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO LINK : https://www.youtube.com/watch?v=Wm3ioV_Tr5Q
    Company Tags          : Will update later
    Leetcode Link         : https://leetcode.com/problems/maximize-consecutive-elements-in-an-array-after-modification
*/


/*********************************************************** C++ **************************************************/
//Approach-1 (Recursion Memoization)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    int n;
    vector<vector<int>> memo;

    int findMethod(vector<int>& nums, int start, int target) {
        int j = lower_bound(begin(nums) + start, end(nums), target) - begin(nums);

        if(j < n && nums[j] == target) {
            return j;
        }

        return -1;
    }

    int solve(int i, int inc, vector<int>& nums) {

        if(memo[i][inc] != -1) {
            return memo[i][inc];
        }

        int currVal = nums[i] + inc; //inc = 0/1
        int len = 1;

        //1st Option = find (currVal+1)
        int j = findMethod(nums, i+1, currVal+1);
        if(j != -1) {
            len = max(len, 1 + solve(j, 0, nums));
        }

        //2nd Option = find (currVal) and then inc by +1
        j = findMethod(nums, i+1, currVal);
        if(j != -1) {
            len = max(len, 1 + solve(j, 1, nums));
        }

        return memo[i][inc] = len;
    }

    int maxSelectedElements(vector<int>& nums) {
        n = nums.size();

        sort(begin(nums), end(nums));

        memo.assign(n+1, vector<int>(2, -1));

        int result = 1;
        for(int i = 0; i < n; i++) {
            result = max({result, solve(i, 0, nums), solve(i, 1, nums)});
        }

        return result;
    }
};


//Approach-2 (Bottom Up)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    vector<vector<int>> dp;
    int n;

    int findMethod(vector<int>& nums, int start, int target) {
        int j = lower_bound(nums.begin() + start, nums.end(), target) - nums.begin();
        if (j < n && nums[j] == target)
            return j;

        return -1;
    }

    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        n = nums.size();
        dp.assign(n + 1, vector<int>(2, 0));

        int result = 1;


        for (int i = n - 1; i >= 0; i--) { //O(n * log(n))
            for (int inc = 0; inc <= 1; inc++) {

                int currVal = nums[i] + inc;
                int len = 1;

                //1st Option = find (currVal+1)
                int j = findMethod(nums, i + 1, currVal + 1);
                if (j != -1) {
                    len = max(len, 1 + dp[j][0]);
                }

                //2nd Option = find (currVal) and then inc by +1
                j = findMethod(nums, i + 1, currVal);
                if (j != -1) {
                    len = max(len, 1 + dp[j][1]);
                }

                dp[i][inc] = len;
                result = max(result, len);
            }
        }

        return result;
    }
};



/*********************************************************** JAVA **************************************************/
//Approach-1 (Recursion Memoization)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
    int n;
    int[][] memo;

    // First index >= start where nums[index] == target, or -1 if none
    private int findMethod(int[] nums, int start, int target) {
        int lo = start, hi = n; // search in [start, n)
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }

        if (lo < n && nums[lo] == target) {
            return lo;
        }

        return -1;
    }

    private int solve(int i, int inc, int[] nums) {

        if (memo[i][inc] != -1) {
            return memo[i][inc];
        }

        int currVal = nums[i] + inc; //inc = 0/1
        int len = 1;

        //1st Option = find (currVal+1)
        int j = findMethod(nums, i + 1, currVal + 1);
        if (j != -1) {
            len = Math.max(len, 1 + solve(j, 0, nums));
        }

        //2nd Option = find (currVal) and then inc by +1
        j = findMethod(nums, i + 1, currVal);
        if (j != -1) {
            len = Math.max(len, 1 + solve(j, 1, nums));
        }

        return memo[i][inc] = len;
    }

    public int maxSelectedElements(int[] nums) {
        n = nums.length;

        Arrays.sort(nums);

        memo = new int[n + 1][2];
        for (int[] row : memo) {
            Arrays.fill(row, -1);
        }

        int result = 1;
        for (int i = 0; i < n; i++) {
            result = Math.max(result, Math.max(solve(i, 0, nums), solve(i, 1, nums)));
        }

        return result;
    }
}



//Approach-2 (Bottom Up)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
    int n;
    int[][] dp;

    // First index >= start where nums[index] == target, or -1 if none
    private int findMethod(int[] nums, int start, int target) {
        int lo = start, hi = n; // search in [start, n)
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }

        if (lo < n && nums[lo] == target) {
            return lo;
        }

        return -1;
    }

    public int maxSelectedElements(int[] nums) {
        n = nums.length;

        Arrays.sort(nums);

        dp = new int[n + 1][2];

        int result = 1;

        for (int i = n - 1; i >= 0; i--) { //O(n * log(n))
            for (int inc = 0; inc <= 1; inc++) {

                int currVal = nums[i] + inc;
                int len = 1;

                //1st Option = find (currVal+1)
                int j = findMethod(nums, i + 1, currVal + 1);
                if (j != -1) {
                    len = Math.max(len, 1 + dp[j][0]);
                }

                //2nd Option = find (currVal) and then inc by +1
                j = findMethod(nums, i + 1, currVal);
                if (j != -1) {
                    len = Math.max(len, 1 + dp[j][1]);
                }

                dp[i][inc] = len;
                result = Math.max(result, len);
            }
        }

        return result;
    }
}
