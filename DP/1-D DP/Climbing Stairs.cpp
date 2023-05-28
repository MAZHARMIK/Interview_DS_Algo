/*
    ADDED MY YOUTUBE VIDEO FOR THIS Qn  : https://www.youtube.com/watch?v=6OjGE04Kx_M
    Company Tags                        : Google, Amazon, OYO Rooms, Microsoft, Adobe, Flipkart, Siemens
    Leetcode Link                       : https://leetcode.com/problems/climbing-stairs/
    GfG Link                            : https://practice.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair-1587115620/1
    
    NOTE : For GfG, you need to take Module with pow(10, 9) + 7 (mentioned in the Qn) to avoid overflow
*/

//Approach-1 (Recursion with Memo) : Top Down
class Solution {
public:
    int t[46];
    int solve(int n){
        if(n == 0 || n == 1 || n == 2)
            return n;
        
        if(t[n] != -1)
            return t[n];
        
        int a = solve(n-1);
        int b = solve(n-2);
        
        return t[n] = a+b;
        
    }
    int climbStairs(int n) {
        memset(t, -1, sizeof(t));
        return solve(n);
    }
};


//Approach-2 (Using Bottom Up DP)
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1 || n == 2)
            return n;
        
        vector<int> t(n+1);
        
        //t[i] = total ways to climb i stairs
        t[0] = 0;
        t[1] = 1;
        t[2] = 2;
        
        for(int i = 3; i<=n; i++) {
            t[i] = t[i-1] + t[i-2];
        }
        
        return t[n];
    }
};


//Approach-3 (Improving approach-2) -
//See that it looks nothing but a fibonacci sequence. You just have to store last 2 values (t[i-1] & t[i-2]) to find current value (t[i])
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1 || n == 2 || n == 3)
            return n;
        
        int a = 1;
        int b = 2;
        int c = 3;
        
        for(int i = 3; i<=n; i++) {
            c = a + b;
            
            int temp_b = b;
            b = c;
            a = temp_b;
            
        }
        return c;
    }
};

