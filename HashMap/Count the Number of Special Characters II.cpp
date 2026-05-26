/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/count-the-number-of-special-characters-ii/description/
    Part I of this problem      : http://youtube.com/post/UgkxA76EhTpRxCqK4apoG-YaaQ5Lao9VypAU?si=Gi0wKGIFA-kr9iaF
*/


/*********************************************************** C++ **************************************************/
//Approach (Track last occurrence of lowercase and first occurrence of uppercase)
//T.C : O(n)
//S.C : O(1) - fixed-size arrays of length 26
class Solution {
public:
    int numberOfSpecialChars(string word) {
        
        vector<int> lastSmall(26, -1);
        vector<int> firstCapital(26, -1);

        for(int i = 0; i < word.length(); i++) {
            
            char ch = word[i];

            if(islower(ch)) {
                lastSmall[ch - 'a'] = i;
            }
            else {
                if(firstCapital[ch - 'A'] == -1) {
                    firstCapital[ch - 'A'] = i;
                }
            }
        }

        int count = 0;

        for(int i = 0; i < 26; i++) {

            if(lastSmall[i] != -1 && firstCapital[i] != -1 &&
               lastSmall[i] < firstCapital[i]) {
                count++;
            }
        }

        return count;
    }
};


/*********************************************************** JAVA **************************************************/
//Approach(Track last occurrence of lowercase and first occurrence of uppercase)
//T.C : O(n)
//S.C : O(1) - fixed-size arrays of length 26
class Solution {
    public int numberOfSpecialChars(String word) {
        
        int[] lastSmall = new int[26];
        int[] firstCapital = new int[26];

        java.util.Arrays.fill(lastSmall, -1);
        java.util.Arrays.fill(firstCapital, -1);

        for(int i = 0; i < word.length(); i++) {
            
            char ch = word.charAt(i);

            if(Character.isLowerCase(ch)) {
                lastSmall[ch - 'a'] = i;
            }
            else {
                if(firstCapital[ch - 'A'] == -1) {
                    firstCapital[ch - 'A'] = i;
                }
            }
        }

        int count = 0;

        for(int i = 0; i < 26; i++) {

            if(lastSmall[i] != -1 && firstCapital[i] != -1 &&
               lastSmall[i] < firstCapital[i]) {
                count++;
            }
        }

        return count;
    }
}
