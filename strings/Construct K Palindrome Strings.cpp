/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Hh14hvVIHJc
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/construct-k-palindrome-strings
*/


/**************************************************************** C++ ****************************************************************/
//Approach - (Using the fact that odd frequency characters count control the palindromes count)
//T.C : O(n)
//S.C : O(26) ~ O(1)
class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.length();

        if(n < k) {
            return false;
        }

        if(n == k) {
            return true;
        }

        vector<int> vec(26, 0);
        for(char &ch : s) {
            vec[ch-'a']++;
        }

        int oddFreqCharCount = 0;
        for(int i = 0; i < 26; i++) {
            if(vec[i]%2 != 0) {
                oddFreqCharCount++;
            }
        }

        return oddFreqCharCount <= k;
    }
};


/**************************************************************** JAVA ****************************************************************/
//Approach - (Using the fact that odd frequency characters count control the palindromes count)
//T.C : O(n)
//S.C : O(26) ~ O(1)
class Solution {
    public boolean canConstruct(String s, int k) {
        int n = s.length();

        if(n < k) {
            return false;
        }

        if(n == k) {
            return true;
        }

        int[] vec = new int[26];
        for(char ch : s.toCharArray()) {
            vec[ch-'a']++;
        }

        int oddFreqCharCount = 0;

        for(int i = 0; i < 26; i++) {
            if(vec[i]%2 != 0) {
                oddFreqCharCount++;
            }
        }

        return oddFreqCharCount <= k;
    }
}
