/*
     MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=mdej8UiRCkI
    Company Tags                 : Amazon (With variations), Microsoft, MentorGraphics, MakeMyTrip, Accolite, Adobe, Cisco, Goldman Sachs,Paytm, 
                                   Samsung, SAP Labs
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

//Approach-2 (Two Pointer)
class Solution {
public:
    string reverseWords(string s) {
        //story
        //1. reverse whole string
        
        reverse(s.begin(), s.end());
        
        int i = 0;
        //hero honge hamare l and r jo revrese karenge words ko
        int l = 0, r = 0;
        
        int n = s.length();
        
        while(i < n) {
            while(i < n && s[i] != ' ') { //i ko agar char dikha to r ko dega and i++ and r++
                s[r++] = s[i++];
            }
            
            if(l < r) { //l     r
                reverse(s.begin()+l, s.begin()+r);
                
                s[r] = ' ';
                r++;
                
                l = r;
            }
            
            i++; //y eto badhta rahega
        }
        
        s = s.substr(0 , r-1);
        
        return s;
        
    }
};
