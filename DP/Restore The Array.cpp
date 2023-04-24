/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=8FZo3dcConU
    Company Tags                : Google, Amazon, Microsoft, Uber
    Leetcode Link               : https://leetcode.com/problems/restore-the-array/
*/

//Approach-1 (Recur + Memo)
class Solution {
public:
    
    int n;
    
    const int MOD = 1e9+7;
    
    int solve(int start, string &s, int &k, vector<int>& t) {
        
        if(start >= n)
            return 1;
        
        if(t[start] != -1)
            return t[start];
        
        if(s[start] == '0')
            return t[start] = 0;
        
        long ans = 0;
        
        long long num = 0;
        
        for(int end = start; end < n; end++) {
            
            num = (num*10) + (s[end] - '0');
            
            if(num > k)
                break;
            
            ans = (ans%MOD + solve(end+1, s, k, t)%MOD)%MOD;
            
        }
        
        return t[start] = ans;
    }
    
    
    int numberOfArrays(string s, int k) {
        n = s.length();
        
        vector<int> t(n, -1);
        
        return solve(0, s, k, t);
    }
};


//Approach-2 (Bottom Up)
//Soon
