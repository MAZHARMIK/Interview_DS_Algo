/*
    Company Tags  : Baidu
    Leetcode Link : https://leetcode.com/problems/out-of-boundary-paths/
*/


////////using map for memoization. Time : 156 ms//////////////////////////
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

////////using 3-D array for memoization. Time : 4 ms//////////////////////////
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
