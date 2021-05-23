/*
    Company Tags  : It's quite tough to be asked in interview. But you may be asked for the Time Cimplexity
    Leetcode Link : https://leetcode.com/problems/find-the-shortest-superstring/
*/

//Note: I will be back with a better explanation for this approach  later :-)
class Solution {
public:
    string shortestSuperstring(vector<string>& A) {
        int n = A.size();
        
        vector<vector<int>> overlaps(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int m = min(A[i].size(), A[j].size());
                for (int k = m; k >= 0; --k) {
                    if (A[i].substr(A[i].size() - k) == A[j].substr(0, k)) {
                        overlaps[i][j] = k;
                        break;
                    }
                }
            }
        }
  
        // dp[mask][i] = most overlap with mask, ending with ith element
        vector<vector<int>> dp(1<<n, vector<int>(n, 0));
        vector<vector<int>> parent(1<<n, vector<int>(n, -1));
        
        for (int mask = 0; mask < (1<<n); ++mask) {

            for (int bit = 0; bit < n; ++bit) {
                if (((mask>>bit)&1) > 0) {
                    int pmask = mask^(1<<bit);
                    
                    if (pmask == 0) 
                        continue;
                    for (int i = 0; i < n; ++i) {
                        if (((pmask>>i)&1) > 0) {
                            int val = dp[pmask][i] + overlaps[i][bit];
                            if (val > dp[mask][bit]) {
                                dp[mask][bit] = val;
                                parent[mask][bit] = i;
                            }
                        }
                    }
                }
            }
        }
        
        vector<int> perm;
        vector<bool> seen(n);
        int mask = (1<<n) - 1;
        
        int p = 0;
        for (int i = 0; i < n; ++i) {
            if (dp[(1<<n) - 1][i] > dp[(1<<n) - 1][p]) {
                p = i;
            }
        }
        
        while (p != -1) {
            perm.push_back(p);
            seen[p] = true;
            int p2 = parent[mask][p];
            mask ^= (1<<p);
            p = p2;
        }
        
        reverse(perm.begin(), perm.end());
        
        for (int i = 0; i < n; ++i) {
            if (!seen[i]) {
                perm.push_back(i);
            }
        }
        
        string ans = A[perm[0]];
        for (int i = 1; i < n; ++i) {
            int overlap = overlaps[perm[i - 1]][perm[i]];
            ans += A[perm[i]].substr(overlap);
        }
        
        return ans;
        
    }
};
