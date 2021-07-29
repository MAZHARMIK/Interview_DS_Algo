/*
    Company Tags  : Google
    Leetcode Link : https://leetcode.com/problems/01-matrix/
*/

Why BFS ?
Always remember whenever you have to find shortest path in graph, 2-d matrix , BFS
must come to your mind first.

Kind of similar qn : "Walls And Gates" https://leetcode.com/problems/walls-and-gates/

//Approach-1 (Using BFS) Time : O(m*n)
/*
	Do BFS from every 1, and find the nearest 0.
	That's fine but too slow. Because you will be calling one BFS call for each 1.
	So, what we can do to make it better ?
	Instead of doing BFS from 1, store all 0s and do BFS from them, and when you see the nearest 1, update its value. It will be shortest coz we stop at nearest 1
	
	Why Time complexity is O(m*n) ?
	Since we update the 1 with smallest distance, we don't get to visit that again and hence
	every cell gets added to queue only once.
*/

class Solution {
public:
    int m, n;
    typedef pair<int, int> P;
    vector<vector<int>> directions{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();
        queue<P> que;
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(mat[i][j] == 0) {
                    dist[i][j] = 0;
                    que.push({i, j});
                }
            }
        }
        
        auto isSafe = [](int& i, int& j, int& m, int& n) {
            return i>=0 && i<m && j>=0 && j<n;
        };
        
        while(!que.empty()) {
            P p = que.front();
            que.pop();
            
            for(auto &dir : directions) {
                int i = p.first  + dir[0];
                int j = p.second + dir[1];
                
                if(isSafe(i, j, m, n)) {
                    if(dist[i][j] > 1 + dist[p.first][p.second]) {
                        que.push({i, j});
                        dist[i][j] = 1 + dist[p.first][p.second];
                    }
                }
            }
            
        }
        
        return dist;
        
    }
};


/*
Approach-2 (Using DP)
Link : https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/DP/01%20Matrix.cpp
*/
