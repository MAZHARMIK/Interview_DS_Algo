/*    Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn  : https://www.youtube.com/watch?v=9tUv0SfUyGg
    Company Tags                 : will update later
    Leetcode Link                : https://leetcode.com/problems/find-missing-and-repeated-values
*/


/********************************************************************* C++ *********************************************************************/
//Approach-1 (Simple using map)
//T.C : O(n^2)
//S.C : O(n^2)
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int N = n*n; //total elements

        unordered_map<int, int> mp;

        int a = -1;
        int b = -1;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                mp[grid[i][j]]++;
            }
        }

        //[1...N]
        for(int num = 1; num <= N; num++) {
            if(!mp.count(num)) {
                b = num;
            } else if(mp[num] == 2) {
                a = num;
            }

            if(a != -1 && b != -1) {
                break;
            }
        }

        return {a, b};
    }
};


//Approach-2 (using maths)
//T.C : O(n^2)
//S.C : O(n^2)
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();

        long long N = n*n;

        long long gridSum   = 0;
        long long gridSqSum = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                gridSum += grid[i][j];
                gridSqSum += grid[i][j]*grid[i][j];
            }
        }

        long long sum   = (N * (N+1))/2; //Expected sum of N natural numbers
        long long sqSum = (N * (N+1) * (2*N+1))/6; //Expected sq sum of natural numbers

        int sqDiff  = gridSqSum - sqSum;
        int sumDiff = gridSum - sum;

        int a = (sqDiff/sumDiff + sumDiff)/2; 
        int b = (sqDiff/sumDiff - sumDiff)/2;

        return {a, b};
    }
};



/********************************************************************* JAVA *********************************************************************/
//Approach-1 (Simple using map)
//T.C : O(n^2)
//S.C : O(n^2)
/********************************************************************* Java *********************************************************************/
//Approach-1 (Simple using HashMap)
//T.C : O(n^2)
//S.C : O(n^2)
class Solution {
    public int[] findMissingAndRepeatedValues(int[][] grid) {
        int n = grid.length;
        int N = n * n; // total elements

        HashMap<Integer, Integer> map = new HashMap<>();

        int a = -1;
        int b = -1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                map.put(grid[i][j], map.getOrDefault(grid[i][j], 0) + 1);
            }
        }

        //[1...N]
        for (int num = 1; num <= N; num++) {
            if (!map.containsKey(num)) {
                b = num;
            } else if (map.get(num) == 2) {
                a = num;
            }

            if (a != -1 && b != -1) {
                break;
            }
        }

        return new int[]{a, b};
    }
}


//Approach-2 (using maths)
//T.C : O(n^2)
//S.C : O(n^2)
class Solution {
    public int[] findMissingAndRepeatedValues(int[][] grid) {
        int n = grid.length;

        long N = (long) n * n;

        long gridSum = 0;
        long gridSqSum = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                gridSum += grid[i][j];
                gridSqSum += (long) grid[i][j] * grid[i][j];
            }
        }

        long sum = (N * (N + 1)) / 2; // Expected sum of N natural numbers
        long sqSum = (N * (N + 1) * (2 * N + 1)) / 6; // Expected sq sum of natural numbers

        long sqDiff = gridSqSum - sqSum;
        long sumDiff = gridSum - sum;

        int a = (int) ((sqDiff / sumDiff + sumDiff) / 2);
        int b = (int) ((sqDiff / sumDiff - sumDiff) / 2);

        return new int[]{a, b};
    }
}
