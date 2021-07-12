/*
     Company Tags  : Facebook
     Leetcode Link : https://leetcode.com/problems/decode-ways-ii/
*/

//Approach-1 (Recur + Memo) (TLE)
class Solution {
public:
    int n;
    int M= 1e9+7;
    int t[1000001];
    unordered_map<string, int> mp;
    long long solve(string s, int idx) {
        if(idx > n)
            return 0;
        
        if(idx == n)
            return 1;
        
        if(s[idx] == '0')
            return 0;
        
        if(t[idx] != -1)
            return t[idx];
        
        long long result = ((s[idx] == '*' ? 9 : 1 ) * solve(s, idx+1))%M;
        
        if(idx < n-1) {
            string last2 = s.substr(idx, 2); //get two digit number
            if((last2[0] == '*' || last2[1] == '*')) {
                result = (result+mp[last2]*solve(s, idx+2))%M;
                
            } else {
                
                if(s[idx] == '1' || (s[idx] == '2' && s[idx+1] < '7'))
                    result = (result + solve(s, idx+2))%M;
            }
        }
        
        return t[idx] = result;
    }
    
    int numDecodings(string s) {
        mp["**"] = 15; //{11, 12, 13, 14, 15, 16, 17, 18, 19, 21, 22, 23, 24, 25, 26}
        mp["1*"] = 9;  //{11, 12, 13, 14, 15, 16, 17, 18, 19}
        mp["2*"] = 6;  //{21, 22, 23, 24, 25, 26}
        mp["*0"] = 2;  //{10, 20}
        mp["*1"] = 2;  //{11, 21}
        mp["*2"] = 2;  //{12, 22}
        mp["*3"] = 2;  //{13, 23}
        mp["*4"] = 2;  //{14, 24}
        mp["*5"] = 2;  //{15, 25}
        mp["*6"] = 2;  //{16, 26}
        mp["*7"] = 1;  //{17}
        mp["*8"] = 1;  //{18}
        mp["*9"] = 1;  //{19}
        memset(t, -1, sizeof(t));
        n = s.length();
        return solve(s, 0);
    }
};

//Approach-2 (Recur + Memo without map : Accepted)
class Solution {
public:
    long mod = 1e9+7;
    int n;
    long solve(vector<long> &t, string &s, int idx) {
        if (idx == n)
            return 1;
        
        if (idx > s.length() || s[idx] == '0')
            return 0;
        
        if (t[idx] != -1)
            return t[idx];
        
        long last1 = solve(t, s, idx + 1) * (s[idx] == '*' ? 9  : 1);
        
        long last2 = 0;
        if (idx < n-1 && s[idx] < '3') {
            if (s[idx] == '*' && s[idx + 1] == '*')
                last2 = 15;
            else if (s[idx] == '*')
                last2 = s[idx + 1] < '7' ? 2 : 1;
            else if (s[idx + 1] == '*')
                last2 = s[idx] == '1' ? 9 : 6;
            else {
                int num = stoi(s.substr(idx, 2));
                last2 = num <= 26 ? 1 : 0;
            }
            last2 *= last2 ? solve(t, s, idx + 2) : 0;
        }
        
        return t[idx] = (last1 + last2) % mod;
    }
    
    int numDecodings(string s) {
        n = s.length();
        vector<long> t(s.size(), -1);
        return solve(t, s, 0);
    }
};


//Approach-3 (Bottom Up DP)
class Solution {
public:
    int M= 1e9+7;
    
    int numDecodings(string s) {
        static unordered_map<string, int> mp;
        mp["**"] = 15; //{11, 12, 13, 14, 15, 16, 17, 18, 19, 21, 22, 23, 24, 25, 26}
        mp["1*"] = 9;  //{11, 12, 13, 14, 15, 16, 17, 18, 19}
        mp["2*"] = 6;  //{21, 22, 23, 24, 25, 26}
        mp["*0"] = 2;  //{10, 20}
        mp["*1"] = 2;  //{11, 21}
        mp["*2"] = 2;  //{12, 22}
        mp["*3"] = 2;  //{13, 23}
        mp["*4"] = 2;  //{14, 24}
        mp["*5"] = 2;  //{15, 25}
        mp["*6"] = 2;  //{16, 26}
        mp["*7"] = 1;  //{17}
        mp["*8"] = 1;  //{18}
        mp["*9"] = 1;  //{19}
        
        int n = s.length();
        vector<long long> t(n+1, 0);
        t[n] = 1;
        
        for(int i = n-1; i>=0; i--) {
            if(s[i] == '0')
                t[i] = 0;
            else {
                t[i] = (s[i] == '*' ? 9 : 1) * t[i+1];
                if(i < n-1) {
                    string last2 = s.substr(i, 2); //get two digit number
                    if((last2[0] == '*' || last2[1] == '*')) {
                        t[i] = (t[i] + mp[last2]*t[i+2]) % M;

                    } else {

                        if(s[i] == '1' || (s[i] == '2' && s[i+1] < '7'))
                            t[i] = (t[i] + t[i+2]) % M;
                    }
                }
            }
        }
        return (int)t[0];
    }
};

//Approach-4 (Bottom Up O(1) space)
class Solution {
public:
    int M = 1e9+7;
    int numDecodings(string s) {
        static unordered_map<string, int> mp;
        mp["**"] = 15; //{11, 12, 13, 14, 15, 16, 17, 18, 19, 21, 22, 23, 24, 25, 26}
        mp["1*"] = 9;  //{11, 12, 13, 14, 15, 16, 17, 18, 19}
        mp["2*"] = 6;  //{21, 22, 23, 24, 25, 26}
        mp["*0"] = 2;  //{10, 20}
        mp["*1"] = 2;  //{11, 21}
        mp["*2"] = 2;  //{12, 22}
        mp["*3"] = 2;  //{13, 23}
        mp["*4"] = 2;  //{14, 24}
        mp["*5"] = 2;  //{15, 25}
        mp["*6"] = 2;  //{16, 26}
        mp["*7"] = 1;  //{17}
        mp["*8"] = 1;  //{18}
        mp["*9"] = 1;  //{19}
        
        int n = s.length();
        if(s[0] == '0')
            return 0;
        if(n == 1)
            return s[0] == '*' ? 9 : 1;
        
        
        long last1 = 1, last2 = 1;
        
        for(int i = n-1; i>=0; i--) {
            int count = 0;
            if(s[i] == '0')
                count = 0;
            else {
                count = (count + last1*(s[i] == '*' ? 9 : 1)) % M;
                if(i < n-1) {
                    string temp = s.substr(i, 2);
                    if(temp[0] == '*' || temp[1] == '*')
                        count = (count + last2*mp[temp]) % M;
                    else {
                        if(s[i] == '1' || (s[i] == '2' && s[i+1] < '7'))
                            count = (count + last2) % M;
                    }
                }
            }
            
            last2 = last1;
            last1 = count;
        }
        
        return (int)last1;
    }
};
