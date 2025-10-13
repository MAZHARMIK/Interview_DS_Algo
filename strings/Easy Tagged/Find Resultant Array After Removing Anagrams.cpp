/*    Scroll below to see JAVA code as well    */
/*
    MY YOUTUBE VIDEO ON THIS QN : https://www.youtube.com/watch?v=HK9CnjrpqlI
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/
*/

//SEE MY YOUTUBE VIDEO ABOVE FOR 4 MORE WAYS TO SOLVE THIS PROBLEM

/*************************************************************************** C++ ***************************************************************************/
//Approach (simple traverse and check)
//T.C : O(n*m)
//S.C : O(1)
class Solution {
public:
    bool checkAnagram(string &s1, string& s2) {
        int arr[26] = {0};

        for(char &ch : s1) {
            arr[ch-'a']++;
        }

        for(char &ch : s2) {
            arr[ch-'a']--;
        }
        
        for(int i = 0; i < 26; i++) {
            if(arr[i] != 0)
                return false;
        }

        return true;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();

        vector<string> result;

        result.push_back(words[0]);

        for(int i = 1; i < n; i++) {
            if(!checkAnagram(words[i], result.back())) {
                result.push_back(words[i]);
            }
        }

        return result;
    }
};




/*************************************************************************** JAVA ***************************************************************************/
//Approach (simple traverse and check)
//T.C : O(n*m)
//S.C : O(1)
public class Solution {

    private boolean checkAnagram(String s1, String s2) {
        if (s1.length() != s2.length()) {
            return false;
        }

        int[] arr = new int[26];

        for (int i = 0; i < s1.length(); i++) {
            arr[s1.charAt(i) - 'a']++;
        }

        for (int i = 0; i < s2.length(); i++) {
            arr[s2.charAt(i) - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (arr[i] != 0) {
                return false;
            }
        }

        return true;
    }

    public List<String> removeAnagrams(String[] words) {
        int n = words.length;
        List<String> result = new ArrayList<>();

        result.add(words[0]);

        for (int i = 1; i < n; i++) {
            String lastWord = result.get(result.size() - 1);
            if (!checkAnagram(words[i], lastWord)) {
                result.add(words[i]);
            }
        }

        return result;
    }
}
