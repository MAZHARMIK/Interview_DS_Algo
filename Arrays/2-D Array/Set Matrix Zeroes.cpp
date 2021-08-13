/*
    Company Tags  : Microsoft, Amazon
    Leetcode Link : https://leetcode.com/problems/set-matrix-zeroes/
*/

//Approch-1 (The first solution that comes to our mind)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> t(m, vector<int>(n, 0));
        unordered_set<pair<int, int>> st;
        
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(matrix[i][j] == 0)
                    st.insert({i, j});
            }
        }
        
        for(const pair<int, int>& p : st) {
            int row = p.first;
            int col = p.second;
            
            int c = 0;
            while(c < n) {
                matrix[row][c] = 0;
                c++;
            }
            int r = 0;
            while(r < m) {
                matrix[r][col] = 0;
                r++;
            }
        }
    }
};

//Approach-2 (Read below)
/*
a) If you see a 0 at [i][j] then make [0][j] = 0 and [i][0] = 0
They will act as a flag that the corresponding row and column are meant to be 0s

However, note one thing we need to be careful at one point. We need to handle column0
carefully. Why ?????

You are here n the DISCUSS section to learn. So, let's start with not handling the 0th column 
specially and do (a) mentioned above blindly. Submit it and check what's error you are getting.
It will fail in test cases like :

    Why did we handled column 0 like above ?
    Because if we don't do so, your code will fail for cases like this below : 
	(Do a dry run to see for yourself)
    [[1,2,3,4],[5,0,7,8],[0,10,11,12],[13,14,15,0]]

*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        bool col0_zero = false;
        
        for(int i = 0; i<m; i++) {
            if(matrix[i][0] == 0) col0_zero = true;
            
            for(int j = 1; j<n; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
		//Also, why I had to traverse from bottom right to top ?
		//Do the same thing here, traverse from top right instead and submit
		//and you will yourself find the error in some test case after dry run.
		//That's how I came to this solution. This is the best way to understand an approach.
		//Don't memorise. Try and then understand and learn from your mistakes.
        for(int i = m-1; i>=0; i--) {
            for(int j = n-1; j>=1; j--) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
            if(col0_zero)
                matrix[i][0] = 0;
        }
                
    }
};
