/*
    Company Tags  : Mathworks
    Leetcode Link : https://leetcode.com/problems/reshape-the-matrix/
*/
//Both are of same time complexity O(m*n)

//Approach-1 (Naive)
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();

        if(m*n != r*c)
            return mat;

        vector<vector<int>> newMat(r, vector<int>(c));
        
        int i = 0, j = 0;
        int k = 0, l = 0;

        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(l >= c) {
                    k++;
                    l = 0;
                }
                newMat[k][l] = mat[i][j];
                l++;
            }
        }
        return newMat;
    }
};

//Approach-2 (Smart approach - Visualization)
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();

        if(m*n != r*c)
            return mat;

        vector<vector<int>> newMat(r, vector<int>(c));
        
        //Imagine mat as how it would be stored in computer memory (strip of 1-D array)
        /*
            [[1,2]
             [3,4]]
            
            Can be visualized as :
            
			   1      2      3     4
            [0][0], [0][1], [1][0], [1][1]
               0      1       2       3
               
            Notice that in 2-D matrix, column starts from 0, goes till 1,
            and then starts from 0 and then goes till 1
            So, whenever you notice a scenario where a value
            is doing a cycle (0 to 1 and back to 0 and then to 1 and so on)
            modulo operation comes to rescue (%). It helps
            to rewind the value from where it satarted after reaching limit.
            
            Similarly, we can assume the reshaped matrix as 1-d visualiztion
            
            So, for finding the column, it's easy just do a modulo operation
			on index where you are right now.
            And for rows, notice that the visualized 1-d array is actually
			cut by number of columns. So, when we divide (/) index by
			number of column, we get the row number
            
            This is an important concept which is used in many other questions.
            
            mat[0][0] can be written  = mat[i/n][i%n]
            
            Similarly, newMat[0][0] = newMat[i/c][i%c]
        */

        for(int i = 0; i<m*n; i++) {
            newMat[i/c][i%c] = mat[i/n][i%n];
        }
        
        return newMat;
    }
};
