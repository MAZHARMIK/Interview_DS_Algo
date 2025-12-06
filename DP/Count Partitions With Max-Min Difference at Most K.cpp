/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Will update later
    Leetcode Link               : https://leetcode.com/problems/count-partitions-with-max-min-difference-at-most-k
*/


/**************************************************************** C++ ****************************************************************/
//Approach-1 (Recursion and Memoization)
//T.C : 
//S.C : 
class Solution {
public:
    int M = 1e9 + 7;
    int n;
    typedef long long ll;

    ll t[50000 + 1];

    ll solve(int i, vector<int>& nums, int k) {
        if (i >= n) // successfully formed partitions till end
            return 1;

        if (t[i] != -1)
            return t[i];

        ll count = 0;
        int minEl = INT_MAX;
        int maxEl = INT_MIN;

        for (int j = i; j < n; ++j) {
            minEl = min(minEl, nums[j]);
            maxEl = max(maxEl, nums[j]);

            if (maxEl - minEl > k)
                break;

            count = (count + solve(j + 1, nums, k)) % M;
        }

        return t[i] = count;
    }

    int countPartitions(vector<int>& nums, int k) {
        n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(0, nums, k);
    }
};



//Approach-2 (Bottom Up)
//T.C : 
//S.C : 



//Approach-3 (DP + Sliding Window)
//T.C : 
//S.C : 
class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        int n = nums.size();

        vector<int> dp(n + 1, 0);
        vector<int> pref(n + 1, 0);

        dp[0] = 1;
        pref[0] = 1;

        deque<int> minQ, maxQ;
        int i = 0, j = 0;

        while (j < n) {

            while (!maxQ.empty() && nums[j] > nums[maxQ.back()])
                maxQ.pop_back();
            maxQ.push_back(j);

            while (!minQ.empty() && nums[j] < nums[minQ.back()])
                minQ.pop_back();
            minQ.push_back(j);

            while (nums[maxQ.front()] - nums[minQ.front()] > k) {
                i++;
                if (!maxQ.empty() && maxQ.front() < i) maxQ.pop_front();
                if (!minQ.empty() && minQ.front() < i) minQ.pop_front();
            }

            dp[j + 1] = (pref[j] - (i > 0 ? pref[i - 1] : 0) + MOD) % MOD;
            pref[j + 1] = (pref[j] + dp[j + 1]) % MOD;

            j++;
        }

        return dp[n];
    }
};





/**************************************************************** JAVA ****************************************************************/
//Approach-1 (Recursion and Memoization)
//T.C : 
//S.C : 




//Approach-2 (Bottom Up)
//T.C : 
//S.C : 




//Approach-3 (DP + Sliding Window)
//T.C : 
//S.C : 
