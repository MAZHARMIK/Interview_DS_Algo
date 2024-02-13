/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=JPB_lLGSgnc
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/find-first-palindromic-string-in-the-array
*/

/****************************************************************** C++ ******************************************************************/
//Approach-1 (creating a reversed string)
//T.C : O(m*n) - m = number of words, n = max length length of words
//S.C : O(n) - Creating a reversed string
class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        
        
        for(string &word : words) {
            if(word == string(rbegin(word), rend(word))) {
                return word;
            }
        }
        
        return "";
        
    }
};


//Approach-2 (using equal)
//T.C : O(m*n) - m = number of words, n = max length length of words
//S.C : O(1)
class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        
        
        for(string &word : words) {
            if(equal(word.begin(), word.begin() + word.size() / 2, word.rbegin())) {
                return word;
            }
        }
        
        return "";
        
    }
};



/****************************************************************** JAVA ******************************************************************/
//Approach-1 (creating a reversed string)
//T.C : O(m*n) - m = number of words, n = max length length of words
//S.C : O(n) - Creating a reversed string
class Solution {
    public String firstPalindrome(String[] words) {
        for (String word : words) {
            String reversed = new StringBuilder(word).reverse().toString();

            if (word.equals(reversed)) {
                return word;
            }
        }
        return "";
    }
}


//Approach-2 (using 2 pointer)
//T.C : O(m*n) - m = number of words, n = max length length of words
//S.C : O(1)
public class Solution {
    public String firstPalindrome(List<String> words) {
        for (String word : words) {
            if (isPalindrome(word)) {
                return word;
            }
        }
        return "";
    }

    private boolean isPalindrome(String word) {
        int length = word.length();
        for (int i = 0; i < length / 2; i++) {
            if (word.charAt(i) != word.charAt(length - 1 - i)) {
                return false;
            }
        }
        return true;
    }
}
