/*
    MY YOUTUBE VIDEO ON THIS Qn :
    Company Tags                : Will soon update
    Leetcode Link               : https://leetcode.com/problems/maximum-balanced-subsequence-sum
*/

/********************************************************************************** C++ **********************************************************************************/
//Approach-1 (Using LIS) - Recursion + Memoization (TLE) ---> 341 / 345 testcases passed
//T.C : O(n^2) - prev index for every i
class Solution {
public:
    unordered_map<string, long long> mp; //For memoization
    long long solve(int i, int prev, vector<int>& nums) {
        if(i >= nums.size()) {
            return 0;
        }

        string key = to_string(i) + "_" + to_string(prev);
        if(mp.find(key) != mp.end()) {
            return mp[key];
        }

        long long taken = INT_MIN;

        if(prev == -1 || nums[i] - i >= nums[prev] - prev) {
            taken = nums[i] + solve(i+1, i, nums);
        }
        
        long long not_taken = solve(i+1, prev, nums);
        return mp[key] = max<long long>(taken, not_taken);
    }

    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        bool allNegative = true;
        long long maxEl = INT_MIN;
        mp.clear();
        for(int &x : nums) {
            maxEl = max<long long>(maxEl, x);
            if(x >= 0) {
                allNegative = false;
            }
        }
        if(allNegative) {
            return maxEl;
        }
        return solve(0, -1, nums);
    }
};

//Approach-2 (Using LIS Bottom Up) - TLE (341/345 Test cases passed)
//Time : O(n^2)
class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];

        bool allNegative = true;
        long long maxEl = INT_MIN;

        for(int &x : nums) {
            maxEl = max<long long>(maxEl, x);
            if(x >= 0) {
                allNegative = false;
            }
        }
        if(allNegative) {
            return maxEl;
        }

        vector<long long> t(n);
        for(int i = 0; i<n; i++) {
            t[i] = nums[i];
        }

        long long maxSum = INT_MIN;
        for(int i = 0; i<n; i++) {

            for(int j = 0; j<i; j++) {

                if(nums[i] - i >= nums[j] - j) {
                    t[i] = max<long long>(t[i], t[j] + nums[i]);
                    maxSum = max<long long>(maxSum, t[i]);
                }

            }
        }

        return maxSum > maxEl ? maxSum : maxEl;
    }
};


/********************************************************************************** JAVA **********************************************************************************/
//Approach-1 (Using LIS) - Recursion (TLE) ---> 316 / 345 testcases passed
//T.C : O(n^2) - prev index for every i
public class Solution {
    private Map<String, Long> memo = new HashMap<>();

    public long solve(int i, int prev, int[] nums) {
        if (i >= nums.length) {
            return 0;
        }

        String key = i + "_" + prev;
        if (memo.containsKey(key)) {
            return memo.get(key);
        }

        long taken = Integer.MIN_VALUE;

        if (prev == -1 || nums[i] - i >= nums[prev] - prev) {
            taken = nums[i] + solve(i + 1, i, nums);
        }

        long notTaken = solve(i + 1, prev, nums);
        long result = Math.max(taken, notTaken);
        memo.put(key, result);

        return result;
    }

    public long maxBalancedSubsequenceSum(int[] nums) {
        boolean allNegative = true;
        long maxEl = Integer.MIN_VALUE;
        memo.clear();

        for (int x : nums) {
            maxEl = Math.max(maxEl, x);
            if (x >= 0) {
                allNegative = false;
            }
        }

        if (allNegative) {
            return maxEl;
        }

        return solve(0, -1, nums);
    }
}



//Approach-2 (Using LIS Bottom Up) - TLE (341/345 Test cases passed)
//Time : O(n^2)
public class Solution {
    public long maxBalancedSubsequenceSum(int[] nums) {
        int n = nums.length;
        if (n == 1)
            return nums[0];

        boolean allNegative = true;
        long maxEl = Integer.MIN_VALUE;

        for (int x : nums) {
            maxEl = Math.max(maxEl, (long) x);
            if (x >= 0) {
                allNegative = false;
            }
        }
        if (allNegative) {
            return maxEl;
        }

        long[] t = new long[n];
        for (int i = 0; i < n; i++) {
            t[i] = nums[i];
        }

        long maxSum = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] - i >= nums[j] - j) {
                    t[i] = Math.max(t[i], t[j] + nums[i]);
                    maxSum = Math.max(maxSum, t[i]);
                }
            }
        }

        return Math.max(maxSum, maxEl);
    }
}
