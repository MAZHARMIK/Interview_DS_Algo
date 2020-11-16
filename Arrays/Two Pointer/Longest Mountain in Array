/*
    Compnay Tags  : NIL
    Leetcode Link : https://leetcode.com/problems/longest-mountain-in-array/
*/

class Solution {
public:
    int longestMountain(vector<int>& A) {
        int n = A.size();
        if(n < 3)
            return 0;
        int mid = 1;
        int result = 0;
        while(mid < n-1) {
            if(A[mid-1] < A[mid] && A[mid] > A[mid+1]) {
                int start = mid-1;
                int end   = mid+1;
                while(start > 0 && A[start] > A[start-1]) {
                    start--;
                }

                while(end < n-1 && A[end] > A[end+1]) {
                    end++;
                }
                
                result = max(result, end-start+1);
            }
            mid++;
        }
        return result;
    }
};
