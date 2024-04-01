/*    Scroll below to see JAVA code also  */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=hi0I4UiPu-M
    Company Tags                : AMAZON
    Leetcode Link               : https://leetcode.com/problems/length-of-last-word/
*/

/******************************************************************************* C++ **********************************************************************/
//Approach-1 (without library functions)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        if(n == 0)
            return 0;
        int i = n-1;
        while(i >=0 && s[i] == ' ')
            i--;
        
        int length = 0;
        for(; i>=0; i--) {
            if(s[i] == ' ')
                break;
            length++;
        }
        return length;
    }
};

//Approach-2 (Using library functions) - Not good for interviews
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int lengthOfLastWord(string s) {
        
        //s.find_last_not_of(' ') : This function searches for the last character in the string s that is not equal to the space character ' '. 
                                    //It returns the index of the last non-space character found, or string::npos if no such character is found.
        //s.erase(pos)            : This function removes characters from the string s, starting from the position pos specified as an argument.
                                    //It removes characters from pos until the end of the string.
        
        s.erase(s.find_last_not_of(' ') + 1); //Removes the trailing spaces
        
        // Find the last space character
        int lastSpace = s.find_last_of(' ');

        // Calculate the length of the last word
        return lastSpace == string::npos ? s.length() : s.length() - lastSpace - 1;
        
    }
};



/******************************************************************************* JAVA **********************************************************************/
//Approach-1 (without library functions)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int lengthOfLastWord(String s) {
        int n = s.length();
        if (n == 0)
            return 0;
        int i = n - 1;
        while (i >= 0 && s.charAt(i) == ' ')
            i--;

        int length = 0;
        for (; i >= 0; i--) {
            if (s.charAt(i) == ' ')
                break;
            length++;
        }
        return length;
    }
}


//Approach-2 (Using library functions) - Not good for interviews
//T.C : O(n)
//S.C : O(1)
public class Solution {
    public int lengthOfLastWord(String s) {
        /*
          \\s: This represents any whitespace character.
          +: This quantifier matches one or more occurrences of the preceding element, which in this case is whitespace characters.
          $: This asserts the position at the end of the input.
        */
        // Trim trailing spaces
        s = s.replaceAll("\\s+$", "");

        // Find the last space character
        int lastSpace = s.lastIndexOf(' ');

        // Calculate the length of the last word
        return lastSpace == -1 ? s.length() : s.length() - lastSpace - 1;
    }
}
