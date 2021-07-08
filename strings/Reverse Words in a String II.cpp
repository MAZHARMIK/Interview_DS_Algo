/*
    Company Tags  : Amazon, Microsoft, Uber, MentorGraphics
    Leetcode Link : https://leetcode.com/problems/reverse-words-in-a-string-ii/
    
    Since it's a Premium Qn, I have added Description and Example below
    
    Description

    Given an input character array, reverse the array word by word.
    A word is defined as a sequence of non-space characters.
    The input character array does not contain leading or trailing
    spaces and the words are always separated by a single space.
    
    Example

    Example1

    Input: s = "the sky is blue"

    Output: "blue is sky the"

    Example2

    Input: "a b c"

    Output: "c b a"

    Challenge

    Could you do it in-place without allocating extra space?
*/

//Approach-0 (use stack to store words and then collect them to form reversed string) O(n) space solution


//Approach-1 (O(n^2))
class Solution {
public:
    string reverseWords(string &str) {
        string result = "";
        int n = str.length();
        int i = n-1;
        int j = n-1;
        while(i >= 0) {
            if(str[i] == ' ') {
                result += str.substr(i+1, j-i) + " ";
                j = i-1;
            }
            i--;
        }
        result += str.substr(i+1, j-i);
        return result;
    }
};

//Approach-2 (O(no. of words * max_length_of_word) usin stringstream)
class Solution {
public:
    string reverseWords(string &str) {
        string result = "";
        stringstream ss(str);
        string token = "";

        while(ss >> token) {
            result = token + " " + result; //this is O(n) operation (prepending string)
        }
        
        return result.substr(0, result.length()-1);
    }
};
