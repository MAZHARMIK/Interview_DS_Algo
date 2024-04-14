/*    Scroll below to see JAVA code also   */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/minimum-sum-of-values-by-dividing-array/
*/

/***************************************************************** C++ *******************************************************/
//Approach - 1 (Recursion + Memoization)
//T.C : O(n*11*log(max element in nums))
//S.C : O(n*11*log(max element in nums))
class Solution {
public:
    int m;
    int n;
    
    vector<vector<unordered_map<int,int>>> dp;
    
    int helper(vector<int>& nums, vector<int>& andValues, int i, int j, int AndVal) {
        if(i >= m){
            if(j >= n) 
                return 0;
            else //invalid case
                return 1e9;
        } else if(j >= n) {
            return 1e9;
        }
        
        if(dp[i][j].count(AndVal)) 
            return dp[i][j][AndVal];

        int inclu = 1e9;
        
        if((AndVal & nums[i]) == andValues[j]) {
            inclu = nums[i] + helper(nums, andValues, i+1, j+1, ((1<<17)-1));
        }
        
        int exclu = helper(nums, andValues, i+1, j, (AndVal&nums[i]));

        return dp[i][j][AndVal] = min(inclu, exclu);
    }
    
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        m = nums.size();
        n = andValues.size();
        
        dp.resize(m+1, vector<unordered_map<int,int>>(11));
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
        int ans = helper(nums, andValues, 0, 0, ((1<<17)-1));

        if(ans == 1e9) 
            return -1;
        
        return ans;
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
    
    int helper(int[] nums, int[] andValues, int i, int j, int AndVal) {
        if(i >= m){
            if(j >= n) 
                return 0;
            else //invalid case
                return (int)1e9;
        } else if(j >= n) {
            return (int)1e9;
        }
        
        if(dp[i][j] != null && dp[i][j].containsKey(AndVal)) 
            return dp[i][j].get(AndVal);

        int inclu = (int)1e9;
        
        if((AndVal & nums[i]) == andValues[j]) {
            inclu = nums[i] + helper(nums, andValues, i+1, j+1, ((1<<17)-1));
        }
        
        int exclu = helper(nums, andValues, i+1, j, (AndVal&nums[i]));

        int result = Math.min(inclu, exclu);
        if (dp[i][j] == null) {
            dp[i][j] = new HashMap<>();
        }
        dp[i][j].put(AndVal, result);
        return result;
    }
    
    int minimumValueSum(int[] nums, int[] andValues) {
        m = nums.length;
        n = andValues.length;
        
        dp = new HashMap[m+1][11];
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
        int ans = helper(nums, andValues, 0, 0, ((1<<17)-1));

        if(ans == (int)1e9) 
            return -1;
        
        return ans;
    }
}
