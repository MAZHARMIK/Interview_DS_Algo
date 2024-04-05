/*         Scroll down to see JAVA code also     */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=J43ZIltH3AY
    Company Tags                : Google, Apple, LinkedIn, Microsoft
    Leetcode Link               : https://leetcode.com/problems/make-the-string-great/
*/


/********************************************************************** C++ ********************************************************/
//T.C : O(n)
//S.C : O(1) -> Ignoring the space taken for result string
class Solution {
public:
    string makeGood(string s) {
        string result = "";
        
        for(char &ch : s) {
            if(result.size() > 0 && (ch + 32 == result.back() || ch - 32 == result.back())) {
                result.pop_back();
            } else {
                result.push_back(ch);
            }
        }
        
        return result;
    }
};



/********************************************************************** JAVA ********************************************************/
//T.C : O(n)
//S.C : O(1) -> Ignoring the space taken for result string
public class Solution {
    public String makeGood(String s) {
        StringBuilder result = new StringBuilder();
        
        for (char ch : s.toCharArray()) {
            if (result.length() > 0 && (ch + 32 == result.charAt(result.length() - 1) || ch - 32 == result.charAt(result.length() - 1))) {
                result.deleteCharAt(result.length() - 1);
            } else {
                result.append(ch);
            }
        }
        
        return result.toString();
    }
}
