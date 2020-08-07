/*
    Company Tags     : Amazon, DE-Shaw, Microsoft, Morgan Stanley, Paytm, Samsung, Snapdeal, Zoho
    Leetcode Qn Link : https://leetcode.com/problems/rotate-image/
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int N = matrix.size();
        
        //find transpose
        for(int i = 0; i<N; i++) {
            for(int j = i; j<N; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        
        //flip horizontally
        for(int i = 0; i<N; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
