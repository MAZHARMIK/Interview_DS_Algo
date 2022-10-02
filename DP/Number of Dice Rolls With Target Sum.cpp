/*
    Company Tags          : Amazon, Microsoft
    Leetcode Link         : https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
    GfG Link (Dice Throw) : https://practice.geeksforgeeks.org/problems/dice-throw5349/1
*/

//Approach-1 (Recur + Memo) - It's Just Like coin change-2 (Only in this qn, assume that coin has k faces having different values)
class Solution {
public:
    long M = 1e9 + 7;
    int t[31][1001];
    int solve(int n, int k, int target) {
        if(target < 0 || n == 0)
            return target == 0 ? 1 : 0;
        
        if(t[n][target] != -1)
            return t[n][target];
        
        int sum = 0;
        
        for(int i = 1; i <= k; i++) {
            sum  = sum + solve(n-1, k, target-i);
            sum %= M;
        }
        
        return t[n][target] = sum;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        memset(t, -1, sizeof(t));
        return solve(n, k, target);
    }
};


//Approach-2 (Bottom Up) - It's Just Like coin change-2 (Only in this qn, assume that coin has k faces having different values)
class Solution {
public:
    long M = 1e9+7;
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> t(n+1, vector<int>(target+1));
        
        //t[i][j] = total ways to obtain j from exactly i dices
        
        t[0][0] = 1; 
        /*
            if(n == 0 && target == 0) we have found the target with all dices
            Or, understand it like this : 
            To obtain target 0 with 0 dices, how many ways  : 1
        */
        
        for(int i = 1; i <= n; i++) { //coin size loop (from coin change-2)
            for(int j = 1; j<= target; j++) { //target loop (from coin change-2)
                
                //Now since coin (here dice) has faces, so we need a loop for that too
                for(int f = 1; f <= k; f++) {
                    //face value should be always <= target
                    //so,
                    if(f <= j) {
                        t[i][j] = (t[i][j] + t[i-1][j-f])%M;
                    }
                }
            }
        }
        
        return t[n][target];
        
    }
};
