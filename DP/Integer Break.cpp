/*
    MY YOUTUBE VIDEO ON THIS Qn : Recursion + Memoization - https://www.youtube.com/watch?v=iXtqfIrWMZg
                                  Bottom Up               - 
    Company Tags                : AMAZON
    Leetcode Link               : https://leetcode.com/problems/integer-break/
*/

/****************************************************** C++ ***********************************************************/
//Approach-1 (Recursion  + Memo)
//T.C : O(n^2) - Because we visit at max n states and at each state we run a for loop from 1 to n-1
//S.C : O(59) ~ O(1)
class Solution {
public:
    int t[59];
    int solve(int n ){
        
        if(n == 1)
            return 1;
        
        if(t[n] != -1)
            return t[n];
        
        int result = INT_MIN;
      
        for(int i = 1; i<n; i++) {
            int prod = i * max(n-i, solve(n-i));
            
            result = max(result, prod);
        }
        
        return t[n] = result;
        
    }
    
    int integerBreak(int n) {
        memset(t, -1, sizeof(t));
        return solve(n);
    }
};

//Approach-2 (Bottom Up)
//Don't worry, coming soon

/****************************************************** JAVA ***********************************************************/
//Approach-1 (Recursion  + Memo)
//T.C : O(n^2) - Because we visit at max n states and at each state we run a for loop from 1 to n-1
//S.C : O(59) ~ O(1)
class Solution {
    private int[] t;

    public int solve(int n) {
        if (n == 1)
            return 1;

        if (t[n] != -1)
            return t[n];

        int result = Integer.MIN_VALUE;

        for (int i = 1; i < n; i++) {
            int prod = i * Math.max(n - i, solve(n - i));
            result = Math.max(result, prod);
        }

        return t[n] = result;
    }

    public int integerBreak(int n) {
        t = new int[59];
        Arrays.fill(t, -1);
        return solve(n);
    }
}

//Approach-2 (Bottom Up)
//Don't worry, coming soon
