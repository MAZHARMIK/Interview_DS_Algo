/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=B7_jRUZPUCU
    Company Tags                : Goldman Sachs
    Leetcode Link               : https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/
*/

/************************************************************** C++ **************************************************************/
//Approach-1 (Simple concatenation)
//T.C : O(n*k) - n and m = length of word1 and word2 respectively
//S.C : O(n+k)
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1 = "";
        string s2 = "";
        
        for(string s:word1)
            s1 += s;
        
        for(string s:word2)
            s2 += s;
        
        return s1==s2;
    }
};


//Approach-2 (Using comparison character by character using index)
//T.C : O(n*k) - n and m = length of word1 and word2 respectively
//S.C : O(1)
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int m = word1.size();
        int n = word2.size();
        
        int w1i = 0; int i = 0;
        int w2i = 0; int j = 0;
        
        
        while(w1i < m && w2i < n) {
            if(word1[w1i][i] != word2[w2i][j])
                return false;
            
            i++;
            j++;
            
            if(i == word1[w1i].length()) {
                i = 0;
                w1i++;
            }
            
            if(j == word2[w2i].length()) {
                j = 0;
                w2i++;
            }
        }
        
        if(w1i == word1.size() && w2i == word2.size())
            return true;
        
        return false;
        
    }
};


/************************************************************** JAVA **************************************************************/
//Approach-1 (Simple concatenation)
//T.C : O(n*k) - n and m = length of word1 and word2 respectively
//S.C : O(n+k)
public class Solution {
    public boolean arrayStringsAreEqual(String[] word1, String[] word2) {
        StringBuilder s1 = new StringBuilder();
        StringBuilder s2 = new StringBuilder();

        for (String s : word1) {
            s1.append(s);
        }

        for (String s : word2) {
            s2.append(s);
        }

        return s1.toString().equals(s2.toString());
    }
}




//Approach-2 (Using comparison character by character using index)
//T.C : O(n*k) - n and m = length of word1 and word2 respectively
//S.C : O(1)
public class Solution {
    public boolean arrayStringsAreEqual(String[] word1, String[] word2) {
        int m = word1.length;
        int n = word2.length;

        int w1i = 0, i = 0;
        int w2i = 0, j = 0;

        while (w1i < m && w2i < n) {
            if (word1[w1i].charAt(i) != word2[w2i].charAt(j))
                return false;

            i++;
            j++;

            if (i == word1[w1i].length()) {
                i = 0;
                w1i++;
            }

            if (j == word2[w2i].length()) {
                j = 0;
                w2i++;
            }
        }

        return w1i == m && w2i == n;
    }
}
