/*          Scroll down to see JAVA code also         */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/maximum-difference-by-remapping-a-digit/description/
*/


/*************************************************************** C++ ***************************************************************/
//Approach-1 (Simple iterating on digits)
//T.C : O(log10(n))
//S.C : O(log10(n))
class Solution {
public:
    int minMaxDifference(int num) {
        string minNum = to_string(num);
        string maxNum = to_string(num);
        int n = minNum.length();

        char ch = ' ';
        for(int i = 0; i < n; i++) {
            if(maxNum[i] != '9') {
                ch = maxNum[i];
                break;
            }
        }

        for(int i = 0; i < n; i++) {
            if(maxNum[i] == ch) {
                maxNum[i] = '9';
            }
        }
        

        ch = minNum[0];
        for(int i = 0; i < n; i++) {
            if(minNum[i] == ch) {
                minNum[i] = '0';
            }
        }

        return stoi(maxNum) - stoi(minNum);

    }
};


//Approach-2 (Using C++ STLs)
//T.C : O(log10(n))
//S.C : O(log10(n))
class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string t = s;

        // Replace first non-'9' digit in s with '9' to maximize
        int pos = s.find_first_not_of('9');
        if (pos != string::npos) {
            char a = s[pos];
            replace(s.begin(), s.end(), a, '9');
        }

        // Replace all occurrences of the first digit in t with '0' to minimize
        char b = t[0];
        replace(t.begin(), t.end(), b, '0');

        return stoi(s) - stoi(t);
    }
};



/*************************************************************** JAVA ***************************************************************/
//Approach-1 (Simple iterating on digits)
//T.C : O(log10(n))
//S.C : O(log10(n))
class Solution {
    public int minMaxDifference(int num) {
        String minNum = Integer.toString(num);
        String maxNum = Integer.toString(num);
        int n = minNum.length();

        // Find the first digit in maxNum that is not '9' and replace all its occurrences with '9'
        char ch = ' ';
        for (int i = 0; i < n; i++) {
            if (maxNum.charAt(i) != '9') {
                ch = maxNum.charAt(i);
                break;
            }
        }

        if (ch != ' ') {
            maxNum = maxNum.replace(ch, '9');
        }

        // Replace all occurrences of the first digit in minNum with '0'
        ch = minNum.charAt(0);
        minNum = minNum.replace(ch, '0');

        return Integer.parseInt(maxNum) - Integer.parseInt(minNum);
    }
}


//Approach-2 (Using Java Standard Library functions)
//T.C : O(log10(n))
//S.C : O(log10(n))
class Solution {

    public int minMaxDifference(int num) {
        String s = Integer.toString(num);
        String t = s;
        
        int pos = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) != '9') {
                pos = i;
                break;
            }
        }

        if (pos < s.length()) {
            s = s.replace(s.charAt(pos), '9');
        }

        t = t.replace(t.charAt(0), '0');
        return Integer.parseInt(s) - Integer.parseInt(t);
    }
}
