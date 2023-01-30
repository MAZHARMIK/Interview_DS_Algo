/*
    Company Tags  : 
    Leetcode Link : https://leetcode.com/problems/n-th-tribonacci-number/
*/

//Approach-1 (Recursion + Memoization)
class Solution {
public:
    int t[38];
    int find(const int& n) {
        if(n == 0)           return 0;
        if(n == 1 || n == 2) return 1;
        if(t[n] != -1)       return t[n];
        
        t[n-1] = t[n-1] == -1 ? find(n-1) : t[n-1];
        t[n-2] = t[n-2] == -1 ? find(n-2) : t[n-2];
        t[n-3] = t[n-3] == -1 ? find(n-3) : t[n-3];
        
        return t[n] = t[n-1]+t[n-2]+t[n-3];
    }
    int tribonacci(int n) {
        memset(t, -1, sizeof(t));
        
        return find(n);
    }
};


//Approach-2 (Using Bottom Up DP)
class Solution {
public:
    int tribonacci(int n) {
        static int t[38];
        memset(t, -1, sizeof(t));
        
        if(t[n] != -1) return t[n];
        
        t[0] = 0;
        t[1] = 1;
        t[2] = 1;
        
        for(int i = 0; i<=34; i++)
            t[i+3] = t[i] + t[i+1] + t[i+2];
        
        return t[n];
    }
};
