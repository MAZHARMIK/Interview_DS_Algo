/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer/
*/


/************************************************************ C++ ************************************************/
//Approach (replacing with 9 for maximum and carefully minimizing the number using greedy)
//T.C : O(log10(num))
//S.C : O(log10(num))
class Solution {
public:
    int maxDiff(int num) {
        string str1 = to_string(num);
        string str2 = str1;

        int idx = str1.find_first_not_of('9');
        if(idx != string::npos) {
            char ch = str1[idx];
            replace(begin(str1), end(str1), ch, '9');
        }

        //We can't directly choose 0th index character and make it 0
        //because qn says we can't have leading zeros
        for(int i = 0; i < str2.length(); i++) {
            char ch = str2[i];
            if(i == 0) {
                if(ch != '1') {
                    replace(begin(str2), end(str2), ch, '1');
                    break;
                }
            } else if(ch != '0' && ch != str2[0]) {
                //example : 111, even if we skip 1 at str2[0], we see again at str2[1]
                //But we can't change 1 to 0 because it will replace 1 of str2[0] as well
                replace(begin(str2), end(str2), ch, '0');
                break;
            }
        }
        return stoi(str1) - stoi(str2);
    }
};


/************************************************************ JAVA ************************************************/
//Approach (replacing with 9 for maximum and carefully minimizing the number using greedy)
//T.C : O(log10(num))
//S.C : O(log10(num))
class Solution {
    public int maxDiff(int num) {
        String str1 = Integer.toString(num);
        String str2 = str1;

        // Create max number by replacing first non-9 digit with 9
        int idx = -1;
        for (int i = 0; i < str1.length(); i++) {
            if (str1.charAt(i) != '9') {
                idx = i;
                break;
            }
        }

        if (idx != -1) {
            char ch = str1.charAt(idx);
            str1 = str1.replace(ch, '9');
        }

        // Create min number with care to avoid leading zeros
        for (int i = 0; i < str2.length(); i++) {
            char ch = str2.charAt(i);
            if (i == 0) {
                if (ch != '1') {
                    str2 = str2.replace(ch, '1');
                    break;
                }
            } else if (ch != '0' && ch != str2.charAt(0)) {
                str2 = str2.replace(ch, '0');
                break;
            }
        }

        return Integer.parseInt(str1) - Integer.parseInt(str2);
    }
}
