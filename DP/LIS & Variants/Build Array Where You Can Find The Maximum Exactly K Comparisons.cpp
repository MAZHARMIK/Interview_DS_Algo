/*
    MY YOUTUBE VIDEO ON THIS Qn : Recur + Memo - https://www.youtube.com/watch?v=YU9IGG5PB2Y
                                  Bottom Up - Soon coming
    Company Tags                : Will Update soon
    Leetcode Link               : https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons/
*/

/************************************************************ C++ ************************************************************/
//Approach-1 (Using Recursion + Memoization)
//T.C : O(m*n*k)
class Solution {
public:
    int N, M, K;
    int MOD = 1e9+7;
    int t[51][51][101];
    
    int solve(int idx, int searchCost, int maxSoFar) {
        if(idx == N) {
            if(searchCost == K)
                return 1;
            return 0;
        }
        
        if(t[idx][searchCost][maxSoFar] != -1) {
            return t[idx][searchCost][maxSoFar];
        }
        
        int result = 0;
        
        for(int i = 1; i <= M; i++) {
            
            if(i > maxSoFar) {
                result = (result + solve(idx+1, searchCost+1, i)) % MOD;
            } else {
                result = (result + solve(idx+1, searchCost, maxSoFar)) % MOD;
            }
            
        }
        
        return t[idx][searchCost][maxSoFar] = result % MOD;
        
    }
    
    int numOfArrays(int n, int m, int k) {
        N = n;
        M = m;
        K = k;
        memset(t, -1, sizeof(t));
        return solve(0, 0, 0);
    }
};

//Approach-2 (Bottom Up)
//T.C : O(NKM^2)
class Solution {
public:
    /* let ways[i][j][k] = # ways to construct an array of length i with max element equal to j and a search cost of k. */
    long long ways[51][101][51];
    const int MOD = 1e9 + 7;
    
    int numOfArrays(int n, int m, int k) {
		/* There are our base cases. For each index 1 <= j <= m, we require ways[1][j][1] = 1 because the array consisting of only the element j
			has length 1, maximum element j, and it has a search cost of 1. */
        for (int j = 1; j <= m; j++) {
                ways[1][j][1] = 1;
        }
        
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= m; b++) {
                for (int c = 1; c <= k; c++) {
                    long long s = 0;

		            /* In this first case, we can append any element from [1, b] to the end of the array. */
                    s = (s + b * ways[a - 1][b][c]) % MOD;
                    
		           /* In this second case, we can append the element "b" to the end of the array. */
                    for (int x = 1; x < b; x++) {
						s = (s + ways[a - 1][x][c - 1]) % MOD;
                    }
					
                    ways[a][b][c] = (ways[a][b][c] + s) % MOD;
                }
            }
        }

        long long ans = 0;
        for (int j = 1; j <= m; j++) {
            ans = (ans + ways[n][j][k]) % MOD;
        }
        
        return int(ans);
    }
};

/************************************************************ JAVA ************************************************************/
//Approach-1 (Using Recursion + Memoization)
//T.C : O(m*n*k)
public class Solution {
    private int N, M, K;
    private final int MOD = 1000000007;
    private int[][][] t;

    public int numOfArrays(int n, int m, int k) {
        N = n;
        M = m;
        K = k;
        t = new int[51][51][101];
        for (int i = 0; i < 51; i++) {
            for (int j = 0; j < 51; j++) {
                Arrays.fill(t[i][j], -1);
            }
        }
        return solve(0, 0, 0);
    }

    private int solve(int idx, int searchCost, int maxSoFar) {
        if (idx == N) {
            if (searchCost == K) {
                return 1;
            }
            return 0;
        }

        if (t[idx][searchCost][maxSoFar] != -1) {
            return t[idx][searchCost][maxSoFar];
        }

        int result = 0;

        for (int i = 1; i <= M; i++) {
            if (i > maxSoFar) {
                result = (result + solve(idx + 1, searchCost + 1, i)) % MOD;
            } else {
                result = (result + solve(idx + 1, searchCost, maxSoFar)) % MOD;
            }
        }

        return t[idx][searchCost][maxSoFar] = result % MOD;
    }
}


//Approach-2 (Bottom Up)
//T.C : O(NKM^2)
class Solution {
    private long[][][] ways;
    private final int MOD = 1000000007;
    
    public int numOfArrays(int n, int m, int k) {
        ways = new long[52][102][52];
        
        for (int j = 1; j <= m; j++) {
            ways[1][j][1] = 1;
        }
        
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= m; b++) {
                for (int c = 1; c <= k; c++) {
                    long s = 0;
                    
                    s = (s + b * ways[a - 1][b][c]) % MOD;
                    
                    for (int x = 1; x < b; x++) {
                        s = (s + ways[a - 1][x][c - 1]) % MOD;
                    }
                    
                    ways[a][b][c] = (ways[a][b][c] + s) % MOD;
                }
            }
        }
        
        long ans = 0;
        for (int j = 1; j <= m; j++) {
            ans = (ans + ways[n][j][k]) % MOD;
        }
        
        return (int)ans;
    }
}
