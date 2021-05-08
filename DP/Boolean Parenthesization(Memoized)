/*
  Company Tags : Amazon, LinkedIn, Microsoft
  Qn Link      : https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1
  
  Qn : Given a boolean expression with following symbols.
  Symbols
      'T' ---> true 
      'F' ---> false 

  And following operators filled between symbols

  Operators
      &   ---> boolean AND
      |   ---> boolean OR
      ^   ---> boolean XOR 

  Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true. 
*/

//NOTE: This is an accepted solution
#include<bits/stdc++.h>
using namespace std;
int t[202][202][2];
int solve(string& expr, int i, int j, bool isTrue) {
    if(i > j)
        return 0;
    if(t[i][j][isTrue] != -1)
        return t[i][j][isTrue];
    if(i == j) {
        if(isTrue)
            return t[i][j][isTrue] = (expr[i] == 'T');
        else
            return t[i][j][isTrue] = (expr[i] == 'F');
    }
    int ans = 0;
    int lt, lf, rt, rf;
    for(int k = i+1; k<=j-1; k+=2) {
        if(t[i][k-1][true] != -1)
            lt = t[i][k-1][true];
        else
            lt = t[i][k-1][true] = solve(expr, i, k-1, true);
        if(t[i][k-1][false] != -1)
            lf = t[i][k-1][false];
        else
            lf = t[i][k-1][false] = solve(expr, i, k-1, false);

        if(t[k+1][j][true] != -1)
            rt = t[k+1][j][true];
        else
            rt = t[k+1][j][true] = solve(expr, k+1, j, true);
        if(t[k+1][j][false] != -1)
            rf = t[k+1][j][false];
        else
            rf = t[k+1][j][false] = solve(expr, k+1, j, false);

        if(expr[k] == '&') {
            if(isTrue == true)
                ans += (lt*rt);
            else
                ans += (lt*rf) + (lf*rt) + (lf*rf);
        }
        else if(expr[k] == '|') {
            if(isTrue == true)
                ans += (lt*rt) + (lf*rt) + (lt*rf);
            else
                ans += (lf*rf);
        }
        else if(expr[k] == '^') {
            if(isTrue == true)
                ans += (lt*rf) + (lf*rt);
            else
                ans += (lt*rt) + (lf*rf);
        }
    }
    return t[i][j][isTrue] = ans%1003;
}

int main()
 {
    int T, N;
    string expr;
    cin >> T;
    while(T--) {
        cin >> N;
        cin >> expr;
          memset(t,-1,sizeof(t));
        cout << solve(expr, 0, N-1, true) << endl;

    }
    return 0;
}
