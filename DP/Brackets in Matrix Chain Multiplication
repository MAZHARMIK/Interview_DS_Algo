/*
    Company Tags  : Microsoft
    Question Link : https://practice.geeksforgeeks.org/problems/brackets-in-matrix-chain-multiplication/0#
*/

class Solution{
public:
    string result = "";
    char a = 'A';
    void solve(int i, int j, vector<vector<int>>& brackets) {
        if(i>=j) {
            result.push_back(a);
            a++;
            return;
        }
        
        result += "(";
        solve(i, brackets[i][j], brackets);   //solve(i, k)
        solve(brackets[i][j]+1, j, brackets); //solve(k+1, j)
        result += ")";
    }
    string matrixChainOrder(int arr[], int n){
        vector<vector<int>> t(n, vector<int>(n));
        vector<vector<int>> brackets(n, vector<int>(n));
        //brackets[i][j]  = k means dividing the chain at k gives minimum cost
        
        //t[i][j] = minimum multiplication cost for A[i], A[i+1]. ,.. A[j]
        //A[i] = matrix(arr[i-1]*arr[i])
                
        for(int i = 0; i<n; i++)
            t[i][i] = 0; //only one matrix will cost 0
            
        for(int L = 2; L<=n; L++) {
            for(int i = 0; i<n-L+1; i++) {
                int j = i + L - 1;
                
                t[i][j] = INT_MAX;
                for(int k = i; k<=j-1; k++) {
                    int temp = arr[i-1]*arr[k]*arr[j] + 
                               t[i][k] + 
                                t[k+1][j];
                    
                    if(t[i][j] > temp) {
                        t[i][j] = temp;
                        brackets[i][j] = k;
                    }
                }
            }
        }
        
        solve(1, n-1, brackets);
        return result;
    }
};
