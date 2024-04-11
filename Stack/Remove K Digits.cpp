/*         Scroll down to see JAVA code also        */
/*
    YOUTUBE LINK  : https://www.youtube.com/watch?v=lWcZB7l-O7M
    Company Tags  : Snapchat, Microsoft, Google, Meta
    Leetcode Link : https://leetcode.com/problems/remove-k-digits/
*/


/********************************************************************* C++ ***********************************************************/
//Using simple Monotonic Nature of Numbers
//T.C : O(n)
//S.C : O(1) - I am ignoring the space taken for result variable
class Solution {
public:
    string removeKdigits(string num, int k) {
        
        string result = ""; //it will act like a stack
        int n = num.length();
        
        for(int i = 0; i < n; i++) {
            
            while(result.length() > 0 && result.back() > num[i] && k > 0) {
                result.pop_back();
                k--;
            }
            
            if(result.length() > 0 || num[i] != '0') {
                result.push_back(num[i]); //to avoid the case when we have preceeding zeros
            }
            
        }
        
        
        while(result.length() > 0 && k > 0) {
            result.pop_back();
            k--;
        }

        if(result == "") {
            return "0";
        }
        
        return result;
        
    }
};


/************************************************************** JAVA ***************************************************/
//T.C : O(n)
//S.C : O(n)
public class Solution {
    public String removeKdigits(String num, int k) {
        StringBuilder result = new StringBuilder(); // it will act like a stack
        int n = num.length();
        
        for(int i = 0; i < n; i++) {
            while(result.length() > 0 && result.charAt(result.length() - 1) > num.charAt(i) && k > 0) {
                result.deleteCharAt(result.length() - 1);
                k--;
            }
            
            if(result.length() > 0 || num.charAt(i) != '0') {
                result.append(num.charAt(i)); // to avoid the case when we have preceding zeros
            }
        }
        
        while(result.length() > 0 && k > 0) {
            result.deleteCharAt(result.length() - 1);
            k--;
        }

        if(result.length() == 0) {
            return "0";
        }
        
        return result.toString();
    }
}
