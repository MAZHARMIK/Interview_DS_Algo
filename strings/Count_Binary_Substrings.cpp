/*
    Company Tags  : Helix
    Leetcode Link : https://leetcode.com/problems/count-binary-substrings/
*/

//Approach-1 (Brute Force (TLE)
class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.length();
        int count = 0;
        for(int i = 0; i<n; i++) {
            string temp = "";
            char ch = s[i];
            int count_ch = 1;
            int j = i+1;
            while(j < n && s[j] == ch) {
                count_ch++;
                j++;
            }
            
            while(j < n && s[j] != ch) {
                count_ch--;
                if(count_ch == 0) {
                    count++;
                    break;
                }
                j++;
            }
        }
        
        return count;
    }
};

//Approach-2 (Accepted: O(n) space)
class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.length();
        vector<int> groups(n); //max there can be n groups (every consecutive character are different)
        int t = 0;
        groups[t] = 1;
        for(int i = 1; i<n; i++) {
            if(s[i-1] != s[i]) {
                groups[++t] = 1;
            } else {
                groups[t]++;
            }
        }
        
        int ans = 0;
        for(int  i = 1; i<=t; i++) {
            ans += min(groups[i-1], groups[i]);
        }
        
        return ans;
    }
};

//Notice above you only need the current group count and previous group count (groups[i-1], groups[i]). Let's keep track of them in the fly
//Approach-3 (Accepted : O(1) space)
class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.length();
        
        
        int ans  = 0;
        int prev = 0;
        int curr = 1;
        for(int i = 1; i<n; i++) {
            if(s[i-1] != s[i]) {
                ans += min(prev, curr);
                prev = curr;
                curr = 1;
            } else {
                curr++;
            }
        }
        
        return ans + min(prev, curr);
    }
};
