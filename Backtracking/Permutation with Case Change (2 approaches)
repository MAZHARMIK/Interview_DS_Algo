#include <bits/stdc++.h>
using namespace std;

void generateP_1(string output, string input) {
    if(input.length() == 0) {
        cout << output << endl;
        return;
    }

    string op1 = output+ input[0];
    string op2 = output + string(1, (islower(input[0])?(char)toupper(input[0]):(char)tolower(input[0])));
    generateP_1(op1, input.substr(1));
    generateP_1(op2, input.substr(1));
}


void generateP_2(int start, string s) {
    cout << s << endl;
    if(start == s.length()) {
        return;
    }

    for(int i = start; i<s.length(); i++) {
        s[i] = islower(s[i])?(char)toupper(s[i]):(char)tolower(s[i]);
        generateP_2(i+1, s);
        s[i] = islower(s[i])?(char)toupper(s[i]):(char)tolower(s[i]);
    }
}

int main() {
    string s = "ab";

    generateP_1("", s);
    cout << "\n------------------\n";
    generateP_2(0, s);
}
