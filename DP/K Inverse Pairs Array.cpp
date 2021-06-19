/*
    Company Tags  : Not known yet. Few people claimed it to be Google's but I am not sure. 
    Leetcode Link : https://leetcode.com/problems/k-inverse-pairs-array/
*/

//Approach-1 (Reucr+Memo) Time : O(n*k*n)
class Solution {
public:
    const int M = 1e9+7;
    int t[1001][1001] = {};
    int kInversePairs(int n, int k) {
        if(n == 0)
            return 0;
        
        if(k == 0)
            return 1;
        
        if(t[n][k] != 0)
            return t[n][k];
        int totalInversions = 0;
        
        for(int i = 0; i<= min(n-1, k); i++) {
            totalInversions = (totalInversions + kInversePairs(n-1, k-i))%M;
        }
        
        return t[n][k] = totalInversions;
    }
};
```


```
//Approach-2 (Bottom UP derived from Approach-1) : Time : O(n*k*n)
class Solution {
public:
    const int M = 1e9+7;
    int kInversePairs(int n, int k) {
        vector<vector<int>> t(n+1, vector<int>(k+1));
        t[0][0] = 1;
        for(int i = 1; i<=n; i++) {
            
            for(int j = 0; j<=k; j++) {
                if(j == 0) {
                    t[i][j] = 1;
                }
                else {
                    for(int p = 0; p<=min(i-1, j); p++) {
                        t[i][j] = (t[i][j] + t[i-1][j-p])%M;
                    }
                }
            }
        }
        return t[n][k];
    }
};
```

```
//DP with cumulative sum approach (using approach-2 above) Time : O(n*k)
//Read the comment below how people got this idea
class Solution {
public:
    const int M = 1e9+7;
    int kInversePairs(int n, int k) {
        vector<vector<int>> t(n+1, vector<int>(k+1));
        t[0][0] = 1;
        for(int i = 1; i<=n; i++) {
            long long cumSum = 0;
            for(int j = 0; j<=k; j++) {
                if(j == 0) {
                    t[i][j] = 1;
                    cumSum += 1;
                }
                else {
                    cumSum += t[i-1][j];
                    if(j-i >= 0)
                        cumSum -= t[i-1][j-i];
                    t[i][j] = cumSum%M;
                }
            }
        }
        
        for(int i = 0; i<n+1; i++) {
            for(int j = 0; j<k+1; j++) {
                cout << t[i][j] << "   ";
            }
            cout << endl;
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
            If you notice te DP table of Bottom up approach, you will notice that
            t[i][j] = sum of elements of previous row (i-1) starting from that column (j) till 0
            
            Example : Let's fill up the last row of our dp table shown above.
            i.e. we will be filling i = 5, from j = 0 t0 j = 5
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
    
*/
```
