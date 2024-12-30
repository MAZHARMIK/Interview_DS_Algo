/*    Scroll below to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : Recur+Memo - https://www.youtube.com/watch?v=G-i4CveBSYI
                                  Bottom Up  - https://www.youtube.com/watch?v=SbB8tKCMtTE
    Company Tags                : META
    Leetcode Link               : https://leetcode.com/problems/count-ways-to-build-good-strings/
*/


/******************************************************** C++ ****************************************************************/
//Approach-1 (Using Recur + Memo)
//T.C : O(H)
//S.C : O(H)
class Solution {
public:
    int ans;
    int L, H;
    int Z, O;
    const int M = 1e9+7;
    
    int solve(int l, vector<int>& t) {
        
        if(l > H)
            return 0;
        
        if(t[l] != -1) {
            return t[l];
        }
        
        bool addOne = false;
        if(l >= L && l <= H) {
            addOne = true;
        }
        
        int take_zero = solve(l+Z, t);
        int take_one  = solve(l+O, t);
        
        return t[l] = (addOne + take_zero + take_one)%M;
        
    }
    
    int countGoodStrings(int low, int high, int zero, int one) {
        ans = 0;
        L = low;
        H = high;
        Z = zero;
        O = one;
        
        vector<int> t(H+1, -1);
        return solve(0, t);
    }
};


//Approach-2 (Bottom Up)
//T.C : O(H)
//S.C : O(H)
class Solution {
public:
    const int M = 1e9+7;
    
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> t(high+1, 0);
        //t[i] = Total number of good strings of length i
        
        t[0] = 1; //Only one good string ""
        
        for(int i = 1; i <= high; i++) {
            
            if(i - zero >= 0)
                t[i] = (t[i]%M + t[i-zero]%M)%M;
            
            if(i - one >= 0)
                t[i] = (t[i]%M + t[i-one]%M)%M;
            
        }
        
        int ans = 0;
        
        for(int l = low; l <= high; l++) {
            ans = (ans%M + t[l]%M)%M;
        }
        
        return ans;
    }
};


/******************************************************** JAVA ****************************************************************/
//Approach-1 (Using Recur + Memo)
//T.C : O(H)
//S.C : O(H)
class Solution {
    int ans;
    int L, H;
    int Z, O;
    final int M = 1_000_000_007;
    int[] dp;

    private int solve(int l) {
        if (l > H) {
            return 0;
        }

        if (dp[l] != -1) {
            return dp[l];
        }

        boolean addOne = false;
        if (l >= L && l <= H) {
            addOne = true;
        }

        int takeZero = solve(l + Z);
        int takeOne = solve(l + O);

        dp[l] = (addOne ? 1 : 0) + takeZero + takeOne;
        dp[l] %= M;

        return dp[l];
    }

    public int countGoodStrings(int low, int high, int zero, int one) {
        L = low;
        H = high;
        Z = zero;
        O = one;

        dp = new int[H + 1];
        Arrays.fill(dp, -1);

        return solve(0);
    }
}

//Approach-1 (Using Bottom Up)
//T.C : O(H)
//S.C : O(H)
class Solution {
    private final int M = 1_000_000_007;

    public int countGoodStrings(int low, int high, int zero, int one) {
        int[] t = new int[high + 1];
        // t[i] = Total number of good strings of length i

        t[0] = 1; // Only one good string ""

        for (int i = 1; i <= high; i++) {
            if (i - zero >= 0) {
                t[i] = (t[i] % M + t[i - zero] % M) % M;
            }
            if (i - one >= 0) {
                t[i] = (t[i] % M + t[i - one] % M) % M;
            }
        }

        int ans = 0;

        for (int l = low; l <= high; l++) {
            ans = (ans % M + t[l] % M) % M;
        }

        return ans;
    }
}
