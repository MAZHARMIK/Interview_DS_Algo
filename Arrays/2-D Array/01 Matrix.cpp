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
Some more explanation on why BFS from '0's is better than BFS from '1's
Let's take it this way,

    When you do a BFS from a '1', you visit 0's around you and find the nearest 0 and update the value for '1'.
    Again you have to do it for the next '1' and so on for other 1's
    When you do a BFS from a '0', you will find nearest '1's and update their values.
    So in one go, you are able to update multiple '1' nearest '0' distance

The best example I see for this is :
0, 1, 1
1, 1, 1
1, 1, 1

You do a BFS on [0][1] and find the nearest 0
You do a BFS on [0][2] and find the nearest 0
.... so on
You do a BFS on [2][2] and find the nearest 0 which is at [0][0]
Notice that you have to travel whole matrix in worst case to find that only 0 at [0][0] for each '1'

Now, Alternatively, you do a BFS on '0' which is at [0][0], initially que has only [{0, 0}]
It will update [0][1]'s and [1][0]'s distance from [0][0] at once and add them to que for further processing. que = [{0, 1}, {1, 0}]
And now, in the next iteration you will update the neighbors of current content of que.
Notice, you don't have to visit the [0][0] for each '1'. You are just passing on the value of neighbors to their neighbors and so on.

Hope that answers your question.

Suggestion : Try both approaches (1) BFS from each '1', (2) BFS from each '0' and every time print the contents of que
Example :
0, 1, 1
1, 1, 1
1, 1, 1
Try on this example. You'll be able to see easily what's different between two approaches.
/*


Approach-2 (Using DP)
Link : https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/DP/01%20Matrix.cpp
*/
