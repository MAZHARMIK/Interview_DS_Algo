/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=VQAp7AQ8JcM
    Company Tags                : Payu
    GfG Link                    : https://www.geeksforgeeks.org/problems/count-possible-ways-to-construct-buildings5007/1
*/

/******************************************************************** C++ ********************************************************************/
//Approach-1 (Recursion + Memoization)
//T.C : O(n)
//S.C : O(n)
class Solution{
	public:
	int t[100001][2];
	int M = 1e9 + 7;
	
	int space    = 0;
	int building = 1;
	    
	int solve(int n, int status) {
	    if(n == 0)
	        return 1; //All done. Found one way
	    
	    if(t[n][status] != -1) 
	        return t[n][status];
	    
	    if(status == building) 
	        return t[n][status] = solve(n - 1, space) % M;
	    
	    else
	        return t[n][status] = (solve(n - 1, building) % M + solve(n - 1, space) % M) % M;
	        
	       
	   return -1; //Yaha kabhi nahi aaega flow
	}
	
	int TotalWays(int N) {
	    memset(t, -1, sizeof(t));
	    
	    long long x = (solve(N - 1, building) % M + solve(N - 1, space) % M) % M;
	    
	    return (x * x) % M;
	}
};


//Approach-2 (Bottom Up)
//T.C : O(n)
//S.C : O(n)
class Solution{
	public:
	int M        = 1e9 + 7;
	int space    = 0;
	int building = 1;
	
	int TotalWays(int N) {
	    vector<vector<int>> t(N, vector<int>(2));
	    //t[i][j] :
	    //Number of ways to construct buildings till ith slot having j status
        //i:It denotes the current position or index in the sequence (from 0 to N-1).
        //j: It represents the status of the current position, 
        //where j = 0 corresponds to the "space" status, 
        //and j = 1 corresponds to the "building" status.
        
        //n this case, there is only one way to arrange the buildings and spaces: 
        //either placing a building or leaving it as a space. 
        //Hence, t[0][j] for both j = 0 (space) and j = 1 (building) is set to 1.
        for(int j = 0; j < 2; j++) {
            t[0][j] = 1;
        }
        
        for(int i = 1; i < N; i++) {
            for(int j = 0; j < 2; j++) {
                
                if(j == building) {
                    t[i][j] = t[i-1][space] % M;
                } else {
                    t[i][j] = (t[i-1][space] % M + t[i-1][building] % M) % M;
                }
            }
        }
        
        long long result = (t[N - 1][building] % M + t[N - 1][space] % M) % M;

        return (int) (result * result % M);
	}
};


/******************************************************************** JAVA ********************************************************************/
//Approach-1 (Recursion + Memoization) - Stack Overflow
//T.C : O(n)
//S.C : O(n)
class Solution
{
    int[][] t;
    int M = (int) (1e9 + 7);

    int space = 0;
    int building = 1;
    
    public int solve(int n, int status) {
        if (n == 0)
            return 1; // All done. Found one way

        if (t[n][status] != -1)
            return t[n][status];

        if (status == building)
            return t[n][status] = solve(n - 1, space) % M;
        else
            return t[n][status] = (solve(n - 1, building) % M + solve(n - 1, space) % M) % M;
    }
    
    public int TotalWays(int N) {
        t = new int[N + 1][2];
        for (int i = 0; i <= N; i++) {
            Arrays.fill(t[i], -1);
        }

        long x = (solve(N - 1, building) % M + solve(N - 1, space) % M) % M;

        return (int) ((x * x) % M);
    }
}


//Approach-2 (Bottom Up)
//T.C : O(n)
//S.C : O(n)
class Solution
{   
    int M = (int) (1e9 + 7);

    int space = 0;
    int building = 1;
    
    public int TotalWays(int N) {
        int[][] t = new int[N + 1][2];
        for (int i = 0; i < N; i++) {
            Arrays.fill(t[i], -1);
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 2; j++) {
                if (i == 0) {
                    t[i][j] = 1;
                } else {
                    if (j == building) {
                        t[i][j] = t[i - 1][space] % M;
                    } else {
                        t[i][j] = (t[i - 1][building] % M + t[i - 1][space] % M) % M;
                    }
                }
            }
        }

        long result = (t[N - 1][building] % M + t[N - 1][space] % M) % M;

        return (int) (result * result % M);
    }
}
