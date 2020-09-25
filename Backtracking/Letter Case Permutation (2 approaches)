/*
    Company Tags  : Amazon
    Leetcode Link : https://leetcode.com/problems/letter-case-permutation/
*/

class Solution {
public:
    //Approach-1
    void generateP_1(string output, string input, vector<string>& result) {
        if(input.length() == 0) {
            result.push_back(output);
            return;
        }

        if(!isalpha(input[0])) {
            output += input[0];
            generateP_1(output, input.substr(1), result);
        } else {
            string op1 = output + input[0];
            string op2 = output + string(1, (islower(input[0])?(char)toupper(input[0]):(char)tolower(input[0])));
            generateP_1(op1, input.substr(1), result);
            generateP_1(op2, input.substr(1), result);
        }
    }

    //Approach-2
    void generateP_2(int start, string s, vector<string>& result) {
        result.push_back(s);
        if(start == s.length()) {
            return;
        }

        for(int i = start; i<s.length(); i++) {
            if(!isalpha(s[i]))
                continue;
            s[i] = islower(s[i])?(char)toupper(s[i]):(char)tolower(s[i]);
            generateP_2(i+1, s, result);
            s[i] = islower(s[i])?(char)toupper(s[i]):(char)tolower(s[i]);
        }
    }
    vector<string> letterCasePermutation(string S) {
        vector<string> result;
        
        generateP_2(0, S, result);
        
        //generateP_1("", S, result);
        return result;
    }
};
