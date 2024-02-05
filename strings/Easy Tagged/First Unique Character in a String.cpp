/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=vqLiP9cdDLA
    Company Tags                : Amazon
    Leetcode Link               : https://leetcode.com/problems/first-unique-character-in-a-string/
*/


/******************************************************** C++ **********************************************************************/
//T.C : O(n)
//S.C : O(26) ~ O(1)
class Solution {
public:
    int firstUniqChar(string s) {
        int arr[26] = {0};
        
        for(char &ch : s) {
            arr[ch-'a']++;
        }
        
        
        for(int i = 0; i < s.length(); i++) {
            if(arr[s[i]-'a'] == 1) {
                return i;
            }
        }
        
        return -1;
    }
};


/******************************************************** JAVA **********************************************************************/
//T.C : O(n)
//S.C : O(1)
public class Solution {
    public int firstUniqChar(String s) {
        int[] arr = new int[26];
        
        for(char ch : s.toCharArray()) {
            arr[ch - 'a']++;
        }
        
        for(int i = 0; i < s.length(); i++) {
            if(arr[s.charAt(i) - 'a'] == 1) {
                return i;
            }
        }
        
        return -1;
    }
}
