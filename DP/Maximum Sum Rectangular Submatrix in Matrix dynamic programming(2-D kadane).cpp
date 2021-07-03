/*
    Company Tags  :  Accolite, Amazon, D-E-Shaw, FactSet, Samsung, Walmart
    Question Link : https://practice.geeksforgeeks.org/problems/maximum-sum-rectangle2948/1
    
    This question will help you to solve Leetcode-363(Max Sum of Rectangle No Larger Than K)
    Youtube Link for this Question (Tushar Roy) : https://www.youtube.com/watch?v=yCQN096CwWM
    
    Link to Leetcode-363 solution : https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/DP/Max%20Sum%20of%20Rectangle%20No%20Larger%20Than%20K.cpp
*/

#include<bits/stdc++.h>
using namespace std;

int maxL, maxR, maxUp, maxDown;
int maxResult = INT_MIN;

void KadanesAlgo(int nums[], int &n, int &L, int &R) {
    int currSum = 0;
    int maxSum  = 0;
    int start   = 0;
    int end     = 0;
    int beg     = 0;
    for(int i = 0; i<n; i++) {
        currSum += nums[i];

        if(currSum < 0) {
            currSum = 0;
            beg = i+1;
        }

        if(currSum > maxSum) {
            maxSum = currSum;
            start = beg;
            end   = i;
        }
    }

    //update the coordinates of new rectangle having greater sum
    if(maxSum > maxResult) {
        maxResult = maxSum;
        maxL      = L;
        maxR      = R;
        maxUp     = start;
        maxDown   = end;
    }
}

void towDKadane(vector<vector<int>>& matrix) {
    int rows   = matrix.size();
    int cols   = matrix[0].size();

    for(int L = 0; L<cols; L++) {
        int temp[rows] = {0};
        for(int R = L; R<cols; R++) {

            for(int row = 0; row < rows; row++)
                temp[row] += matrix[row][R];

            KadanesAlgo(temp, rows, L, R);            
        }
    }
  
    cout << maxResult << endl << "The sub-matrix is \n";

    for(int i = maxL; i<=maxR; i++) {
        for(int j = maxUp; j<= maxDown; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
}

int main() {
    vector<vector<int>> matrix
                        {
                         {2,1,-3,-4,5},
                         {0,6,3,4,1},
                         {2,-2,-1,4,-5},
                         {-3,3,1,0,3}
                        };
    towDKadane(matrix);

}
