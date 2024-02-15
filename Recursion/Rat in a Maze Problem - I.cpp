/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=wXwZSytYrIs
    Company Tags                : Amazon, Microsoft, Expedia
    GfG Link                    : https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
*/

/************************************************************ C++ ************************************************************/
//T.C : O(3^(n^2))
//S.C : O(L * X) - L = Length of path, X = number of paths
class Solution{
    public:
    vector<string> result;
    
    bool isSafe(int i, int j ,int n) {
        return i >= 0 && i < n && j >= 0 && j < n;
    }
    
    void solve(int i, int j, vector<vector<int>> &m, int n, string& temp) {
        if(!isSafe(i, j, n) || m[i][j] == 0) {
            return;
        }
        if(i == n-1 && j == n-1) {
            result.push_back(temp);
            return;
        }
        
        m[i][j] = 0;
        
        temp.push_back('D');
        solve(i+1, j, m, n, temp);
        temp.pop_back();
        
        temp.push_back('R');
        solve(i, j+1, m, n, temp);
        temp.pop_back();
        
        temp.push_back('U');
        solve(i-1, j, m, n, temp);
        temp.pop_back();
        
        temp.push_back('L');
        solve(i, j-1, m, n, temp);
        temp.pop_back();
        
        m[i][j] = 1;
        
    }
    
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        string temp = "";
        
        solve(0, 0, m, n, temp);
        return result;
    }
};



/************************************************************ JAVA ************************************************************/
//T.C : O(3^(n^2))
//S.C : O(L * X) - L = Length of path, X = number of paths
class Solution {
    private static int[] di = {+1, 0, 0, -1};
    private static int[] dj = {0, -1, +1, 0};

    public static void solve(int[][] m, int n, int[][] vis, int i, int j, ArrayList<String> ars, String ref) {
        if (i == n - 1 && j == n - 1) {
            ars.add(ref);
            return;
        }

        String st = "DLRU";

        for (int l = 0; l < 4; l++) {
            int dc = i + di[l];
            int dd = j + dj[l];

            if (dc >= 0 && dd >= 0 && dc < n && dd < n && vis[dc][dd] == 0 && m[dc][dd] == 1) {
                vis[i][j] = 1;
                solve(m, n, vis, dc, dd, ars, ref + st.charAt(l));
                // backtracking
                vis[i][j] = 0;
            }
        }
    }

    public static ArrayList<String> findPath(int[][] m, int n) {
        ArrayList<String> ars = new ArrayList<>();

        int[][] visited = new int[n][n];
        String ref = "";

        if (m[0][0] == 1) {
            solve(m, n, visited, 0, 0, ars, ref);
        }

        if (ars.isEmpty()) {
            ars.add("-1");
        }

        return ars;
    }
}
