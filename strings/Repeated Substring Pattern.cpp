/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : AMAZON, GOOGLE
    Leetcode Link               : https://leetcode.com/problems/repeated-substring-pattern/
*/

//T.C : O(n * root(n))
/*
  The "if(n%l == 0)" body will only run for divisors of n. 
  There can be 2*root(n) divisors of a number n.
  Inside if condition, we call substr which takes n and also run a for loop for n/l times ----- n + n/l ~ O(n)

  So, Time complexity becomes = O(2* root(n) * n)  ~~ O(n * root(n))
*/
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        
        for(int l = 1; l <= n/2; l++) {
            
            if(n%l == 0) {
                int times = n/l;
                
                string pattern   = s.substr(0, l);
                string newStr = "";
                while(times--) {
                    newStr += pattern;
                }
                
                if(newStr == s)
                    return true;
            }
            
        }
        
        return false;
    }
};
