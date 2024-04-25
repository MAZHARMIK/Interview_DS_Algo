/*    Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=01nYV8eqxm8
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/longest-ideal-subsequence/
*/


/************************************************************** C++ ******************************************************************/
//Approach-1 (Using LIS code eactly)
//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.length();
        
        int result = 1;
        vector<int> t(n, 1);
        //t[i] = Longest Ideal Subsequence ending at index i
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                
                if(abs(s[j] - s[i]) <= k) {
                    t[i] = max(t[i], t[j]+1);
                }
            }
            result = max(result, t[i]);
        }
        
        return result;
    }
};


//Approach-2 (Optimised - Chec only those characters for s[i] such that abs(ch - s[i]) <=k)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.length();
        
        vector<int> t(26, 0);
        
        int result = 0;
        
        for(int i = 0; i < n; i++) {
            
            int curr    = s[i]-'a';
            int left    = max(0, curr-k);
            int right   = min(25, curr+k);

            int longest = 0;
            for(int j = left; j <= right; j++) {
                longest = max(longest, t[j]);
            }
            
            t[curr] = max(t[curr], longest+1);
            result = max(result, t[curr]);
        }
        
        return result;
        
    }
};



/************************************************************** JAVA ******************************************************************/
//Approach-1 (Using LIS code eactly)
//T.C : O(n^2)
//S.C : O(n)
public class Solution {
    public int longestIdealString(String s, int k) {
        int n = s.length();
        
        int result = 1;
        int[] t = new int[n];
        Arrays.fill(t, 1);
        // t[i] = Longest Ideal Subsequence ending at index i
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                
                if(Math.abs(s.charAt(j) - s.charAt(i)) <= k) {
                    t[i] = Math.max(t[i], t[j]+1);
                }
            }
            result = Math.max(result, t[i]);
        }
        
        return result;
    }
}


//Approach-2 (Optimised - Chec only those characters for s[i] such that abs(ch - s[i]) <=k)
//T.C : O(n)
//S.C : O(1)
public class Solution {
    public int longestIdealString(String s, int k) {
        int n = s.length();
        
        int[] t = new int[26];
        
        int result = 0;
        
        for(int i = 0; i < n; i++) {
            
            int curr = s.charAt(i) - 'a';
            int left = Math.max(0, curr - k);
            int right = Math.min(25, curr + k);

            int longest = 0;
            for(int j = left; j <= right; j++) {
                longest = Math.max(longest, t[j]);
            }
            
            t[curr] = Math.max(t[curr], longest + 1);
            result = Math.max(result, t[curr]);
        }
        
        return result;
        
    }
}
