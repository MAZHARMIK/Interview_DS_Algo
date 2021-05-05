/*
    Company Tags  : Amazon, Microsoft
    Question Link : https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
*/

#include<bits/stdc++.h>
using namespace std;

int MCM_Recursive(vector<int>& arr, int i, int j) {
    if(i >= j)
        return 0;

    int ans = INT_MAX;

    for(int k = i; k<=j-1; k++) {
        int temp = MCM_Recursive(arr, i, k)   +
                   MCM_Recursive(arr, k+1, j) +
                   arr[i-1]*arr[k]*arr[j];

        ans = min(ans, temp);
    }

    return ans;
}

int MCM_Memoized(vector<int>& arr, int i, int j, vector<vector<int>>& t) {
    if(i >= j)
        return 0;

    if(t[i][j] != -1)
        return t[i][j];
    int ans = INT_MAX;

    for(int k = i; k<=j-1; k++) {
        int temp = MCM_Memoized(arr, i, k, t) +
                   MCM_Memoized(arr, k+1, j, t) +
                   arr[i-1]*arr[k]*arr[j];

        ans = min(ans, temp);
    }

    return t[i][j] = ans;
}

//Simply derived from Recursive solution
int MCM_Topdown(vector<int>& arr, int n) {
    vector<vector<int>> t(n, vector<int>(n));
    //t[i][j] = min cost to multiply A[i], A[i+1], ... A[j]
    //where, A[i] is a matrix and its dimensions are as follows arr[i-1]*arr[i];

    for(int i = 1; i<n; i++) {
        //cost to multiply one matrix is 0 as there will
        //be no multiplication
        t[i][i] = 0;
    }

    for(int L = 2; L<n; L++) { //chain length
        for(int i = 1; i<n-L+1; i++) {
            int j = i+L-1;

            t[i][j] = INT_MAX;

            for(int k = i; k<=j-1; k++) {
                int temp = t[i][k] +
                           t[k+1][j] +
                           arr[i-1]*arr[j]*arr[k];
                t[i][j] = min(t[i][j], temp);
            }
        }
    }

    return t[1][n-1]; //Remember, we had sent solve(1, n-1) in Recursive solution as well
}

int main() {
    vector<int> arr{1,2,3,4,3};
    int n = arr.size();
    cout << MCM_Recursive(arr, 1, n-1) << endl;

    vector<vector<int>> t(n+1, vector<int>(n+1, -1));
    cout << MCM_Memoized(arr, 1, n-1, t) << endl;

    cout << MCM_Topdown(arr, n) << endl;
    return 0;
}
