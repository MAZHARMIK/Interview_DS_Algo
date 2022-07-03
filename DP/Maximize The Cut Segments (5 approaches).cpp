/*
    Company Tags  : Amazon, OYO Rooms, Microsoft, Google
    Question Link : https://practice.geeksforgeeks.org/problems/cutted-segments/0
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

//APPROACH-1 (Using Simple Maths)
int maxSeg1(int N, int x, int y, int z) {
    int maxR = 0;
    for(int a = 0; a<=N; a++) {
        for(int b = 0; b<=N; b++) {
            int cz    = N-(a*x + b*y);
            if(cz < 0) {
                break;
            }
            double c  = double(cz)/double(z);
            if(c == int(c)) {
                maxR = max(maxR, a+b+(int)c);
            }
        }
    }
    return maxR;
}

//APPROACH-2 (Usin concept of Coin Change)
int maxSeg2(vector<int> pieces, int n, int Sum) {
    vector<vector<int>> t(n+1, vector<int>(Sum+1));
    for(int col = 0; col<Sum+1; col++) {
        t[0][col] = INT_MIN;
    }
    
    for(int row = 1; row<n+1; row++) {
        t[row][0] = 0;
    }

    for(int col = 1; col<Sum+1; col++) {
        if(col%pieces[0] == 0)
            t[1][col] = col/pieces[0];
        else
            t[1][col] = INT_MIN;
    }
    
    for(int i = 2; i<n+1; i++) {
        for(int j = 1; j<Sum+1; j++) {
            if(pieces[i-1] <= j)
                t[i][j] = max(1 + t[i][j-pieces[i-1]], t[i-1][j]);
            else
                t[i][j] = t[i-1][j];
        }
    }
    
    return t[n][sum] < 0 ? 0 : t[n][sum];
}

//APPROACH-3 (Bottom Up DP)
int maxSeg3(int a, int b, int c, int N) {
    vector<int> t(N+1, -1);
    //t[i] = max # of segments from ribbon of length i
    t[0] = 0;
    for(int i = 0; i<N+1; i++) {
        if(t[i] == -1)
            continue;
        if(i+a < N+1)
            t[i+a] = max(t[i+a], 1 + t[i]);
        if(i+b < N+1)
            t[i+b] = max(t[i+b], 1 + t[i]);
        if(i+c < N+1)
            t[i+c] = max(t[i+c], 1 + t[i]);
    }
    return t[N];
}

//APPROACH-4 (Using recursion with Memoization)
int maxSeg4(int N, int x, int y, int z, vector<int>& t) {
    if(N < 0)
        return INT_MIN;
    if(N == 0)
        return 0;
    if(t[N] != -1)
        return t[N];
    int a = 1 + maxSeg(N-x, x, y, z, t);
    int b = 1 + maxSeg(N-y, x, y, z, t);
    int c = 1 + maxSeg(N-z, x, y, z, t);
    
    return t[N] = max({a, b, c});
}

//APPROACH-5 (Using concept of Rod Cutting)
int maxSeg5(vector<int>& pieces, int n, int Sum) {
    vector<vector<int>> t(n+1, vector<int>(Sum+1));
    for(int i = 0; i<n+1; i++) {
        for(int j = 0; j<Sum+1; j++) {
            if(i == 0 || j == 0)
                t[i][j] = 0;
        }
    }
    
    for(int i = 1; i<n+1; i++) {
        for(int j = 1; j<Sum+1; j++) {
            if(pieces[i-1] <= j) {
                if(pieces[i-1] == j || t[i][j-pieces[i-1]] != 0) //It checks for a valid peice (If we cut a segment, then remaining segment length should also be valid)
                    t[i][j] = max(1 + t[i][j-pieces[i-1]], t[i-1][j]);
                else
                    t[i][j] = t[i-1][j];
            } else {
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][Sum];
}

int main() {
    int T, x, y, z, N;
    vector<int> vec(3);
    cin >> T;
    while(T--){
        cin >> N;
        cin >> x >> y >> z;
        int maxR = 0;
        cout << maxSeg1(N, x, y, z) << endl;  //APPROACH-1 : Intuitive approach
        
        vector<int> pieces(3);
        pieces[0] = x;
        pieces[1] = y;
        pieces[2] = z;
        cout << maxSeg2(pieces, 3, N) << endl; //APPROACH-2 : using coin change concept
        
        cout << maxSeg3(N, x, y, z) << endl;   //APPROACH-3 : Simple DP
        
        vector<int> t(N+1, -1);
        int result = maxSeg4(N, x, y, z, t); //APPROACH-4 : Simple recursion with Memoization
        cout <<  result < 0 ? 0 : result << endl;
        
        cout << maxSeg5(pieces, 3, N) << endl;  //APPROACH-5 : Using rod cutting concept
    }
return 0;
}
