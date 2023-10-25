/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Cw7A8YU0WjY
    Company Tags                : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/k-th-symbol-in-grammar
*/

/************************************************ C++ ************************************************/
//(Using Recursion)
//T.C : O(N)
//S.C : O(N) Stack space
class Solution {
public:
    int kthGrammar(int N, int K) {
        if(N == 1 && K == 1)
            return 0;
        int mid = pow(2, N-1)/2;
        
        if(K <= mid)
            return kthGrammar(N-1, K);
        
        return !kthGrammar(N-1, K-mid);
    }
};




/************************************************ JAVA ************************************************/
//(Using Recursion)
//T.C : O(N)
//S.C : O(N) Stack space
public class Solution {
    public int kthGrammar(int N, int K) {
        if (N == 1 && K == 1) {
            return 0;
        }
        int mid = (int) Math.pow(2, N - 1) / 2;

        if (K <= mid) {
            return kthGrammar(N - 1, K);
        }

        return 1 - kthGrammar(N - 1, K - mid); //same as ! that I used in C++ above
    }
}
