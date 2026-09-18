/*         Scroll down to see JAVA code also                    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=SlSPlKmuKwY
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/description/
*/


/********************************************************************* C++ ****************************************************************/
//Approach (Greedy + two pointers)
//T.C : O(n)
//S.C : O(26)
class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();

        vector<int> start(26, -1);
        vector<int> end(26, 0);
        vector<bool> isValid(26, true);

        vector<string> result;

        for(int i = 0; i < n; i++) {
            int idx = s[i] - 'a';

            if(start[idx] == -1) {
                start[idx] = i;
            }
            end[idx] = i;
        }

        for(int c = 0; c < 26; c++) { //checking all characters
            if(start[c] == -1) continue;

            
            for(int i = start[c]; i <= end[c]; i++) {
                if(start[s[i]-'a'] < start[c]) {
                    isValid[c] = false;
                    break;
                }

                end[c] = max(end[c], end[s[i]-'a']);
            }
        }

        int lastTakenStart = INT_MAX;

        for(int i = n-1; i >= 0; i--) {
            int c = s[i] - 'a';

            if(!isValid[c]) continue;

            if(i == start[c] && end[c] < lastTakenStart) {
                result.push_back(s.substr(i, end[c] - i + 1));
                lastTakenStart = i;
            }
        }
        return result;
    }
};



/********************************************************************* JAVA ****************************************************************/
//Approach (Greedy + two pointers)
//T.C : O(n)
//S.C : O(26)
class Solution {
    public List<String> maxNumOfSubstrings(String s) {
        int n = s.length();

        int[] start = new int[26];
        int[] end = new int[26];
        boolean[] isValid = new boolean[26];

        Arrays.fill(start, -1);
        Arrays.fill(isValid, true);

        List<String> result = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            int idx = s.charAt(i) - 'a';

            if (start[idx] == -1) {
                start[idx] = i;
            }
            end[idx] = i;
        }

        for (int c = 0; c < 26; c++) { // checking all characters
            if (start[c] == -1) continue;

            for (int i = start[c]; i <= end[c]; i++) {
                int ch = s.charAt(i) - 'a';
                if (start[ch] < start[c]) {
                    isValid[c] = false;
                    break;
                }

                end[c] = Math.max(end[c], end[ch]);
            }
        }

        int lastTakenStart = Integer.MAX_VALUE;

        for (int i = n - 1; i >= 0; i--) {
            int c = s.charAt(i) - 'a';

            if (!isValid[c]) continue;

            if (i == start[c] && end[c] < lastTakenStart) {
                result.add(s.substring(i, end[c] + 1));
                lastTakenStart = i;
            }
        }

        return result;
    }
}
