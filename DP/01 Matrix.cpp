/*
    Company Tags  : Google
    Leetcode Link : https://leetcode.com/problems/01-matrix/
*/

//Approach-1 (DP) Time (O(m*n))
/*
	Note that, if you are standing at 1, you can ask your neighbours "Hey, can you please tell me the nearest 1 to you ? ")
	I find the minimum from my neighbors and add 1 to them for me. 
	
	But we need to do this in 2 pass. 
	   - First fill by traversing top-down
	   -  And then fill bottom-up .
	   -  Or vice versa

Why ?
See the example below to understand :
Don't look on the giagantic arrays below. Just see [1][1] of all of them
For [1][1], the nearest 0 is at [1][2] or [2][1] which are at distance 1
But, while doing my first traversal (top and left), I only considered 
top ([0][1]) and left([1][0]) which has value 1 and I did 1 + min(1, 1) = 2
which gave me wrong answer. The expected answer should be 1.

Input :
[[0,1,0,1,1],
 [1,1,0,0,1],
 [0,0,0,1,0],
 [1,0,1,1,1],
 [1,0,0,0,1]]
 
Output : 
[[0,1,0,1,2],
 [1,2,0,0,1],
 [0,0,0,1,0],
 [1,0,1,2,1],
 [2,0,0,0,1]]
 
Expected : 
[[0,1,0,1,2],
 [1,1,0,0,1],
 [0,0,0,1,0],
 [1,0,1,1,1],
 [1,0,0,0,1]]
 


Qn : Why didn't I compare top, left, right, bottom at the same time in the fist loop ?

Ans: Because, when I am traversing row wise (left to right and bottom to top), I only have
updated values of my top and left because I have already visited them but I don't know
what's optimal values for my right and down as I have not yet visited them.
So, best way is to traverse (i) top to down  (ii) bottom to up

*/
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> dist(m, vector<int>(n, 1000000));
        
        //top to bottom (I only have access to left and top optimal values)
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(mat[i][j] == 0) {
                    dist[i][j] = 0;
                } else {
                    int left = dist[i][max(0, j-1)];
                    int top  = dist[max(0, i-1)][j];
                    
                    dist[i][j] = min(dist[i][j], 1 + min(left, top));
                }
            }
        }
        
        //bottom to up (I will have access to right and down optimal values)
        for(int i = m-1; i>=0; i--) {
            for(int j = n-1; j>=0; j--) {
                if(mat[i][j] == 0) {
                    dist[i][j] = 0;
                } else {
                    int right = dist[i][min(n-1, j+1)];
                    int down  = dist[min(m-1, i+1)][j];
                    
                    dist[i][j] = min(dist[i][j], 1 + min(right, down));
                }
            }
        }
        
        
        return dist;
    }
};

/*
Approach-2 (Using BFS)
Link : https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/2-D%20Array/01%20Matrix.cpp
*/
