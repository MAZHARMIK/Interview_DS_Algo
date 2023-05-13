/*
    MY YOUTUBE VIDEO ON THIS Qn : <soon>
    Company Tags                : META
    Leetcode Link               : https://leetcode.com/problems/count-ways-to-build-good-strings/
*/

//Approach-1 (Using Recur + Memo)
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
