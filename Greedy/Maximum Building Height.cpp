/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/maximum-building-height/description
*/


/*********************************************************** C++ **************************************************/
//Approach (Math and Greedy)
//T.C : O(n log n)
//S.C : O(1) (ignoring the space taken for sorting internally)
class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1, 0});
        restrictions.push_back({n, n-1});

        sort(begin(restrictions), end(restrictions));

        int N = restrictions.size();

        //Left To Right
        for(int i = 1; i < N; i++) {
            int diffDist = restrictions[i][0] - restrictions[i-1][0];
            restrictions[i][1] = min(restrictions[i][1], restrictions[i-1][1] + diffDist);
        }

        //Right to Left
        for(int i = N-2; i >= 0; i--) {
            int diffDist       = restrictions[i+1][0] - restrictions[i][0];
            restrictions[i][1] = min(restrictions[i][1], restrictions[i+1][1] + diffDist);
        }

        int result = 0;

        //Calculating result
        for(int i = 1; i < N; i++) {
            int leftPos = restrictions[i-1][0];
            int leftHt  = restrictions[i-1][1];

            int currPos = restrictions[i][0];
            int currHt  = restrictions[i][1];

            int d      = currPos - leftPos;
            int htDiff = abs(leftHt - currHt);


            int peak = max(leftHt, currHt) + (d - htDiff)/2;

            result = max(result, peak);
        }

        return result;
    }
};



/*********************************************************** JAVA **************************************************/
//Approach (Math and Greedy)
//T.C : O(n log n)
//S.C : O(m) for arr (ignoring the space taken for sorting internally)
class Solution {
    public int maxBuilding(int n, int[][] restrictions) {
        int m = restrictions.length;
        int[][] arr = new int[m + 2][2];

        for (int i = 0; i < m; i++) {
            arr[i][0] = restrictions[i][0];
            arr[i][1] = restrictions[i][1];
        }

        arr[m][0] = 1;
        arr[m][1] = 0;
        arr[m + 1][0] = n;
        arr[m + 1][1] = n - 1;

        Arrays.sort(arr, Comparator.comparingInt(a -> a[0]));

        int N = arr.length;

        // Left to Right
        for (int i = 1; i < N; i++) {
            int diffDist = arr[i][0] - arr[i - 1][0];
            arr[i][1] = Math.min(arr[i][1], arr[i - 1][1] + diffDist);
        }

        // Right to Left
        for (int i = N - 2; i >= 0; i--) {
            int diffDist = arr[i + 1][0] - arr[i][0];
            arr[i][1] = Math.min(arr[i][1], arr[i + 1][1] + diffDist);
        }

        int result = 0;

        // Calculating result
        for (int i = 1; i < N; i++) {
            int leftPos = arr[i - 1][0];
            int leftHt = arr[i - 1][1];

            int currPos = arr[i][0];
            int currHt = arr[i][1];

            int d = currPos - leftPos;
            int htDiff = Math.abs(leftHt - currHt);

            int peak = Math.max(leftHt, currHt) + (d - htDiff) / 2;
            result = Math.max(result, peak);
        }

        return result;
    }
}
