/*
    MY YOUTUBE VIDEO ON THIS QN : 
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/
*/

/************************************************************ C++ ************************************************************/
//Approach (Using hash map store frequency)
//T.C : O(n)
//S.C : O(26)
class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        
        int count[26] = {0};
        
        for(string &word : words) {
            
            for(char &ch : word) {
                count[ch-'a']++;
            }
            
        }
        
        for(int i = 0; i < 26; i++) {
            if(count[i]%n != 0) {
                return false;
            }
        }
        
        return true;
        
    }
};


/************************************************************ C++ ************************************************************/
//Approach (Using hash map store frequency)
//T.C : O(n)
//S.C : O(26)
class Solution {
    public boolean makeEqual(String[] words) {
        int n = words.length;

        int[] count = new int[26];

        for (String word : words) {
            for (char ch : word.toCharArray()) {
                count[ch - 'a']++;
            }
        }

        for (int i = 0; i < 26; i++) {
            if (count[i] % n != 0) {
                return false;
            }
        }

        return true;
    }
}
