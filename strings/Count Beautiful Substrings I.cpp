/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=ipobT-2_DkQ
    Company Tags                : will soon update
    Leetcode Link               : https://leetcode.com/problems/count-beautiful-substrings-i/
*/

/****************************************************************** C++ ******************************************************************/
//Approach : (Using Simple Finding substrings)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    int beautifulSubstrings(string s, int k) {
        int n = s.length();
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            int vowels = 0;
            int consonants = 0;

            for (int j = i; j < n; j++) {
                if (isVowel(s[j])) {
                    vowels++;
                } else {
                    consonants++;
                }

                if (vowels == consonants && (vowels * consonants) % k == 0) {
                    count++;
                }
            }
        }
        
        return count;
    }
};



/****************************************************************** JAVA ******************************************************************/
//Approach : (Using Simple Finding substrings)
//T.C : O(n^2)
//S.C : O(1)
public class Solution {
    public boolean isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    public int beautifulSubstrings(String s, int k) {
        int n = s.length();
        int count = 0;

        for (int i = 0; i < n; i++) {
            int vowels = 0;
            int consonants = 0;

            for (int j = i; j < n; j++) {
                if (isVowel(s.charAt(j))) {
                    vowels++;
                } else {
                    consonants++;
                }

                if (vowels == consonants && (vowels * consonants) % k == 0) {
                    count++;
                }
            }
        }

        return count;
    }
}
