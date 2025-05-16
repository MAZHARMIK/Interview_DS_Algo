/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=reX7--RYbzw
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/total-characters-in-string-after-transformations-i
*/


/************************************************************ C++ *****************************************************/
//Approach - Using frequency count in map
//T.C : O(n+t)
//S.C : O(26) ~= O(1)
class Solution {
public: 
    int M = 1e9+7;
    int lengthAfterTransformations(string s, int t) {
        int n = s.length();
        //unordered_map<char, int> mp;
        vector<int> mp(26, 0);

        for(char &ch : s) {
            mp[ch - 'a']++;
        }

        for(int count = 1; count <= t; count++) { //O(t)
            //unordered_map<char, int> temp;
            vector<int> temp(26, 0);

            for(int i = 0; i < 26; i++) { //O(26)
                char ch  = i + 'a'; // 0->a, 1->b and so on
                int freq = mp[i];

                if(ch != 'z') {
                    temp[(ch+1) - 'a'] = (temp[(ch+1) - 'a'] + freq) % M;
                } else {
                    temp['a' - 'a'] = (temp['a' - 'a'] + freq) % M;
                    temp['b' - 'a'] = (temp['b' - 'a'] + freq) % M;
                }
            }

            mp = move(temp);
        }

        int result = 0;
        for(int i = 0; i < 26; i++) {
            result = (result + mp[i]) % M;
        }

        return result;
    }
};


/************************************************************ JAVA *****************************************************/
//Approach - Using frequency count in map
//T.C : O(n+t)
//S.C : O(26) ~= O(1)
class Solution {
    private final int M = 1_000_000_007;

    public int lengthAfterTransformations(String s, int t) {
        int[] mp = new int[26];

        for (char ch : s.toCharArray()) {
            mp[ch - 'a']++;
        }

        for (int count = 1; count <= t; count++) {
            int[] temp = new int[26];

            for (int i = 0; i < 26; i++) {
                char ch = (char) (i + 'a');
                int freq = mp[i];

                if (ch != 'z') {
                    temp[(ch + 1) - 'a'] = (temp[(ch + 1) - 'a'] + freq) % M;
                } else {
                    temp['a' - 'a'] = (temp['a' - 'a'] + freq) % M;
                    temp['b' - 'a'] = (temp['b' - 'a'] + freq) % M;
                }
            }

            mp = temp;
        }

        int result = 0;
        for (int i = 0; i < 26; i++) {
            result = (result + mp[i]) % M;
        }

        return result;
    }
}
