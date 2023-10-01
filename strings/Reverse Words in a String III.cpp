/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=c-cT9b2YyXk
    Company Tags                : Zappos, MentorGraphics
    Leetcode Link               : https://leetcode.com/problems/reverse-words-in-a-string-iii/
*/

/******************************************************** C++ ******************************************************************/ 
//Approach-1 (Simple traversal)
class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            
            if (s[i] != ' ') {
                
                int j = i;
                
                while( j < n && s[j] != ' ') {
                    j++;
                }
                
                reverse(s.begin() + i, s.begin() + j);
                
                i = j;
            }
            
        }
        
        return s;
    }
};

//Approach-2 (Using stringstream in C++)
class Solution {
public:
    string reverseWords(string &s) {
        stringstream ss(s);

        string result = "";
        string token = "";

        while(ss >> token) {
            reverse(begin(token), end(token));
            result += token + " ";
        }

        return result.substr(0, result.length()-1);
    }
};


/******************************************************** JAVA ******************************************************************/
//Approach-1 (Simple traversal)
public class Solution {
    public String reverseWords(String s) {
        int n = s.length();
        
        char[] result = s.toCharArray();
        
        for (int i = 0; i < n; i++) {
            
            if (result[i] != ' ') {
                int j = i;
                while (j + 1 < n && result[j + 1] != ' ') { 
                    j++; 
                }
                reverse(result, i, j);
                i = j;
            }
        }
        
        return new String(result);
    }

    private void reverse(char[] result, int i, int j) {
        while(i < j) {
            char tmp = result[i];
            result[i] = result[j];
            result[j] = tmp;
            
            i++;
            j--;
        }
    }
}


//Approach-2 (Using string tokenizer in java)
public class Solution {
    public String reverseWords(String s) {
        StringTokenizer tokenizer = new StringTokenizer(s);
        StringBuilder result = new StringBuilder();

        while (tokenizer.hasMoreTokens()) {
            String token = tokenizer.nextToken();
            StringBuilder reversedToken = new StringBuilder(token).reverse();
            result.append(reversedToken).append(" ");
        }

        // Remove the trailing space
        if (result.length() > 0) {
            result.setLength(result.length() - 1);
        }

        return result.toString();
    }
}
