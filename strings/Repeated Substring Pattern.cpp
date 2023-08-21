/*
    MY YOUTUBE VIDEO ON THIS Qn : https://youtu.be/7J8x0XudV0Y
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
************************************************ C++ ******************************************
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();

        //You can also try from l = n/2 to l = 1 -> for(int l = n/2; l >= 0; l--) //This can be helpful for large test valid cases to return early
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




************************************************ JAVA ******************************************
class Solution {
    public boolean repeatedSubstringPattern(String s) {
        int n = s.length();
        
        for (int l = n/2; l >= 1; l--) {
            
            if (n % l == 0) {
                
                int times = n/l;
                String pattern = s.substring(0, l);
                StringBuilder newStr = new StringBuilder();
                
                while(times > 0) {
                    newStr.append(pattern);
                    times--;
                }
                
                
                if (s.equals(newStr.toString())) {
                    return true;
                }
                
            }
        }
        
        return false;
    }
}
