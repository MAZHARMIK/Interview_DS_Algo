/*    Scroll below to see JAVA code as well    */
/*
    MY YOUTUBE VIDEO ON THIS QN : 
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/count-binary-substrings
*/

/*************************************************************************** C++ ***************************************************************************/
//Approach (simple traverse and check)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.length();
        
        
        int result  = 0;
        int prev = 0;
        int curr = 1;
        for(int i = 1; i<n; i++) {
            if(s[i-1] != s[i]) {
                result += min(prev, curr);
                prev = curr;
                curr = 1;
            } else {
                curr++;
            }
        }
        
        return result + min(prev, curr);
    }
};




/*************************************************************************** JAVA ***************************************************************************/
//Approach (simple traverse and check)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int countBinarySubstrings(String s) {
        int result = 0;

        int prevCount = 0;
        int currCount = 1;

        for(int i = 1; i < s.length(); i++) {
            if(s.charAt(i) == s.charAt(i-1)) {
                currCount++;
            } else {
                result    += Math.min(prevCount, currCount);
                prevCount = currCount;
                currCount = 1;
            }
        }

        return result + Math.min(prevCount, currCount);
    }
}
