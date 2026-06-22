/*    Scroll below to see JAVA code also    */
/*
    MY YOUTUBE POST ON THIS Qn   : http://youtube.com/post/UgkxpbXF-rtqNwC0VuevvQQyVmfcPbgpAC2r?si=iAZLhxLp64RdkNU8
    Company Tags                 : will update later
    Leetcode Link                : https://leetcode.com/problems/maximum-number-of-balloons
*/


/********************************************************************* C++ *********************************************************************/
//Approach (Just find the one which is minimum)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int maxNumberOfBalloons(string text) { 
        int t[26] = {0};
        for(const char& ch : text) {
            t[ch-'a']++;
        }
        
        int count = INT_MAX;
        count = min(count, t['b'-'a']);
        count = min(count, t['a'-'a']);
        count = min(count, t['l'-'a']/2);
        count = min(count, t['o'-'a']/2);
        count = min(count, t['n'-'a']);
        
        return count;
    }
};



/********************************************************************* JAVA *********************************************************************/
//Approach (Just find the one which is minimum)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int maxNumberOfBalloons(String text) {
        int[] t = new int[26];
        for (char ch : text.toCharArray()) {
            t[ch - 'a']++;
        }
        
        int count = Integer.MAX_VALUE;
        count = Math.min(count, t['b' - 'a']);
        count = Math.min(count, t['a' - 'a']);
        count = Math.min(count, t['l' - 'a'] / 2);
        count = Math.min(count, t['o' - 'a'] / 2);
        count = Math.min(count, t['n' - 'a']);
        
        return count;
    }
}
