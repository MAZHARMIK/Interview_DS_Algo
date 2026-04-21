/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=IKY4B7Yu7JA
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-i
*/


/************************************************************ C++ *****************************************************/
//Approach-1 (Constant time check of 0,2 and 1,3 indices)
//T.C : O(1)
//S.C : O(1)
class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        //index 0 and 2
        bool condition1 = (s1[0] == s2[0] && s1[2] == s2[2]) || (s1[0] == s2[2] && s1[2] == s2[0]);


        //index 1 and 3
        bool condition2 = (s1[1] == s2[1] && s1[3] == s2[3]) || (s1[1] == s2[3] && s1[3] == s2[1]);

        return condition1 && condition2;
    }
};



//Approach-2 - Using map for grouping even and odd indices
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        int even[26] = {0};
        int odd[26] = {0};

        int n = s1.length();

        for(int i = 0; i < 4; i++) {
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
//Approach-1 (Constant time check of 0,2 and 1,3 indices)
//T.C : O(1)
//S.C : O(1)
class Solution {
    public boolean canBeEqual(String s1, String s2) {
        // index 0 and 2
        boolean condition1 = 
            (s1.charAt(0) == s2.charAt(0) && s1.charAt(2) == s2.charAt(2)) ||
            (s1.charAt(0) == s2.charAt(2) && s1.charAt(2) == s2.charAt(0));

        // index 1 and 3
        boolean condition2 = 
            (s1.charAt(1) == s2.charAt(1) && s1.charAt(3) == s2.charAt(3)) ||
            (s1.charAt(1) == s2.charAt(3) && s1.charAt(3) == s2.charAt(1));

        return condition1 && condition2;
    }
}



//Approach-2 - Using map for grouping even and odd indices
//T.C : O(n)
//S.C : O(1)
class Solution {
    public boolean canBeEqual(String s1, String s2) {
        int[] even = new int[26];
        int[] odd = new int[26];

        int n = s1.length();

        for (int i = 0; i < 4; i++) {
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
