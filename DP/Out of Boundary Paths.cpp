/*
    Company Tags  : Baidu
    Leetcode Link : https://leetcode.com/problems/out-of-boundary-paths/
*/


////////using map for memoization. Time : 156 ms (O(m*n*maxMove))//////////////////////////
using ll = unsigned long long ;
class Solution {
public:
    int m, n;
    unordered_map<string, ll> mp;
    int solve(int maxMove, int i, int j) {
        if(i < 0 || i >= m || j < 0 || j >= n) {
            return 1;
        }
        if(maxMove == 0)
            return 0;
        
        string key   = to_string(maxMove) + "_" + to_string(i) + "_" + to_string(j);
            
        if(mp.find(key) != mp.end())
            return mp[key];
        
        ll left     = solve(maxMove-1, i, j-1);
        ll right    = solve(maxMove-1, i, j+1);
        ll up       = solve(maxMove-1, i-1, j);
        ll down     = solve(maxMove-1, i+1, j);

        return mp[key] = (left+right+up+down)%1000000007;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        if(maxMove == 0)
            return 0;
        mp.clear();
        this->m = m;
        this->n  = n;

        return solve(maxMove, startRow, startColumn);

    }
};

////////using 3-D array for memoization. Time : 4 ms (O(m*n*maxMove))//////////////////////////
using ll = unsigned long long ;
class Solution {
public:
    int m, n;
    int t[51][51][51];
    int solve(int maxMove, int i, int j) {
        if(i < 0 || i >= m || j < 0 || j >= n) {
            return 1;
        }
        if(maxMove == 0)
            return 0;
        
        if(t[maxMove][i][j] != -1)
            return t[maxMove][i][j];
        
        ll left     = solve(maxMove-1, i, j-1);
        ll right    = solve(maxMove-1, i, j+1);
        ll up       = solve(maxMove-1, i-1, j);
        ll down     = solve(maxMove-1, i+1, j);

        return t[maxMove][i][j] = (left+right+up+down)%1000000007;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        if(maxMove == 0)
            return 0;
        
        memset(t, -1, sizeof(t));
        this->m = m;
        this->n  = n;

        return solve(maxMove, startRow, startColumn);

    }
};

////////using Bottom Up. Time : 4 ms (O(m*n*maxMove))//////////////
/*I'ts a tricky one. I couldn't come up with this solution in the first time*/
typedef unsigned long long ll;
class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        ll prev[51][51] = {0};
        //t[i][j] = # ways to reach [i][j] with x moves in hand
        prev[startRow][startColumn] = 1;
        /*
            There is only one(1) way to reach [startRow][startCol] with 0 moves in hand
        */
        
        ll count = 0;
        ll M     = 1e9+7;
        for(int move = 1; move <= maxMove; move++) {
            ll curr[51][51] = {0};
            for(int i = 0; i<m; i++) {
                for(int j = 0; j<n; j++) {
                    if(i == 0)
                        count = (count+prev[i][j])%M;
                    if(i == m-1)
                        count = (count+prev[i][j])%M;
                    if(j == 0)
                        count = (count+prev[i][j])%M;
                    if(j == n-1)
                        count = (count+prev[i][j])%M;
                    
                    curr[i][j] += (i > 0   ? prev[i-1][j] : 0)%M;   // we can come to [i][j] from UP    only if curr i > 0
                    curr[i][j] += (i < m-1 ? prev[i+1][j] : 0)%M;   // we can come to [i][j] from DOWN  only if curr i < m-1
                    curr[i][j] += (j > 0   ? prev[i][j-1] : 0)%M;   // we can come to [i][j] from LEFT  only if curr j > 0
                    curr[i][j] += (j < n-1 ? prev[i][j+1] : 0)%M;   // we can come to [i][j] from RIGHT only if curr j < n-1
                }
            }
            swap(prev, curr);
        }
        
        return count;
    }
};
