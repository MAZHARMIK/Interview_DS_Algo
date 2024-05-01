/*     Scroll below to see JAVA code also   */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=EH3EdJobbA8
    Company Tags                : Amazon (Need to double confirm on this)
    Leetcode Link               : https://leetcode.com/problems/reverse-prefix-of-word/
*/


/************************************************************ C++ ************************************************/
//Using simple loop and swap
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i = 0;
        int j = word.find(ch);
        
        while(i < j) {
            swap(word[i], word[j]);
            i++;
            j--;
        }
        
        return word;
        
    }
};


//Using Library Functions
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    string reversePrefix(string word, char ch) {
        reverse(begin(word), word.begin()+word.find(ch)+1);
        return word;
        
    }
};



/************************************************************ JAVA ************************************************/
//Using simple loop and swap
//T.C : O(n)
//S.C : O(1)
class Solution {
    public String reversePrefix(String word, char ch) {
        int i = 0;
        int j = word.indexOf(ch);
        
        char[] chars = word.toCharArray();
        while (i < j) {
            char temp = chars[i];
            chars[i] = chars[j];
            chars[j] = temp;
            i++;
            j--;
        }
        
        return new String(chars);
    }
}


//Using Library Functions
//T.C : O(n)
//S.C : O(1)
class Solution {
    public String reversePrefix(String word, char ch) {
        int index = word.indexOf(ch);
        if (index != -1) {
            return new StringBuilder(word.substring(0, index + 1)).reverse().toString() + word.substring(index + 1);
        }
        return word;
    }
}
