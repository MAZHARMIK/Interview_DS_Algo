/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Salesforce, Miscrosoft, Facebook, Google
    Leetcode Link               : https://leetcode.com/problems/russian-doll-envelopes/
*/


//Approach-1 (Using Simple LIS recursion+memo) - Since Qn doesn't say to take envelopes in given order, we can sort it too.
//T.C : O(n*n)
//TLE
class Solution {
public:
    int n;
    vector<vector<int>> t;
    int lis(vector<vector<int>>& envelopes, int prev_idx, int curr_idx) {
        if(curr_idx == n) {
            return 0;
        }

        if(prev_idx != -1 && t[prev_idx][curr_idx] != -1)
            return t[prev_idx][curr_idx];
        
        int taken = 0;
        if(prev_idx == -1 || 
           (envelopes[curr_idx][0] > envelopes[prev_idx][0] && envelopes[curr_idx][1] > envelopes[prev_idx][1]))
            taken = 1 + lis(envelopes, curr_idx, curr_idx+1);
        
        int not_taken = lis(envelopes, prev_idx, curr_idx+1);
        
        if(prev_idx != -1)
            t[prev_idx][curr_idx] = max(taken, not_taken);
        
        return max(taken, not_taken);
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        n = envelopes.size();
        sort(envelopes.begin(), envelopes.end()); 
        
        t.resize(n+1, vector<int>(n+1, -1));
        
        return lis(envelopes, -1, 0);
    }
};


//Approach-2 (Bottom Up)
//T.C : O(nlogn) + O(n^2)
//TLE
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end());
        
        //Now, find LIS keeping width and height both in consideration
                
        vector<int> lis(n, 1);
        int result = 1;
        for(int i = 1; i<n; i++) {
            for(int j = 0; j<i; j++) {
                if(envelopes[i][0] > envelopes[j][0] && 
                   envelopes[i][1] > envelopes[j][1]) {
                    lis[i] = max(lis[i], lis[j]+1);
                    result = max(result, lis[i]);
                }
            }
        }
        
        return result;
    }
};


//Approach-3 (coming soon)
