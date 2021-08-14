/*
    Company Tags           : Tencent
    Leetcode Link          : https://leetcode.com/problems/remove-boxes/
    Best video explanation : https://www.youtube.com/watch?v=6EfBJX9uLDI
    Similar problem        : Burst Balloons (Leetcode-312)
*/

//Using Recursion+Memoization
class Solution {
public:
    vector<int> boxes;
    int t[101][101][101];
    int solve(int i, int j, int k) {
        if(i > j)
            return 0;
        
        if(t[i][j][k] != -1)
            return t[i][j][k];
        
        int count = 1;
        int ii    = i + 1;
        while(ii <= j && boxes[ii] == boxes[ii-1]) {
            ii++;
            count++;
        }
        
        //Option-1 (Remove the current ith box)
        int result = pow(k+count, 2) + solve(ii, j, 0);
        
        //Option-2 Find if you have same box (boxes[i]) further somewhere and
        //see if you can remove middle part to make  boxes[i] bigger in group
        
        for(int m = ii; m<=j; m++) {
            if(boxes[m] == boxes[i]) {
                result = max(result, solve(ii, m-1, 0) + solve(m, j, k+count));
            }
        }
        
        return t[i][j][k] = result;
    }
    
    int removeBoxes(vector<int>& boxes) {
        this->boxes = boxes;
        memset(t, -1, sizeof(t));
        return solve(0, boxes.size()-1, 0);
    }
};
