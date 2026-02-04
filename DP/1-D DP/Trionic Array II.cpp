/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/trionic-array-ii/description/
*/


/**************************************************************** C++ ****************************************************************/
//Approach (Recursion + Memoization)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    typedef long long ll;
    int n;
    vector<vector<ll>> memo;

    ll solve(int i, int trend, vector<int>& nums) {
        if(i == n) {
            if(trend == 3) {
                return 0; //no more elements, you reached out of bound
            } else {
                return LLONG_MIN/2; //invalid small value
            }
        }

        if(memo[i][trend] != LLONG_MIN) {
            return memo[i][trend];
        }

        ll take = LLONG_MIN/2;
        ll skip = LLONG_MIN/2;

        //skip
        if(trend == 0) {
            skip = solve(i+1, 0, nums);
        }

        //i am at trend 3 and i can now end at nums[i]
        if(trend == 3) {
            take = nums[i]; //finish it here
        }

        if(i+1 < n) {
            int curr = nums[i];
            int next = nums[i+1];

            if(trend == 0 && next > curr) {
                take = max(take, curr + solve(i+1, 1, nums));
            } else if(trend == 1) {
                if(next > curr) {
                    take = max(take, curr + solve(i+1, 1, nums));
                } else if(next < curr) {
                    take = max(take, curr + solve(i+1, 2, nums));
                }
            } else if(trend == 2) {
                if(next < curr) {
                    take = max(take, curr + solve(i+1, 2, nums));
                } else if(next > curr) {
                    take = max(take, curr + solve(i+1, 3, nums));
                }
            } else if(trend == 3 && next > curr) {
                take = max(take, curr + solve(i+1, 3, nums));
            }
        }
        
        return memo[i][trend] = max(take, skip);
    }

    ll maxSumTrionic(vector<int>& nums) {
        n = nums.size();

        memo.assign(n+1, vector<ll>(4, LLONG_MIN));

        return solve(0, 0, nums); //solve(i, trend = 0)
    }
};



/**************************************************************** JAVA ****************************************************************/
//Approach (Recursion + Memoization)
//T.C : O(n)
//S.C : O(n)
class Solution {
    int n;
    long[][] memo;
    static final long NEG_INF = Long.MIN_VALUE / 2;

    long solve(int i, int trend, int[] nums) {
        if (i == n) {
            return (trend == 3) ? 0 : NEG_INF;
        }

        if (memo[i][trend] != Long.MIN_VALUE) {
            return memo[i][trend];
        }

        long take = NEG_INF;
        long skip = NEG_INF;

        // Skip (only before sequence starts)
        if (trend == 0) {
            skip = solve(i + 1, 0, nums);
        }

        // If trionic pattern already completed, we can end here
        if (trend == 3) {
            take = nums[i];
        }

        if (i + 1 < n) {
            int curr = nums[i];
            int next = nums[i + 1];

            if (trend == 0 && next > curr) {
                take = Math.max(take, curr + solve(i + 1, 1, nums));
            } 
            else if (trend == 1) {
                if (next > curr) {
                    take = Math.max(take, curr + solve(i + 1, 1, nums));
                } else if (next < curr) {
                    take = Math.max(take, curr + solve(i + 1, 2, nums));
                }
            } 
            else if (trend == 2) {
                if (next < curr) {
                    take = Math.max(take, curr + solve(i + 1, 2, nums));
                } else if (next > curr) {
                    take = Math.max(take, curr + solve(i + 1, 3, nums));
                }
            } 
            else if (trend == 3 && next > curr) {
                take = Math.max(take, curr + solve(i + 1, 3, nums));
            }
        }

        return memo[i][trend] = Math.max(take, skip);
    }

    public long maxSumTrionic(int[] nums) {
        n = nums.length;
        memo = new long[n][4];

        // Initialize memo with "uncomputed"
        for (int i = 0; i < n; i++) {
            Arrays.fill(memo[i], Long.MIN_VALUE);
        }

        return solve(0, 0, nums);
    }
}
