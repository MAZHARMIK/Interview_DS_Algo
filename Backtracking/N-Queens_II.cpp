/*
    Company Tags  : Accolite, Amazon, Visa, MAQ Software, Amdocs, Twitter, Qualcomm, Google 
    Leetcode Link : https://leetcode.com/problems/n-queens-ii/
*/

/*
    A simple approach will be the same as N Queens problem. Instead of returning all the configurations of board (vector<vector<string>>),
    here we return the count of total configurations. Link : https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Backtracking/N-Queens.cpp
    
    But, you don't need to form boards and configurations to count the total configurations. See the solution below.
*/
class Solution {
public:
    int count = 0;
    unordered_set<int> cols;
    unordered_set<int> diags;
    unordered_set<int> antiDiags;
    void dfs(int row, int n) {
        if(row == n) {
            count++;
            return;
        }
        
        for(int col = 0; col<n; col++) {
            int d  = row-col;
            int ad = row+col;
            
            if(cols.count(col) || diags.count(d) || antiDiags.count(ad))
                continue;
            
            cols.insert(col);
            diags.insert(d);
            antiDiags.insert(ad);
            
            dfs(row+1, n);
            
            cols.erase(col);
            diags.erase(d);
            antiDiags.erase(ad);
            
        }
    }
    vector<vector<string>> result;
    int totalNQueens(int n) {
        count = 0;
        if(n == 1)
            return 1;
        if(n <= 3)
            return count;
        
        dfs(0, n);
        
        return count;
        
    }
};
