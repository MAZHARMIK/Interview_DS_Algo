/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=qEJR7ox0mNI
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/count-number-of-homogenous-substrings/
*/

/************************************************************ C++ ************************************************************/
//Simple loop and count
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int MOD = 1e9+7;
    
    int countHomogenous(string s) {
        int n = s.length();
        int result = 0;
        int count  = 0;
        
        for(int i = 0; i<n; i++) {
            if(i > 0 && s[i] == s[i-1]) {
                count++;
            } else {
                count = 1;
            }
            
            result = (result + count) % MOD;
        }
        
        return result;
    }
};



/************************************************************ JAVA ************************************************************/
//Simple loop and count
//T.C : O(n)
//S.C : O(1)
class Solution {
    public static final int MOD = 1000000007;
    
    public int countHomogenous(String s) {
        int n = s.length();
        int result = 0;
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            if (i > 0 && s.charAt(i) == s.charAt(i - 1)) {
                count++;
            } else {
                count = 1;
            }
            
            result = (result + count) % MOD;
        }
        
        return result;
    }
}
