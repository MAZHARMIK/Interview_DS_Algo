/*
    Company Tags  : Google
    Leetcode Link : https://leetcode.com/problems/beautiful-arrangement/
*/

class Solution {
public:
    int result = 0;
    
    void dfs(vector<int>& vec, int pos, int n) {
        if(pos > n) {
            result++;
            return;
        }
        
        for(int i = pos; i<=n; i++) {
            if(vec[i]%pos == 0 || pos%vec[i] == 0) {
                swap(vec[i], vec[pos]);
                dfs(vec, pos+1, n);
                swap(vec[i], vec[pos]);
            }
        }
    }
    
    int countArrangement(int n) {
        //Objective is to see which permutation is beautiful
        //So, simply apply permutation code and apply the condition
        //for solving this question
        vector<int> vec(n+1);
        for(int i = 1; i<=n; i++)
            vec[i] = i;
        
        
        dfs(vec, 1, n);
        return result;
    }
};
