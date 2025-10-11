/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=i0hOOfgEJaU
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/maximum-total-damage-with-spell-casting
*/


/**************************************************************** C++ ****************************************************************/
//Approach-1 - Recursion + Memoization
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    typedef long long ll;
    int n;                                
    unordered_map<ll,ll> mp;      
    vector<ll> t;           

    long long solve(int i, const vector<ll>& nums) {
        if (i >= n) 
            return 0;

        if (t[i] != -1)
            return t[i];

        //skip current damage
        ll skip = solve(i + 1, nums);

        //take current damage
        int j = lower_bound(begin(nums) + i + 1, end(nums), nums[i] + 3) - begin(nums);
        ll take = nums[i] * mp[nums[i]] + solve(j, nums);

        return t[i] = max(skip, take);
    }

    long long maximumTotalDamage(vector<int>& power) {
        for (int x : power) 
            mp[x]++;

        vector<ll> nums(mp.size());

        for (auto &p : mp)
            nums.push_back(p.first);

        sort(begin(nums), end(nums));
        n = nums.size();
        t.assign(n, -1);

        return solve(0, nums);
    }
};


//Approach-2 - Bottom Up
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    typedef long long ll;
    long long maximumTotalDamage(vector<int>& power) {
        // Step 1: Count frequency of each unique power value
        unordered_map<ll, ll> mp;
        
        for (int &x : power)
            mp[x]++;

        // Step 2: \\Collect and sort unique values
        vector<ll> nums(mp.size());
        for (auto &p : mp)
            nums.push_back(p.first);

        sort(begin(nums), end(nums));

        int n = nums.size();
        vector<ll> t(n, 0);
        //dp[i] = Maximum Total Damage if we start from index i
        
        long long result = INT_MIN;

        for (int i = n - 1; i >= 0; --i) {
            //skip current value
            ll skip = (i + 1 < n) ? t[i + 1] : 0;

            //take current value
            int j   = lower_bound(begin(nums) + i + 1, end(nums), nums[i] + 3) - begin(nums);
            ll take = nums[i] * mp[nums[i]] + ((j < n) ? t[j] : 0);

            t[i]   = max(skip, take);
            result = max(result, t[i]);
        }

        return result;
    }
};



/**************************************************************** JAVA ****************************************************************/
//Approach-1 - Recursion + Memoization
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
    private int n;
    private Map<Long, Long> freq;
    private long[] dp;

    private long solve(int i, List<Long> nums) {
        if (i >= n)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        // skip current damage
        long skip = solve(i + 1, nums);

        // take current damage
        int j = lowerBound(nums, i + 1, nums.get(i) + 3);
        long take = nums.get(i) * freq.get(nums.get(i)) + solve(j, nums);

        return dp[i] = Math.max(skip, take);
    }

    // Helper function to replicate C++ lower_bound
    private int lowerBound(List<Long> nums, int start, long target) {
        int low = start, high = nums.size();
        while (low < high) {
            int mid = (low + high) / 2;
            if (nums.get(mid) < target)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }

    public long maximumTotalDamage(int[] power) {
        freq = new HashMap<>();
        for (int x : power)
            freq.put((long)x, freq.getOrDefault((long)x, 0L) + 1);

        List<Long> nums = new ArrayList<>(freq.keySet());
        Collections.sort(nums);
        n = nums.size();
        dp = new long[n];
        Arrays.fill(dp, -1);

        return solve(0, nums);
    }
}




//Approach-2 - Bottom Up
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
    public long maximumTotalDamage(int[] power) {
        // Step 1: Frequency map
        Map<Long, Long> freq = new HashMap<>();
        for (int x : power)
            freq.put((long)x, freq.getOrDefault((long)x, 0L) + 1);

        // Step 2: Sort unique values
        List<Long> nums = new ArrayList<>(freq.keySet());
        Collections.sort(nums);
        int n = nums.size();
        long[] dp = new long[n];

        long result = Long.MIN_VALUE;

        for (int i = n - 1; i >= 0; i--) {
            // Skip current value
            long skip = (i + 1 < n) ? dp[i + 1] : 0;

            // Take current value
            int j = lowerBound(nums, i + 1, nums.get(i) + 3);
            long take = nums.get(i) * freq.get(nums.get(i)) + ((j < n) ? dp[j] : 0);

            dp[i] = Math.max(skip, take);
            result = Math.max(result, dp[i]);
        }

        return result;
    }

    // Helper for binary search (lower_bound equivalent)
    private int lowerBound(List<Long> nums, int start, long target) {
        int low = start, high = nums.size();
        while (low < high) {
            int mid = (low + high) / 2;
            if (nums.get(mid) < target)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
}
