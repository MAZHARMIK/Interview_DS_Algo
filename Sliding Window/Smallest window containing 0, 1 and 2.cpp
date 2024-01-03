/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Paytm
    GfG Link                    : https://www.geeksforgeeks.org/problems/smallest-window-containing-0-1-and-2--170637/1
*/


/************************************************************ C++ **********************************************************************/
//Approach (Khandani Sliding Window template)
//T.C : O(n) -> No element is visited more than twice
//S.C : O(1)
class Solution {
  public:
    int smallestSubstring(string s) {
        int n = s.length();
        
        int i = 0, j = 0;
        
        int result = INT_MAX;
        int zero = 0;
        int one  = 0;
        int two  = 0;
        
        while(j < n) {
            if(s[j] == '0')
                zero++;
            else if(s[j] == '1')
                one++;
            else 
                two++;
            
            while(zero > 0 && one > 0 && two > 0 && j-i+1 >= 3) {
                result = min(result, j - i + 1);
                
                if(s[i] == '0') zero--;
                else if(s[i] == '1') one--;
                else if(s[i] == '2') two--;
                
                i++;
            }
            
            j++;
            
        }
        
        return result == INT_MAX ? -1 : result;
    }
};


/************************************************************ JAVA **********************************************************************/
//Approach (Khandani Sliding Window template)
//T.C : O(n) -> No element is visited more than twice
//S.C : O(1)
class Solution {
    public int smallestSubstring(String s) {
        int n = s.length();

        int i = 0, j = 0;

        int result = Integer.MAX_VALUE;
        int zero = 0;
        int one = 0;
        int two = 0;

        while (j < n) {
            if (s.charAt(j) == '0')
                zero++;
            else if (s.charAt(j) == '1')
                one++;
            else
                two++;

            while (zero > 0 && one > 0 && two > 0 && j - i + 1 >= 3) {
                result = Math.min(result, j - i + 1);

                if (s.charAt(i) == '0') zero--;
                else if (s.charAt(i) == '1') one--;
                else if (s.charAt(i) == '2') two--;

                i++;
            }

            j++;
        }

        return result == Integer.MAX_VALUE ? -1 : result;
    }
};
