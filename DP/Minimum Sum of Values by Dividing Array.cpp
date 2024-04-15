/*    Scroll below to see JAVA code also   */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=JToq_-hQxv8
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/minimum-sum-of-values-by-dividing-array/
*/

/***************************************************************** C++ *******************************************************/
//Approach - 1 (Recursion + Memoization)
//T.C : O(n*11*log(max element in nums))
//S.C : O(n*11*log(max element in nums))
class Solution {
public:
    int n;
    int m;
    
    vector<vector<unordered_map<int, int>>> dp;
    
    int solve(vector<int>& nums, vector<int>& andValues, int i, int j, int andOp) {
        
        if(i >= n) {
            if(j >= m) {
                return 0;
            } else {
                return 1e9;
            }
        } else if(j >= m) {
            return 1e9;
        }
        
        if(dp[i][j].count(andOp)) {
            return dp[i][j][andOp];
        }
        
        int take_i = 1e9;
        
        if((andOp & nums[i]) == andValues[j]) {
            take_i = nums[i] + solve(nums, andValues, i+1, j+1, ((1<<17)-1)); //You can pass -1 as well for initial value of andOp
        }
        
        int not_take_i = solve(nums, andValues, i+1, j, (andOp & nums[i]));
        
        
        return dp[i][j][andOp] = min(take_i, not_take_i);
        
    }
    
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        n = nums.size();
        
        m = andValues.size();
        
        dp.resize(n+1, vector<unordered_map<int, int>>(11));
        
        int result = solve(nums, andValues, 0, 0, ((1<<17)-1)); //You can pass -1 as well for initial value of andOp
         /*
            Why (1<<1 7 - 1) is the initial value of AndVal ?
            Because we need an initial value which doesn't impact the first number.
            We can't take 1 because this will impact the And operation result.
            So we need an initial value which will not impact the first number And operation
            So, take a value which has all 1s so that nums[i] & AndVal = nums[i] for this initial AndVal
            Now, 0 <= andValues[j] < 10^5
            So, 10^5 can be represented in binary as 11000011010100000 (17 bits)
            So, I have tried to keep AndVal initial value as "11111111111111111" (17 bits)
            You can create this using trick - [(1 << 17)-1] 
        */ 
        
        
        return result == 1e9 ? -1 : result;
    }
};


/***************************************************************** JAVA *******************************************************/
//Approach - 1 (Recursion + Memoization)
//T.C : O(n*11*log(max element in nums))
//S.C : O(n*11*log(max element in nums))
class Solution {
    int m;
    int n;
    
    Map<Integer, Integer>[][] dp;
    
    int solve(int[] nums, int[] andValues, int i, int j, int AndVal) {
        if(i >= n){
            if(j >= m) 
                return 0;
            else //invalid case
                return (int)1e9;
        } else if(j >= m) {
            return (int)1e9;
        }
        
        if(dp[i][j] != null && dp[i][j].containsKey(AndVal)) 
            return dp[i][j].get(AndVal);

        int inclu = (int)1e9;
        
        if((AndVal & nums[i]) == andValues[j]) {
            inclu = nums[i] + solve(nums, andValues, i+1, j+1, ((1<<17)-1)); //You can pass -1 as well for initial value of andOp
        }
        
        int exclu = solve(nums, andValues, i+1, j, (AndVal&nums[i]));

        int result = Math.min(inclu, exclu);
        if (dp[i][j] == null) {
            dp[i][j] = new HashMap<>();
        }
        dp[i][j].put(AndVal, result);
        return result;
    }
    
    int minimumValueSum(int[] nums, int[] andValues) {
        n = nums.length;
        m = andValues.length;
        
        dp = new HashMap[n+1][11];
        /*
            Why (1<<7 - 1) is the initial value of AndVal ?
            Because we need an initial value which doesn't impact the first number.
            We can't take 1 because this will impact the And operation result.
            So we need an initial value which will not impact the first number And operation
            So, take a value which has all 1s so that nums[i] & AndVal = nums[i] for this initial AndVal
            Now, 0 <= andValues[j] < 10^5
            So, 10^5 can be represented in binary as 11000011010100000 (17 bits)
            So, I have tried to keep AndVal initial value as "11111111111111111" (17 bits)
            You can create this using trick - [(1 << 17)-1]
        */
        int ans = solve(nums, andValues, 0, 0, ((1<<17)-1)); //You can pass -1 as well for initial value of andOp

        if(ans == (int)1e9) 
            return -1;
        
        return ans;
    }
}
