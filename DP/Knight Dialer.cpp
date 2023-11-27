/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=pOmSGFPcMjQ
    Company Tags                : Facebook, Dropbox, Microsoft, Google
    Leetcode Link               : https://leetcode.com/problems/knight-dialer/
*/

/********************************************************************** C++ **************************************************************************/
//Approach-1 (Using Recursion + Memoization)
//T.C : O(n*9) Total n*k states
//S.C : O(n*9)
//NOTE : T.C Without Memoization - O(10 * 3^n). This is because each cell has up to three possible next cells (neighbors)
class Solution {
public:
    
    int M = 1e9+7;
    vector<vector<int>> adj = {
        {4, 6},
        {6, 8},
        {7, 9},
        {4, 8},
        {3, 9, 0},
        {},
        {1, 7, 0},
        {2, 6},
        {1, 3},
        {2, 4}
    };
    
    int t[5001][10];
    
    int solve(int n, int cell) {
        if(n == 0) {
            return 1;
        }
        
        if(t[n][cell] != -1) {
            return t[n][cell];
        }
        
        int result = 0;
        
        for(int &nextCell : adj[cell]) {
            result = (result + solve(n-1, nextCell)) % M; 
        }
        
        return t[n][cell] = result;
    }
    
    int knightDialer(int n) {
        int result = 0;
        memset(t, -1, sizeof(t));
        
        for(int cell = 0; cell <= 9; cell++) {
            result = (result + solve(n-1, cell)) % M;
        }
        
        return result;
    }
};


//Approach-2 (Using Bottom Up - Just write from the recursion)
//T.C : O(n*10)
//S.C : O(n*10)
class Solution {
public:
    
    int M = 1e9+7;
    vector<vector<int>> adj = {
        {4, 6},
        {6, 8},
        {7, 9},
        {4, 8},
        {3, 9, 0},
        {},
        {1, 7, 0},
        {2, 6},
        {1, 3},
        {2, 4}
    };
    
    int knightDialer(int n) {
        int result = 0;
        
        //t[i][j] = number of ways to form a number of length i when I am currently at cell j
        
        vector<vector<int>> t(n, vector<int>(10));
        for(int cell = 0; cell < 10; cell++) {
            t[0][cell] = 1; //for n == 0, we always returned 1
        }
        
        for(int i = 1; i < n; i++) { //This is length of number 
            
            for(int cell = 0; cell <= 9; cell++) {    
                int ans = 0;
                for(int &nextCell : adj[cell]) {
                    
                    ans = (ans + t[i-1][nextCell]) % M;
                    
                }
                t[i][cell] = ans;
                
            }
            
        }
        
        
        for(int cell = 0; cell <= 9; cell++) {
            result = (result + t[n-1][cell]) % M;
        }
        
        return result;
    }
};



/********************************************************************** JAVA **************************************************************************/
//Approach-1 (Using Recursion + Memoization)
//T.C : O(n*9) Total n*k states
//S.C : O(n*9)
public class Solution {
    private static final int M = 1000000007;
    private static final List<List<Integer>> adj = Arrays.asList(
            Arrays.asList(4, 6),
            Arrays.asList(6, 8),
            Arrays.asList(7, 9),
            Arrays.asList(4, 8),
            Arrays.asList(3, 9, 0),
            Arrays.asList(),
            Arrays.asList(1, 7, 0),
            Arrays.asList(2, 6),
            Arrays.asList(1, 3),
            Arrays.asList(2, 4)
    );

    private int[][] t = new int[5001][10];

    private int solve(int n, int cell) {
        if (n == 0) {
            return 1;
        }

        if (t[n][cell] != -1) {
            return t[n][cell];
        }

        int result = 0;

        for (int nextCell : adj.get(cell)) {
            result = (result + solve(n - 1, nextCell)) % M;
        }

        return t[n][cell] = result;
    }

    public int knightDialer(int n) {
        int result = 0;
        Arrays.stream(t).forEach(row -> Arrays.fill(row, -1));

        for (int cell = 0; cell <= 9; cell++) {
            result = (result + solve(n - 1, cell)) % M;
        }

        return result;
    }
}


//Approach-2 (Using Bottom Up - Just write from the recursion)
//T.C : O(n*10)
//S.C : O(n*10)
public class Solution {
    private static final int M = 1000000007;
    private static final List<List<Integer>> adj = Arrays.asList(
            Arrays.asList(4, 6),
            Arrays.asList(6, 8),
            Arrays.asList(7, 9),
            Arrays.asList(4, 8),
            Arrays.asList(3, 9, 0),
            Arrays.asList(),
            Arrays.asList(1, 7, 0),
            Arrays.asList(2, 6),
            Arrays.asList(1, 3),
            Arrays.asList(2, 4)
    );

    public int knightDialer(int n) {
        int result = 0;

        // t[i][j] = number of ways to form a number of length i when I am currently at cell j
        int[][] t = new int[n][10];

        for (int cell = 0; cell < 10; cell++) {
            t[0][cell] = 1; // for n == 0, we always return 1
        }

        for (int i = 1; i < n; i++) { // This is the length of the number
            for (int cell = 0; cell <= 9; cell++) {
                int ans = 0;
                for (int nextCell : adj.get(cell)) {
                    ans = (ans + t[i - 1][nextCell]) % M;
                }
                t[i][cell] = ans;
            }
        }

        for (int cell = 0; cell <= 9; cell++) {
            result = (result + t[n - 1][cell]) % M;
        }

        return result;
    }
}
