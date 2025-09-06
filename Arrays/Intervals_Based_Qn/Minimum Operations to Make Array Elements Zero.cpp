/*         Scroll below to see JAVA code as well        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=VYDl3p9bkkw
    Company Tags                : Will update later
    Leetcode Qn Link            : https://leetcode.com/problems/minimum-operations-to-make-array-elements-zero
*/


/************************************************************************ C++ ************************************************************/
//Approach (Using Power Four Range for Steps of Reduction to 0)
//T.C : O(Q * log(max r)), Q =  number of queries, r = right value of ranges
//S.C : O(1)
class Solution {
public:

    long long solve(int l, int r) {
        //L, R
        //1 to 3 : 1 steps
        //4 to 15 : 2 steps
        long long L = 1; //R = 4*L-1
        long long S = 1;
        long long steps = 0;

        while(L <= r) {
            long long R = 4*L - 1;

            long long start = max(L, (long long)l);
            long long end   = min(R, (long long)r);

            if(start <= end) {
                steps += (end-start+1)*S;
            }

            S += 1;
            L = L*4;
        }

        return steps;
    }

    long long minOperations(vector<vector<int>>& queries) {
        long long result = 0;

        for(auto &query : queries) {
            int l = query[0];
            int r = query[1];

            long long steps = solve(l, r);

            result += (steps+1)/2;
        }

        return result;
    }
};



/************************************************************************ JAVA ************************************************************/
//Approach (Using Power Four Range for Steps of Reduction to 0)
//T.C : O(Q * log(max r)), Q =  number of queries, r = right value of ranges
//S.C : O(1)
class Solution {

    private long solve(int l, int r) {
        long L = 1;  // starting point of range
        long S = 1;  // steps multiplier
        long steps = 0;

        while (L <= r) {
            long R = 4 * L - 1;  // end of current range

            long start = Math.max(L, (long) l);
            long end = Math.min(R, (long) r);

            if (start <= end) {
                steps += (end - start + 1) * S;
            }

            S += 1;
            L = L * 4;
        }

        return steps;
    }

    public long minOperations(int[][] queries) {
        long result = 0;

        for (int[] query : queries) {
            int l = query[0];
            int r = query[1];

            long steps = solve(l, r);
            result += (steps + 1) / 2;
        }

        return result;
    }
}
