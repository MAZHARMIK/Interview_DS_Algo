/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=IKY4B7Yu7JA
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-ii
*/


/************************************************************ C++ *****************************************************/
//Approach - Using map for grouping even and odd indices
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int even[26] = {0};
        int odd[26] = {0};

        int n = s1.length();

        for(int i = 0; i < n; i++) {
            if(i%2 == 0) { //even indices
                even[s1[i] - 'a']++;
                even[s2[i] - 'a']--;
            } else { //odd indices
                odd[s1[i] - 'a']++;
                odd[s2[i] - 'a']--;
            }
        }

        for(int i = 0; i < 26; i++) {
            if(even[i] != 0 || odd[i] != 0)
                return false;
        }

        return true;
    }
};



/************************************************************ JAVA *****************************************************/
//Approach - Using map for grouping even and odd indices
//T.C : O(n)
//S.C : O(1)
class Solution {
    public boolean checkStrings(String s1, String s2) {
        int[] even = new int[26];
        int[] odd = new int[26];

        int n = s1.length();

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) { // even indices
                even[s1.charAt(i) - 'a']++;
                even[s2.charAt(i) - 'a']--;
            } else { // odd indices
                odd[s1.charAt(i) - 'a']++;
                odd[s2.charAt(i) - 'a']--;
            }
        }

        for (int i = 0; i < 26; i++) {
            if (even[i] != 0 || odd[i] != 0) {
                return false;
            }
        }

        return true;
    }
}
