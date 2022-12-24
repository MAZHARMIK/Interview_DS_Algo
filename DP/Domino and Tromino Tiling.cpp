/*
    MY YOUTUBE VIDEO FOR THIS Qn  : https://www.youtube.com/watch?v=Iwmn-gFL3c0
    Company Tags                  : Google
    Leetcode Link                 : https://leetcode.com/problems/domino-and-tromino-tiling/
*/

//NOTE : See the YouTube video above for the easiest explanation and intuition

//Approach-1 (Recur + Memo) : O(n)
class Solution {
public:
    int M = 1000000007;
    int t[1001];
    int solve(int n) {
         if(n == 1 || n == 2)
            return n;
        if(n == 3)
            return 5;
        
        if(t[n] != -1)
            return t[n];
        
        return t[n] = (2*solve(n-1)%M + solve(n-3)%M)%M;
    }
    
    int numTilings(int n) {
       
        memset(t, -1, sizeof(t));
        
        
        return solve(n);
        
    }
};

//Approach-2 (Bottom Up) : O(n)
class Solution {
public:
    int M = 1000000007;
    int numTilings(int n) {
        if(n == 1 || n == 2)
            return n;
        
        vector<int> t(n+1, 0);
        
        t[1] = 1;
        t[2] = 2;
        t[3] = 5;
        
        for(int i = 4; i<=n; i++) {
            t[i] = (2*t[i-1]%M + t[i-3]%M) % M;
        }
        
        return t[n];
        
        
    }
};
