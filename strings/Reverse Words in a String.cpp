/*
     MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                 : Amazon (With variations), Microsoft, MentorGraphics, MakeMyTrip, Accolite, Adobe, Cisco, Goldman Sachs,Paytm, Samsung, SAP Labs
    Leetcode Link                : https://leetcode.com/problems/reverse-words-in-a-string/
*/

//Approach-1 (Perfect use of std::stringstream)
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string token = "";

        string result = "";
        //By default stringstream tokenizes on ' ' (space character)
        //Know more : https://github.com/MAZHARMIK/Cpp-STL-Quick-Help/blob/main/README.md
        while(ss >> token) {
            result = token + " " + result;
        }

        return result.substr(0, result.length()-1);
    }
};

//Approach-2 (Using simple loop)
class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string result;
        int i = 0;
        while(i<n) {
            while(i < n && s[i] == ' ')
                i++;
            if(i >= n)
                break;
            int j = i+1;
            while(j < n && s[j] != ' ')
                j++;
            string temp = s.substr(i, j-i);
            if(result.length() == 0)
                result = temp;
            else
                result = temp + " " + result;
            i = j+1;
        }
        return result;
    }
};
