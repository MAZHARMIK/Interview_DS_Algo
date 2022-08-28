/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=mNWwJQ7_z4Q
    Company Tags  : MICROSOFT
    Leetcode Link : https://leetcode.com/problems/sort-the-matrix-diagonally/
    
    Similar GfG Qn :  https://practice.geeksforgeeks.org/problems/diagonal-morning-assembly0028/1#
    Leetcode Qn Like this : Leetcode-498 (Diagonal Traverse) : https://leetcode.com/problems/diagonal-traverse/
*/

/*
    Note : If you want to travel diaginally from left side, you can use the key map as (i+j) instead of (i-j)
    Related Qn : https://leetcode.com/problems/diagonal-traverse/
*/

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        unordered_map<int, vector<int>> mp;
        
        //store diagonal elements
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                mp[i-j].push_back(mat[i][j]);
            }
        }
        
        //sort them
        for(auto &it : mp) {
            sort(it.second.begin(), it.second.end());
        }
        
        
        //now, put them back in sorted fashion
        for(int i = m-1; i>=0; i--) {
            for(int j = n-1; j>=0; j--) {
                mat[i][j] = mp[i-j].back();
                
                mp[i-j].pop_back();
            }
        }
        
        return mat;
    }
};
