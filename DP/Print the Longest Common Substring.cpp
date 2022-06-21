/*
    Qn Link      : https://www.geeksforgeeks.org/print-longest-common-substring/
    Company Tags : Amazon, Microsoft, Morgan Stanley : Generally Combined with "Longest Common Substring" Question
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int LCSubstring(string s1, string s2, int m, int n) {
    vector<vector<int>> t(m+1, vector<int>(n+1));

    int maxC = 0;
    int row, col;
    for(int i = 1; i<m+1; i++) {
        for(int j = 1; j<n+1; j++) {
            if(i == 0 || j == 0)
                t[i][j] = 0;
            else if(s1[i-1] == s2[j-1]) {
                t[i][j] = 1 + t[i-1][j-1];
                //keep track of the row and col when we got the max length
                if(t[i][j] > maxC) {
                    maxC = t[i][j];
                    row = i;
                    col = j;
                }
            } else {
                t[i][j] = 0;
            }
        }
    }

    string res("", maxL);
    while(t[row][col] != 0) {
        res += s1[row-1];
        //move diagonally only because of t[i][j] = 1 + t[i-1][j-1];
        row--;
        col--;
    }
    
    //Alternatively, you can do like this
    //cout << s1.substr(row-maxC, maxC) << endl;
    
    cout << res << endl;
    return maxC;
}

int main() {
    string s1 = "OldSite:GeeksforGeeks.org";
    string s2 = "NewSite:GeeksQuiz.com";
    int m = s1.length();
    int n = s2.length();

    cout << LCSubstring(s1, s2, m, n);
}
