/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=8-6Mqs-p2I8
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments/
*/


/**************************************************************** C++ ****************************************************************/
//Approach (Simple traversal using two pointers)
//T.C : O(m+n)
//S.C : O(1)
class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int m = str1.length();
        int n = str2.length();
        if(n > m) {
            return false;
        }

        int i = 0;
        int j = 0;

        while(i < m && j < n) {
            if((str1[i] == str2[j])   ||
               (str1[i]+1 == str2[j]) ||
               (str1[i]-25 == str2[j])) {
                j++;
            }

            i++;
        }

        return j == n;
    }
};



/**************************************************************** JAVA ****************************************************************/
//Approach (Simple traversal using two pointers)
//T.C : O(m+n)
//S.C : O(1)
class Solution {
    public boolean canMakeSubsequence(String str1, String str2) {
        int m = str1.length();
        int n = str2.length();
        
        if (n > m) {
            return false;
        }
        
        int i = 0;
        int j = 0;
        
        while (i < m && j < n) {
            if ((str1.charAt(i) == str2.charAt(j)) || 
                (str1.charAt(i) + 1 == str2.charAt(j)) || 
                (str1.charAt(i) - 25 == str2.charAt(j))) {
                j++;
            }
            i++;
        }
        
        return j == n;
    }
}
