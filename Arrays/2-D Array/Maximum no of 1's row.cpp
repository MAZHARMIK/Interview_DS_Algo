/*
    Company Tags : 24*7 Innovation Labs,  D-E-Shaw,  Microsoft,  Paytm
    Qn Link : https://practice.geeksforgeeks.org/problems/maximum-no-of-1s-row3027/1/?page=2&curated[]=1&sortBy=submissions#
*/

//Approach-1 (SImple Binary Search)
class Solution
{
    public:
        int maxOnes (vector <vector <int>> &Mat, int M, int N) {
            int rowAns   = 0;
            int maxOnes  = -1;
            
            for(int row = 0; row<M; row++) {
                int low = 0, high = N-1;
                int result = -1;
                while(low <= high) {
                    int mid = low + (high-low)/2;
                    if(Mat[row][mid] == 1) {
                        result = mid;
                        high = mid-1;
                    } else {
                        low = mid+1;
                    }
                }
                if(result != -1 && N-result > maxOnes) {
                    maxOnes = N-result;
                    rowAns = row;
                }
            }
            
            return rowAns;
            
        }
};


//Approach-2 (Similar, but using lower_bound)
class Solution
{
    public:
        int maxOnes (vector <vector <int>> &Mat, int M, int N) {
            int rowAns   = 0;
            int maxOnes  = -1;
            
            for(int row = 0; row<M; row++) {
                
                auto it = lower_bound(begin(Mat[row]), end(Mat[row]), 1);
                int index = it-begin(Mat[row]);
                
                if(index != N && N-index > maxOnes) {
                    maxOnes = N-index;
                    rowAns = row;
                }
            }
            
            return rowAns;
            
        }
};
