/*          Scroll down to see JAVA code also         */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=i8UYdogHsCA
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
        string str1 = to_string(num);
        string str2 = str1;

        int idx = str1.find_first_not_of('9');
        if(idx != string::npos) {
            char ch = str1[idx];
            replace(begin(str1), end(str1), ch, '9');
        }

        char ch = str2[0]; //given input will not have leading zero
        replace(begin(str2), end(str2), ch, '0');

        return stoi(str1) - stoi(str2);
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
        String str1 = Integer.toString(num);
        String str2 = str1;

        int idx = 0;
        for(int i = 0; i < str1.length(); i++) {
            if(str1.charAt(i) != '9') {
                idx = i;
                break;
            }
        }

        if(idx < str1.length()) {
            str1 = str1.replace(str1.charAt(idx), '9');
        }

        str2 = str2.replace(str2.charAt(0), '0');

        return Integer.parseInt(str1) - Integer.parseInt(str2);
    }
}
