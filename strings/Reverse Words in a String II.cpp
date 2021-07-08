/*
    Company Tags  : Amazon, Microsoft, Uber
    Leetcode Link : https://leetcode.com/problems/reverse-words-in-a-string-ii/
*/

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
