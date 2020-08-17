/*
    Company Tags : Amazon
    Qn Link      : https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence/0
    Note: This link contains the question for finding the length of Longest Repeating Subsequence". But using the same solution, you can print it as well.
*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int LRS(string s1, string s2, int m, int n) {
    vector<vector<int>> t(m+1, vector<int>(n+1));
    for(int i = 0; i<m+1; i++) {
        for(int j = 0; j<n+1; j++) {
            if(i == 0 || j == 0)
                t[i][j] = 0;
            else if(s1[i-1] == s2[j-1] && i != j) {
                t[i][j] = 1 + t[i-1][j-1];
            } else {
                t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
    }
    int i = m, j = n;
    string s = "";
    while(i > 0 && j > 0) {
        if(s1[i-1] == s2[j-1] && i!= j) {
            s += s1[i-1];
            i--;
            j--;
        } else {
            if(t[i-1][j] > t[i][j-1]) {
                i--;
            } else {
                j--;
            }
        }
    }
    reverse(s.begin(), s.end());
    cout << s << endl;
    return t[m][n];
}

int main() {
    string s1 = "AABEBCDD";
    int m = s1.length();
    cout << LRS(s1, s1, m, m);


return 0;
}
