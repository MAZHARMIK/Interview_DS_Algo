/*
    Company Tags     : Facebook, Uber, Google, Facebook, Microsoft
    Leetcode Link    : https://leetcode.com/problems/decode-ways/
    Four approaches  : Memoized, Top Down, Better Top Down, O(1) space DP
*/

class Solution {
public:
    int ways_better_top_down(string&s, int n) {
        //simply simulate the memoized version
        vector<int> t(n+1, 0);
        //t[i] = ways to decode string of length i
        t[n] = 1;
        
        for(int i = n-1; i>=0; i--) {
            if(s[i] == '0')
                t[i] = 0;
            else {
                t[i] = t[i+1];
                if(i < n-1 && (s[i] == '1' || (s[i] == '2' && s[i+1] < '7')))
                    t[i] += t[i+2];
            }
        }
        return t[0];
    }
    
    int ways_memoized(string &s, int n, int idx, vector<int>& t) {
        if(idx > n)
            return 0;
        if(t[idx] != -1)
            return t[idx];
        if(idx == n)
            return t[idx] = 1;
        
        if(s[idx] == '0')
            return t[idx] = 0;
        
        int result = ways_memoized(s, n, idx+1, t); //length 1
        //for length 2, we need to check if it doesn't cross 27
        if(idx < n-1) {
            if(s[idx] == '1' || (s[idx] == '2' && s[idx+1] < '7')) {
                result += ways_memoized(s, n, idx+2, t);
            }
        }
        return t[idx] = result;
    }
    
    int ways_top_down(string&s, int n) {
        vector<int> t(n+1, 0);
        //t[i] = ways to decode string of length i
        t[0] = 1;
        t[1] = s[0]=='0'?0:1;
        
        for(int i = 2; i<=n; i++) {            
            if(s[i-1] != '0')
                t[i] += t[i-1];
                
            if(s[i-2] == '1' || (s[i-2] == '2' && s[i-1] < '7'))
                t[i] += t[i-2];
            
        }
        return t[n];
    }
    
    int numDecodings(string &s) {
        int n = s.length();
        if(n == 0)
            return 0;
        vector<int> t(n+1, -1);
        //return ways_memoized(s, n, 0, t);
        //return ways_top_down(s, n);
        return ways_better_top_down(s, n);
    }
};


//Approach-4 (O(1) space DP)
class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if(n == 1)
            return s[0] == '0' ? 0 : 1;
        if(s[0] == '0')
            return 0;
        
        int last1 = 1, last2 = 1;
        
        for(int i = 1; i<n; i++) {
            int count = s[i] != '0' ? last1 : 0;
            
            if(s[i-1] == '1' || (s[i-1] == '2' && s[i] < '7'))
                count += last2;
            
            last2 = last1;
            last1  = count;
        }
        
        return last1;
    }
};
