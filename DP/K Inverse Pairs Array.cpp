       						//SCROLL DOWN TO SEE JAVA CODE ALSO
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=y9yo1kyW7Bg
    Company Tags 	        : Google
    Leetcode Link 		: https://leetcode.com/problems/k-inverse-pairs-array/
*/

/*************************************************************** C++ ***************************************************************/
//Approach-1 (Reucr+Memo)
//T.C  : O(n*k*n)
//S.C  : O(n*k) for memo + Recursion call stack
class Solution {
public:
    const int M = 1e9+7;
    int t[1001][1001];
    int solve(int n, int k) {
        if(n == 0)
            return 0;
        
        if(k == 0)
            return 1;
        
        if(t[n][k] != -1)
            return t[n][k];

        int totalInversions = 0;
        
        //In an array of length n, We can't create inversions more than (n-1) -> min(n-1, k)
        for(int i = 0; i <= min(n-1, k); i++) {
            totalInversions = (totalInversions%M + kInversePairs(n-1, k-i)%M)%M;
        }
        
        return t[n][k] = totalInversions;
    }

    int kInversePairs(int n, int k) {
        memset(t, -1, sizeof(t));
        return solve(n, k);
    }
};


//Approach-2 (Bottom UP derived from Approach-1)
//T.C  : O(n*k*n)
//S.C  : O(n*k) for memo + Recursion call stack
class Solution {
public:
    const int M = 1e9+7;
    int kInversePairs(int n, int k) {
        vector<vector<int>> t(n+1, vector<int>(k+1));

        for(int i = 0; i < n+1; i++) {
            t[i][0] = 1;
        }

        for(int i = 1; i<=n; i++) {
            
            for(int j = 1; j <= k; j++) {

                for(int inv = 0; inv <= min(i-1, j); inv++) {
                    t[i][j] = (t[i][j] + t[i-1][j-inv])%M;
                }

            }
        }
        return t[n][k];
    }
};

//Approach-3 (Improving on Approach-1 above) - DP with cumulative sum approach
//Time : O(n*k)
//S.C : O(n*k)
//Read the comment below how people got this idea
class Solution {
public:
    int M = 1e9+7;

    int kInversePairs(int n, int k) {
        vector<vector<int>> t(n+1, vector<int>(k+1));
        //t[i][j] = total number of arrays having (1 to i) and exactly j inversions

        //for j = 0, t[i][0] = 1
        for(int i = 0; i <= n; i++) {
            t[i][0] = 1;
        }

        //O(n*k)
        for(int i = 1; i <= n; i++) {
            long long cumSum = 1;
            for(int j = 1; j <= k; j++) {
                
                cumSum += t[i-1][j];
                if(j >= i) {
                    cumSum -= t[i-1][j-i];
                }
                t[i][j] = cumSum % M;
            }
        }


        return t[n][k];

    }
};

/*   
	For me, I had to print the DP table and understand where exactly others were able to see the cumulative sum.
  Then after this, when I saw Approach-2, I could figure out that yes, it could be improved with cumulative sum (Approach-3)
	
    Exmaple: n = 5, k = 5
    
           |___________________________
           |   1   0   0   0    0    0   
           |   1   0   0   0    0    0   
           |   1   1   0   0    0    0   
           |   1   2   2   1    0    0   
           |   1   3   5   6    5    3   
           |   1   4   9   15   20   22  
            
            
            
            row is shown by i
            col is shown by j
            If you notice the DP table of Bottom up approach, you will notice that
            t[i][j] = sum of elements of previous row (i-1) starting from that column (j) till 0
            
            Example : Let's fill up the last row of our dp table shown above.
            i.e. we will be filling i = 5, from j = 0 to j = 5
            Now,
            for j = 0, t[i][j] = t[i][0] = 1 (since for K = 0, we have only 1 arrangement), so cumulativeSum = 1
            for j = 1, i.e. t[i][j] = t[i-1][1] + t[i-1][0] (Instead of adding this, we store the previous sum in cumulaiveSum)
            So, cumSum += t[i-1][j]  i.e. cumSum = 4 (Because t[i-1][j] was 3 and cumSum was already)
            Now, t[i][1] = cumSum
            i.e. t[i][1] = 4
            
            Similaryly, 
            For j = 2,
            cumSum += t[i-1][2] = 9
            t[i][2] = cumSum = 9;
            
            Now, you can see how the rows are being filled.
            
            BUT, there is a catch, 
            If you see, t[5][5] should have been 23 if we follow our cumulative approach, but it's 22
            This is because, we add only upto 'i' previous column. So, when j reaches i, we substract cumSum from t[i-1][j-i]th entry
            
            By the time we reach j = 5 (for i = 5), cumSum = 23 i.e. (1  + 3 +  5 +  6  +  5  +  3)
            But we can only add 'i' number of previous elements. i.e. till 3 only (3 + 5 + 6 + 5 + 3 = 22)
            So, we substract t[i-1][j-i] from SumSum. So, cumSum = 23-1 = 22
            So, t[5][5] = 22
			
			Try to print the DP table for bigger n and k to see what has been explained above.


   	Another example : n = 5, k = 7 (See last row)
    
        1   0   0   0    0    0    0    0   
	1   0   0   0    0    0    0    0   
	1   1   0   0    0    0    0    0   
	1   2   2   1    0    0    0    0   
	1   3   5   6    5    3    1    0   
	1   4   9   15   20   22   20   15   
    
*/
```



/*************************************************************** JAVA ***************************************************************/
//Approach-1 (Reucr+Memo)
//T.C  : O(n*k*n)
//S.C  : O(n*k) for memo + Recursion call stack
public class Solution {
    final int M = 1000000007;
    int[][] t = new int[1001][1001];

    public int solve(int n, int k) {
        if (n == 0)
            return 0;

        if (k == 0)
            return 1;

        if (t[n][k] != -1)
            return t[n][k];

        int totalInversions = 0;

        // In an array of length n, we can't create inversions more than (n-1) -> min(n-1, k)
        for (int i = 0; i <= Math.min(n - 1, k); i++) {
            totalInversions = (int) ((totalInversions % M + kInversePairs(n - 1, k - i) % M) % M);
        }

        return t[n][k] = totalInversions;
    }

    public int kInversePairs(int n, int k) {
        for (int i = 0; i < t.length; i++) {
            Arrays.fill(t[i], -1);
        }
        return solve(n, k);
    }
}

//Approach-2 (Bottom UP derived from Approach-1)
//T.C  : O(n*k*n)
//S.C  : O(n*k) for memo + Recursion call stack
public class Solution {
    final int M = 1000000007;

    public int kInversePairs(int n, int k) {
        int[][] t = new int[n + 1][k + 1];

        for (int i = 0; i < n + 1; i++) {
            t[i][0] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                for (int inv = 0; inv <= Math.min(i - 1, j); inv++) {
                    t[i][j] = (int) ((t[i][j] + t[i - 1][j - inv]) % M);
                }
            }
        }
        return t[n][k];
    }
}


//Approach-3 (Improving on Approach-1 above) - DP with cumulative sum approach
//Time : O(n*k)
//S.C : O(n*k)
//Read the comment below how people got this idea
public class Solution {
    int M = 1000000007;

    public int kInversePairs(int n, int k) {
        int[][] t = new int[n + 1][k + 1];

        // t[i][j] = total number of arrays having (1 to i) and exactly j inversions

        // for j = 0, t[i][0] = 1
        for (int i = 0; i <= n; i++) {
            t[i][0] = 1;
        }

        // O(n*k)
        for (int i = 1; i <= n; i++) {
            long cumSum = 1;
            for (int j = 1; j <= k; j++) {

                cumSum += t[i - 1][j];
                if (j >= i) {
                    cumSum -= t[i - 1][j - i];
                }
                t[i][j] = (int) (cumSum % M);
            }
        }

        return t[n][k];
    }
}
